//
// Created by zyr on 2023/11/18.
//
#include <stdio.h>
#define N 10005
void MergeSort(int nums[],int l,int r);
void Merge(int nums[],int l,int mid,int r);
int nums[N];
int main(void){
    int n=0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&nums[i]);
    }

    MergeSort(nums,0,n);
    return 0;
}
void MergeSort(int nums[],int l,int r){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    MergeSort(nums,l,mid);
    MergeSort(nums,mid+1,r);
    Merge(nums,l,mid,r);
}
void Merge(int nums[],int l,int mid,int r){
    int Copy[]={0};
}