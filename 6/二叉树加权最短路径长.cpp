#include<iostream>

using namespace std;

typedef struct node {
	int key;
	struct node* ls, * rs;
}Node;
const int maxn = 20005;
int n;
int pre[maxn], in[maxn], w[maxn];
bool vis[maxn];
Node* build(int s, int e, int pi) {
	if (s > e)return NULL;
	Node* ret = new Node;
	ret->key = pre[pi];
	int r;
	for (r = s; r <= e && in[r] != pre[pi]; r++);
	ret->ls = build(s, r - 1, pi + 1);
	ret->rs = build(r + 1, e, pi + 1 + r - s);
	return ret;
}


void dfs(Node* root, int rw) {
	if (!root)return;
	int k = root->key;
	w[k] += rw;
	if (root->ls)dfs(root->ls, w[k]);
	if (root->rs)dfs(root->rs, w[k]);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &pre[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	Node* r = build(0, n - 1, 0);
	dfs(r, 0);
	for (int i = 1; i <= n; i++) {
		printf("%d", w[i]);
		if (i != n)printf(" ");
	}

}