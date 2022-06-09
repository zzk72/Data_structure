#include<iostream>
#include<queue>
#define cit(x,y,z)  for(int x=y;x<=z;x++)

inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}
using namespace std;
const int maxn = 1e4 + 5;
const int maxe = 2e4 + 5;

int n, e, ecnt = 0;
int head[maxn], in[maxn];
int val[maxn];
long long allval = 0;
struct node {
    int to, next;
}edges[maxe];

inline void addedge(int x, int y) {
    edges[ecnt].to = y;
    edges[ecnt].next = head[x];
    head[x] = ecnt++;
}

void topo() {
    queue<int>Q;
    cit(i, 1, n) {
        if (in[i] == 0) { Q.push(i); val[i] = 888; }
    }
    cit(j, 1, n) {
        if (Q.empty()) { cout << -1; return; }
        int tmp = Q.front(); Q.pop();
        for (int i = head[tmp]; ~i; i = edges[i].next) {
            int near = edges[i].to; in[near]--;
            if (in[near] == 0) {
                val[near] = val[tmp] + 1; Q.push(near);
            }
        }
    }

    cit(i, 1, n)allval += (long long)val[i];
    printf("%lld\n", allval);
}

int main() {
    n = read(); e = read();
    cit(i, 0, n)head[i] = -1;
    cit(i, 1, e) {
        int x = read(), y = read();
        addedge(y, x); in[x]++;
    }
    topo();
}
