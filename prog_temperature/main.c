#include <stdio.h>
#include "temp_api.h"

static Data p[16] = {
    {2021,01,16,01,01,-47},
    {2021,01,16,01,03,-44},
    {2021,01,16,01,04,-43},
    {2021,01,16,01,05,-10},
    {2021,02,16,01,01,-25},
    {2021,02,17,01,01,-30},
    {2021,03,16,01,01,-10},
    {2021,04,16,01,01,0},
    {2021,05,16,01,01,10},
    {2021,06,16,01,01,25},
    {2021,07,16,01,01,30},
    {2021,8,16,01,01,20},
    {2021,9,16,01,01,18},
    {2021,10,16,01,01,2},
    {2021,11,16,01,01,-5},
    {2021,12,16,01,01,-20}
};

int main(int argc, char *argv[])
{


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
                // printf("%d \n", mm);
                break;
            default:
                break;
            }
    }

    int size = sizeof(p) / sizeof(p[0]);

    // float res = temp_avg(p,size,mm);
    if(mm!=0)
    {
    printf("Average temperature per month - %d: %.2f\n",mm, temp_avg(p,size,mm));
    printf("Minimum temperature per month - %d: %.2f\n",mm, temp_min(p,size,mm));
    printf("Maximum temperature per month - %d: %.2f\n",mm, temp_max(p,size,mm));  

    }else{
        int i = 1;
        while(i<13)
        {
            printf("Average temperature per month - %d: %.2f\n",i, temp_avg(p,size,i));
            printf("Minimum temperature per month - %d: %.2f\n",i, temp_min(p,size,i));
            printf("Maximum temperature per month - %d: %.2f\n",i, temp_max(p,size,i));  
            printf("-----------------------------------------\n");  
            i++;
        }
    }

    // printf("avg: %.2f ", res);


    return 0;
}