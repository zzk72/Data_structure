/*
7-2 斐波那契数列
分数 100
作者 谷方明
单位 吉林大学
斐波那契数列指的是这样一个数列：1、1、2、3、5、8、13、21、34、……在数学上，斐波那契数列以如下被以递推的方法定义：F(0)=0，F(1)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N）。斐波那契数列，又称为“兔子数列”因数学家莱昂纳多·斐波那契（Leonardo Fibonacci）以兔子繁殖为例子而引入。请计算斐波那契数列第n项。

输入格式:
1个正整数n, n<=10000。

输出格式:
两行。第一行1个整数，为第n项的位数；第二行1个数，为第n项的值。

输入样例:
在这里给出一组输入。例如：

10
输出样例:
在这里给出相应的输出。例如：

2
55
代码长度限制
16 KB
时间限制
100 ms
内存限制
1 MB*/
#include <iostream>
using namespace std;
int arr[3][3001]={{0}};
int main(){
	int i,j,ex,tmp,n; 
    
    arr[1][1]=1;
    arr[2][1]=1;
    
	cin>>n;
	for(i=3;i<=n;i++){
		ex=0;tmp=0;
		for(j=1;j<=3000;j++){
			tmp=arr[1][j]+arr[2][j]+ex;
			arr[1][j]=arr[2][j];
			arr[2][j]=tmp%10;
			ex=tmp/10;
		}
	}

	for(i=3000;arr[2][i]==0;i--);
	ex=arr[2][i];
	int len=0;
	while(ex>0){
		ex/=10;
		len++;
	}
	len+=i-1;
	cout<<len<<endl;
	for(i;i>=1;i--)
		cout<<arr[2][i];
	
    return 0;
}

