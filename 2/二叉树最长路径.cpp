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