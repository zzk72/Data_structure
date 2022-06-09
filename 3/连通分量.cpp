/*
7-1 连通分量
分数 100
作者 谷方明
单位 吉林大学
无向图 G 有 n 个顶点和 m 条边。求 G 的连通分量的数目。

输入格式:
第1行，2个整数n和m，用空格分隔，分别表示顶点数和边数， 1≤n≤50000， 1≤m≤100000.

第2到m+1行，每行两个整数u和v，用空格分隔，表示顶点u到顶点v有一条边，u和v是顶点编号，1≤u,v≤n.

输出格式:
1行，1个整数，表示所求连通分量的数目。

输入样例:
在这里给出一组输入。例如：

6 5
1 3
1 2
2 3
4 5
5 6
输出样例:
在这里给出相应的输出。例如：

2
代码长度限制
16 KB
时间限制
200 ms
内存限制
10 MB
*/
#include<iostream>
#include<vector>

using namespace std;
int *Father;

int Find(int x)
{
	if (Father[x] <= 0) return x;
	return Father[x] = Find(Father[x]);
}

void Union(int x, int y) {//°´ÖÈºÏ²¢
	int xf = Find(x), yf = Find(y);
	if (xf == yf)return;
	if (Father[xf] < Father[yf])Father[yf] = xf;
	else {
		if (Father[xf] == Father[yf])Father[yf] = Father[xf] - 1;
		Father[xf] = yf;
	}
}

int main() {
	int n = 0, m = 0;
	cin >> n >> m;

	Father = new int[n + 1]{ 0 };
	int* mark = new int[n+1] {0};
	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		Union(v, u);
	}
	for (int i = 1; i <= n; i++) {
		mark[Find(i)] = 1;
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
		if(mark[i])ret++;
	cout << ret<<endl;
}
/*
6 3
1 3
4 5
5 6
*/
