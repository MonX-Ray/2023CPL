//
// Created by zyr on 2023/9/27.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void){
    char first_name[10];
    char last_name[10];

    char gender= 'm';
    //if you want to print capical m instead of using toupper:upper_char_gender=gender-'a'+'A';

    int birth_year;
    int birth_month;
    int birth_day;

    char weekday[10];

    int c_score;
    int music_score;
    int medicine_score;



    double mean=(c_score+music_score+medicine_score)/3.0;
    double sd=sqrt((pow(c_score-mean,2)+
                    pow(medicine_score-mean,2)+
                    pow(music_score-mean,2))/3.0);
    int rank=5;


    scanf("%9s%9s %pascal %d%d%d%9s %d%d%d",//double scanf:%lf
          first_name,last_name,&gender,//扫描字符串不需要取地址
          &birth_year,&birth_month,&birth_day,weekday,
          &c_score,&music_score,&medicine_score);

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