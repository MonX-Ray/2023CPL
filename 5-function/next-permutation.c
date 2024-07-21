//
// Created by zyr on 2023/10/27.
//
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[2005] = {0};
    for (int i = 1; i < n + 1; ++i) {
        scanf("%d", &arr[i]);
    }
    int len = 1;
    for (int i = n; i > 1; --i) {
        if (arr[i - 1] > arr[i]) {
            len++;
        } else {
            break;
        }
    }
    int min = 0;
    for (int i = n - len + 1; i < n + 1; ++i) {
        if (arr[i] > arr[n - len]) {
            min = arr[i];
            break;
        }
    }
    int k = 0;
    for (int i = n - len + 1; i < n + 1; ++i) {
        if ((arr[i] > arr[n - len]) && arr[i] <= min) {
            min = arr[i];
            k = i;
        }
    }
    int temp = 0;
    temp = arr[n - len];
    arr[n - len] = arr[k];
    arr[k] = temp;
    for (int i = 1; i < n - len + 1; ++i) {
        printf("%d ", arr[i]);
    }
    for (int i = n; i > n - len; --i) {
        printf("%d ", arr[i]);
    }


    return 0;
}