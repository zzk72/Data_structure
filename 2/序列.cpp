/*
7-4 序列乘积
分数 100
作者 谷方明
单位 吉林大学
两个递增序列A和B,长度都是n。令 Ai 和 Bj 做乘积，1≤i,j≤n.请输出n*n个乘积中从小到大的前n个。

输入格式:
第1行，1个整数n，表示序列的长度， 1≤n≤100000.

第2行，n个整数Ai，用空格分隔，表示序列A，1≤Ai≤40000，1≤i≤n.

第3行，n个整数Bi，用空格分隔，表示序列B，1≤Bi≤40000，1≤i≤n.

输出格式:
1行，n个整数，用空格分隔，表示序列乘积中的从小到大前n个。

输入样例:
在这里给出一组输入。例如：

5
1 3 5 7 9 
2 4 6 8 10
输出样例:
在这里给出相应的输出。例如：

2 4 6 6 8
代码长度限制
16 KB
时间限制
100 ms
内存限制
5 MB
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef struct node {
public:
    int x;
    int y;
    int data;
}node;
struct cmp {
    bool operator()(node& a, node& b) {
        return a.data > b.data;
    }
};
int main() {
    priority_queue<node, vector<node>, cmp> PQ;
    int n;
    scanf("%d", &n);
    int* a = new int[n + 1];
    int* b = new int[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        node tmp;
        tmp.x = 0; tmp.y = i; tmp.data = a[0] * b[i];
        PQ.push(tmp);
    }
    for (int i = 0; i < n; i++) {
        node tmp = PQ.top();
        PQ.pop();
        if (i < n - 1)printf("%d ", tmp.data);
        else printf("%d\n", tmp.data);
            node tmp2;
            tmp2.x = tmp.x + 1; tmp2.y = tmp.y; tmp2.data = a[tmp2.x] * b[tmp2.y];//½«ÆäµÝÔöÒ»´ÎÔÙÈë¶Ó
            PQ.push(tmp2);
    }

    return 0;
}
/*
5
1 3 5 7 9
2 4 6 8 10

*/
