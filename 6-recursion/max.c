//
// Created by zyr on 2023/11/15.
//
#include <stdio.h>

#define N 10005

void Maxmeg(int nums[],int l, int r);

int M(int nums[], int l, int r);

int ans[N][2];
int nums[N];

int main(void) {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
    Maxmeg(nums,0, n-1);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}

void Maxmeg(int nums[],int l, int r) {
    if (l == r) {
        ans[l][0]=l+1;
        ans[l][1]=r+1;
        return;
    }
    if(l>r){
        return;
    }
        int mid = M(nums, l, r);
        ans[mid][0]=l+1;
        ans[mid][1]=r+1;
        Maxmeg(nums,l,mid-1);
        Maxmeg(nums,mid+1,r);

}

int M(int nums[], int l, int r) {
    int index=l;
    for (int i = l; i <=r ; ++i) {
        if(nums[i]>nums[index]){
            index=i;
        }
    }
    return index;
}