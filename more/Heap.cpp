#include<iostream>
using namespace std;

long long* heap;
long long* weight;
long long min1, min2, max, min3, tmp;
void down(long long* heap,int t, int len) {
    int y = t, tt;
    long long tmp;
    while ((2 * y <= len && heap[y] > heap[2 * y]) || (2 * y + 1 <= len && heap[y] > heap[2 * y + 1])) {
        tt = 2 * y;
        if (2 * y + 1 <= len && heap[2 * y + 1] < heap[2 * y])tt++;
        tmp = heap[y];
        heap[y] = heap[tt];
        heap[tt] = tmp;
        y = tt;
    }
}

void up(long long* heap, int x) {
    int y = x;
    long long tmp;
    while (y > 1 && heap[y] < heap[y / 2]) {
        tmp = heap[y];
        heap[y] = heap[y / 2];
        heap[y / 2] = tmp;
        y /= 2;
    }
}



int main() {
    int n;
    scanf("%d", &n);
    heap = new long long[n + 2]{0};
    weight = new long long[n + 2]{0};

    int len = n,fp=1;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &heap[i]);
    }
    if (n == 1) { printf("%lld\n", heap[0]); return 0; }

    for (int i = 1; i <= len; ++i) {
        up(heap,  i);
    }


    while (len > 1) {
        min1 = heap[1];
        swap(heap[1], heap[len]);
        --len;
        down(heap,1, len);
        min2 = heap[1];
        swap(heap[1], heap[len]);

        len--;
        down(heap, 1, len);
        min3 = min1 + min2;
        max += min3;
        weight[fp++] = min3;
        len++;
        heap[len] = min3;
        up(heap, len);
    }
    printf("%lld\n", max);
    for (int i = fp - 1; i >= 1; i--) {
        if (i > 1)printf("%lld ", weight[i]);
        else printf("%lld\n", weight[i]);
    }
    return 0;
}