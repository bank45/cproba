#include <stdio.h>
#include "temp_api.h"
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

stack *p = NULL;
int records = 0;

int main(int argc, char *argv[])
{
    // setlocale(LC_ALL, "Russian");
    // SetConsoleCP(65001);
    // SetConsoleOutputCP(65001);
    system("chcp 65001 > nul");
    int size = 600000;
    // p = (stack *)malloc(size * sizeof(stack));

    FILE *f = NULL, *fout = NULL;
    int mm = 0;
    char fileName[255] = "";
    char baseFileName[255] = "base.dat";

    if (argc == 1)
    {
        printf("******* Console application - Temperature statistics *******\n");
        printf("For instructions, run the program with the '-h' switch.\n");
    }

    for (int i = 0; i < argc; i++)
    {
        char *str = argv[i];
        if (str[0] == '-')
            switch (str[1])
            {
            case 'h':
                printf("Usage: prog [options] [target] ...\n");
                printf("Options:\n");
                printf("-m:                       Month number for displaying statistics\n");
                printf("-f:                       Name of the CSV file for loading data\n");
                printf("-l:                       Loading previously saved data from a binary file\n");
                printf("-h:                       HELP\n");
                printf("-t:                       Demonstration of test data\n");
                printf("-e:                       Editing and printing a list of structures\n");
                return 0;
                break;
            case 'f':
                sscanf(argv[i + 1], "%s", &fileName);
                f = fopen(fileName, "r");
                if (f == NULL)
                {
                    perror("Ошибка открытия файла");
                    return 1;
                }

                printf("file name: %s \n", fileName);
                records = addStatistic(&p, f);
                printf("records: %d\n", records);

                int written = saveRecordsToBinary(&p, baseFileName);
                if (written == -1)
                {
                    printf("Ошибка: неверные аргументы функции (NULL)\n");
                }
                else if (written == 1)
                {

                    printf("Ошибка: не удалось открыть файл для записи\n");
                }
                else if (written == 0)
                {
                    printf("Стек успешно сохранен в бинарный файл\n");
                }

                break;
            case 'm':
                sscanf(argv[i + 1], "%d", &mm);
                records = loadRecordsFromBinary(&p, baseFileName);
                printf("loaded from a binery file %s: %d\n", baseFileName, records);
                // printStack(p);

                break;
            case 't':
                records = addStatisticTest(&p);
                break;
            case 'l':
                records = loadRecordsFromBinary(&p, baseFileName);
                printf("loaded from a binery file %s: %d\n", baseFileName, records);
                break;
            case 'e':
            {
                records = loadRecordsFromBinary(&p, baseFileName);
                printf("loaded from a binery file %s: %d\n", baseFileName, records);
                sortData(&p);
                printStack(p);

                int index_to_delete = 0;
                printf("Enter the index of the line you want to delete: ");

                if (scanf("%d", &index_to_delete) == 1)
                {

                    if (deleteData(&p, index_to_delete) == 0)
                    {
                        printf(RED "delete records: %d \n", records);

                        sortData(&p);

                        int written = saveRecordsToBinary(&p, baseFileName);
                        printf("written to a binery file %s: %d\n", baseFileName, written);

                        printStack(p);
                        if (f != NULL)
                            fclose(f);
                        if (fout != NULL)
                            fclose(fout);
                        free(p);
                        return 0;
                    }
                    else
                    {
                        printf(RED "Error: Failed to delete record (index out of bounds).\n" RESET);
                    }
                }
                else
                {

                    printf(RED "input error! \n" RESET);
                }
                break;
            }
            default:

                break;
            }
    }

    fout = fopen("report.txt", "w");
    if (!fout)
        return 1;
    if (records > 0)
    {
        printReport(p, mm, fout);

        char fullPath[255];
        if (GetFullPathNameA("report.txt", MAX_PATH, fullPath, NULL))
        {
            printf(BLUE "Open report file: \033]8;;file:///%s\033\\%s\033]8;;\033\\\n", fullPath, fullPath);
        }
        else
        {

            printf(BLUE "Open file: report.txt\n");
        }
        printf(RESET "\n");
    }

    fclose(f);
    fclose(fout);
    free(p);
    return 0;
}