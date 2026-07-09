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

        if(arr_temp[i].mm == mm)
        {
            year_mm[mm] =year_mm[mm] + arr_temp[i].temperature;
            coun++;
        }
        
        i++;
    }

    float avg = year_mm[mm] / coun;

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



    return year_mm[mm];
}

int addData(const Data *p, int day)
{


    return 0;
}

int addStatistic()
{



    return 0;
}

int deleteData(const Data *arr, int size)
{


    return 0;
}

int sortData(const Data *arr, int size)
{


    return 0;
}

// int intData(Data * p)
// {
// //     Data p[1000] = {
// //         {2021,01,16,01,01,-47},
// //         {2021,01,16,01,03,-44},
// //         {2021,01,16,01,04,-43},
// //         {2021,01,16,01,05,-10},
// //         {2021,02,16,01,01,-25},
// //         {2021,02,17,01,01,-30},
// //         {2021,03,16,01,01,-10},
// //         {2021,04,16,01,01,0},
// //         {2021,05,16,01,01,10},
// //         {2021,06,16,01,01,25},
// //         {2021,07,16,01,01,30},
// //         {2021,8,16,01,01,20},
// //         {2021,9,16,01,01,18},
// //         {2021,10,16,01,01,2},
// //         {2021,11,16,01,01,-5},
// //         {2021,12,16,01,01,-20}
// //     };

//     return 0;
// }

int printData(const Data *p, int size, int mm)
{

    if(mm!=0)
    {
        printf("------------------------temperature statistics------------------------\n");
        printf("             month     Average        Minimum        Maximum \n");  
        printf("      %10d    %10.2f    %10.2f    %10.2f\n",mm, temp_avg(p,size,mm), temp_min(p,size,mm), temp_max(p,size,mm));        
    }else{

        int i = 1;
        printf("------------------------temperature statistics------------------------\n");
        printf("             month     Average        Minimum        Maximum \n");        
        while(i<13)
        {

            printf("      %10d    %10.2f    %10.2f    %10.2f\n",i, temp_avg(p,size,i), temp_min(p,size,i), temp_max(p,size,i));
            // printf("Average temperature per month - %d: %.2f\n",i, temp_avg(p,size,i));
            // printf("Minimum temperature per month - %d: %.2f\n",i, temp_min(p,size,i));
            // printf("Maximum temperature per month - %d: %.2f\n",i, temp_max(p,size,i));  
            // printf("-----------------------------------------\n");  
            i++;
        }



    }
;

    return 0;
}
