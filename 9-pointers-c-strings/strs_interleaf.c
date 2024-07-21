//
// Created by zyr on 2023/12/2.
//时间超限写法
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1005

int main(void) {
    int T = 0;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; ++i) {
        char *p1 = (char *) malloc(N * sizeof(char));
        char *p2 = (char *) malloc(N * sizeof(char));
        for (int j = 0; j < N; ++j) {
            scanf("%c", p1 + j);
            if (*(p1 + j) == ';') {
                *(p1 + j) = '\0';
                break;
            }
        }
        for (int j = 0; j < N; ++j) {
            scanf("%c", p2 + j);
            if (*(p2 + j) == ';') {
                *(p2 + j) = '\0';
                break;
            }
        }
        int len1 = (int) strlen(p1);
        int len2 = (int) strlen(p2);
        int d1 = 0;
        int d2 = 0;
        int size = 0;
        scanf("%d;%d;%d", &d1, &d2, &size);
        char *p3 = malloc(size * sizeof(char));
        int index3 = 0;
        int index1 = 0;
        int index2 = 0;
        while (index3 < size) {
            if (index3 % (d1 + d2) == 0) {
                for (int j = 0; j < d1; ++j) {
                    if (index1 < len1 && index3 < size) {
                        *(p3 + index3) = *(p1 + index1);
                        index3++;
                        index1++;
                    }
                }
                for (int j = 0; j < d2; ++j) {
                    if (index2 < len2 && index3 < size-1) {
                        *(p3 + index3) = *(p2 + index2);
                        index3++;
                        index2++;
                    }
                }
            }
            if (index1 == len1 && index2 != len2) {
                while (index3 < size && index2 < len2) {
                    *(p3 + index3) = *(p2 + index2);
                    index2++;
                    index3++;
                }
                break;
            }
            if (index2 == len2  && index1 != len1 ) {
                while (index3 < size && index1 < len1) {
                    *(p3 + index3) = *(p1 + index1);
                    index1++;
                    index3++;
                }
                break;
            }
            if (index1 == len1&& index2 == len2) {
                break;
            }
        }
        *(p3 + size - 1) = '\0';
        printf("%s\n", p3);
        getchar();
        free(p1);
        free(p2);
        free(p3);
    }
    return 0;
}