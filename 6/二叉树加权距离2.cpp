#include <iostream>
#include<vector>
/*找最小公共父节点*/
using namespace std;
const int maxn = 1e5 + 5;
int n;
int fa[maxn],dp[maxn]={0,1};
int dep(int k) {
	if (dp[k])return dp[k];
	dp[k] = dep(fa[k]) + 1;
	return dp[k];
}
int find(int u, int v) {//dp[u]>=dp[v]
	while (dp[u] > dp[v])u = fa[u];
	if (u == v)return v;
	while (u != v) u = fa[u], v = fa[v];
	return u;
}

int main() {
	int a,b,u, v;int len = 0;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &a, &b);
		fa[b] = a;
	}
	scanf("%d%d", &u, &v);
	for (int i = 2; i <= n; i++)dep(i);
	
	int pubf;
	if (dp[u] >= dp[v])pubf =find(u, v);
	else pubf =find(v, u);


	for (; u != pubf; u = fa[u], len += 3);
	for (; v != pubf; v = fa[v], len += 2);
	printf("%d", len);
	return 0;
}
/*
5
1 2
2 3
1 4
4 5
3 4

*/