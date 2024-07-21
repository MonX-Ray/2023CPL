//
// Created by zyr on 2023/9/23.
//


#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void){
    char first_name[]="Dayou";
    char last_name[]="Luo";

    char gender= 'm';

    int birth_year=1954;
    int birth_month=7;
    int birth_day=20;

    char weekday[]="Tuesday";

    int c_score=30;
    int music_score=100;
    int medicine_score=85;

    double mean=(c_score+music_score+medicine_score)/3.0;
    double sd=sqrt((pow(c_score-mean,2)+
            pow(medicine_score-mean,2)+
            pow(music_score-mean,2))/3.0);
    int rank=5;


    printf("%s\t%s\t%pascal\n"
           "%.2d-%d-%d\t%.3s.\n"
           "%d\t%d\t%d\n"

           "%.1f\t%.2f\t%d%%",
           first_name, last_name, toupper(gender),
           birth_month, birth_day ,birth_year,weekday,
           c_score,music_score,medicine_score,
           mean,sd,rank);







    return 0;
}