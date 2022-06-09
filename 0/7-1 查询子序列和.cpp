/*
7-1 查询子序列和
分数 100
作者 谷方明
单位 吉林大学
对N个整数的序列，查询子序列和∑
k=i
j
​
 A
k
​
  , (1≤i,j≤N).

输入格式:
第1行，两个整数：N和Q，表示整数的个数和查询的次数，1≤N≤100000，0≤Q≤100000.

第2行，N个用空格分开的整数 x ， │x│≤20000.

第3至Q+2行，每行两个整数i和j，表示所求子序列和的区间[i，j]，1≤i≤j≤N，保证所有区间都合法。

输出格式:
Q行,每行一个整数，表示相应子序列的和

输入样例:
5 3
1 2 3 4 5
1 5
2 4
3 5
输出样例:
在这里给出相应的输出。例如：

15
9
12
代码长度限制
16 KB
时间限制
200 ms
内存限制
2 MB
*/
#include<stdio.h>
int main(){
	int n,q,k,j,cnt=0;
	scanf("%d%d",&n,&q);
	int arr[n+1];arr[0]=0;
	int ret[q];
	for(int i=1;i<=n;i++){//令时间复杂度为O(n); 
		scanf("%d",&arr[i]);
		arr[i]+=arr[i-1];
	}
	
	for(int i=0;i<q;i++){
		int sum=0;
		 scanf("%d%d",&k,&j);
		ret[i]=arr[j]-arr[k-1];
	}
	for(int i=0;i<q;i++){
		printf("%d",ret[i]);
		if(i<q-1)printf("\n");
	}
	return 0;
}
