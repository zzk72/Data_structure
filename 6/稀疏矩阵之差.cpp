#include<iostream>
using namespace std;
const int maxn = 50005;
int r1 = 0, c1 = 0, n1 = 0;
int r2 = 0, c2 = 0, n2 = 0;

typedef struct node {
	int r, c, v;
}Node;
Node mt1[maxn], mt2[maxn], dif[maxn];
int diff(Node Mat1[], Node Mat2[], Node diff[], int n1, int n2) {
	int p1 = 0, p2 = 0, pn = 0;
	while (p1 != n1 && p2 != n2) {
		if (Mat1[p1].r == Mat2[p2].r && Mat1[p1].c == Mat2[p2].c) {
			diff[pn] = mt1[p1];
			diff[pn].v = mt1[p1].v - mt2[p2].v;
			p1++; p2++;
			if (0!=diff[pn].v)pn++;
		}
		else if (Mat1[p1].r < Mat2[p2].r || (Mat1[p1].r == Mat2[p2].r && Mat1[p1].c < Mat2[p2].c)) {
			dif[pn] = mt1[p1];
			p1++,pn++;
		}
		else{
			dif[pn] = mt2[p2];
			dif[pn].v *= -1;
			p2++, pn++;
		}
	}
	for (; p1 != n1;p1++, pn++) 
		diff[pn] = mt1[p1];
	
	for (; p2 != n2; p2++, pn++) 
		dif[pn] = mt2[p2];
	
	return pn;
}

int main() {
	scanf("%d%d%d", &r1, &c1, &n1);

	for (int i = 0; i < n1; i++) {
		scanf("%d%d%d", &mt1[i].r, &mt1[i].c, &mt1[i].v);
	}
	scanf("%d%d%d", &r2, &c2, &n2);

	for (int i = 0; i < n2; i++) {
		scanf("%d%d%d", &mt2[i].r, &mt2[i].c, &mt2[i].v);
	}
	if (r1 != r2 || c1 != c2) {
		printf("Illegal!"); return 0;
	}
	int nn = diff(mt1, mt2, dif, n1, n2);
	printf("%d %d %d\n", r1, c1, nn);
	for (int i = 0; i < nn; i++) {
		printf("%d %d %d\n", dif[i].r, dif[i].c, dif[i].v);
	}
}