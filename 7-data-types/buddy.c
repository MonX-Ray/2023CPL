//
// Created by zyr on 2023/11/18.
//
#include <stdio.h>
#include <math.h>

#define N 10005
int a[N];
int b[N];
int nums = 1;

int main(void) {
    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);
    a[0] = n;
    getchar();
    for (int i = 0; i < q; ++i) {
        char flag = 0;
        scanf("%c", &flag);
        if (flag == 'Q') {
            printf("%d\n", nums);
            for (int j = 0; j < nums; ++j) {
                printf("%d ", b[j]);
            }
            printf("\n");
        }
        if (flag == 'A') {
            int id = 0;
            int m = 0;
            scanf("%d%d", &id, &m);
            int mm = 0;
            for (int j = 0;; ++j) {
                if (pow(2, j) >= m) {
                    mm = j;
                    break;
                }
            }
            int flagg = 0;
            while (flagg == 0) {
                for (int k = 0; k < nums; ++k) {
                    if (a[k] == mm && b[k] == 0) {
                        b[k] = id;
                        flagg = 1;
                        break;
                    }
                }
                if (flagg == 0) {
                    int index = 0;
                    for (int j = 0; j < nums; ++j) {
                        if (a[j] > mm && b[j] == 0) {
                            index = j;
                            a[j] = a[j] - 1;
                            break;
                        }
                    }
                    for (int j = nums; j > index; --j) {
                        a[j] = a[j - 1];
                        b[j] = b[j - 1];
                    }
                    nums++;
                }
            }
        }
        getchar();
    }
    return 0;
}