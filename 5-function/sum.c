//
// Created by zyr on 2023/10/27.
//
#include <stdio.h>

int main(void) {
    int n = 0;
    int t = 0;
    int sum = 0;
    int ans=0;
    scanf("%d%d", &n, &t);
    for (int i = 1, temp = 1; i < n + 1; i++, temp *= 10) {
        sum += t * temp;
        ans+=sum;
    }
    printf("%d", ans);
    return 0;
}