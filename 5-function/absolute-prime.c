//
// Created by zyr on 2023/10/27.
//
#include <stdio.h>
#include <math.h>

int IsPrime(int x);
int Reverse(int x);

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int sum = 0;

    for (int i = 2; i < n + 1; ++i) {
        if (IsPrime(i) && IsPrime(Reverse(i))) {
            sum++;
        }
    }
        printf("%d", sum);
        return 0;
    }


int IsPrime(int x) {
    for (int i = 2; i <= sqrt(x + 0.5); ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;//1表示是素数
}

int Reverse(int x) {
    int reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed;
}//逆序数字多写几次



