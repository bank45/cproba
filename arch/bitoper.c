#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{

    uint32_t arr[1] = {3};

    int i = 0;
    while (arr[i] != 0)
    {
        printf("i:%d size: %u arr[i]: %x\n", i, sizeof(arr[i]),arr[i]);
        i++;
    }

    return 0;
}