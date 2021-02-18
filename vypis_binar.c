

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int max(int a, int b)
{
    if (a < b)
        return b;

    return a;
}

unsigned long long total = 0;

void vypis(char *output, int len, int n, int k, int zeros, int ones)
{
    if (len > 0 && zeros <= k && ones <= k)
    {
        total++;
        // for (int i = 0; i < len; i++)
        // printf("%c", output[i]);
        printf("%s\n", output);
    }

    if (len == n || (zeros == k && ones == k))
    {
        // output[len - 1] = '\0';
        return;
    }

    char last_char, cur_char;
    cur_char = output[len - 1];
    if (len > 1)
        last_char = output[len - 2];
    else
        last_char = output[0];

    if (cur_char == '0')
        zeros++;
    if (cur_char == '1')
        ones++;

    if (cur_char != last_char)
    {
        if (last_char == '0')
            zeros = 0;
        if (last_char == '1')
            ones = 0;
    }

    if (ones + 1 <= k) // pridavat nuly
    {
        output[len] = '1';
        vypis(output, len + 1, n, k, zeros, ones);
        output[len] = '\0';
    }

    if (len > 0 && zeros + 1 <= k) // pridavat nuly // nulou nesmi zacinat
    {
        output[len] = '0';
        vypis(output, len + 1, n, k, zeros, ones);
        output[len] = '\0';
    }
}

void assert_basic()
{
    int n = 0, k = 0;

    char *output = (char *)calloc(20, sizeof(char));

    n = 4;
    k = 2;
    total = 0;
    output[0] = '1';
    vypis(output, 0, n, k, 0, 0);
    // printf("total=%d\n", total);
    assert(total == 11);

    n = 5;
    k = 1;
    total = 0;
    output[0] = '1';
    vypis(output, 1, n, k, 0, 0);
    // printf("total=%d\n", total);
    assert(total == 5);

    n = 12;
    k = 6;
    total = 0;
    output[0] = '1';
    vypis(output, 1, n, k, 0, 0);
    // printf("total=%d\n", total);
    assert(total == 3903);
}

int main()
{
    // NACITANI ZADANI
    int n = 0, k = 0;
    int stav = scanf("%d\n%d", &n, &k);
    if (stav != 2)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }

    char *output = (char *)calloc(n + 1, sizeof(char));

    if (n <= 0 || n > 64 || k <= 0)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }

    total = 0;
    output[0] = '1';
    vypis(output, 1, n, k, 0, 0);
    printf("Celkem: %llu\n", total);

    free(output);
    return 0;
}
