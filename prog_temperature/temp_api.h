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
float temp_min(const Data *arr_temp, int size, int mm);
float temp_max(const Data *arr_temp, int size, int mm);

int compareData(const void *a, const void *b);
int sortData(Data *arr, int size);

int printReport(const Data *p, int size, int mm,FILE* fout);
int printArray(const Data *p, int size);
int addStatisticTest( Data *p);
int addStatistic(Data *p, FILE* f);
int saveRecordsToBinary(const Data *arr, int size, const char *fileName);
int loadRecordsFromBinary(Data **arr, int *max_size, const char *fileName);
int deleteData( Data *arr, int *size, int index_to_delete);
#endif