#include <stdio.h>
#include "temp_api.h"





int main(int argc, char **argv)
{
    
    Data p[3]={
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };

    avg(* p);

    return 0;
}