#include <stdio.h>
#include "temp_api.h"
#include <stdlib.h>
#include <windows.h>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

stack *p = NULL;
int records = 0;


int main(int argc, char *argv[])
{
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
                printf("-b:                       Loading previously saved data from a binary file\n");
                printf("-h:                       HELP\n");
                printf("-t:                       Demonstration of test data\n");
                printf("-s:                       Printing a Array\n");
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

                int written = saveRecordsToBinary(p, records, baseFileName);

                printf("written to a binery file %s: %d\n", baseFileName, written);

                break;
            case 'm':
                sscanf(argv[i + 1], "%d", &mm);
                break;
            case 't':
                records = addStatisticTest(&p);
                break;
            case 'b':
                records = loadRecordsFromBinary(&p, &size, baseFileName);
                printf("loaded from a binery file %s: %d\n", baseFileName, records);
                break;
            case 's':
            {
                records = loadRecordsFromBinary(&p, &size, baseFileName);
                printf("loaded from a binery file %s: %d\n", baseFileName, records);
                sortData(p, records);
                printArray(p, records);

                int index_to_delete = 0;
                printf("Enter the index of the line you want to delete: ");

                if (scanf("%d", &index_to_delete) == 1)
                {

                    if (deleteData(p, &records, index_to_delete) == 0)
                    {
                        printf(RED "delete records: %d \n", records);

                        sortData(p, records);

                        int written = saveRecordsToBinary(p, records, baseFileName);
                        printf("written to a binery file %s: %d\n", baseFileName, written);

                        printArray(p, records);
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