//
// Created by zyr on 2024/1/2.
//
#include <stdio.h>

#define LEN 200005
int a[LEN];
int b[LEN];

int main(void) {
    int len1 = 0;
    int len2 = 0;
    scanf("%d", &len1);
    for (int i = 0; i < len1; ++i) {
        scanf("%d",&a[i]);
    }
    scanf("%d", &len2);
    for (int i = 0; i < len2; ++i) {
        scanf("%d",&b[i]);
    }
    int mid1 = 0;
    int mid2 = 0;
    for (int i = 0; i < len1; ++i) {
        if (a[i] > a[i + 1]) {
            mid1 = i;
            break;
        }
    }
    for (int i = 0; i < len2; ++i) {
        if (b[i] > b[i + 1]) {
            mid2 = i;
            break;
        }
    }

    int left = 0;
    int right = 0;
    while (left <= mid1 && right <= mid2) {
        if (a[left] <= b[right]) {
            printf("%d ", a[left++]);
        } else {
            printf("%d ", b[right++]);
        }
    }
    while (right <= mid2) {
        printf("%d ", b[right++]);
    }
    while(left<=mid1){
        printf("%d ",a[left++]);
    }

    left=mid1+1;
    right=mid2+1;
    while (left < len1 && right < len2) {
        if (a[left] >= b[right]) {
            printf("%d ", a[left++]);
        } else {
            printf("%d ", b[right++]);
        }
    }
    while (right < len2) {
        printf("%d ", b[right++]);
    }
    while(left< len1){
        printf("%d ",a[left++]);
    }
    return 0;
}