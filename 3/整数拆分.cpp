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
	if (k == 1) {//Ŀ��״̬
		number[def] = num; 
		output(number);cnt++;
		return;
	}
	else {
		for (int i = 1; i <= num - k+1&&i<=num>>1; i++) {//��ÿ������չ״̬
			number[def - k + 1] = i;//״̬��չ
			if (!check(number, def - k+1))continue;//״̬����Ƿ�����Լ������
			dfs(num - i, k - 1);
			//ѭ���������Զ��ָ�����״̬��չ����ֱ�Ӹ�������ֵ
		}
	}
}

int main() {
	cin >> val >> def;
	number = new int[def+1]{0};
	dfs(val, def);
	//cntҲ��ø�Ϊlong long
	cout << cnt << endl;
}