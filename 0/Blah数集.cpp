/*
7-4 Blah数集
分数 100
作者 谷方明
单位 吉林大学
大数学家高斯小时候偶然发现一种有趣的自然数集合Blah。以a为基的集合Ba定义如下：

a是集合Ba的基，且a是Ba的第一个元素；
若x在集合Ba中，则2x+1和3x+1也都在Ba中；
没有其它元素在集合Ba中。
现在小高斯想知道如果将集合Ba中元素按照升序排列，第n个元素会是多少？
输入格式:
多行，每行包括两个数，集合的基a(1<=a<=50))以及所求元素序号n(1<=n<=1000000)

输出格式:
对于每个输入，输出集合Ba的第n个元素值

输入样例:
在这里给出一组输入。例如：

1 5
25 100000
输出样例:
在这里给出相应的输出。例如：

9
34503679
代码长度限制
16 KB
时间限制
1000 ms
内存限制
10 MB
*/
#include<iostream>
#include<stdlib.h>

#include<iomanip>
#define size1 1000010

using namespace std;

class myquene {
	long long* mquene;
	int count;

public:
	int mfront;
	int rear;
	
	myquene() {
		mquene = (long long*)malloc(sizeof(long long) * size1);
		rear = 0; mfront = 0; count = 0;
	}
	void set(){ rear = 0; mfront = 0; count = 0; }
	void push(int x);
	void delect(void);
	int size(void) { return count; }
	int front(void);

};


void myquene::push(int x) {
	
	mquene[rear] = x;
	rear = (rear + 1) % size1;
	count++;
}

void myquene::delect() {
	
	mfront = (mfront + 1) % size1;
	count--;
}

int myquene::front() {
	return mquene[mfront];
}


int main() {
	
	int basicnum, n;
	myquene th;
	myquene fo;
	while (~scanf_s("%d%d", &basicnum, &n)) {
		int cnt = 1;
		int tmp = basicnum;
		th.set(); fo.set();

		if (cnt == n)printf("%d\n", tmp);
		while (cnt < n) {
			th.push(tmp * 2 + 1);
			fo.push(tmp * 3 + 1);

			if (th.front() < fo.front()) {
				tmp = th.front(); th.delect();cnt++;
			}
			else {
				tmp = fo.front(); fo.delect(); cnt++;
			}
			if (cnt == n)printf("%d\n", tmp);
		}
	}
	return 0;

}
