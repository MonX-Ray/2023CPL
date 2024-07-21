//
// Created by zyr on 2023/10/27.
//
#include <stdio.h>

#define N 100005

int main(void) {
    int n = 0;
    int m = 0;
    int t = 0;
    scanf("%d%d%d", &n, &m, &t);
    int arr[N] = {0};
    int brr[N] = {0};
    int drr[N] = {0};
    int crr[N] = {0};
    int flag = 0;
    int max=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &brr[i]);
    }

    int d = 0;
    for (int i = 0; i < m; ++i) {
        int l = 0;
        int r = n - 1;
        //二分查找中是否取等与最终确定的值的表示（l与l-1的区分
        while (r >= l) {
            int mid = (l + r) / 2;
            if (brr[i] + arr[mid] <= t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        drr[d] = brr[i] + arr[l-1];
        d++;
    }
    int c=0;
    for (int i = 0; i < d; ++i) {
        if (drr[i] <= t) {
            flag = 1;
            crr[c]=drr[i];
            c++;
        }
    }
    max=crr[0];
    for (int i = 0; i < c; ++i) {
        if(crr[i]>max){
            max=crr[i];
        }
    }
    if (flag == 0) {
        printf("-1");
    } else {
        printf("%d", t - max);
    }

    return 0;
}