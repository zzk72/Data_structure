#include<iostream>

#define ls (i << 1)
#define rs (i << 1 | 1)
inline int read() {
	int x = 0; int w = 1; register char c = getchar();
	for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
	if (c == '-') w = -1, c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	return x * w;
}

using namespace std;
const int maxn = 1e6 + 5;
//此题所有测试数据小于maxn

struct segment {
	struct node {
		int l, r, cnt;
	}st[maxn << 2];

	void build(int i, int l, int r) {
		st[i] = { l, r, 0 };
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
	}

	inline	void insert(int i, int val) {
		if (st[i].l == st[i].r) st[i].cnt++;
		else {
			if (val <= st[ls].r) insert(ls, val);
			else insert(rs, val);
			st[i].cnt++;
		}
	}
	inline	void del(int i, int val) {
		if (st[i].l == st[i].r) st[i].cnt--;
		else {
			if (val <= st[ls].r)del(ls, val);
			else del(rs, val);
			st[i].cnt--;
		}
	}
	inline	int find_kth(int i, int k) {
		if (st[i].l == st[i].r)return st[i].l;
		if (k <= st[ls].cnt)return find_kth(ls, k);
		else return find_kth(rs, k - st[ls].cnt);
	}

}ST;

int main() {
	int n = read(),cm,x,out;
	ST.build(1, 0, maxn);
	for (int i = 0; i < n; i++) {
		cm = read(); x = read();

		if (cm == 1) ST.insert(1, x);
		if (cm == 2) { 
			out = ST.find_kth(1, x); 
			printf("%d\n",out); 
		}
		if (cm == 3) ST.del(1, x);
	}
	return 0;
}