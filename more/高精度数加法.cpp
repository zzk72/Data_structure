#include<iostream>

using namespace std;

const int maxl = 121;
int n,last = 0;
int num1[maxl],num2[maxl];

inline int read(int *num) {
    int r = 0, x = 0; 
    memset(num, 0, sizeof(num));
    register char c = getchar();
    for (; c < '0' || c > '9'; c = getchar());
    for (; c >= '0' && c <= '9'; c = getchar()) num[r++] =  c - '0';
    return r - 1;
}
void add(int num[]) {
    register int mo = 0,sum=0;
    for (int i = 0; last>=0; i++,last--) {
        sum = num[last] + num1[i] + mo;
        num1[i] = (sum < 10) ? sum : sum - 10;
        mo = sum >= 10;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n;i++) {
       last=read(num2);add(num2);
    }
    int rear;
    for (rear = maxl - 1; !num1[rear]; rear--);
    for (; rear >= 0; rear--)putchar(num1[rear] + '0');
}
