#pragma once
#include<iostream>
#include<queue>
#include<vector>
typedef long long  ll;
using namespace std;
int n;
priority_queue <ll, vector<ll>, greater<ll> >maxx;
priority_queue<ll >minn;

int main() {
	scanf("%d", &n);
	ll x,ans1=1,ans2=1;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		maxx.push(x);
		minn.push(x);
	}
	
	for (int i = 1; i < n; i++) {
		ans1 = maxx.top(); maxx.pop();
		ans2 = maxx.top(); maxx.pop();
		maxx.push(ans2 * ans1+1);
	//	printf("%d ", ans2 * ans1+1);
		ans1 = minn.top(); minn.pop();
		ans2 = minn.top(); minn.pop();
		minn.push(ans2 * ans1+1);
	//	printf("%d\n", ans2 * ans1+1);

	}
	printf("%lld", maxx.top() - minn.top());
}