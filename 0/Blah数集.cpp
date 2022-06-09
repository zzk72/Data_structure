/*
7-4 Blah����
���� 100
���� �ȷ���
��λ ���ִ�ѧ
����ѧ�Ҹ�˹Сʱ��żȻ����һ����Ȥ����Ȼ������Blah����aΪ���ļ���Ba�������£�

a�Ǽ���Ba�Ļ�����a��Ba�ĵ�һ��Ԫ�أ�
��x�ڼ���Ba�У���2x+1��3x+1Ҳ����Ba�У�
û������Ԫ���ڼ���Ba�С�
����С��˹��֪�����������Ba��Ԫ�ذ����������У���n��Ԫ�ػ��Ƕ��٣�
�����ʽ:
���У�ÿ�а��������������ϵĻ�a(1<=a<=50))�Լ�����Ԫ�����n(1<=n<=1000000)

�����ʽ:
����ÿ�����룬�������Ba�ĵ�n��Ԫ��ֵ

��������:
���������һ�����롣���磺

1 5
25 100000
�������:
�����������Ӧ����������磺

9
34503679
���볤������
16 KB
ʱ������
1000 ms
�ڴ�����
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
