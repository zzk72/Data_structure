/*
7-3 �������II
���� 100
���� �ȷ���
��λ ���ִ�ѧ
�߼����Գ�������еĸ�������Ӧ��ƥ�䣬���磺��(�� �� ��)��ƥ�䡢��[���� ��]�� ƥ�䡢��{���� ��}�� ƥ��ȡ�
����һ�ַ��ļ����ж����е������Ƿ�ƥ�䡣��������û�����ȼ����

�����ʽ:
���У��ַ����������� 65536��

�����ʽ:
һ�����ʣ���ʾ�ַ��ļ�������ƥ��Ľ����ƥ�������yes�������������no��.

��������:
���������һ�����롣���磺

( { } )
{a=(b*c)+free( ) }
�������:
�����������Ӧ����������磺

yes
���볤������
16 KB
ʱ������
10 ms
�ڴ�����
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
//��ȷ��ע���п� 
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
