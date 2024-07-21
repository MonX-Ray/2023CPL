//
// Created by zyr on 2023/12/15.
//
#include <stdio.h>

int n1;
int n2;
int jie1[100005];
int jie2[100005];
int out1[100005];
int out2[100005];
int out3[200005];

int main(void) {
    char s[15];
    scanf("%d%d", &n1, &n2);
    scanf("%s", s);
    for (int i = n1; i >= 0; --i) {
        scanf("%d", &jie1[i]);
    }
    for (int i = n2; i >= 0; --i) {
        scanf("%d", &jie2[i]);
    }
    int max = (n1 > n2) ? n1 : n2;
    for (int i = max; i > -1; --i) {
        out1[i] = jie1[i] + jie2[i];
        out2[i] = jie1[i] - jie2[i];
    }
    int maxx = n1 + n2;
    for (int i = 0; i < maxx + 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            out3[i] += jie1[j] * jie2[i - j];
        }
    }

    //he
    if (max > 1) {
        if (out1[max] == 1) {
            printf("%s^%d", s, max);
        } else if (out1[max] == -1) {
            printf("-%s^%d", s, max);
        } else {
            printf("%d%s^%d", out1[max], s, max);
        }
        for (int i = max - 1; i > 1; --i) {
            if (out1[i] == 0) { ;
            } else if (out1[i] < 0 && out1[i] != -1) {
                printf("%d%s^%d", out1[i], s, i);
            } else if (out1[i] == -1) {
                printf("-%s^%d", s, i);
            } else if (out1[i] != 1) {
                printf("+%d%s^%d", out1[i], s, i);
            } else {
                printf("+%s^%d", s, i);
            }
        }
        if (out1[1] == 0) { ;
        } else if (out1[1] < 0 && out1[1] != -1) {
            printf("%d%s", out1[1], s);
        } else if (out1[1] == -1) {
            printf("-%s", s);
        } else if (out1[1] != 1) {
            printf("+%d%s", out1[1], s);
        } else {
            printf("+%s", s);
        }
    } else {
        if (out1[1] == 0) { ;
        } else if (out1[1] < 0 && out1[1] != -1) {
            printf("%d%s", out1[1], s);
        } else if (out1[1] == -1) {
            printf("-%s", s);
        } else if (out1[1] != 1) {
            printf("%d%s", out1[1], s);
        } else {
            printf("%s", s);
        }
    }
    if (out1[0] < 0) {
        printf("%d", out1[0]);
    } else if (out1[0] > 0) {
        printf("+%d", out1[0]);
    }
    printf("\n");

    //cha
    if (max > 1) {
        if (out2[max] == 1) {
            printf("%s^%d", s, max);
        } else if (out2[max] == -1) {
            printf("-%s^%d", s, max);
        } else {
            printf("%d%s^%d", out2[max], s, max);
        }
        for (int i = max - 1; i > 1; --i) {
            if (out2[i] == 0) { ;
            } else if (out2[i] < 0 && out2[i] != -1) {
                printf("%d%s^%d", out2[i], s, i);
            } else if (out2[i] == -1) {
                printf("-%s^%d", s, i);
            } else if (out2[i] != 1) {
                printf("+%d%s^%d", out2[i], s, i);
            } else {
                printf("+%s^%d", s, i);
            }
        }
        if (out2[1] == 0) { ;
        } else if (out2[1] < 0 && out2[1] != (-1)) {
            printf("%d%s", out2[1], s);
        } else if (out2[1] == -1) {
            printf("-%s", s);
        } else if (out2[1] != 1) {
            printf("+%d%s", out2[1], s);
        } else {
            printf("+%s", s);
        }
    } else {
        if (out2[1] == 0) { ;
        } else if (out2[1] < 0 && out2[1] != (-1)) {
            printf("%d%s", out2[1], s);
        } else if (out2[1] == -1) {
            printf("-%s", s);
        } else if (out2[1] != 1) {
            printf("%d%s", out2[1], s);
        } else {
            printf("%s", s);
        }
    }
    if (out2[0] < 0) {
        printf("%d", out2[0]);
    } else if (out2[0] > 0) {
        printf("+%d", out2[0]);
    }
    int flag = 0;
    for (int i = 0; i < max + 1; ++i) {
        if (out3[i] != 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("0");
    }
    printf("\n");

    //ji
    if (maxx > 1) {
        if (out3[maxx] == 1) {
            printf("%s^%d", s, maxx);
        } else if (out3[maxx] == -1) {
            printf("-%s^%d", s, maxx);
        } else {
            printf("%d%s^%d", out3[maxx], s, maxx);
        }
        for (int i = maxx - 1; i > 1; --i) {
            if (out3[i] == 0) { ;
            } else if (out3[i] < 0 && out3[i] != -1) {
                printf("%d%s^%d", out3[i], s, i);
            } else if (out3[i] == -1) {
                printf("-%s^%d", s, i);
            } else if (out3[i] != 1) {
                printf("+%d%s^%d", out3[i], s, i);
            } else {
                printf("+%s^%d", s, i);
            }
        }
        if (out3[1] == 0) { ;
        } else if (out3[1] < 0 && out3[1] != -1) {
            printf("%d%s", out3[1], s);
        } else if (out3[1] == -1) {
            printf("-%s", s);
        } else if (out3[1] != 1) {
            printf("+%d%s", out3[1], s);
        } else {
            printf("+%s", s);
        }
    } else {
        if (out3[1] == 0) { ;
        } else if (out3[1] < 0 && out3[1] != -1) {
            printf("%d%s", out3[1], s);
        } else if (out3[1] == -1) {
            printf("-%s", s);
        } else if (out3[1] != 1) {
            printf("%d%s", out3[1], s);
        } else {
            printf("%s", s);
        }
    }
    if (out3[0] < 0) {
        printf("%d", out3[0]);
    } else if (out3[0] > 0) {
        printf("+%d", out3[0]);
    }
    return 0;
}