//
// Created by zyr on 2023/11/18.
//
#include <stdio.h>

#define N 10005

int main(void) {
    int n = 0;
    int L = 0;
    int wine[N][2] = {0};
    int used[N] = {0};
    int volume = 0;
    int pay = 0;
    scanf("%d%d", &n, &L);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &wine[i][0]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &wine[i][1]);
    }
    while (volume < L) {
        int max = 0;
        int add = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i] == 0) {
                max = wine[i][0];
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (wine[i][0] > max && used[i] == 0) {
                max = wine[i][0];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (wine[i][0] == max && used[i] == 0) {
                add += wine[i][1];
                used[i] = 1;
            }
        }
        if (volume + add <= L) {
            pay += max * add;
            volume += add;
        } else {
            pay += max * (L - volume);
            volume = L;
        }
    }
    printf("%d", pay);
    return 0;
}
