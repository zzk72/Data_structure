/*
7-4 最喜爱的序列
分数 100
作者 谷方明
单位 吉林大学
 小唐这段时间在研究序列。拿来N个整数的序列，他给序列中的每个整数都赋予一个喜爱值。喜爱值也是整数，
 有正有负，越大表明越喜欢。他想知道，如何从序列中连续取最多m个数，他获得喜爱值最大。1≤N≤500000，1≤m≤N。
输入格式:
第一行是两个整数N,m。分别代表序列中数的个数以及能取的最多个数。

第二行用空格隔开的N个整数，第i个整数Li代表他对第i个数的喜爱值。│Li│≤1000

输出格式:
一行，三个数，表示获得最大喜爱值，及第一个取最大喜爱值的区间。

输入样例:
在这里给出一组输入。例如：

5 2
1 4 5 2 3
输出样例:
在这里给出相应的输出。例如：

9 2 3
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int>ret(nums.size() - k + 1);
	deque<int> slid; 
	for (int i = 0; i < nums.size(); i++) {
		while (!slid.empty() && nums[slid.back()] <= nums[i]) {
			slid.pop_back();
		}
		if (slid.empty() || nums[slid.back()] > nums[i]) {
			slid.push_back(i);
		}
		if (slid.front() <= i - k) slid.pop_front();
		if (i >= k - 1)ret[i - k + 1] = slid.front();
	}
	return ret;
}


int main() {
	int n = 0, m = 0;
	int max = INT32_MIN, fp = 0,lp=0;
	scanf("%d%d", &n, &m);
	vector<int> Live(n);
	int sum = 0;
	Live[0] = 0;
	for(int i=0;i<n;i++){
		scanf("%d", &Live[i]);
		if(i!=0)Live[i] += Live[i - 1];
	}

	vector<int> slidmax = maxSlidingWindow(Live, m);
	for (int i = 0; i <= n-m; i++) {
		/*if (i >= Live.size()) {
			cout << i << "Live"; exit(1);
		}
		if (i >= slidmax.size()) { cout << i << "slid"; exit(2); }*/
		//if ( slidmax[i]>=i) { cout << i << "slid i"<< slidmax[i]; exit(2); }

		if (i == 0)sum = Live[slidmax[i]];
		else sum= Live[slidmax[i]]-Live[i-1];
		if (max < sum) {
			max = sum;
			fp = i; lp = slidmax[i];
		}
	}
	int min = Live[slidmax[n-m]],mp=n-m;
	for (int i = n - m; i <=slidmax[n-m]; i++) {
		if (Live[i] < min) { min = Live[i]; mp = i+1; }
	}
	sum = Live[slidmax[n - m]] - min;
	if (max < sum) { max = sum; fp = mp; }
	printf("%d %d %d", max, fp+1, lp+1);
}

/*9 3
1 -3 4 9 2 -7 -2 11 8
19 7 9*/
