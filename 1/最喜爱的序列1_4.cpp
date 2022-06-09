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