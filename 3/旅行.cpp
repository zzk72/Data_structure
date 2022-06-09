#include<iostream>
#include<queue>

using namespace std;
const int maxx = INT32_MAX;
int* dist;
typedef struct aaa {
	int Veradj;
	int cost;
	struct aaa* link;
}Linknode;

struct Headnode {
	int VerName;
	Linknode* link;
};


struct cmp {
	bool operator()(int x, int y) {
		return dist[x] > dist[y];
	}
};
void DIJKSTRA(struct Headnode Head[], int cu, int n) {
	priority_queue< int, vector<int>, cmp>Q;
	int* path = new int[n + 1], * visited = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		path[i] = 0; dist[i] = maxx; visited[i] = 0;
	}
	dist[cu] = 0; path[cu] = 0; Q.push(cu);
	while (!Q.empty()) {
		cu = Q.top(); Q.pop();
		visited[cu] = 1;
		for (Linknode* p = Head[cu].link; p; p = p->link) {
			int near = p->Veradj;
			if (dist[near] > dist[cu] + p->cost) {
				dist[near] = dist[cu] + p->cost;
				path[near] = path[cu] + 1;
				Q.push(near);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (Linknode* p = Head[i].link; p; p = p->link) {
			int near = p->Veradj;
			if (dist[near] == dist[i] + p->cost) {
				if (path[near] < path[i] + 1) {
					path[near] = path[i] + 1;
					Q.push(near);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dist[i];
		if (i != n)cout << " ";
	}cout << endl;
	for (int i = 1; i <= n; i++) {
		cout << path[i];
		if (i != n)cout << " ";
	}cout << endl;
}
int main() {
	int n, e, cu;
	cin >> n >> e >> cu;
	dist = new int[n + 1];
	struct Headnode* Head = new struct Headnode[n + 1];
	int v, u, weight;
	for (int i = 0; i <= n; i++) {
		Head[i].VerName = i;
		Head[i].link = NULL;
	}
	for (int i = 1; i <= e; i++) {
		scanf("%d%d%d", &v, &u, &weight);
		Linknode* tmp = new Linknode, * tp;
		tmp->cost = weight; tmp->Veradj = u; tmp->link = NULL;
		tp = Head[v].link;
		Head[v].link = tmp;
		tmp->link = tp;
		Linknode* tmp2 = new Linknode;
		tmp2->cost = weight;
		tmp2->Veradj = v;
		tmp2->link = NULL;
		tp = Head[u].link;
		Head[u].link = tmp2;
		tmp2->link = tp;
	}
	/*cout << endl << "____________" << endl;
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
		for (Linknode* p = Head[i].link; p; p = p->link) {
			cout <<p->Veradj<<"-"<< p->cost << " ";
		}cout << endl;
	}*/
	DIJKSTRA(Head, cu, n);
}

/*
5 6 2
1 2 1
2 3 3
2 4 4
2 5 1
3 5 1
1 4 1

5 5 1
1 2 2
1 4 5
2 3 4
3 5 7
4 5 8

*/