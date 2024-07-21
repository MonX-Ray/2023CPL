//
// Created by zyr on 2023/11/15.
//
#include <stdio.h>

#define N 10005
int num[N] = {0};

int find(int x, int i);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i < n+1; ++i) {
        scanf("%d",&num[i]);
    }
    for (int i = 1; i < n + 1; ++i) {
        printf("%d ", find(num[i],i));
    }
    return 0;
}

int find(int x, int i) {
    if (x == i) {
        return x;
    } else {
        return find(num[x], x);
    }
}

