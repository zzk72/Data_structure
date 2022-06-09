#include<iostream>

using namespace std;
const int maxn = 10005;
 struct node {
	int t,f,n;
}f[maxn];

int main() {
	int siz = 0, opnum = 0,n = 0;
	scanf("%d",&n);
	char oper[10];
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &siz, &opnum);
		for (int i = 1; i <= siz; i++) 
			f[i] = { i,i-1,i + 1 };

		f[1].f= siz,f[siz].n = 1;
		for (int i = 0; i < opnum; i++) {
			scanf("%s %d %d", oper, &x, &y);
			switch (oper[0]) {
			case 'A': {
				f[f[x].f].n = f[x].n;
				f[f[x].n].f = f[x].f;

				f[x].f = f[y].f;
				f[x].n = y;

				f[f[y].f].n = x;
				f[y].f = x;
				break;
			}
			case 'B': {
				f[f[x].f].n = f[x].n;
				f[f[x].n].f = f[x].f;

				f[x].f = y;
				f[x].n = f[y].n;

				f[f[y].n].f = x;
				f[y].n = x;
				break;
			}
			case'Q': {
				if (x == 0)printf("%d\n", f[f[y].f].t);
				else   printf("%d\n", f[f[y].n].t);
				break;
			}
			}
		}
	}
}
/*
1
9999 4
B 1 2
A 3 9999
Q 1 1
Q 0 3


*/