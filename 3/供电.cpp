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