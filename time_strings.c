#include <time.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h> // pulls in declaration of malloc, free
#include <memory.h>

#define COUNT 100000

typedef struct string
{
    size_t len, max;
    char *buf;
} string;

string *init_string()
{
    string *str = malloc(sizeof(string));
    str->len = 0;
    str->max = 1000;
    str->buf = (char *)calloc(str->max, sizeof(char));
}

void mystrcat(string *dest, char *src)
{
    size_t new_size = dest->len + strlen(src);
    if (new_size > dest->max)
    {
        reallocate(dest, new_size);
    }
    strcpy(str->buf + str->len, src);
}

void a(char *first, char *second, char *both)
{
    for (int i = 0; i != COUNT; i++)
    {
        strcat(both, first);
        strcat(both, " ");
        strcat(both, second);
    }
}

void b(char *first, char *second, char *both)
{
    for (int i = 0; i != COUNT; i++)
        sprintf(both, "%s %s", first, second);
}

int main(void)
{
    char *first = "First";
    char *second = "Second";
    size_t size = (strlen(first) + strlen(second) + 2) * (COUNT + 10);
    char *both = (char *)calloc(size, sizeof(char));
    clock_t start;

    start = clock();
    a(first, second, both);
    printf("strcat      = %f seconds\n", (float)(clock() - start) / CLOCKS_PER_SEC);
    printf("%s", both);

    start = clock();
    b(first, second, both);
    printf("sprintf     = %f seconds\n", (float)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}