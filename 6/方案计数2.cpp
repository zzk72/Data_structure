#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define cit(x,y,z)  for(int x=y;x<=z;x++)
typedef long long ll;
inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}
using namespace std;
const int maxn = 1e4 + 5;
const int maxe = 1e5 + 5;
const int maxl = 103;

int head[maxn], in[maxn], out[maxn];
ll ve[maxn], vl[maxn], cost[maxn];

struct node {
    int to, w, next;
}edges[maxe];
int n, e, ecnt = 0;
inline void addedge(int x, int y, int w) {
    edges[ecnt] = { y,w,head[x] };
    head[x] = ecnt++;
}
#define MAXN 9999
#define DLEN 4
class BigNum {
private:
    int a[40];
    int len;
public:
    BigNum() { len = 1; memset(a, 0, sizeof(a)); }
    BigNum& operator=(const BigNum&);
    BigNum operator+(const BigNum&) const;
    void print();
};
BigNum& BigNum::operator=(const BigNum& n) {
    len = n.len;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < len; i++)
        a[i] = n.a[i];
    return *this;
}
BigNum BigNum::operator+(const BigNum& T) const {
    BigNum t(*this);
    int i, big;
    big = T.len > len ? T.len : len;
    for (i = 0; i < big; i++) {
        t.a[i] += T.a[i];
        if (t.a[i] > MAXN)
            t.a[i + 1]++, t.a[i] -= MAXN + 1;
    }
    t.len = (t.a[big] == 0) ? big : big + 1;
    return t;
}
void BigNum::print() {
    printf("%d", a[len]);
    for (int i = len - 2; i >= 0; i--)
        printf("%04d", a[i]);
    printf("\n");
}
BigNum dis[maxn];
bool topo() {
    queue<int>Q;
    Q.push(0); //入虚源点
    cit(j, 0, n) {
        if (Q.empty())return 0;
        int tmp = Q.front(); Q.pop();
        for (int i = head[tmp]; ~i; i = edges[i].next) {
            int near = edges[i].to; in[near]--;
            if (in[near] == 0)Q.push(near);

            if (ve[near] < ve[tmp] + edges[i].w) {
                ve[near] = ve[tmp] + edges[i].w;
                dis[near] = dis[tmp];
            }
            else if (ve[near] == ve[tmp] + edges[i].w)dis[near] = dis[near] + dis[tmp];
        }
    }
    return 1;
}

int main() {//关键方案数即关键路径数
    n = read(); e = read();
    cit(i, 0, n + 1) head[i] = -1;
    cit(i, 1, n)cost[i] = read();

    cit(i, 1, e) {
        int x = read(), y = read();
        addedge(x, y, cost[x]);
        in[y]++, out[x]++;
    }
    cit(i, 1, n) {
        if (out[i] == 0)addedge(i, n + 1, cost[i]);//虚汇
        if (in[i] == 0)addedge(0, i, 0), in[i]++;//虚源
    }
    if (!topo())printf("0");
    else {
        dis[n + 1].print();
    }
    return 0;
}
/*
6 6
1 3 4 1 2 3
1 2
1 3
2 4
2 5
3 4
4 6
*/

/*
8 9
1 2 3 4 8 6 7 8
1 3
1 4
4 7
2 7
3 7
3 6
3 5
5 8
7 8

7 6
1 1 1 2 2 2 1
1 2
1 3
2 4
2 5
3 6
3 7
*/