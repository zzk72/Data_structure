#include<iostream>
using namespace std;
int fa[505];
int Find(int x){
	if (fa[x] <= 0) return x;
	return  fa[x] = Find(fa[x]);
}
bool Union(int x, int y) {
	int yf = Find(y);
	if (x == yf)return false;//判环
	fa[x] = yf;
	return true;
}
int main() {
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);

	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);

		if (0 == fa[v])			//一个只需合并一次
			if(Union(v, u))n--;
	}
	printf("%d", n);
	return 0;
}
/*
6 5
1 2
2 3
3 1
6 5
4 5

*/