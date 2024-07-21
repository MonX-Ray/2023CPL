//
// Created by zyr on 2023/12/30.
//
#include <stdio.h>
#include <string.h>

void Move(int a[], int key);

int main(void) {
    int t = 0;
    int n = 0;
    int m = 0;
    int a[1005] = {0};
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d%d", &n, &m);
        memset(a, 0, 1005 * sizeof(int));

        for (int j = 1; j < n+1; ++j) {
            scanf("%d",&a[j]);
        }

        for (int j = 0; j < m; ++j) {
            int key = 0;
            scanf("%d", &key);
            Move(a, key);
        }
        int flag = 1;
        for (int i = 2; i < n+1; ++i) {
            if (a[i] < a[i - 1]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("I love C programming language\n");
        } else {
            printf("mayi is a good teacher\n");
        }
    }

    return 0;
}

void Move(int a[], int key) {
    int temp = a[key];
    for (int i = key; i > 0; --i) {
        a[i] = a[i - 1];
    }
    a[1] = temp;
}