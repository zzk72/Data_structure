
/*
7-2 整数拆分
分数 100
作者 谷方明
单位 吉林大学
整数拆分是一个古老又有趣的问题。请给出将正整数 n 拆分成 k 个正整数的所有不重复方案。例如，将 5 拆分成 2 个正整数的不重复方案，有如下2组：(1，4)和(2，3)。注意(1，4) 和(4，1)被视为同一方案。每种方案按递增序输出，所有方案按方案递增序输出。

输入格式:
1行，2个整数n和k，用空格分隔， 1≤k≤n≤50.

输出格式:
若干行，每行一个拆分方案，方案中的数用空格分隔。

最后一行，给出不同拆分方案的总数。

输入样例:
在这里给出一组输入。例如：

5 2
输出样例:
在这里给出相应的输出。例如：

1 4
2 3
2
代码长度限制
16 KB
时间限制
100 ms
内存限制
1 MB
*/
#include<iostream>
using namespace std;
int* number;
int cnt = 0;
int val, def;
void output(int* number) {
	for (int i = 1; i <= def; i++) {
		printf("%d", number[i]);
		if (i < def)printf(" ");
		else printf("\n");
	}
}
bool check(int* number, int len) {
	for (int i = 1; i < len; i++)
		if (number[i] > number[i + 1])return false;
	return true;
}

void dfs(int num, int k) {
	if (k == 1) {//目标状态
		number[def] = num; 
		output(number);cnt++;
		return;
	}
	else {
		for (int i = 1; i <= num - k+1&&i<=num>>1; i++) {//对每个可拓展状态
			number[def - k + 1] = i;//状态拓展
			if (!check(number, def - k+1))continue;//状态检查是否满足约束条件
			dfs(num - i, k - 1);
			//循环结束会自动恢复，因状态拓展可以直接覆盖数组值
		}
	}
}

int main() {
	cin >> val >> def;
	number = new int[def+1]{0};
	dfs(val, def);
	//cnt也许该改为long long
	cout << cnt << endl;
}
