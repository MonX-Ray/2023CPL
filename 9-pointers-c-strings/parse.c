//
// Created by zyr on 2023/12/2.
//
#include <stdio.h>
#include <string.h>

#define N 150
#define M 1050

int main(void) {
    char rule[N];
    char name[N];
    char output[N];
    scanf("%s", rule);
    int len0 = (int) strlen(rule);
    getchar();
    char input[M];
    for (int i = 0;; ++i) {
        scanf("%c", input + i);
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }
    int len = (int) strlen(input);
    int index = 0;

    for (int i = 0; i < len; ++i) {//27-35 name
        if (input[i] != ' ') {
            name[i] = input[i];
            output[i] = input[i];
            index++;
        } else {
            output[index] = '\n';
            name[index] = '\0';
            index++;
            break;
        }
    }

    int nums[M]={0};//是否扫描过
    for (int i = index; i < len; ++i) {
        if (input[i] == '-' && nums[i] == 0) {
            nums[i]=1;
            int flag = 0;//是否在rule中
            //在rule中查找规则
            for (int j = 0; j < len0; ++j) {
                if (rule[j] == input[i + 1]) {
                    if (rule[j + 1] == ':') {

                        if (i + 3 >= len) {
                            printf("%s: option requires an argument -- '%c'",
                                   name, input[i + 1]);
                            return 0;
                        }

                        output[index] = input[i + 1];
                        nums[i + 1] = 1;
                        index++;
                        output[index] = '=';
                        index++;
                        for (int k = i + 3; k < len; ++k) {
                            if (input[k] != ' ') {
                                output[index] = input[k];
                                nums[k] = 1;
                                index++;
                            }else{
                                output[index]='\n';
                                index++;
                                break;
                            }
                        }
                    } else {
                        output[index] = input[i + 1];
                        nums[i + 1] = 1;
                        index++;
                        output[index] = '\n';
                        index++;
                    }
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                printf("%s: invalid option -- '%c'",
                       name, input[i + 1]);
                return 0;
            }
        }
    }
    output[index]='\0';
    printf("%s", output);
    return 0;
}