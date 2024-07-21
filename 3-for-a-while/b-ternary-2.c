//
// Created by zyr on 2023/10/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  N 10005

int main(void) {
    int n=0;
    int a = 0;
    int len=0;
    char s[N];
    int flag = 0;
    int jin = 0;
    int zyr[100] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        len = strlen(s);
        int num = atoi(s);

        if (s[0] == '0' || s[0] == '1' || s[0] == '2' || s[0] == '3' || s[0] == '4' || s[0] == '5' ||
            s[0] == '6' ||
            s[0] == '7' || s[0] == '8' || s[0] == '9' || s[0] == '-') {
            a = 0;
            for (int j = 1; j < len; ++j) {
                if (s[j] == '0' || s[j] == '1' || s[j] == '2' || s[j] == '3' || s[j] == '4' || s[j] == '5' ||
                    s[j] == '6' ||
                    s[j] == '7' || s[j] == '8' || s[j] == '9') {
                    a = 0;
                } else {
                    a = 1;
                    break;
                }
            }
        } else {
            a = 1;
        }

        if (a == 1) {
            printf("Radix Error\n");
        } else if (a == 0 && num > 0) {
            jin = 0;
            flag = 0;
            while (num > 0) {
                zyr[flag] = num % 3 + jin;
                jin = 0;
                num = num / 3;
                if (zyr[flag] == 1 || zyr[flag] == 0) {
                    zyr[flag] = zyr[flag];
                } else if (zyr[flag] == 2) {
                    jin = 1;
                } else if (zyr[flag] == 3) {
                    zyr[flag] = 0;
                    jin = 1;
                }
                flag++;
            }
            if (jin == 1) {
                zyr[flag] = 1;
                for (int j = flag; j >= 0; --j) {
                    if (zyr[j] == 0 || zyr[j] == 1) {
                        printf("%d", zyr[j]);
                    } else if (zyr[j] == 2) {
                        printf("Z");
                    }
                }
                printf("\n");
            } else {
                for (int j = flag - 1; j >= 0; --j) {
                    if (zyr[j] == 0 || zyr[j] == 1) {
                        printf("%d", zyr[j]);
                    } else if (zyr[j] == 2) {
                        printf("Z");
                    }
                }
                printf("\n");
            }


        } else if (a == 0 && num < 0) {
            num = (-1) * num;
            jin = 0;
            flag = 0;
            while (num > 0) {
                zyr[flag] = num % 3 + jin;
                jin = 0;
                num = num / 3;
                if (zyr[flag] == 1 || zyr[flag] == 0) {
                    zyr[flag] = zyr[flag];
                } else if (zyr[flag] == 2) {
                    jin = 1;
                } else if (zyr[flag] == 3) {
                    zyr[flag] = 0;
                    jin = 1;
                }
                flag++;
            }
            if (jin == 1) {
                zyr[flag] = 1;
                for (int j = flag; j >= 0; --j) {
                    if (zyr[j] == 0) {
                        printf("%d", zyr[j]);
                    } else if (zyr[j] == 2) {
                        printf("1");
                    } else if (zyr[j] == 1) {
                        printf("Z");
                    }
                }
                printf("\n");
            } else {
                for (int j = flag-1; j >= 0; --j) {
                    if (zyr[j] == 0) {
                        printf("%d", zyr[j]);
                    } else if (zyr[j] == 2) {
                        printf("1");
                    } else if (zyr[j] == 1) {
                        printf("Z");
                    }
                }
                printf("\n");
            }
        } else if (a == 0 && num == 0) {
            printf("0\n");
        }
    }
    return 0;
}