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