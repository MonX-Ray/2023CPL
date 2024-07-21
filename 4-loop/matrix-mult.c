//
// Created by zyr on 2023/10/21.
//
#include <stdio.h>
#define N 100

int main(void) {
    int m = 0;
    int n = 0;
    int p = 0;
    int A[N][N];
    int B[N][N];
    int C[N][N];

    scanf("%d%d%d", &m, &n, &p);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            scanf("%d", &B[i][j]);
        }
    }


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }


    return 0;
}