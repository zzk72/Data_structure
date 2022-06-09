/*
7-3 旅行 I
分数 100
作者 谷方明
单位 吉林大学
五一要到了,来一场说走就走的旅行吧。当然，要关注旅行费用。由于从事计算机专业，你很容易就收集到一些城市之间的交通方式及相关费用。将所有城市编号为1到n，你出发的城市编号是s。你想知道，到其它城市的最小费用分别是多少。如果可能，你想途中多旅行一些城市，在最小费用情况下，到各个城市的途中最多能经过多少城市。

输入格式:
第1行，3个整数n、m、s，用空格分隔，分别表示城市数、交通方式总数、出发城市编号， 1≤s≤n≤10000, 1≤m≤100000 。

第2到m+1行，每行三个整数u、v和w，用空格分隔，表示城市u和城市v的一种双向交通方式费用为w ， 1≤w≤10000。

输出格式:
第1行，若干个整数Pi，用空格分隔，Pi表示s能到达的城市i的最小费用，1≤i≤n，按城市号递增顺序。

第2行，若干个整数Ci，Ci表示在最小费用情况下，s到城市i的最多经过的城市数，1≤i≤n，按城市号递增顺序。

输入样例:
在这里给出一组输入。例如：

5 5 1
1 2 2
1 4 5
2 3 4
3 5 7
4 5 8
输出样例:
在这里给出相应的输出。例如：

0 2 6 5 13
0 1 2 1 3
代码长度限制
16 KB
时间限制
1000 ms
内存限制
10 MB
*/
#include<iostream>
#include<queue>

using namespace std;
const int maxx = INT32_MAX;
int* dist;
typedef struct node {
	int Veradj;
	int cost;
	struct node* link;
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
