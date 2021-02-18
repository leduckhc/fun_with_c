#include <stdio.h>
#include <math.h>

#define MAX 10000

int isTriangle(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a) // Triangle inequality
    {
        return 1;
    }
    return 0;
}

int intCmp(const int *aPtr, const int *bPtr)
{
    return (*bPtr < *aPtr) - (*aPtr < *bPtr);
}

int main(void)
{
    printf("Delky nosniku:\n");
    long long arr[MAX];
    for (int i = 0; i < MAX; i++)
        arr[i] = 0;
    long long num = 0; // delky nosniku
    int cnt = 0;       // pocet nostniku
    int err = 0;
    int triangleCnt = 0;

    // nacitani vstupu
    while ((err = scanf("%lld", &num)) == 1)
    {
        if (num <= 0)
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        arr[cnt] = num;

        cnt++;
        if (cnt >= MAX)
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
    }

    // input checks
    if (cnt < 3)
    {
        printf("Nespravny vstup.\n");
        return 1;
    }

    if (err != EOF)
    {
        printf("Nespravny vstup.\n");
        return 1;
    }

    // sort
    qsort(arr, cnt, sizeof(arr[0]),
          (int (*)(const void *, const void *))intCmp);

    for (int i = 0; i < cnt - 2; i++)
    {
        if (i > 0 && arr[i - 1] == arr[i])
        {
            continue;
        }

        // tohle je nove
        if (!isTriangle(arr[i], arr[i], arr[i]))
        {
            break;
        }
        // konec noveho

        for (int j = i + 1; j < cnt - 1; j++)
        {
            if (j > i + 1 && arr[j - 1] == arr[j])
            {
                continue;
            }

            // tohle je nove
            if (!isTriangle(arr[i], arr[j], arr[j]))
            {
                break;
            }
            // konec noveho

            for (int k = j + 1; k < cnt - 0; k++)
            {
                if (k > j + 1 && arr[k - 1] == arr[k])
                {
                    continue;
                }

                if (isTriangle(arr[i], arr[j], arr[k]))
                {
                    printf("%lld %lld %lld\n", arr[i], arr[j], arr[k]);
                    triangleCnt++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    printf("Trojuhelniku: %d\n", triangleCnt);
}
