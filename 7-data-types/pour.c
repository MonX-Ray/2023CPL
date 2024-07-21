//
// Created by zyr on 2023/11/1
//
#include <stdio.h>

void pour(int m, int n, int p, int k);

int k;
int va;
int vb;
int vc;
int a;
int b;
int c;
int aa;
int bb;
int cc;
int flag=0;

int main(void) {
    scanf("%d%d%d%d%d%d%d%d%d%d", &k, &va, &vb, &vc, &a, &b, &c, &aa, &bb, &cc);
    pour(a, b, c, k);
    if(flag==1){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}

void pour(int m, int n, int p, int k) {
    if (m == aa && n == bb && p == cc && k >= 0) {
        flag=1;
        return;
    }
    if(k<0){
        return;
    }
    pour((m + n > va) ? va : m + n, 0, p, k - 1);
    pour(0,(m + n > vb) ? vb : m + n,p, k - 1);
    pour(m, (p + n > vb) ? vb : p + n,0 , k - 1);
    pour(m,0,(n+p>vc?vc:n+p),k-1);
    pour((m + p > va) ? va : m + p, n, 0, k - 1);
    pour(0, n, (m + p > vc) ? vc : m + p, k - 1);
}