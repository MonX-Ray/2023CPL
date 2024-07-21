//
// Created by zyr on 2023/12/9.
//
#include <stdio.h>

#define N 1005
int w, n, d;
int num[N];
int ansl[N];
int ansr[N];
int ans[N];
int sum = 0;

int flipl(int a, int b);


int main(void) {
    scanf("%d%d%d", &w, &n, &d);
    for (int i = 1; i <= w; ++i) {
        scanf("%d", &num[i]);
    }
    int mid = w / 2;
    for (int i = 1; i <= mid; ++i) {
        ansl[i] = flipl(num[i], num[w + 1 - i]);
        if (ansl[i] == -1) {
            printf("Impossible");
            return 0;
        }
    }

    for (int i = 1; i <= w / 2; ++i) {
        sum += ansl[i];
    }
    printf("%d", sum);
    return 0;
}

int flipl(int a, int b) {
    int arr[N] = {a};
    int temp = -1;
    int index = 1;
    int len = 0;
    if (a == b) {
        return 0;
    }
    while (1) {
        if((a+d)%n==0){
            a=n;
        }else{
            a=(a+d)%n;
        }
        arr[index] = a;
        if (a == b) {
            temp = index;
        }
        if (arr[index] == arr[0]) {
            len = index;
            if (temp == -1) {
                return -1;
            } else if(len-temp<temp){
                return len-temp;
            }else{
                return temp;
            }
        }
        index++;
    }
}
