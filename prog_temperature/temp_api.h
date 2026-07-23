#ifndef TEMP_API_H
#define TEMP_API_H

typedef struct stack
{
    int dddd, mm, dd, hh, m;
    float temperature;
    struct stack *next;
} stack;

float temp_avg(const stack *head, int mm);
float temp_min(const stack *head, int mm);
float temp_max(const stack *head, int mm);

int compareData(const void *a, const void *b);
int sortData(stack **head);

int printReport(const stack *p, int mm, FILE *fout);
int printStack(const stack *p);

int addStatisticTest(stack **head);
int addStatistic(stack **head, FILE *f);
int addData(stack **head, int dddd, int mm, int dd, int hh, int m, float temperature);

int saveRecordsToBinary(stack **head, const char *fileName);
int loadRecordsFromBinary(stack **head, const char *fileName);
int deleteData(stack **head, int index_to_delete);


void push(struct stack **head, int dddd, int mm, int dd, int hh, int m, float temperature);
#endif