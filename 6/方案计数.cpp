#include<iostream>
#include<queue>
#define cit(x,y,z)  for(int x=y;x<=z;x++)
typedef long long ll;

using namespace std;
const int maxn = 1e4 + 5;
const int maxe = 1e5 + 5;
const int maxl = 103;

int n, e, ecnt = 0;
int head[maxn], in[maxn], out[maxn];
ll ve[maxn], vl[maxn], cost[maxn];
int bn[maxn][maxl] = { 1,1 };
struct node {
    int to, w, next;
}edges[maxe];

inline void addedge(int x, int y, int w) {
    edges[ecnt] = { y,w,head[x] };
    head[x] = ecnt++;
}

void add(int x, int y) {
    int v = 0, i = 1;
    for (; i <= max(bn[x][0], bn[y][0]) + 1; i++) {
        bn[x][i] = bn[y][i] + bn[x][i] + v;
       (bn[x][i] >= 10) ? v = 1 ,bn[x][i] -= 10: v=0;
    }
    i--;
    bn[x][0] = (bn[x][i] > 0) ? i : i - 1;
}

bool topo() {
    queue<int>Q;
    Q.push(0); 
    cit(j, 0, n) {
        if (Q.empty())return 0;
        int tmp = Q.front(); Q.pop();
        for (int i = head[tmp]; ~i; i = edges[i].next) {
            int near = edges[i].to; in[near]--;
            if (in[near] == 0)Q.push(near);
            if (ve[near] < ve[tmp] + edges[i].w) {
                ve[near] = ve[tmp] + edges[i].w;
                cit(k,0,maxl-1)bn[near][k] = 0;
                add(near, tmp);
            }
            else if (ve[near] == ve[tmp] + edges[i].w)add(near, tmp);
        }
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &e);
    cit(i, 0, n + 1) head[i] = -1;
    cit(i, 1, n)scanf("%d", &cost[i]);
    int x, y;
    cit(i, 1, e) {
        scanf("%d%d", &x, &y);
        addedge(x, y, cost[x]);
        in[y]++, out[x]++;
    }
    cit(i, 1, n) {
        if (out[i] == 0)addedge(i, n + 1, cost[i]);
        if (in[i] == 0)addedge(0, i, 0), in[i]++;//ÐéÔ´
    }
    if (!topo())printf("0");
    else {
        printf("%lld\n", ve[n + 1]);
        for (int i = bn[n + 1][0]; i >= 1; i--)printf("%d", bn[n + 1][i]);
    }
    return 0;
}