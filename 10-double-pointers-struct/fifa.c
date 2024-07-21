//
// Created by zyr on 2023/12/15.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char *name;
    int attack;
    int guard;
    int tactics;
} player;
typedef struct {
    char *country_name;
    player play_list[11];
    int ave[3];
} country;
country country_list[1005];
void sort(int a);
int n;
int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        country_list[i].country_name = malloc(25 * sizeof(char));
        scanf("%s", country_list[i].country_name);
        for (int j = 0; j < 11; ++j) {
            country_list[i].play_list[j].name = malloc(25 * sizeof(char));
            scanf("%s", country_list[i].play_list[j].name);
            scanf("%d", &country_list[i].play_list[j].attack);
            country_list[i].ave[0] += country_list[i].play_list[j].attack;
            scanf("%d", &country_list[i].play_list[j].guard);
            country_list[i].ave[1] += country_list[i].play_list[j].guard;
            scanf("%d", &country_list[i].play_list[j].tactics);
            country_list[i].ave[2] += country_list[i].play_list[j].tactics;
        }
    }
    sort(0);
    sort(1);
    sort(2);

    return 0;
}
void sort(int a){
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if(country_list[j].ave[a]>country_list[i].ave[a]){
                country temp=country_list[i];
                country_list[i]=country_list[j];
                country_list[j]=temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s ",country_list[i].country_name);
    }
    printf("\n");
}
