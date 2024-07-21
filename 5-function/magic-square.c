//
// Created by zyr on 2023/10/27.
//
#include <stdio.h>
#define N 1005
int num[N][N] = {0};

int main(void) {
    int n = 0;
    scanf("%d", &n);
    num[1][(n+1)/2] = 1;
    int i = 1;
    int j = (n+1)/2;
    for (int x = 2; x < n * n + 1; ++x) {
        if ((i - 1 >= 1) && (j + 1 <= n)) {
            if(num[i-1][j+1]==0) {
                i--;
                j++;
            }
        }else if ((i - 1 < 1) && (j + 1 > n)) {
            if(num[n][1]==0){
                i = n;
                j = 1;
            }
        } else if ((i - 1 < 1) && (j + 1 <= n)) {
            if(num[n][j+1]==0){
                i = n;
                j = j + 1;
            }
        } else if ((i - 1 >= 1) && (j + 1 > n)) {
            if(num[i-1][1]==0) {
                i = i - 1;
                j = 1;
            }
        }
        while(num[i][j]!=0){
            i=i+1;
        }
        num[i][j]=x;
    }
    for (int k = 1; k < n + 1; ++k) {
        for (int l = 1; l < n + 1; ++l) {
            printf("%d ", num[k][l]);
        }
        printf("\n");
    }


    return 0;
}

