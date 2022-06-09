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
            tmp2.x = tmp.x + 1; tmp2.y = tmp.y; tmp2.data = a[tmp2.x] * b[tmp2.y];//将其递增一次再入队
            PQ.push(tmp2);
    }

    return 0;
}
/*
5
1 3 5 7 9
2 4 6 8 10

*/