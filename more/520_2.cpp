#include<iostream>

using namespace std;
const int maxn = 410;
int cnt[10]={0};
int cnt2[10] = { 0 };
inline bool read(int cnt[]) {
    int x = 0; int w = 1; register char c = getchar();
    bool flag=false;
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) { 
    if (c - '0')flag = true;if(flag)cnt[c - '0']++; 
    }
    return flag;
}
inline void inti() {
    for (int i = 0; i < 10; i++)cnt2[i] = 0;
}
inline bool cmp() {
    for (int i = 0; i < 10; i++)
        if (cnt[i] != cnt2[i])return false;
    return true;
}
int main() {
    read(cnt); read(cnt);
  
    while (1) {
        inti();
        bool b1 = read(cnt2);
        bool b2 = read(cnt2);
        if (!b1 && !b2)break;
        if (cmp())printf("Yes\n");
        else printf("No\n");
    }

    return 0;


}