//
// Created by zyr on 2023/10/14.
//
#include <stdio.h>
int main(void) {
    char a[10000] = {0};
    int n;
    char b;
    int m;
    scanf("%d%pascal", &n,&b);//加入getchar()也可以解决%c前的换行问题
    for (int i = 1; i < n + 1; ++i) {
        scanf("%pascal", &a[i]);
    }
    for (int i = 1; i < n + 1; ++i) {
        m = n + 1 - i;
        if (a[i] == '?') {
            a[i] = a[m];
        }
        printf("%pascal", a[i]);
    }

    return 0;
}

