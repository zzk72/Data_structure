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