//
// Created by zyr on 2023/12/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1005

int compare(const void *a, const void *b);

char s[N];
char *ans[110];

int main(void) {
    int i = 0;
    scanf("%s", s);
    char key;
    getchar();
    scanf("%c", &key);
    char *poi= strtok(s,&key);
    while(poi!=NULL){
        ans[i]= malloc(110);
        ans[i++]=poi;
        poi=strtok(NULL,&key);
    }
    qsort(ans, i,
          sizeof(ans[0]),
          compare);
    for (int j = 0; j < i; ++j) {
        printf("%s\n",ans[j]);
    }
    return 0;
}

int compare(const void *a, const void *b) {
    const char *const *c = a;
    const char *const *d = b;
    return strcmp(*c, *d);
}