#include<iostream>
#include<string.h>

using namespace std;
const int maxl = 1e6 + 5;
char s[maxl];

inline bool cmps(char a1[], int s2, int len) {
	for (int i = 0, j = s2; i < len; i++, j++) {
		if (a1[i] != a1[j])return false;
	}
	return true;
}
int main() {
	while (1) {
		fgets(s, maxl, stdin);
		char* find = strchr(s, '\n');
		if (find) *find = '\0';
		if (s[0] == '.' && strlen(s) == 1)break;
		int len = strlen(s);
		for (int i = 1; i <= len; i++) {
			if (len % i != 0)continue;
			int j = 0, flag = 1;
			for (; j < len; j += i) {
				if (cmps(s, j, i) == 0) { flag = 0; break; }
			}
			if (flag && j == len) {
				printf("%d\n", i); break;
			}
		}
	}
}