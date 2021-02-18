#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[20] = "C programming";
    char *str2 = (char *)calloc(10000000, sizeof(char));

    // copying str1 to str2
    size_t index = 0;
    size_t len = strlen(str1);
    for (int i = 0; i < 100000; i++)
    {
        strcat(str2 + index, str1);
        index += len;
    }

    //puts(str2); // C programming

    return 0;
}