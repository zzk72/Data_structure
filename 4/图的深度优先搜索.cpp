#include <iostream>
#include <vector>
#include <algorithm>
#define cit(x,y,z)  for(int (x)=(y);(x)<=(z);(x)++)

inline int read() {
	int x = 0; int w = 1; register char c = getchar();
	for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
	if (c == '-') w = -1, c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	return x * w;
}
using namespace std;
const int maxn = 50010;

vector<int> G[maxn];
vector<pair<int, int>> path;
int n, e;
int st[maxn]={0}, en[maxn]={0};
int tim = 0;
void dfs(int u) {
	st[u] = ++tim;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!st[v])path.push_back(make_pair(v, u)),dfs(v);
	}
	en[u] = ++tim;
}

int main() {
	n = read(); e = read();
	int  u = 0, v = 0;
	cit(i,1,e) {
		u = read(); v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cit(i,1,n)if(!st[i])dfs(i);
	cit(i,1,n)printf("%d %d\n", st[i], en[i]);
	printf("%d\n", path.size());
	sort(path.begin(), path.end(), less<pair<int, int>>());

	for (int i = 0; i < path.size();i++)//for (int i = 0; i <= path.size()-1;i++)段错误为类型转换问题
		printf("%d %d\n", path[i].second, path[i].first);
	return 0;
}
/*
6 5
1 3
1 2
2 3
4 5
5 6

*/