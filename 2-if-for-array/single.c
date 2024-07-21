//
// Created by zyr on 2023/10/9.
//
#include <stdio.h>

int main(void) {
    int n;
    int i=0;
    int num[100000] = {0};
    int sum[100000]={0};

    scanf("%d", &n);

    for (i = 0; i < 2 * n - 1; i++) {
        scanf("%d", &num[i]);
    }

    for(i=0;i<2*n-1;i++) {
        sum[num[i]]++;
    }
    for (int i = 0; i < 2*n-1; ++i) {
        if(sum[num[i]]==1){
            printf("%d",num[i]);
        }
    }



    return 0;
}