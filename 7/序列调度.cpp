#include<iostream>
#include<stack>
inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}
using namespace std;
const int maxn = 10005;
int n, ssize;

stack<int>s;
bool check() {
    bool ret = 1;
    int N = read();
    while (!s.empty())s.pop();
    int ex = 1, x;
    for (int i = 1; i <= N; i++) {
        x = read();
        if (!ret)continue;
        if (x == ex)s.push(ex++);
        while (x >= ex)s.push(ex++);//将小于等于的全部入栈
        if (s.size() > ssize)  ret = 0;
        if (s.top() == x)s.pop();
        else ret = 0;
    }
    return ret;
}

int main() {
    n = read(), ssize = read();
    for (int i = 0; i < n; i++) {
        if (check())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
/*
1 1 50
2 1 10
2 3 20
4 1 -30
4 4 5
*/