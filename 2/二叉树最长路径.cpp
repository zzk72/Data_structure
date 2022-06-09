/*
7-1 二叉树最长路径
分数 100
作者 谷方明
单位 吉林大学
给定一棵二叉树T，求T中的最长路径的长度，并输出此路径上各结点的值。若有多条最长路径，输出最右侧的那条。

输入格式:
第1行，1个整数n，表示二叉树有n个结点， 1≤n≤100000.

第2行，2n+1个整数，用空格分隔，表示T的扩展先根序列， -1表示空指针，结点用编号1到n表示。

输出格式:
第1行，1个整数length，length表示T中的最长路径的长度。

第2行，length+1个整数，用空格分隔，表示最右侧的最长路径。

输入样例:
在这里给出一组输入。例如：

5
1 2 -1 -1 3 4 -1 -1 5 -1 -1
输出样例:
在这里给出相应的输出。例如：

2
1 3 5
代码长度限制 16 KB
时间限制 100 ms
内存限制 5 MB
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;


Node* BT(void) {
    Node* root;
    int t;
    scanf("%d", &t);
    if (t == -1)return NULL;
    else {
        root = (Node*)malloc(sizeof(Node));
        root->data = t;
        root->left = BT();
        root->right = BT();
    }
    return root;
}

void LR(Node* root, int* road, int Len, int* longroad, int& Llength) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            road[Len++] = root->data;
            if (Len >= Llength) {
                int i;
                for (i = 0; i <= Len - 1; i++) {
                    longroad[i] = road[i];
                }
                Llength = Len;
            }
        }

        else {
            road[Len++] = root->data;
            LR(root->left, road, Len, longroad, Llength);
            LR(root->right, road, Len, longroad, Llength);
        }

    }
    return;
}


int main() {
    int n;
    scanf("%d", &n);
    Node* root;
    root = BT();
    int *road=new int[n+1]{ 0 };
    int Llength = 0;
    int* Lroad=new int[n+1]{ 0 };
    LR(root, road, 0, Lroad, Llength);
    printf("%d\n", Llength - 1);
    for (int i = 0; i <Llength; i++) {
        if (i < Llength - 1)printf("%d ", Lroad[i]);
        else printf("%d\n", Lroad[i]);
    }
    return 0;
}
