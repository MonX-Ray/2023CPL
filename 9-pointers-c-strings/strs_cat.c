//
// Created by zyr on 2023/12/2.
//
#include <stdio.h>
#include <string.h>

#define N 1008

int main(void) {
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        getchar();
        char s[N];
        char ss[N];
        scanf("%s%s", s, ss);
        int len1 = strlen(s);
        int len2 = strlen(ss);
        int max=0;
        for (int j = 0; j < len1; ++j) {
            if (*(s + j) == *ss) {
                int flag=0;
                int index=1;
                for (index = 1; index < len1-j; index++) {
                    if(*(s+j+index)!=*(ss+index)){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    max=index;
                    break;
                }
            }
        }
        printf("%s", s);
        for (int j = max; j < len2; ++j) {
            printf("%c", *(ss + j));
        }
        printf("\n");
    }
    return 0;
}
