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
void Merge(int* a, int* x, int t, int m, int n) {//t、m为第一个序列的头尾指针，n为第二个序列尾
	int f1 = t, f2 = m + 1, xp = t;
	while (f1 <= m && f2 <= n) {
		if (a[f1] <= a[f2]) {
			x[xp++] = a[f1++];
		}
		else {
			x[xp++] = a[f2++];
			cnt +=(long long) m - f1+1;//加上前一个文件剩余的元素数
		}
	}
	while (f1 <= m)x[xp++] = a[f1++];
	while (f2 <= n)x[xp++] = a[f2++];
}
void MPass(int* a, int len, int L, int* x) {//将所有长度小于等于L的两两合并为2*L总长len的
	int i = 0;
	for (; i + L * 2 - 1 <= len; i += L * 2) {//每次将L*2长内的序列两两合并
		Merge(a, x, i, i + L - 1, i + 2 * L - 1);
	}
	if (i + L - 1 < len) {
		Merge(a, x, i, i + L - 1, len);
	}
	else {
		for (int j = i; j <= len; j++)x[j] = a[j];
	}
}
//归并排序
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