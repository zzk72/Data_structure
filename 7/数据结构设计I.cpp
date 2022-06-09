#include<iostream>
#include<set>
#include<queue>

inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}
using namespace std;

const int maxn = 1e6 + 5;
bool IsNot = false;
queue<int>Q;
multiset<int>S;
void Insert() {
    int x = read(); x = (IsNot) ? -x : x;
    S.insert(x), Q.push(x);
}
void Del(){
    if (Q.empty())return;
    int x = Q.front(); Q.pop();
    S.erase(S.find(x));
}
void Mfind() {
    if (Q.empty())return;
    if (IsNot)printf("%d\n",- *S.begin());
    else printf("%d\n",*S.rbegin());
}


int main() {
    int n = read();
    char ch;
    for (int i = 1; i <= n;i++) {
        while ((ch = getchar()) != 'I'&& ch != 'D'&&ch != 'M' && ch != 'R');
        switch (ch) {
        case 'I':Insert(); break;
        case 'D':Del(); break;
        case 'M':Mfind(); break;
        case 'R':IsNot = !IsNot; break;
        }
    }
    return 0;
}
