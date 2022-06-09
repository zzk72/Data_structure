/*
7-2 报数游戏
分数 100
作者 谷方明
单位 吉林大学
n个人围成一圈，从1开始依次编号，做报数游戏。 现指定从第1个人开始报数，报数到第m个人时，该人出圈，然后从其下一个人重新开始报数，仍是报数到第m个人出圈，如此重复下去，直到所有人都出圈。总人数不足m时将循环报数。请输出所有人出圈的顺序。

输入格式:
一行，两个整数n和m。n表示游戏的人数，m表示报数出圈的数字，1≤n≤50000，1≤m≤100.

输出格式:
一行，n个用空格分隔的整数，表示所有人出圈的顺序

输入样例:
在这里给出一组输入。例如：

5 2
输出样例:
在这里给出相应的输出。例如：

2 4 1 5 3
代码长度限制16 KB
时间限制400 ms
内存限制64 MB
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n=0,m=0, max = 0;
	scanf("%d%d", &n,&m);
	int *peo=new int [n+1];
	int* Isout = new int[n+1];

	for (int i = 1; i <= n; i++) {
		peo[i] = i; Isout[i] = 0;
	}

int p = 1,cnt=1;
	for (int i = 1; i <= n; i++) {
		cnt = 1;
		
		 while(cnt <= m) {
			 if (cnt == m&&!Isout[p]) {
				 Isout[p] = 1; 
				 if(i<n)printf("%d ", p);
				 else printf("%d\n", p);
				 break;
			}
			if (!Isout[p]) {
				cnt++;
			}
			p++;
			if (p > n)p = 1;
		}


	}
}
