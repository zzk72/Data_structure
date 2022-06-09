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
