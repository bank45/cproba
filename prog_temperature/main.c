#include <stdio.h>
#include "temp_api.h"


int main(int argc, char *argv[])
{
    Data p[365]={0};
    int mm = 0;
    char fileName[255] = "";
    if (argc == 1)
        printf("help\n");

    for (int i = 0; i < argc; i++)
    {
        char *str = argv[i];
        if (str[0] == '-')
            switch (str[1])
            {
            case 'h':
                printf("HELP\n");
                break;
            case 'f':
                sscanf(argv[i + 1], "%s", &fileName);
                printf("%s \n", fileName);
                break;
            case 'm':
                sscanf(argv[i + 1], "%d", &mm);
                break;
            default:
                break;
            }
    }


    addStatistic(p);

    int size = sizeof(p) / sizeof(p[0]);
    printData(p, size, mm);


    return 0;
}