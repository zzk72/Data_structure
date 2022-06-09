/*
7-3 纸带切割
分数 100
作者 谷方明
单位 吉林大学
有一条细长的纸带,长度为 L 个单位，宽度为一个单位。现在要将纸带切割成 n 段。每次切割把当前纸带分成两段，切割位置都在整数单位上，切割代价是当前切割纸带的总长度。每次切割都选择未达最终要求的最长纸带切割，若这样的纸带有多条，则任选一条切割。如何切割，才能完成任务，并且总代价最小。

输入格式:
第1行，1个整数n，表示切割成的段数， 1≤n≤100000.

第2行，n个整数Li，用空格分隔，表示要切割成的各段的长度，1≤Li≤200000000，1≤i≤n.

输出格式:
第1行，1个整数，表示最小的总代价。

第2行，若干个整数，用空格分隔，表示总代价最小时每次切割的代价。

输入样例:
在这里给出一组输入。例如：

5
5 6 7 2 4
输出样例:
在这里给出相应的输出。例如：

54
24 13 11 6
代码长度限制
16 KB
时间限制
100 ms
内存限制
5 MB
*/


#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 6;
typedef long long ll;

ll n, t, ans[maxn];
inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') { f = -1; }
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1)/* x*10 */ + (ch ^ 48)/*即x-48 */;
		ch = getchar();
	}
	return f * x;
}//快读数字 可以用cin或者scanf
int main() {
	priority_queue<ll, vector<ll>, greater<ll> > q;//优先升序队列
	n = read();
	for (int i = 1; i <= n; i++) {
		t = read();//关于为什么不开一个数组的问题，因为1e6感觉会mle
		q.push(t);
	}

	for (int i = 1; i < n; i++) {
		int m = q.top(); q.pop();
		int n = q.top(); q.pop();//这两段 每次都取最小值
		q.push(m + n);
		ans[i] = m + n;//根 可以参考上面的图 也就是母带的长度
	}

	long long res = 0;
	for (int i = 1; i < n; i++) {
		res += ans[i];
	}

	cout << res << endl;
	for (int i = n - 1; i >= 1; --i) {
		cout << ans[i];
		if (i != 1) {
			cout << " ";
		}
	}
}
