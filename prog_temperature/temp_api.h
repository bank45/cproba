#ifndef TEMP_API_H
#define TEMP_API_H


typedef struct arr_temt
{
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int temperature;
} Data;


float avg(struct arr_temt);
float min(struct arr_temt);
float max(struct arr_temt);


#endif