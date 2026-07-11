#include <stdio.h>
#include "temp_api.h"
// #include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

float temp_avg(const Data *arr_temp, int size, int mm)
{

    // float year_mm[13] = {0};
    // int i = 0;
    // int coun = 0;
    // while (i <= size)
    // {
    //     if (arr_temp[i].mm == mm)
    //     {
    //         year_mm[mm] = year_mm[mm] + arr_temp[i].temperature;
    //         coun++;
    //     }
    //     i++;
    // }
    // if (coun == 0)
    //     return 0.0f;

    // return (float)year_mm[mm] / coun;
    if (mm < 1 || mm > 12)
        return 0.0f;

    float sum = 0.0f;
    int count = 0;

    for (int i = 0; i < size; ++i)
    {
        if (arr_temp[i].mm == mm)
        {
            sum += arr_temp[i].temperature;
            count++;
        }
    }

    return count > 0 ? sum / count : 0.0f;
}

float temp_min(const Data *arr_temp, int size, int mm)
{

    float year_mm[13] = {0};
    int i = 0;
    int coun = 0;
    year_mm[mm] = 100;
    while (i <= size)
    {
        if (arr_temp[i].mm == mm)
        {
            if (year_mm[mm] == 100)
            {
                year_mm[mm] = arr_temp[i].temperature;
                // printf("year_mm[mm]: %.2f arr_temp[i].temperature: %.2f\n", year_mm[mm], arr_temp[i].temperature);
            }
            else
            {
                if (year_mm[mm] > arr_temp[i].temperature)
                {
                    // printf("temp_min: year_mm[mm]: %.2f arr_temp[i].temperature: %.2f\n", year_mm[mm], arr_temp[i].temperature);
                    year_mm[mm] = arr_temp[i].temperature;
                }
            }

            coun++;
        }
        i++;
    }
    if (coun == 0)
        return 0.0f;

    return year_mm[mm];
}

float temp_max(const Data *arr_temp, int size, int mm)
{
    float year_mm[13] = {0};
    int i = 0;
    int coun = 0;
    year_mm[mm] = 100;
    while (i <= size)
    {

        if (arr_temp[i].mm == mm)
        {
            if (year_mm[mm] == 100)
            {
                year_mm[mm] = arr_temp[i].temperature;
            }
            else
            {
                if (year_mm[mm] < arr_temp[i].temperature)
                {
                    // printf("temp_max: year_mm[mm]: %.2f arr_temp[i].temperature: %.2f\n", year_mm[mm], arr_temp[i].temperature);
                    year_mm[mm] = arr_temp[i].temperature;
                }
            }
            coun++;
        }
        i++;
    }

    if (coun == 0)
        return 0.0f;

    return year_mm[mm];
}

int addData(Data *p, int day, int dddd, int mm, int dd, int hh, int m, float temperature)
{
    p[day].dddd = dddd;
    p[day].mm = mm;
    p[day].dd = dd;
    p[day].hh = hh;
    p[day].m = m;
    p[day].temperature = temperature;

    return 0;
}

int addStatisticTest(Data *p)
{
    // printf("addStatisticTest\n");

    int arr[21][6] = {
        {2021, 01, 16, 01, 01, -47},
        {2021, 01, 16, 01, 03, -44},
        {2021, 01, 16, 01, 04, -43},
        {2021, 01, 16, 01, 05, -10},
        {2021, 02, 16, 01, 01, -25},
        {2021, 02, 17, 01, 01, -30},
        {2021, 03, 16, 01, 01, -10},
        {2021, 04, 16, 01, 01, 0},
        {2021, 05, 16, 01, 01, 10},
        {2021, 06, 16, 01, 01, 25},
        {2021, 07, 16, 01, 01, 30},
        {2021, 8, 16, 01, 01, 20},
        {2021, 9, 16, 01, 01, 18},
        {2021, 10, 16, 01, 01, 2},
        {2021, 11, 16, 01, 01, -5},
        {2021, 12, 16, 01, 01, -20}};

    int i = 0;

    while (arr[i][0] != 0)
    {

        addData(p, i, arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][5]);
        i++;
    }

    return i;
}

int addStatistic(Data *p, FILE *f)
{
    char buffer[1024];
    int s = 0;

    // printf("1/ fscanf : %d;%d;%d;%d;%d;%f;", dddd, mm, dd, hh, m, temperature);
    while (fgets(buffer, sizeof(buffer), f) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        buffer[strcspn(buffer, "\r")] = '\0';
        int dddd = 0, mm = 0, dd = 0, hh = 0, m = 0;
        float temperature = 0.0f;
        //     char *value = strtok(buffer, "; ");
        //     int i = 0;
        int parse = sscanf(buffer, "%d;%d;%d;%d;%d;%f",
                           &dddd, &mm, &dd, &hh, &m, &temperature);

        if (parse == 6)
        {
            // printf("addStatistic %d: %d;%d;%d;%d;%d;%.2f;\n", s, dddd, mm, dd, hh, m, temperature);
            addData(p, s, dddd, mm, dd, hh, m, temperature);
            // p[s].dddd = dddd;
            // p[s].mm = mm;
            // p[s].dd = dd;
            // p[s].hh = hh;
            // p[s].m = m;
            // p[s].temperature = temperature;
            s++;
        }
        else
        {
            fprintf(stderr, "Error: Invalid data format in string %d: %s\n", s, buffer);
            // fprintf(stderr, "parse %d: \n", parse);
        }
    }

    return s;
}

int deleteData(const Data *arr, int size)
{

    return 0;
}

int sortData(const Data *arr, int size)
{

    return 0;
}

int printData(const Data *p, int size, int mm)
{

    if (mm != 0 && mm < 13 && mm > 0)
    {
        printf("------------------------temperature statistics------------------------\n");

        printf("             month     Average        Minimum        Maximum \n");
        printf("      %10d    %10.2f    %10.2f    %10.2f\n", mm, temp_avg(p, size, mm), temp_min(p, size, mm), temp_max(p, size, mm));
        printf("======================================================================\n");
    }
    else if (mm < 13 && mm >= 0)
    {

        int i = 1;
        printf("------------------------temperature statistics------------------------\n");
        printf("             month     Average        Minimum        Maximum \n");

        while (i < 13)
        {

            printf("      %10d    %10.2f    %10.2f    %10.2f\n", i, temp_avg(p, size, i), temp_min(p, size, i), temp_max(p, size, i));
            // printf("Average temperature per month - %d: %.2f\n",i, temp_avg(p,size,i));
            // printf("Minimum temperature per month - %d: %.2f\n",i, temp_min(p,size,i));
            // printf("Maximum temperature per month - %d: %.2f\n",i, temp_max(p,size,i));
            // printf("-----------------------------------------\n");
            i++;
        }
        printf("======================================================================\n");
    };

    return 0;
}
