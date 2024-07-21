
//
// Created by zyr on 2023/12/2.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define N 5000
#define M 15
const char *reserved[16] = {"const", "int", "float", "double",
                            "long", "static", "void", "char",
                            "extern", "return", "break", "enum",
                            "struct", "typedef", "union", "goto"};
const char *operator[11] = {"+", "-", "*", "/",
                            "=", "==", "!=", ">=",
                            "<=", ">", "<"};
char out[N];

void JUDGE(const char *s);

bool Integer(const char *s);

int p;
bool flag = false;

int main(void) {
    char *s = (char *) malloc(N * sizeof(char));
    while (scanf("%s", s) != EOF) {
        int len = (int) strlen(s);
        const char *position = strchr(s, ';');
        if (position == NULL) {
            flag = false;
            JUDGE(s);
            if (!flag) {
                printf("Compile Error");
                return 0;
            }
        } else {
            size_t l = position - s;
            if (l == 0) {
                if(out[p-1]==' '){
                    out[p-1] = '\n';
                }else{
                    out[p]='\n';
                    p++;
                }
                JUDGE(s + 1);
            } else {
                char s1[len];
                char s2[len];
                strncpy(s1, s, l);
                s1[l] = '\0';
                strncpy(s2, position + 1, len - l);
                s2[len - l] = '\0';
                flag = false;
                JUDGE(s1);
                if (!flag) {
                    printf("Compile Error");
                    return 0;
                }
                if(out[p-1]==' '){
                    out[p-1] = '\n';
                }else{
                    out[p]='\n';
                    p++;
                }
                flag = false;
                if (strlen(s2)!=0) {
                    JUDGE(s2);
                    if (!flag) {
                        printf("Compile Error");
                        return 0;
                    }
                }
            }
        }
    }
    out[p - 1] = '\0';
    printf("%s", out);
    return 0;
}


bool Integer(const char *s) {
    int len = (int) strlen(s);
    for (int i = 0; i < len; ++i) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    if (len == 0) {
        return false;
    } else {
        return true;
    }
}

void JUDGE(const char *s) {
    int len = (int) strlen(s);
    if (len == 0) {
        flag = true;
        return;
    }
    if (len == 1 && s[0] == ';') {
        flag = true;
        if(out[p-1]==' '){
            out[p-1] = '\n';
        }else{
            out[p]='\n';
            p++;
        }
        return;
    }
    int sem = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ';') {
            sem++;
        }
    }
    if (sem >= 1) {
        const char *position = strchr(s, ';');
        size_t l = position - s;
        if (l == 0) {
            if(out[p-1]==' '){
                out[p-1] = '\n';
            }else{
                out[p]='\n';
                p++;
            }
            JUDGE(s + 1);
        } else {
            char s1[len];
            char s2[len];
            strncpy(s1, s, l);
            s1[l] = '\0';
            strncpy(s2, position + 1, len - l);
            s2[len - l] = '\0';
            flag = false;
            JUDGE(s1);
            if (!flag) {
                return;
            }
            if(out[p-1]==' '){
                out[p-1] = '\n';
            }else{
                out[p]='\n';
                p++;
            }
            if (len - l - 1) {
                flag = false;
                JUDGE(s2);
                if (!flag) {
                    return;
                }
            }else{

            }
        }
    }

    if (sem == 0) {
        if (Integer(s)) {
            flag = true;
            strcpy(out + p, "integer ");
            p = p + 8;
            return;
        }
        for (int i = 0; i < 11; ++i) {
            if (!strcmp(s, operator[i])) {
                flag = true;
                strcpy(out + p, "operator ");
                p = p + 9;
                return;
            }
        }
        for (int i = 0; i < 16; ++i) {
            if (!strcmp(s, reserved[i])) {
                flag = true;
                strcpy(out + p, "reserved ");
                p = p + 9;
                return;
            }
        }

        int num = 0;
        bool f = true;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '.') {
                num++;
            }
        }
        if (num == 1) {
            for (int i = 0; i < len; ++i) {
                if (!isdigit(s[i]) && s[i] != '.') {
                    f = false;
                }
            }
            if (f) {
                flag = true;
                strcpy(out + p, "float ");
                p = p + 6;
                return;
            }
        }

        if (len > 1) {
            bool v = true;
            for (int i = 0; i < len; ++i) {
                if (!isdigit(s[i]) && !isalpha(s[i]) && s[i] != '_') {
                    v = false;
                }
            }
            if (v && !isdigit(s[0])) {
                flag = true;
                strcpy(out + p, "variable ");
                p = p + 9;
                return;
            }
        } else if (len == 1) {
            if (isalpha(s[0])) {
                flag = true;
                strcpy(out + p, "variable ");
                p = p + 9;
                return;
            }
        }
    }
}
