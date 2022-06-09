#include<iostream>
inline int read() {
    int x = 0; int w = 1; register char c = getchar();
    for (; c ^ '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') w = -1, c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    return x * w;
}
using namespace std;
const int maxn = 210;

int main() {
    /*int n = read();
    printf("%d! 520!", n);*/
   /* int n = read(),m=read(),me=read();
    int t = m - n * me;
    if (t == 0)printf("zheng hao mei ren %d!",me);
    else if (t < 0)printf("hai cha %d!",-t);
    else printf("hai sheng %d!",t);*/
    int p[maxn][3] = {0};
    int  sex=read();
    int lowy=read(), upy=read(), lowh=read(), uph=read();
    int n = read();
    int s, y, h,cnt=0;
    for (int i = 0; i < n; i++) {
        s = read(); y = read(); h = read();
        if (s == sex)continue;
        if (y <= upy && y >= lowy && h <= uph && h >= lowh) {
            p[cnt][0] = s, p[cnt][1] = y, p[cnt][2] = h; cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        printf("%d %d %d", p[i][0], p[i][1], p[i][2]);
        if (i < cnt - 1)printf("\n");
    }


	return 0;


}