#include<bits/stdc++.h>
using namespace std;
const int _ = 1e5 + 5;
typedef struct node {
	int l, r, num;
}T;
int n,m;
T x[_<<1],tree[_<<1];
int lazy[_ << 1];
void build(int nod, int l, int r) {
	if (l == r) {
		cin >> x[l].num;
		tree[nod].l = l;
		tree[nod].r = r;
		tree[nod].num = x[l].num;
		return;
	}
	int mid = (l + r) >> 1;
	build((nod << 1), l, mid);
	build((nod << 1) + 1, mid + 1, r);
	tree[nod].num = tree[(nod << 1) + 1].num + tree[nod << 1].num;
	tree[nod].l = l;
	tree[nod].r = r;
}

void add(int nod, int l, int r,int n,int index) {
	if (l == r) {
		tree[nod].num += n;
	}
	int mid = (l + r) >> 1;
	if (index <= mid) {
		add((nod<<1), l, mid, n, index);
	}
	else {
		add((nod << 1) + 1 , mid + 1, l, n, index);
	}
	tree[nod].num = tree[nod * 2 + 1].num + tree[nod * 2].num;
}
inline void push_down(int nod ,int l ,int r) {
	if (lazy[nod]) {
		int mid = (l + r) >> 1;
		lazy[nod << 1] += lazy[nod];
		lazy[(nod << 1) + 1] += lazy[nod];
		tree[nod << 1].num += (mid - l + 1) * lazy[nod];
		tree[(nod << 1) + 1].num += (r - mid) * lazy[nod];
		lazy[nod] = 0;
	}
}
int query(int l,int r,int nod) {



}


int main() {

}