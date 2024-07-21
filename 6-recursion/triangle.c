//
// Created by zyr on 2023/11/15.
//
#include <stdio.h>
#include <math.h>

#define N 10005
int n = 0;

void paint(int n, int x, int y);

char picture[N][N];

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= (int) pow(2,n); ++i) {
        for (int j = 1; j <= (int) pow(2,n+1); ++j) {
            picture[i][j] = ' ';
        }
    }
    paint(n, 1, 1);
    for (int i = 1; i <= (int) pow(2,n); ++i) {
        for (int j = 1; j <= (int) pow(2,n+1); ++j) {
            printf("%c", picture[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void paint(int n, int x, int y) {
    if (n == 1) {
        picture[x][y] = ' ';
        picture[x][y + 1] = '/';
        picture[x][y + 2] = '\\';
        picture[x][y + 3] = ' ';
        picture[x + 1][y] = '/';
        picture[x + 1][y + 1] = '_';
        picture[x + 1][y + 2] = '_';
        picture[x + 1][y + 3] = '\\';
    } else {
        paint(n - 1,x,y+(int) pow(2,n-1));
        paint(n - 1,x+(int) pow(2,n-1),y);
        paint(n - 1,x+(int) pow(2,n-1),y+(int) pow(2,n));
    }
}