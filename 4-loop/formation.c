//
// Created by zyr on 2023/10/21.
//
#include <stdio.h>

#define N 2005
char formation[100000][2005];

int main(void) {

    int m = 0;
    int n = 0;
    scanf("%d%d", &m, &n);
    scanf("%s", formation[0]);
    for (int i = 1; i < n+1; ++i) {
        formation[1][i]=formation[0][i-1];
    }
    for (int i = 0; i < n+2; ++i) {
        formation[0][i]='0';
    }
    for (int i = 0; i < n+2; ++i) {
        formation[m+1][i]='0';
    }
    for (int i = 0; i <m+2 ; ++i) {
        formation[i][0]='0';
    }
    for (int i = 0; i <m+2 ; ++i) {
        formation[i][n+1]='0';
    }

    for (int i = 2; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            int a = 0;
            a = formation[i - 1][j - 1] - '0' + formation[i - 1][j] - '0' + formation[i - 1][j + 1] - '0';
            if (a == 3) {
                formation[i][j] = '0';
            } else if (a == 2) {
                formation[i][j] = '1';
            } else if (a == 0) {
                formation[i][j] = '0';
            } else if (a == 1 && formation[i - 1][j - 1] == '1') {
                formation[i][j] = '0';
            } else if (a == 1 && (formation[i - 1][j] == '1' || formation[i - 1][j + 1] == '1')) {
                formation[i][j] = '1';
            }
            printf("%pascal", formation[i][j]);
        }
        printf("\n");
    }

    return 0;
}