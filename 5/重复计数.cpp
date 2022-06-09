#include<iostream>
#include<set>
inline int read() {
	int x = 0; int w = 1; register char c = getchar();
	for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
	if (c == '-') w = -1, c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	return x * w;
}
using namespace std;
const int maxn = 50005;
int dat[maxn],cnt[maxn];

int main() {
	multiset<int>ms;
	int n = 0,cnt=1,x;
	n = read();
	for (int i = 1; i <= n; i++) {
		x = read();	
		if (ms.count(x) == 0)dat[cnt++] =x;
		ms.insert(x);
	}
	for (int i = 1; i < cnt; i++) {
		printf("%d %d", dat[i], (int)ms.count(dat[i]));
		if (i != cnt)printf("\n");
	}
}

//map<int ,int>Hash;
//queue<int>Q;
//int main() {
//	int n = read(),x;
//	for (int i = 0; i < n; i++) {
//		x = read();
//		if (Hash.count(x) == 0) {
//			Hash.insert(make_pair( x,1));
//			Q.push(x);
//		}
//		else {
//			Hash[x]++;
//		}
//	}
//	while(!Q.empty()) {
//		printf("%d %d", Q.front(), Hash[Q.front()]);
//		Q.pop();
//		if (!Q.empty())printf("\n");
//	}
//	return 0;
//}
//

/*
12
8 2 8 2 2 11 1 1 8 1 13 13
*/
