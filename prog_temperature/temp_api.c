#include <stdio.h>
#include "temp_api.h"
// #include <locale.h>



float temp_avg(const Data *arr_temp, int size,int mm)
{
    // setlocale(LC_ALL, "Russian_Russia.1251");

    float year_mm[13] = {0};
    int i =0;
    int coun =0;
    while(i<size)
    {
        // printf("arr_temp[i].mm]: %d\n", arr_temp[i].mm);
        // printf("arr_temp[i].temperature: %f\n", arr_temp[i].temperature);
        if(arr_temp[i].mm == mm)
        {
            year_mm[mm] =year_mm[mm] + arr_temp[i].temperature;
            coun++;
        }
        
         //+ arr_temp[i].temperature;
        i++;
    }
    // printf("year_mm[mm] : %.2f\n", year_mm[mm]);
    // printf("i : %d\n", i);
    float avg = year_mm[mm] / coun;
    // printf("Average temperature per month - %d: %.2f\n",mm, avg);
    // printf("arr_temt[0].dddd: %d\n",arr_temt[0].dddd);


    return avg;
}

float temp_min(const Data *arr_temp, int size, int mm)
{


    float year_mm[13] = {0};
    int i =0;
    int coun =0;
    year_mm[mm] = 100;
    while(i<size)
    {
        // printf("arr_temp[i].mm]: %d\n", arr_temp[i].mm);
        // printf("arr_temp[i].temperature: %f\n", arr_temp[i].temperature);
        if(arr_temp[i].mm == mm)
        {
            if(year_mm[mm] == 100)
            {
                year_mm[mm] =arr_temp[i].temperature; 
            }else if (year_mm[mm] > arr_temp[i].temperature)
            {
                year_mm[mm] =arr_temp[i].temperature; 
            }
        }
        i++;
    }

    // printf("Minimum temperature per month - %d: %.2f\n",mm, year_mm[mm]);

    return year_mm[mm];
}

float temp_max(const Data *arr_temp, int size, int mm)
{
    float year_mm[13] = {0};
    int i =0;
    int coun =0;
    year_mm[mm] = 100;
    while(i<size)
    {
        // printf("arr_temp[i].mm]: %d\n", arr_temp[i].mm);
        // printf("arr_temp[i].temperature: %f\n", arr_temp[i].temperature);
        if(arr_temp[i].mm == mm)
        {
            if(year_mm[mm] == 100)
            {
                year_mm[mm] =arr_temp[i].temperature; 
            }else if (year_mm[mm] < arr_temp[i].temperature)
            {
                year_mm[mm] =arr_temp[i].temperature; 
            }
        }
        i++;
    }

    // printf("Minimum temperature per month - %d: %.2f\n",mm, year_mm[mm]);

    return year_mm[mm];
}
