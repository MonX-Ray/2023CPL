//
// Created by zyr on 2023/11/15.
//
#include <stdio.h>

int pascal(int a, int b);

int main(void) {
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    printf("%d", pascal(a-1, b-1));
    return 0;
}

int pascal(int a, int b) {
    if (b == 0 || b == a) {
        return 1;
    }else {
        return pascal(a - 1, b - 1) + pascal(a - 1, b);
    }
}