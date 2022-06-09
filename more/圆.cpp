#include<iostream>

using namespace std;

typedef struct circle {
	int x;
	int y;
	int r;
	circle(){}
	circle(int xx,int yy,int rr):x(xx),y(yy),r(rr){}
}Circle;
int* Father;
int n;
Circle** a;

bool check(int x, int y) {
	int tx = a[x]->x - a[y]->x;
	int ty = a[x]->y - a[y]->y;
	int s = a[x]->r + a[y]->r;
	return tx * tx + ty * ty <= s * s;
}

int Find(int x)
{
	if (Father[x] <= 0) return x;
	return Father[x] = Find(Father[x]);
}
bool Union(int x, int y) {//°´ÖÈºÏ²¢
	int xf = Find(x), yf = Find(y);
	if (xf == yf)return false;
	if (!check(x, y))return false;
	if (Father[xf] < Father[yf])Father[yf] = xf;
	else {
		if (Father[xf] == Father[yf])Father[yf] = Father[xf] - 1;
		Father[xf] = yf;
	}
	return true;
}

int main() {
	cin >> n;
	Father = new int[n+1]{0};

	a = new Circle*[n+1];
	int x, y, r;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x, &y, &r);
		a[i] = new Circle(x, y, r);
	}
	int cnt = n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (Union(i, j))cnt--;
		}
	}
	cout << cnt << endl;
}
/*
7
1 1 1
2 1 1
1 7 4
5 4 1
6 3 1
10 8 6
5 13 3


*/