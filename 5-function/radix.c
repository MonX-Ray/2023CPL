//
// Created by zyr on 2023/10/27.
//
#include <stdio.h>

int main(void) {
    int p = 0;
    int q = 0;
    int r = 0;
    scanf("%d%d%d", &p, &q, &r);
    int arr[10] = {p % 10, p / 10, q / 10, q % 10, r / 10, r % 10};
    int max = arr[0];
    for (int i = 1; i < 6; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    for (int N = max + 1; N < 41; ++N) {
        int P = 0;
        int Q = 0;
        int R = 0;
        int a=p,b=q,c=r;
        int temp = 1;
        while (a > 0) {
            P += (a % 10) * temp;
            a = a / 10;
            temp *= N;
        }
        temp = 1;
        while (b > 0) {
            Q += (b % 10) * temp;
            b = b / 10;
            temp *= N;
        }
        temp = 1;
        while (c > 0) {
            R += (c % 10) * temp;
            c = c / 10;
            temp *= N;
        }
        if (P * Q == R) {
            printf("%d", N);
            return 0;
        }
    }
    printf("0");
    return 0;
}
