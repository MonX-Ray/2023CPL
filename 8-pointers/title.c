//
// Created by zyr on 2023/11/30.
//
#include <stdio.h>
#include <stdlib.h>

#define N 4100

int main(void) {
    char *a = (char *) malloc(N * sizeof(char));
    for (int i = 0; i < N; ++i) {
        scanf("%c", a + i);
        if (*(a + i) == '\n') {
            break;
        }
    }
    if (*a >= 97 && *a <= 122) {
        *a -= 32;
    }
    printf("%c",*a);
    int i = 1;
    while (*(a + i) != '\n') {
        if (*(a + i - 1) == ' ' && *(a + i) >= 97 && *(a + i) <= 122) {
            *(a + i) -= 32;
        }
        if (*(a + i - 1) != ' ' && *(a + i) >= 65 && *(a + i) <= 90) {
            *(a + i) += 32;
        }
        printf("%c",*(a+i));
        i++;
    }
    return 0;
}