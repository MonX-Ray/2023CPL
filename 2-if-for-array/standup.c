//
// Created by zyr on 2023/10/9.
//
#include <stdio.h>

#define N 1000

int main(void) {
    int n = 0;
    int students[N];
    int standup = 0;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &students[i]);
    }
    standup = students[0] + ans;

    printf("%d", ans);
    return 0;
}
