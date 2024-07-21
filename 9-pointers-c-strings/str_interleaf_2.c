//
// Created by zyr on 2023/12/11.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1005
#define M 2010

void interleaveStrings(const char *s1, const char *s2
                       ,int d1, int d2, int size,
                       char *s3) {
    int len1 = (int) strlen(s1);
    int len2 = (int) strlen(s2);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < len1 && j < len2 && k < size-1) {
        int step = (d1 > len1 - i) ? (len1 - i) : d1;
        step = (k + step > size-1) ? size - k-1 : step;
        if(step){
            strncpy(&s3[k], &s1[i], step);
            k += step;
            i += step;
        }
        step = (d2 > len2 - j) ? (len2 - j) : d2;
        step = (k + step > size-1) ? size - k-1 : step;
        if(step){
            strncpy(&s3[k], &s2[j], step);
            k += step;
            j += step;
        }
    }

    while (i < len1 && j >= len2 && k < size-1) {
        int LEN = len1 - i < d1 ? len1 - i : d1;
        LEN = (k + LEN) > size-1 ? size - k-1 : LEN;
        if(LEN){strncpy(&s3[k], &s1[i], LEN);
            k += LEN;
            i += LEN;
        }
    }

    while (i >= len1 && j < len2 && k < size-1) {
        int LEN = len2 - j < d2 ? len2 - j : d2;
        LEN = (k + LEN) > size-1 ? size - k -1: LEN;
        if(LEN){
            strncpy(&s3[k], &s2[j], LEN);
            k += LEN;
            j += LEN;
        }
    }
    s3[size - 1] = '\0';
}

int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int d1 = 0;
        int d2 = 0;
        int size = 0;
        char s1[N];
        char s2[N];
        getchar();
        for (int i = 0;; ++i) {
            scanf("%c", &s1[i]);
            if (s1[i] == ';') {
                s1[i] = '\0';
                break;
            }
        }
        for (int i = 0;; ++i) {
            scanf("%c", &s2[i]);
            if (s2[i] == ';') {
                s2[i] = '\0';
                break;
            }
        }
        scanf("%d;%d;%d", &d1, &d2, &size);
        char *s3= malloc(size* sizeof(char));
        interleaveStrings(s1, s2, d1, d2, size, s3);
        printf("%s\n", s3);
    }
    return 0;
}

