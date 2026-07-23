#include <stdio.h>
#include "temp_api.h"
// #include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stddef.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void push(struct stack **head, int dddd, int mm, int dd, int hh, int m, float temperature)
{
    stack *newNode = malloc(sizeof(stack));

    newNode->dddd = dddd;
    newNode->mm = mm;
    newNode->dd = dd;
    newNode->hh = hh;
    newNode->m = m;
    newNode->temperature = temperature;

    newNode->next = *head;
    *head = newNode;
}

float temp_avg(const stack *head, int mm)
{

    if (mm < 1 || mm > 12)
        return 0.0f;

    float sum = 0.0f;
    int count = 0;
    const stack *current = head;

    while (current != NULL)
    {
        if (current->mm == mm)
        {
            sum += current->temperature;
            count++;
        }
        current = current->next;
    }

    return count > 0 ? sum / count : 0.0f;
}

float temp_min(const stack *head, int mm)
{
    if (mm < 1 || mm > 12)
        return 0.0f;

    float min_val = 100.0f;
    int found = 0;
    const stack *current = head;

    while (current != NULL)
    {
        if (current->mm == mm)
        {
            if (!found || current->temperature < min_val)
            {
                min_val = current->temperature;
                found = 1;
            }
        }
        current = current->next;
    }

    return found ? min_val : 0.0f;
}

float temp_max(const stack *head, int mm)
{
    if (mm < 1 || mm > 12)
        return 0.0f;

    float max_val = -100;
    int found = 0;
    const stack *current = head;

    while (current != NULL)
    {

        if (current->mm == mm)
        {
            if (!found || current->temperature > max_val)
            {
                max_val = current->temperature;
                found = 1;
            }
        }
        current = current->next;
    }

    return found ? max_val : 0.0f;
}

int addData(stack **head, int dddd, int mm, int dd, int hh, int m, float temperature)
{
    push(head, dddd, mm, dd, hh, m, temperature);
    return 0;
}

int addStatisticTest(stack **head)
{

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

    for (int j = 0; i < 16; j++)
    {

        addData(head, arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], arr[i][5]);

        i++;
    }

    return i;
}

int addStatistic(stack **head, FILE *f)
{
    char buffer[1024];
    int s = 0;

    while (fgets(buffer, sizeof(buffer), f) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        buffer[strcspn(buffer, "\r")] = '\0';
        int dddd = 0, mm = 0, dd = 0, hh = 0, m = 0;
        float temperature = 0.0f;

        int parse = sscanf(buffer, "%d;%d;%d;%d;%d;%f",
                           &dddd, &mm, &dd, &hh, &m, &temperature);

        if (parse == 6)
        {
            addData(head, dddd, mm, dd, hh, m, temperature);
            s++;
        }
        else
        {
            fprintf(stderr, "\033[1;31mError: Invalid data format in string %d: %s\033[0m\n", s, buffer);
        }
    }

    return s;
}



int deleteData(stack **head, int index_to_delete)
{
    if (head == NULL || *head == NULL || index_to_delete < 0)
    {
        return -1; // Стек пуст или неверный индекс
    }

    stack *temp = *head;

    if (index_to_delete == 0)
    {
        *head = (*head)->next; 
        free(temp);           
        return 0;
    }

    stack *prev = NULL;

    for (int i = 0; temp != NULL && i < index_to_delete; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        fprintf(stderr, "Ошибка: Индекс %d вне границ списка\n", index_to_delete);
        return -1;
    }

    prev->next = temp->next;
    free(temp);

    return 0;
}


int compareData(const void *a, const void *b)
{
    const stack *da = *(const stack **)a;
    const stack *db = *(const stack **)b;
    if (da->dddd != db->dddd)
        return da->dddd - db->dddd;
    if (da->mm != db->mm)
        return da->mm - db->mm;
    if (da->dd != db->dd)
        return da->dd - db->dd;
    if (da->hh != db->hh)
        return da->hh - db->hh;
    if (da->m != db->m)
        return da->m - db->m;
    return 0;
}

int countElements(stack *head)
{
    int count = 0;
    stack *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int sortData(stack **head)
{
    if (head == NULL || *head == NULL)
        return -1;

    int size = countElements(*head);
    if (size <= 1)
        return 0; 

    stack **arr = (stack **)malloc(size * sizeof(stack *));
    if (arr == NULL)
        return -1;

    stack *current = *head;
    for (int i = 0; i < size; i++)
    {
        arr[i] = current;
        current = current->next; 
    }

    qsort(arr, size, sizeof(stack *), compareData);

    for (int i = 0; i < size - 1; i++)
    {
        arr[i]->next = arr[i + 1];
    }
    arr[size - 1]->next = NULL; 

    *head = arr[0];

    free(arr);

    return 0;
}

int printReport(const stack *p, int mm, FILE *fout)
{

    printf(GREEN "------------------------temperature statistics------------------------\n");
    printf("             month     Average        Minimum        Maximum \n");
    printf("----------------------------------------------------------------------\n");

    if (fout)
    {
        fprintf(fout, "------------------------temperature statistics------------------------\n");
        fprintf(fout, "             month     Average        Minimum        Maximum \n");
        fprintf(fout, "----------------------------------------------------------------------\n");
    }

    if (mm >= 1 && mm <= 12)
    {

        float avg = temp_avg(p, mm);
        float min = temp_min(p, mm);
        float max = temp_max(p, mm);

        int has_data = 0;
        const stack *curr = p;
        while (curr != NULL)
        {
            if (curr->mm == mm)
            {
                has_data = 1;
                break;
            }
            curr = curr->next;
        }

        if (has_data)
        {
            printf("      %10d    %10.2f    %10.2f    %10.2f\n", mm, avg, min, max);
            if (fout)
            {
                fprintf(fout, "      %10d    %10.2f    %10.2f    %10.2f\n", mm, avg, min, max);
            }
        }
        else
        {
            printf("      %10d    -    -    -\n", mm);
            if (fout)
            {
                fprintf(fout, "      %10d    -    -    -\n", mm);
            }
        }
    }
    else
    {

        float year_sum = 0.0f;
        int year_total_count = 0;

        float year_min_val = 0.0f;
        float year_max_val = 0.0f;
        int first_year_found = 1;

        for (int i = 1; i <= 12; i++)
        {

            float avg = temp_avg(p, i);
            float min = temp_min(p, i);
            float max = temp_max(p, i);

            int month_count = 0;
            float month_sum = 0.0f;

            const stack *current = p;
            while (current != NULL)
            {
                if (current->mm == i)
                {
                    month_sum += current->temperature;
                    month_count++;
                }
                current = current->next;
            }

            if (month_count > 0)
            {
                printf("      %10d    %10.2f    %10.2f    %10.2f\n", i, avg, min, max);
                if (fout)
                {
                    fprintf(fout, "      %10d    %10.2f    %10.2f    %10.2f\n", i, avg, min, max);
                }

                year_sum += month_sum;
                year_total_count += month_count;

                if (first_year_found)
                {
                    year_min_val = min;
                    year_max_val = max;
                    first_year_found = 0;
                }
                else
                {
                    if (min < year_min_val)
                        year_min_val = min;
                    if (max > year_max_val)
                        year_max_val = max;
                }
            }
            else
            {

                printf("      %10d            -            -            -\n", i);
                if (fout)
                {
                    fprintf(fout, "      %10d            -            -            -\n", i);
                }
            }
        }

        printf("----------------------------------------------------------------------\n");
        if (fout)
        {
            fprintf(fout, "----------------------------------------------------------------------\n");
        }

        if (year_total_count > 0)
        {
            float year_avg_val = year_sum / year_total_count;

            printf("            Year    %10.2f    %10.2f    %10.2f\n", year_avg_val, year_min_val, year_max_val);
            if (fout)
            {
                fprintf(fout, "            Year    %10.2f    %10.2f    %10.2f\n", year_avg_val, year_min_val, year_max_val);
            }
        }
        else
        {
            printf("            Year            -            -            -\n");
            if (fout)
            {
                fprintf(fout, "            Year            -            -            -\n");
            }
        }
    }

    printf("----------------------------------------------------------------------" RESET "\n");
    if (fout)
    {
        fprintf(fout, "----------------------------------------------------------------------\n");
    }

    return 0;
}

int saveRecordsToBinary(stack **head, const char *fileName)
{
    if (head == NULL || *head == NULL)
    {
        return 0; 
    }

    FILE *file = fopen(fileName, "wb"); 
    if (file == NULL)
    {
        return 1;
    }

    stack *current = *head; 

    while (current != NULL)
    {

        fwrite(&(current->dddd), sizeof(int), 5, file);

        fwrite(&(current->temperature), sizeof(float), 1, file);

        current = current->next; 
    }

    fclose(file);
    return 0; 
}

int loadRecordsFromBinary(stack **head, const char *fileName)
{
    FILE *file = fopen(fileName, "rb"); 
    if (file == NULL)
    {
        return 0; 
    }

    *head = NULL;
    stack *tail = NULL; 

    while (1)
    {

        stack *new_node = (stack *)malloc(sizeof(stack));
        if (new_node == NULL)
        {
            fclose(file);
            return 0; 
        }

        if (fread(&(new_node->dddd), sizeof(int), 5, file) != 5)
        {
            free(new_node); 
            break;
        }

        if (fread(&(new_node->temperature), sizeof(float), 1, file) != 1)
        {
            free(new_node);
            break;
        }

        new_node->next = NULL; 

        // Формируем список
        if (*head == NULL)
        {
            *head = new_node; 
            tail = new_node;
        }
        else
        {
            tail->next = new_node; 
            tail = new_node;    
        }
    }

    fclose(file);
    int size = countElements(*head);

    return size; 
}

int printStack(const stack *p)
{

    if (p == NULL)
    {
        printf("Стек абсолютно пуст (NULL).\n");
        return 0;
    }

    int index = 0;
    const stack *current = p;

    printf("--- НАЧАЛО ТЕСТОВОГО ВЫВОДА ---\n");
    while (current != NULL)
    {
        printf(GREEN "index: %5d | Год: %5d, Месяц: %5d, День: %5d, Час: %5d, Мин: %5d, Темп: %6.2f | Next: %p\n",
               index, current->dddd, current->mm, current->dd, current->hh, current->m, current->temperature, (void *)current->next);
        printf(RESET);

        index++;

        if (index > 20)
        {
            printf("Защита: выведено больше 20 элементов.\n");
            break;
        }

        current = current->next;
    }
    printf("--- КОНЕЦ ВЫВОДА. Всего напечатано строк: %d ---\n", index);
    return 0;
}
