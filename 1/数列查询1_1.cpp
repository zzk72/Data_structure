#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct aaa {
	int data;
	int p;
}shunx;

struct cmp {
	bool operator()(shunx& x, shunx& y) {
		return x.data < y.data;
	}
};
int main() {
	int n,max=0;
	scanf("%d", &n);
	shunx* s = new shunx[n];
	int* t = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i].data);

		s[i].p = i;
		t[i] = s[i].data;
	}
	sort<shunx*>(s, s + n, cmp());
	max = s[n - 1].data;
	int f0 = 10, tmp = 0;
	for (int i = 1, j = 0; i <= max; i++) {
		if(i!=1)f0 = f0 * 11 / 10;
		while (s[j].data == i) { t[s[j].p] = f0; j++; }

	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", t[i]);
	}
}