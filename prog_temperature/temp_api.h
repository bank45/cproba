#ifndef TEMP_API_H
#define TEMP_API_H


typedef struct arr_temt
{
    int dddd;
    int mm;
    int dd;
    int hh;
    int m;
    float temperature;
} Data;


float temp_avg(const Data *arr_temp, int size, int mm);
float temp_min(const Data *arr_temp, int sizeб, int mm);
float temp_max(const Data *arr_temp, int size, int mm);

int printData(const Data *p, int size, int mm);
int intData(Data * p);
#endif