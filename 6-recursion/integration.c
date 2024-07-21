//
// Created by zyr on 2023/11/15.
//
#include <stdio.h>
#include <math.h>

int n = 0;
int p = 0;
int num[30];
double error = 0.0001;


double S(double a, double b);

double F(double x);

double ans(double a, double b,double e);

int main(void) {
    double a = 0;
    double b = 0;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n + 1; ++i) {
        scanf("%d", &num[i]);
    }
    scanf("%lf%lf", &a, &b);
    printf("%lf", ans(a, b,error));
    return 0;
}

double F(double x) {
    double sum = num[0];
    for (int i = 1; i < n + 1; ++i) {
        sum = sum + (num[i] * pow(x, i));
    }
    return pow(sum, p);
}

double S(double a, double b) {
    return (((4 * F((a + b) / 2.0) + F(a) + F(b)) / 6.0) * (b - a));
}

double ans(double l, double r,double e) {
    double mid = (l + r) / 2.0;
    double SL = S(l, mid);
    double SR = S(mid, r);
    double SS = S(l, r);
    double fab_x = fabs(SL + SR - SS);
    if (fab_x <= 15 * e) {
        return SL + SR + (SL + SR - SS) / 15.0;
    } else {
        return ans(l, mid,e/2.0) + ans(mid, r,e/2.0);
    }
}