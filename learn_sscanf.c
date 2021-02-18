#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>

int main()
{
    const char *str1 =
        " { 'Progtest Exam' ; [ 1 | 2 ] ; [ 3 | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
        "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
        "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n";

    // const char *str2 = "[ 1 | 2 ] ; [ 3 | 4 ] \n";
    const char *str2 = "-1323  ]2[ ]  ";

    int c1, c2, c3, c4;
    int bytes = sscanf(str2, "%d"  , &c1);
    
    printf("%d\n", bytes);
    printf("%d\n", c1);

    return 0;
}