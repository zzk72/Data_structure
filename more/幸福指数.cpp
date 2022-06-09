#include<iostream>
#include<stack>
using namespace std;

void LeastArea(int* head, int* rear, int* Happy,int n) {
	stack<int> s;
	int beyond = 1;
	s.push(1);
	for (int i = 1;i <= n; i++) {//一共进行n次压栈操作
		int tmp=0;
		if (Happy[i] >= Happy[s.top()]) { 
			head[i] = i;
			s.push(i);
		}
		else {
			while (!s.empty() && Happy[i] < Happy[s.top()]) {
				 tmp = s.top(); s.pop();
				rear[tmp] = i - 1;
			}
			head[i] = head[tmp];
			s.push(i);
		}
	}
	while (!s.empty()) {
		int tmp = s.top(); s.pop();
		rear[tmp] = n;
	}
}

int main() {
	int daynum = 0;
	cin >> daynum;
	int* Happy = new int[daynum+1];
	int *frontsum= new int[daynum + 1];
	int* head = new int[daynum + 1];
	head[0] = 0;
	int* rear = new int[daynum + 1];
	int left = 0, right = 0;
	Happy[0] = 0;
	frontsum[0] = 0;
	for (int i = 1; i <= daynum; i++) {
		scanf("%d", &Happy[i]);
		frontsum[i] = Happy[i]+frontsum[i-1];
	}
	LeastArea(head, rear, Happy, daynum);
	for (int i = 1; i <= daynum; i++) {
		//printf("frontsum-%d\n", frontsum[i]);
		//printf("Happy-%d  head-%d rear-%d\n", Happy[i], head[i], rear[i]);
	}

	long long max=  Happy[1]*Happy[1];
	long long sum = 0;
	for (int i = 1; i <= daynum; i++) {
		sum = (frontsum[rear[i]] - frontsum[head[i]-1]) * Happy[i];
		if (sum > max) {
			max = sum; left = head[i]; right = rear[i];
		}
	}
	cout << max<<endl;
	cout << left << " " << right;

}
/*
7
6 4 5 1 4 5 6
*/