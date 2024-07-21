//
// Created by zyr on 2023/12/9.
//
#include <stdbool.h>
#include <stdio.h>

#define N 3050

int checkl(int i, int j);

int checkr(int i, int j);

int checku(int i, int j);

int checkd(int i, int j);

char map[N][N];
int dan[N][N];
int r;
int c;
int ans;
int m;

int main(void) {
    scanf("%d%d", &r, &c);
    getchar();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%c", &map[i][j]);
            if (map[i][j] != '.') {
                m++;
            }
        }
        getchar();
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (map[i][j] == 'L') {
                dan[i][j] = checkl(i, j);
            } else if (map[i][j] == 'R') {
                dan[i][j] = checkr(i, j);
            } else if (map[i][j] == 'U') {
                dan[i][j] = checku(i, j);
            } else if (map[i][j] == 'D') {
                dan[i][j] = checkd(i, j);
            }
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (dan[i][j] == 1) {
                if (checkl(i, j) == 1 && checkr(i, j) == 1 && checku(i, j) == 1 && checkd(i, j) == 1) {
                    printf("-1");
                    return 0;
                }else {

                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}

int checkl(int i, int j) {
    for (int k = 0; k < j; ++k) {
        if (map[i][k] != '.') {
            return 0;
        }
    }
    return 1;
}

int checkr(int i, int j) {
    for (int k = j + 1; k < c; ++k) {
        if (map[i][k] != '.') {
            return 0;
        }
    }
    return 1;
}

int checku(int i, int j) {
    for (int k = 0; k < i; ++k) {
        if (map[k][j] != '.') {
            return 0;
        }
    }
    return 1;
}

int checkd(int i, int j) {
    for (int k = i + 1; k < r; ++k) {
        if (map[k][j] != '.') {
            return 0;
        }
    }
    return 1;
}