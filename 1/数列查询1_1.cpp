/*7-1 数列查询
分数 100
作者 谷方明
单位 吉林大学
已知数列的通项公式为:

     f(n) = f(n-1)*11/10，f[1]=10. 
通项从左向右计算，*和/分别表示整数乘法和除法。
现在，要多次查询数列项的值。

输入格式:
第1行，1个整数q，表示查询的次数， 1≤q≤10000.
第2至q+1行，每行1个整数i，表示要查询f(i)的值。

输出格式:
q行，每行1个整数，表示f(i)的值。查询的值都在32位整数范围内。

输入样例:
在这里给出一组输入。例如：

3
1
2
3
输出样例:
在这里给出相应的输出。例如：

10
11
12
代码长度限制 16 KB
时间限制 10 ms
内存限制 1 MB
*/
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
