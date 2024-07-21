//
// Created by zyr on 2023/10/21.
//
#include <stdio.h>
#define N 9

int main(void) {
    int num[N][N];
    int a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &num[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        int row[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int column[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int j = 0; j < N; ++j) {
            row[num[i][j]]=row[num[i][j]]+1;
            column[num[j][i]]=column[num[j][i]]+1;
        }
        for (int x = 1; x < 10; ++x) {
            if (row[x] == 1 && column[x] == 1) {
                a = 0;
            } else {
                a = 1;
                goto HERE;
            }
        }
    }
    if (a == 0) {
        int vectors[9][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 0,0,1, -1, 1, 0, 1, 1};
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                int square[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                for (int k = 0; k < 9; ++k) {
                    int newi = (3*i-2) + vectors[k][0];
                    int newj = (3*j-2) + vectors[k][1];
                    square[num[newi][newj]]++;
                }
                for (int h = 1; h < 10; ++h) {
                    if (square[h] == 1) {
                        a = 0;
                    } else {
                        a = 1;
                        //printf("NO");
                        //return 0;(提前结束程序，尽量不要使用goto写法
                        goto HERE;
                    }
                }
            }
        }
    }

    HERE:if(a==0){
        printf("YES");
    }else{
        printf("NO");
    }


    return 0;
}