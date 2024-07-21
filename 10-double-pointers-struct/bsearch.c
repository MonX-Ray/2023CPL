//
// Created by zyr on 2023/12/15.
//
#include <stdio.h>
#include <stdlib.h>

int a[10000005];

int compare(const void *a, const void *b);

int main(void) {
    int n = 0;
    int q = 0;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    size_t scale = sizeof(a[0]);
    size_t size = n;

    for (int i = 0; i < q; ++i) {
        int s = 0;
        scanf("%d", &s);
        const int *ans = (const int *) bsearch(&s, a,
                                               size, scale,
                                               &compare);
//      compare函数自行转换为指针
        if (ans == NULL) {
            printf("-1\n");
        } else {
            printf("%d\n", ans - a);
        }
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}