#include<iostream>
#include<stack>

using namespace std;
int cmp(char a, char b) {//若b的优先级>a则返回1
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

int* getnum(string& s) {//扫描
	int* ret = new int[s.size()];
	for (int i = 0; i < s.size(); ret[i] = -1, i++);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			int j = i; ret[i] = 0;
			while (j <= s.size() && s[j] <= '9' && s[j] >= '0') {
				ret[i] = ret[i] * 10 + s[j] - '0'; j++;
			}
		//	cout << ret[i] << " "; 
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