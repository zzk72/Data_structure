#include <iostream>
#include <queue>
#include <algorithm>
#define cit(x,y,z)  for(int x=y;x<=z;x++)
#define inf 0x3f3f3f3f
/*bfs*/
using namespace std;
const int maxn = 1e5 + 5;
int n;
int  vis[maxn],dis[maxn];
struct node {
	int near[3];
}G[maxn];

void bfs(int st,int en) {
	queue<int>Q;
	Q.push(st); vis[st] = 1;
	while (!Q.empty()) {
		int tmp = Q.front(); Q.pop();
		cit(i, 0, 2) {
			int t = G[tmp].near[i];
			if (vis[t]||!t)continue;

			dis[t] = dis[tmp] + (i == 0 ? 3 : 2);
			if (t == en)  return; 
			else {
				Q.push(t); vis[t] = 1;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int  u = 0, v = 0;
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	cit(i, 0, n)G[i].near[0] = 0, G[i].near[1] = 0, G[i].near[2] = 0;
	cit(i, 1, n-1) {
		scanf("%d%d", &u,&v);
		if (!G[u].near[1])G[u].near[1] = v;
		else G[u].near[2] = v;
		G[v].near[0] = u;
	}
	int st, en;
	scanf("%d%d", &st, &en);
	bfs(st, en);
	printf("%d", dis[en]);
}
/*
14
1 2
1 3
2 4
2 5
4 8
5 10
3 6
4 9
10 13
10 12
3 7
11 14
7 11
13 14
*/