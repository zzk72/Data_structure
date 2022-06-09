/*
7-3 算术表达式计算
分数 100
作者 谷方明
单位 吉林大学
任务: 计算算术表达式的值。

算术表达式按中缀给出，以=号结束，包括+,-,,/四种运算和(、)分隔符。运算数的范围是非负整数，没有正负符号，小于等于109 。

计算过程中,如果出现除数为0的情况,表达式的结果为”NaN” ; 如果中间结果超出32位有符号整型范围,仍按整型计算，不必特殊处理。
输入保证表达式正确。

输入格式:
一行，包括1个算术表达式。算术表达式的长度小于等于1000。

输出格式:
一行，算术表达式的值 。

输入样例:
在这里给出一组输入。例如：

(1+30)/3=
输出样例:
在这里给出相应的输出。例如：

10
代码长度限制16 KB
时间限制400 ms
内存限制64 MB
*/
#include<iostream>
#include<stack>

using namespace std;
int cmp(char a, char b) {//ÈôbµÄÓÅÏÈ¼¶>aÔò·µ»Ø1
	if (a == '(')return 1;
	if (a == '/' || a == '*')return 0;
	if (b != '/' && b != '*')return 0;
	else return 1;
}
int oper(int x, int y, char f,bool* Isreturn) {
	switch (f) {
	case '+':return x + y;
	case '-':return x - y;
	case '*':return x * y;
	case '/': {
		if (y == 0) { *Isreturn = true; return -1; }
			return x / y; }
	}
}

int* getnum(string& s) {//É¨Ãè
	int* ret = new int[s.size()];
	for (int i = 0; i < s.size(); ret[i] = -1, i++);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			int j = i; ret[i] = 0;
			while (j <= s.size() && s[j] <= '9' && s[j] >= '0') {
				ret[i] = ret[i] * 10 + s[j] - '0'; j++;
			}
			i = j - 1;
		}
	}
	return ret;
}
int main() {
	stack<char> fu;
	stack<int> num;
	bool Isreturn = false;
	string s;
	cin >> s;
	int* nums= getnum(s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') { 
			if (nums[i] == -1)continue; 
			num.push(nums[i]);
		}
		else if(s[i]!='=') {
			if (fu.empty() || s[i] == '(' || cmp(fu.top(), s[i]))fu.push(s[i]);
			else if (s[i] == ')') {
				while (fu.top() != '(') {
					int num1 = num.top(); num.pop();
					int num2 = num.top(); num.pop();
					char tmp = fu.top(); fu.pop();
					num.push(oper(num2, num1, tmp, &Isreturn));
					if (Isreturn) { cout << "NaN"; return 0; }
				}
				fu.pop();
			}
			else {
				
				while (!fu.empty() && !cmp(fu.top(), s[i])) {
					int num1 = num.top(); num.pop();
					int num2 = num.top(); num.pop();
					char tmp = fu.top(); fu.pop();
					num.push(oper(num2, num1, tmp, &Isreturn));
					if (Isreturn) { cout << "NaN"; return 0; }
				}
				fu.push(s[i]);
			}
		}
		else if(s[i]=='=') {
			while (!fu.empty()) {
				int num1 = num.top(); num.pop();
				int num2 = num.top(); num.pop();
				char tmp = fu.top(); fu.pop();
				num.push(oper(num2, num1, tmp, &Isreturn));
				if (Isreturn) { cout << "NaN"; return 0; }
			}
		}
	}
	cout << num.top();
	return 0;
}
/***
1+3*(5-6/2*3+(42/2+7))=
100
***/
