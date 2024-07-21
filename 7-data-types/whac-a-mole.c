//
// Created by zyr on 2023/11/18.
//
#include <stdio.h>
#include <math.h>

#define N 1005
int a[N][N];
long long int value[N][N];

int main(void) {
    int n = 0;
    int m = 0;
    int d = 0;
    long long int max = 0;
    int num = 0;
    int delta = 0;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = d + 1; i < d + 1 + n; ++i) {
        for (int j = d + 1; j < d + 1 + m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = d + 1; i < d + 1 + n; ++i) {
        for (int j = i - d; j <= i + d; ++j) {
            for (int k = 1; k <= 2 * d + 1; ++k) {
                if ((abs(i - j) + abs(d + 1 - k)) <= d) {
                    value[i][d + 1] += a[j][k];
                }
            }
        }
    }
    for (int i = d + 1; i < d + 1 + n; ++i) {
        for (int j = d + 2; j < d + 1 + m; ++j) {
            delta = a[i][j + d] - a[i][j - 1 - d];
            for (int k = d; k > 0; --k) {
                delta += a[i - k][j + d - k] - a[i - k][j - 1 - d + k] + a[i + k][j + d - k] - a[i + k][j - 1 - d + k];
            }
            value[i][j] = value[i][j - 1] + delta;
        }
    }
    max = value[d + 1][d + 1];
    for (int i = d + 1; i < d + 1 + n; ++i) {
        for (int j = d + 1; j < d + 1 + m; ++j) {
            if (value[i][j] > max) {
                max = value[i][j];
            }
        }
    }
    for (int i = d + 1; i < d + 1 + n; ++i) {
        for (int j = d + 1; j < d + 1 + m; ++j) {
            if (value[i][j] == max) {
                num++;
            }
        }
    }
    printf("%lld %d\n", max, num);
    for (int i = d + 1; i < d + 1 + n; ++i) {
        for (int j = d + 1; j < d + 1 + m; ++j) {
            if (value[i][j] == max) {
                printf("%d %d\n", i - d, j - d);
            }
        }
    }
    return 0;
}