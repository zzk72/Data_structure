#include<iostream>
#include<queue>

using namespace std;
const int maxn = 1e5 + 5;

typedef struct node {
	int data;
	struct node* path;
	node(int d, struct node* p):data(d),path(p){}
}Node;
int x, y;
bool vis[maxn] = { 0 };
queue<Node*> Q;

void bfs(int s, int end) {
	Node* f = new Node{s,NULL}, * tmp;
	Q.push(f);
	while (!Q.empty()) {
		tmp = Q.front();
		if (tmp->data == y)return;
		Q.pop();
		int dat = tmp->data;
		if (dat + 1 <= y && !vis[dat + 1]) {
			Node* p = new Node{dat+1,tmp};
			Q.push(p); vis[dat + 1] = 1;
		}
		if (dat << 1 <= y + 1 && !vis[dat << 1]) {
			Node* p = new Node{dat<<1,tmp};
			 Q.push(p); vis[dat << 1] = 1;
		}
		if (dat - 1 >= 0 && !vis[dat - 1]) {
			Node* p = new Node{dat-1,tmp};
			Q.push(p); vis[dat - 1] = 1;
		}
	}
}

int main() {
	scanf("%d%d", &x, &y);
	bfs(x, y);
	int road[maxn];
	int rp = 0;
	for (Node* t = Q.front(); t; t = t->path)
		road[rp++] = t->data;
	printf("%d\n", rp - 1);
	for (rp -= 2; rp >= 0; rp--)
		if (rp != 0)printf("%d ", road[rp]);
		else printf("%d\n", road[rp]);

	return 0;
}