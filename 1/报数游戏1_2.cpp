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