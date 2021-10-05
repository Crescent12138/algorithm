///here is jmr's codes
///if you want to copy,please call me 29856325137
///thanks
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
double eps = 1e-6;
const int maxn = 1e5 + 5;
const ll mod = 998244353;
//ll tre[maxn<<1];

long long n, m, x, y, mul, add;
struct node
{
    long long l, r, w;
    long long add_lz, mul_lz;//懒标记 
}tree[4 * 100000 + 10];
long long p = mod, a[100010];
void build(long long k, long long l, long long r)//建树 
{
    tree[k].l = l, tree[k].r = r;
    tree[k].add_lz = 0, tree[k].mul_lz = 1;
    if (l == r)
        tree[k].w = 1;
    else
    {
        int m = (l + r) / 2;
        build(k * 2, l, m);
        build(k * 2 + 1, m + 1, r);
        tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
    }
    tree[k].w %= p;
    return;
}
void down(long long k)//双懒标记下传 
{
    long long l = tree[k].l, r = tree[k].r, m = l + (r - l) / 2;
    tree[k * 2].w = (tree[k * 2].w * tree[k].mul_lz + (m - l + 1) * tree[k].add_lz) % p;
    tree[k * 2 + 1].w = (tree[k * 2 + 1].w * tree[k].mul_lz + (r - m) * tree[k].add_lz) % p;
    tree[k * 2].mul_lz = (tree[k * 2].mul_lz * tree[k].mul_lz) % p;
    tree[k * 2 + 1].mul_lz = (tree[k * 2 + 1].mul_lz * tree[k].mul_lz) % p;
    tree[k * 2].add_lz = (tree[k * 2].add_lz * tree[k].add_lz) % p;
    tree[k * 2 + 1].add_lz = (tree[k * 2 + 1].add_lz * tree[k].add_lz) % p;
    tree[k].mul_lz = 1;
    tree[k].add_lz = 0;
    return;
}
void mu(long long k)
{
    long long l = tree[k].l, r = tree[k].r, m = l + (r - l) / 2;
    if (y < l || r < x)return;
    if (x <= l && y >= r)
    {
        tree[k].w = (tree[k].w * mul) % p;
        tree[k].mul_lz = (tree[k].mul_lz * mul) % p;
        tree[k].add_lz = (tree[k].add_lz * mul) % p;
        return;
    }
    down(k);
    mu(k * 2);
    mu(k * 2 + 1);
    tree[k].w = (tree[k * 2].w + tree[k * 2 + 1].w) % p;
    return;
}
long long query(long long k)
{
    long long l = tree[k].l, r = tree[k].r, m = l + (r - l) / 2;
    if (y < l || r < x)return 0;
    if (x <= l && y >= r)return tree[k].w;
    down(k);
    return (query(k * 2) + query(k * 2 + 1)) % p;
}



ll qpow(ll m, ll k) {
	if (m == 0)return 0;
	ll res = 1 % mod;
	while (k) {
		if (k & 1) res = res * m % mod;
		m = m * m % mod;
		k >>= 1;
	}
	return res;
}
ll kk[maxn];

void init() {
	for (int i = 1; i <= 100; i++) {
		kk[i] =  qpow(100, mod - 2) * i % mod;
	}
}
ll x1[maxn];
ll y2[maxn];
ll z1[maxn];
int main() {
	init();
	cin >> n;
    build(1,1,n);
	for (int i = 1; i <= n; i++)cin >> z1[i] >> x1[i],y2[i] = x1[i];
	sort(x1 + 1, x1 + 1 + n);
	auto pp = unique(x1 + 1, x1 + 1 + n);
    long long ans = 0;
	for (int i = 1; i <= n; i++)y2[i] = lower_bound(x1 + 1, pp, y2[i]) - x1;
	for (int i = 1; i <= n; i++) {
        x = y = y2[i];
        ans =   (query(1) % mod * kk[z1[i]] % mod + ans)%mod;
        x = 1;
        y = y2[i];
        mul = kk[100 - z1[i]];
        mu(1);
	}
    cout << (ans) %mod;
}