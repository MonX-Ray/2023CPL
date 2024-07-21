//
// Created by zyr on 2023/12/6.
//
#include <stdio.h>
#include <string.h>

#define N 1005
#define M 2010
char s3[M];
char *p = s3;
int index3;

void interleavestring(const char *s1, const char *s2);

void move(char *s, int len);

int main(void) {
    int t = 0;
    int d1 = 1;
    int d2 = 1;
    int size = 0;
    int len1 = 0;
    int len2 = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        getchar();
        char s1[N];
        char s2[N];
        for (int i = 0;; ++i) {
            scanf("%c", &s1[i]);
            if (s1[i] == ';') {
                s1[i] = '\0';
                len1 = i;
                break;
            }
        }
        for (int i = 0;; ++i) {
            scanf("%c", &s2[i]);
            if (s2[i] == ';') {
                s2[i] = '\0';
                len2 = i;
                break;
            }
        }
        scanf("%d;%d;%d", &d1, &d2, &size);
        int a = 0;
        for (int i = 0; i < len1; ++i) {
            if (a != 0 && a % d1 == 0) {
                move(s1 + i, len1 - i);
                len1 += 1;
                a = 0;
            } else {
                a++;
            }
        }
        int b = 0;
        for (int i = 0; i < len2; ++i) {
            if (b != 0 && b % d2 == 0) {
                move(s2 + i, len2 - i);
                len2 += 1;
                b=0;
            }else{
                b++;
            }
        }

        const char flag[] = " ";
        char *token1 = strtok(s1, flag);
        char *token2 = strtok(s2, flag);

        while (token1 != NULL || token2 != NULL) {
            interleavestring(token1, token2);

            token1 = strtok(NULL, flag);
            token2 = strtok(NULL, flag);
        }
    }
    printf("%s", s3);
    return 0;
}

void interleavestring(const char *s1, const char *s2) {
    p = p + index3;
    if (s1 == NULL) {
        strcpy(p, s2);
        return;
    }
    if (s2 == NULL) {
        strcpy(p, s1);
        return;
    }
    strcpy(p, s1);
    p = p + strlen(s1);
    strcpy(p, s2);
    p = p + strlen(s2);
}

void move(char *s, int len) {
    for (int i = len; i > 0; --i) {
        s[i] = s[i - 1];
    }
    s[0] = ' ';
}
