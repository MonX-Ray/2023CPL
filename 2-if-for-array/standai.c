//
// Created by zyr on 2023/10/14.
//
#include <stdio.h>
#define max(a,b) a > b ? a : b

int a[100010], sum[100010], n, ans = 0;

int main() {
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
        if(i) sum[i] = sum[i-1] + a[i];
        else sum[i] = a[i];
    }
    for(int i = 0; i <= n; i++)
        if(i)
            if(sum[i-1] < i)
                ans = max(ans, i - sum[i-1]);
    printf("%d\n", ans);
    return 0;
}