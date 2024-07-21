//
// Created by zyr on 2023/10/14.
//
#include <stdio.h>

int num[500007];

int main(void) {
    int T;
    int n;
    int max;

    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &num[j]);
        }
        max = num[0];
        for (int j = 0; j < n - 1; ++j) {
            if (num[j] > max) {
                max = num[j + 1];
            }
        }
        printf("%d\n", max);
        if (num[n - 1] >= max) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}