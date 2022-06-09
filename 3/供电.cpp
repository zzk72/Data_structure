/*
7-4 供电
分数 100
作者 谷方明
单位 吉林大学
要给N个地区供电。每个地区或者建一个供电站，或者修一条线道连接到其它有电的地区。试确定给N个地区都供上电的最小费用。

输入格式:
第1行，两个个整数 N 和 M , 用空格分隔，分别表示地区数和修线路的方案数，1≤N≤10000，0≤M≤50000。

第2行，包含N个用空格分隔的整数P[i]，表示在第i个地区建一个供电站的代价，1 ≤P[i]≤ 100,000，1≤i≤N 。

接下来M行，每行3个整数a、b和c，用空格分隔，表示在地区a和b之间修一条线路的代价为c，1 ≤ c ≤ 100,000，1≤a,b≤N 。

输出格式:
一行，包含一个整数， 表示所求最小代价。

输入样例:
在这里给出一组输入。例如：

4 6
5 4 4 3
1 2 2
1 3 2
1 4 2
2 3 3
2 4 3
3 4 4
输出样例:
在这里给出相应的输出。例如：

9
代码长度限制
16 KB
时间限制
500 ms
内存限制
10 MB
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int next;
    int before;
}node;

int main() {
    int T, n, m;
    scanf("%d", &T);
    int i, j, cnt, g;
    char s;
    for (g = 1; g <= T; g++) {
        scanf("%d%d", &n, &m);
        node* word = (node*)malloc(sizeof(node) * (n + 1));
        for (cnt = 1; cnt <= n; cnt++) {
            word[cnt].next = cnt + 1;
            word[cnt].before = cnt - 1;
        }
        word[n].next = 1;
        word[1].before = n;
        for (cnt = 1; cnt <= m; cnt++) {
            scanf("%c %d %d", &s, &i, &j);
            scanf("%c %d %d", &s, &i, &j);
            if (s == 'A') {
                word[word[i].before].next = word[i].next;
                word[word[i].next].before = word[i].before;
                word[i].before = word[j].before;
                word[i].next = j;
                word[word[j].before].next = i;
                word[j].before = i;
                //printf("A");
            }
            if (s == 'B') {
                word[word[i].before].next = word[i].next;
                word[word[i].next].before = word[i].before;
                word[i].before = j;
                word[i].next = word[j].next;
                word[word[j].next].before = i;
                word[j].next = i;
                //printf("B");

            }
            if (s == 'Q') {
                if (i == 0) { printf("%d\n", word[j].before); }
                if (i == 1) { printf("%d\n", word[j].next); }
                // printf("Q");
            }
        }
        free(word);
    }
    return 0;
}
