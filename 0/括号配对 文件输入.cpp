/*
7-3 括号配对II
分数 100
作者 谷方明
单位 吉林大学
高级语言程序设计中的各种括号应该匹配，例如：“(” 与 “)”匹配、“[”与 “]” 匹配、“{”与 “}” 匹配等。
输入一字符文件，判断其中的括号是否匹配。假设括号没有优先级差别。

输入格式:
多行，字符个数不超过 65536。

输出格式:
一个单词，表示字符文件中括号匹配的结果，匹配输出“yes”，否则输出“no”.

输入样例:
在这里给出一组输入。例如：

( { } )
{a=(b*c)+free( ) }
输出样例:
在这里给出相应的输出。例如：

yes
代码长度限制
16 KB
时间限制
10 ms
内存限制
1 MB
*/
#include<iostream>
using namespace std;
char s[66000];
int main() {
	
	char ch;
	int ret = 1;
	int top=0;
	while (scanf("%c",&ch)==1) {
		if (ch == '[' || ch == '(' || ch == '{' ) {
			s[++top]=ch;
		}
		if (ch == ']' || ch == ')' || ch == '}') {
			if (top < 1) {
				ret = 0; break;
			}
			if (ch == s[top] + 1 || ch == s[top] + 2) {
				s[top--]; 
			}
			else {
				ret = 0;
				break;
			}
		}
		
	}
	if (ret==1&&top==0)cout << "yes";
	else cout << "no";
	return 0;
  
}
//正确，注意判空 
/*#include<stack>
#include<iostream>
using namespace std;
	stack<char> s;

int main() {
	char ch;
	int ret = 1;
	while (scanf("%c",&ch)==1) {
		if (ch == '[' || ch == '(' || ch == '{' ) {
			s.push(ch); 
		}
		if (ch == ']' || ch == ')' || ch == '}') {
		if(s.empty()){ret=0;break;}
			if (ch == s.top() +1 || ch == s.top() + 2) {
				s.pop(); 
			}
			else {
				ret = 0;
				break;
			}
		}

	}
	if (ret&&s.empty())cout << "yes";
	else cout << "no";
	return 0;
  
}*/
