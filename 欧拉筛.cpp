<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
int ans[maxn];
ll k, n;
typedef pair<int, int> pii;
vector<pii> vis;
bool cmp(pii a, pii b) {
	return a.first > b.first;
}
int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	int t1, t2;
	for (int i = 1; i <= k; i++) {
		cin >> t1 >> t2;
		vis.push_back(make_pair(t1, t2));
	}

	sort(vis.begin(), vis.end(), cmp);

	int num = 1;
	bool sy = 1;
	for (int i = 0; i < vis.size(); i++) {

		if (vis[i].first < vis[i].second || (i > 1 && -vis[i].first + vis[i - 1].first < -vis[i].second + vis[i - 1].second)) {
			sy = 0;
			break;
		}

		int temp = vis[i].first - vis[i].second + 1;
		for (int j = vis[i].first - vis[i].second + 1; j <= vis[i].first; j++) {
			if (ans[j]) {
				ans[temp++] = ans[j];
				if (j != temp - 1)
					ans[j] = 0;
			}

		}
		for (int j = temp; j <= vis[i].first; j++) {
			if (ans[j])
				break;
			ans[j] = num++;
		}
	}
	if (sy)
		for (int i = 1; i <= n; i++) {
			if (!ans[i]) {
				cout << num++ << " ";
			}
			else cout << ans[i] << " ";
		}
	else cout << -1 << "\n";
	return 0;
=======
typedef long long ll;
const ll N = 2e5 + 7;
const ll mod = 2147483647;
const int maxn = 100000000;
int prime[maxn];      //就是个素数表
bool sf[maxn];        //判断这个数是不是素数，sf[i]中的i是从1到maxn的数
void sushu() {         //核心 欧拉筛代码
    int num = 0;        //num 用来记筛到第几个质数
    memset(sf, true, sizeof(sf));
    for (int i = 2; i <= maxn; i++) {          //外层枚举1~maxn
        if (sf[i]) prime[++num] = i;      //如果是质数就加入素数表
        for (int j = 1; j <= num; j++) {       //内层枚举num以内的质数
            if (i * prime[j] > maxn) break; //筛完结束
            sf[i * prime[j]] = false;      //筛掉...
            if (i % prime[j] == 0) break;   //避免重复筛
        }
    }
    sf[1] = false;
    sf[0] = false;  //1 0 特判 
>>>>>>> 278fb314a3da4713da79a94cc121bd19c9560df9
}