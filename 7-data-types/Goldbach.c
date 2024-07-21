//
// Created by zyr on 2023/11/29.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int GetData(void);

bool Goldbach(int a);

bool IsPrime(int a);

int main(void) {
    int num = 0;
    here:num = GetData();
    if (Goldbach(num)) {
        printf("%d fits Goldbach conjecture\n", num);
    } else {
        printf("%d doesn't fit Goldbach conjecture\n", num);
    }
    printf("Continue or Not (Please print Yes or No)\n");
    char flag[10];
    scanf("%s", flag);
    if (flag[0] == 'N') {
        return 0;
    } else if (flag[0] == 'Y') {
        goto here;
    }
}

int GetData(void) {
    int a;
    printf("Please enter an integer:\n");
    scanf("%d", &a);
    return a;
}

bool IsPrime(int a) {
    if (a < 2) {
        return false;
    } else {
        int i;
        for (i = 2; i * i <= a; ++i) {
            if (a % i == 0) {
                return false;
            }
        }
    }
    return true;
}
bool Goldbach(int a){
    if(a>=6&&a%2==0){
        for (int i = 3; i <=a/2 ; ++i) {
            if(IsPrime(i)&& IsPrime(a-i)){
                return true;
            }
        }
    }else{
        return false;
    }
}