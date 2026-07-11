#include <stdio.h>
#include "temp_api.h"
#include <stdlib.h>

Data *p = NULL;

int main(int argc, char *argv[])
{
    size_t size = 600000;
    p = (Data *)malloc(size * sizeof(Data));
    int records = 0;
    FILE *f, *fout;
    int mm = 0;
    char fileName[255] = "";

    if (argc == 1)
    {
        records = addStatisticTest(p);
        // int size = sizeof(p) / sizeof(p[0]);
        // printData(p, records, mm);
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
                printf("-f:                       Data file name\n");
                printf("-h:                       HELP\n");
                break;
            case 'f':
                sscanf(argv[i + 1], "%s", &fileName);
                f = fopen(fileName, "r");
                if (f == NULL)
                {
                    perror("Ошибка открытия файла");
                    return 1;
                }

                records = addStatistic(p, f);
                int size = sizeof(p) / sizeof(p[0]);

                // printData(p, records, mm);
                // printf("records: %d\n", records);
                fout = fopen("report.txt", "w");
                // printf("%s \n", fileName);
                break;
            case 'm':
                sscanf(argv[i + 1], "%d", &mm);

                // records = addStatistic(p, f);
                // printData(p, records, mm);
                break;
            default:

                break;
            }
        if (fileName[0] == '\0' && mm < 13 && mm > 0)
        {
            records = addStatisticTest(p);
        }
    }
    printf("records: %d\n", records);
    printData(p, records, mm);
    fclose(f);
    fclose(fout);
    free(p);
    return 0;
}