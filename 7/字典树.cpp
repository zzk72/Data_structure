#include<iostream>

using namespace std;
const int maxn = 2e5 + 1;
struct node {
	int end;
	int son[26];
}trie[maxn];
int tp=1;
void insert(string s) {
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		int c = s[i] - 'a';
		if (trie[cur].son[c] == 0) {
			trie[cur].son[c] = ++tp;
		}
		trie[tp].end++;
		cur = trie[cur].son[c];
	}
}
int query(string s) {
	int cur = 0;
	for (int i = 0; i < s.size(); i++) {
		int c = s[i] - 'a';
		if (trie[cur].son[c] == 0)return 0;

		cur = trie[cur].son[c];
	}
	return trie[cur].end;
}

int main() {
	int m, n;
	cin >> m >> n;
	string s;
	for (int i = 1; i <= m; i++) {
		cin >> s;
		insert(s);
	}
	for (int i = 1; i <= n; i++) {
		cin >> s;
		cout<<query(s)<<'\n';
	}
	return 0;
}

