#include<iostream>
#include<vector>
#include<algorithm>

inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}
using namespace std;
const int maxn = 1e5 + 5;
const int maxe = 2e5 + 5;

int n, e;
int fa[maxn];
typedef struct node {
    int u, w, v;
    node(int t1, int t2, int t3) :u(t1), w(t2), v(t3) {}
}edge;
vector<edge>Edges;

inline int Find(int x) {
    if (fa[x] <= 0)return x;
    return fa[x] = Find(fa[x]);
}
inline void Union(int x, int y) {
    int xf = Find(x), yf = Find(y);
    if (xf == yf)return;
    if (fa[xf] < fa[yf])fa[yf] = xf;
    else {
        if (fa[xf] == fa[yf])fa[yf]--;
        fa[xf] = yf;
    }
}

bool cmp(const edge& x, const edge& y) {
    return x.w < y.w;
}
void Kruskal() {
    sort(Edges.begin(), Edges.end(), cmp);
    for (int i = 0; i < e; i++) {
        Union(Edges[i].u, Edges[i].v);
        if (Find(1) == Find(n)) {
            printf("%d", Edges[i].w); break;
        }
    }
}

int main() {
    n = read(); e = read();

    for (int i = 1; i <= e; i++) {
        int x = read(), y = read(), w = read();
        Edges.push_back({ x,w,y });
    }
    if (n == 1) { putchar('0'); return 0; }
    Kruskal();
    return 0;
}
/*
6 6
1 2 4
2 3 4
3 5 7
1 4 2
4 6 5
5 6 6

*/