#include<iostream>

inline int read() {
	int x = 0; int w = 1; register char c = getchar();
	for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
	if (c == '-') w = -1, c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	return x * w;
}
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn];
long long cnt = 0;
void Merge(int* a, int* x, int t, int m, int n) {//t��mΪ��һ�����е�ͷβָ�룬nΪ�ڶ�������β
	int f1 = t, f2 = m + 1, xp = t;
	while (f1 <= m && f2 <= n) {
		if (a[f1] <= a[f2]) {
			x[xp++] = a[f1++];
		}
		else {
			x[xp++] = a[f2++];
			cnt +=(long long) m - f1+1;//����ǰһ���ļ�ʣ���Ԫ����
		}
	}
	while (f1 <= m)x[xp++] = a[f1++];
	while (f2 <= n)x[xp++] = a[f2++];
}
void MPass(int* a, int len, int L, int* x) {//�����г���С�ڵ���L�������ϲ�Ϊ2*L�ܳ�len��
	int i = 0;
	for (; i + L * 2 - 1 <= len; i += L * 2) {//ÿ�ν�L*2���ڵ����������ϲ�
		Merge(a, x, i, i + L - 1, i + 2 * L - 1);
	}
	if (i + L - 1 < len) {
		Merge(a, x, i, i + L - 1, len);
	}
	else {
		for (int j = i; j <= len; j++)x[j] = a[j];
	}
}
//�鲢����
void MSort(int* a, const int len) {
	int* x = new int[len + 1];
	for (int i = 1; i <= len; i *= 2) {
		MPass(a, len, i, x);
		i *= 2;
		MPass(x, len, i, a);
	}
	delete[] x;
}
int main() {
	int n = read();
	for (int i = 0; i < n; i++) 
		a[i] = read();
	MSort(a, n-1);
	printf("%lld", cnt);
	return 0;
}