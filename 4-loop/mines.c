//
// Created by zyr on 2023/10/21.
//oj能跑，clion爆了

#include <stdio.h>
#define N 10005

int main(void) {
    int n = 0;
    scanf("%d", &n);
    char mines[N][N];
    int vectors[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
    for (int i = 1; i < n + 1; ++i) {
        scanf("%s", mines[i]);
    }
    for (int i = 0; i < n + 2; ++i) {
        mines[0][i] = 'o';
        mines[n + 1][i] = 'o';
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            mines[i][j + 1] = mines[i][j];
        }
    }
    for (int i = 0; i < n + 2; ++i) {
        mines[i][0] = 'o';
        mines[i][n + 1] = 'o';
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (mines[i][j] == '*') {
                printf("*");
            } else if (mines[i][j] == 'o') {
                int count=0;
                for (int k = 0; k < 8; ++k) {
                    int newi = i + vectors[k][0];
                    int newj = j + vectors[k][1];
                    if (mines[newi][newj] == '*') {
                        count++;
                    }
                }
                printf("%d", count);
            }
        }
        printf("\n");
    }
    return 0;
}

/*sa酱作业答案
#include <stdio.h>

char mines[105][105];
int vectors[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1},
                     {1, 0}, {1, 1}, {0, 1}, {0, -1}};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", mines[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mines[i][j] == 'o') {
                int count = 0;
                for (int k = 0; k < 8; ++k) {
                    int newI = i + vectors[k][0];
                    int newJ = j + vectors[k][1];
                    // 注意 newI 和 newJ 必须是合法的坐标值
                    if (newI >= 0 && newI < n && newJ >= 0 &&
                        newJ < n && mines[newI][newJ] == '*')//此处使用边界判断，自己的答案为填充无效值法。尽量使用边界判断法，不破坏原数组的下标
                        count++;
                }
                printf("%d", count);
            } else
                printf("*");
        }
        printf("\n");
    }
    return 0;
}