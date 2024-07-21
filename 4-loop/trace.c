//
// Created by zyr on 2023/10/21.
//
#include <stdio.h>
#define N 105

int main(void) {
    char map[N][N];
    int x = 0;
    int y = 0;
    int n = 0;
    int m = 0;
    int step = 0;
    int vis[N][N] = {0};
    int vectors[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    scanf("%d%d%d%d", &n, &m, &x, &y);
    vis[x][y]=1;
    for (int i = 1; i < n + 1; ++i) {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < m + 2; ++i) {
        map[0][i] = '_';
        map[n + 1][i] = '_';
    }//第一行和最后一行
    for (int i = 1; i < n + 1; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            map[i][j + 1] = map[i][j];
        }
    }//后移一位
    for (int i = 0; i < n + 2; ++i) {
        map[i][0] = '_';
        map[i][m + 1] = '_';
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            if (map[i][j] == '#') {
                step++;
            }
        }
    }
    printf("%d\n", step);
    printf("%d %d\n",x,y);
    while ((vis[x + 1][y] == 0 && map[x + 1][y] == '#') || (vis[x - 1][y] == 0 && map[x - 1][y] == '#') ||
           (vis[x][y + 1] == 0 && map[x][y + 1] == '#') || (vis[x][y - 1] == 0 && map[x][y - 1] == '#')) {
        for (int i = 0; i < 4; ++i) {
            int newx = x + vectors[i][0];
            int newy = y + vectors[i][1];
            if (map[newx][newy] == '#' && vis[newx][newy] == 0) {
                x = newx;
                y = newy;
                vis[x][y] = 1;
                printf("%d %d\n", x, y);
            }
        }
    }
    return 0;
}

