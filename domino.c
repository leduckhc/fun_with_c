#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#endif /* __PROGTEST__ */

#define DEBUG 0

typedef struct domino
{
    char *text;
    int c1, c2, c3, c4;
} domino;

typedef enum state
{
    DOMINO_START, // until open bracket {
    TEXT,         //
    NUMBERS,      // strany domina // 4 cisla
    DOMINO_END,   // }
} state;

void sortTwo(int *a, int *b)
{
    // sort(1, 6) == (1, 6)
    // sort(6, 3) == (3, 6)
    if (*a > *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void readNum(const char *str1, int *index, int *num)
{
    int i = *index;
    int start, end;
    // char c = str1[i];

    // preskoc vsechny mezery,
    while (str1[i] == ' ' || str1[i] == '\t' || str1[i] == ';' || str1[i] == '[' || str1[i] == ']' || str1[i] == '|')
        i++;
    // cti cislo
    start = i;
    // c = str1[i];
    while (str1[i] == '-' || (str1[i] >= '0' && str1[i] <= '9'))
        i++;
    end = i;
    char *s_num = (char *)calloc(end - start + 1, sizeof(char));
    strncpy(s_num, &str1[start], end - start);
    int num1 = atoi(s_num);

    *index = i;
    *num = num1; // out
    free(s_num);
}

int parseDomino(const char *str1, int *index, domino *kostka)
{
    int i = *index;
    int sz = strlen(str1);

    state st = DOMINO_START;

    int start, end;
    int c1, c2, c3, c4;
    //char *text, *s_num, c;

    int is_done = 0;
    while (is_done == 0) // while not done
    {
        switch (st)
        {
        case DOMINO_START:
            while (str1[i] != '{' && i < sz)
                i++;

            if (i == sz)
            {
                if (DEBUG)
                    printf("ERROR %d!\n", DOMINO_START);
                return 0; // false
            }

            st = TEXT;
            break;
        case TEXT:
            // '
            while (str1[i] != '\'' && i < sz)
            {
                i++;
            }
            if (i == sz)
            {
                if (DEBUG)
                    printf("ERROR %d!\n", TEXT);
                return 0;
            }
            i++;
            start = i;

            while (str1[i] != '\'' && i < sz)
            {
                i++;
            }
            if (i == sz)
            {
                if (DEBUG)
                    printf("ERROR %d!\n", TEXT);
                return 0;
            }
            end = i;

            // obsah mezi uvozovkami
            kostka->text = (char *)calloc(end - start + 1, sizeof(char));
            strncpy(kostka->text, &str1[start], end - start);

            i++;
            st = NUMBERS;
            break;
        case NUMBERS:
            readNum(str1, &i, &c1);
            i++;
            readNum(str1, &i, &c2);
            i++;
            readNum(str1, &i, &c3);
            i++;
            readNum(str1, &i, &c4);
            i++;
            st = DOMINO_END;
            break;
        case DOMINO_END:
            while (str1[i] != '}' && i < sz)
                i++;
            if (i == sz)
            {
                if (DEBUG)
                    printf("ERROR %d!\n", DOMINO_END);
                return 0;
            }

            // [1 2|3 4]
            // [2 1|3 4] ==> [1 2|3 4]

            sortTwo(&c1, &c2); // 2 1 => 1 2
            sortTwo(&c3, &c4);

            // kostka->text = text;
            kostka->c1 = c1;
            kostka->c2 = c2;
            kostka->c3 = c3;
            kostka->c4 = c4;

            i++;
            is_done = 1; // end while()
            break;       // end switch

        default:
            break;
        }
    }

    *index = i;
    return 1;
}

void printDomino(domino *kostka)
{
    printf("%s: %d %d %d %d\n", kostka->text, kostka->c1, kostka->c2, kostka->c3, kostka->c4);
}

int countDomino(const char *list)
{
    size_t sz = strlen(list);
    int count_dom = 0;
    for (size_t i = 0; i < sz; i++)
    {
        if (list[i] == '}')
            count_dom++;
    }
    return count_dom;
}

int parseDominoList(const char *list, domino *domino_list)
{
    int count = 0;
    int index = 0; // index of input string
    int has_dom = 0;
    do
    {
        has_dom = parseDomino(list, &index, &domino_list[count]);
        if (has_dom)
        {
            if (DEBUG)
                printDomino(&domino_list[count]); //
            count++;
        }
        if (!has_dom)
        {
            if (DEBUG)
                printf("      error is ok and should end after this\n");
        }
    } while (has_dom);
    return count;
}

int countCollectible(const char *list)
{
    // 1. count number of domino by approximation
    // 2. parse all the domino pices
    // 3. count collectible

    // 1. count number of domino by counting number of openning brackets '{'
    int count_dom = countDomino(list);

    // 2. parse all the domino pieces
    domino *domino_list = (domino *)calloc(count_dom, sizeof(domino));
    count_dom = parseDominoList(list, domino_list);

    // 3. count collectible
    if (count_dom == 0)
        return 0;

    int count_collectibel = 0;
    for (int i = 0; i < count_dom; i++)
    {
        domino *a = &domino_list[i];
        if (strcmp(a->text, "Segfault Extreme") == 0)
        {
            // Exactly one side has sum == 65
            if (((a->c1 + a->c2 == 65) && (a->c3 + a->c4 != 65)) ||
                ((a->c1 + a->c2 != 65) && (a->c3 + a->c4 == 65)))
            {
                count_collectibel++;
            }
        }
    }

    // free memory
    for (int i = 0; i < count_dom; i++)
    {
        free(domino_list[i].text);
    }
    free(domino_list);

    if (DEBUG)
        printf("%d\n", count_collectibel);
    return count_collectibel; /* TODO */
}

int countUnique(const char *list)
{
    // 1. count number of domino
    // 2. parse all the domino pices
    // 3. filter unique

    // 1. count number of domino by counting number of openning brackets '{'
    int count_dom = countDomino(list);

    // 2. parse all the domino pieces
    domino *domino_list = (domino *)calloc(count_dom, sizeof(domino));
    count_dom = parseDominoList(list, domino_list);

    // 3. filter unique
    if (count_dom == 0)
        return 0;

    int n_unique = 1; // ten prvni je urcite sam se sebou unikatni
    for (int i = 1; i < count_dom; i++)
    {
        int is_dup = 0; // false
        for (int j = 0; j < i; j++)
        {
            domino *a = &domino_list[i];
            domino *b = &domino_list[j];
            if (strcmp(a->text, b->text) == 0) // are the same
            {

                // strany domina jsou usporadana podle velikosti
                if (
                    (a->c1 == b->c1 && a->c2 == b->c2     // prvni strana je stejna // a=[1 2 | 3 4]
                     && a->c3 == b->c3 && a->c4 == b->c4) // druha strana je stejna // b=[1 2 | 3 4]
                    ||
                    (a->c1 == b->c3 && a->c2 == b->c4      // prvni strana je stejna jako druha // a=[1 2 | 3 4]
                     && a->c3 == b->c1 && a->c4 == b->c2)) // druha strana je stejna jako prvni // b=[3 4 | 1 2]
                {
                    is_dup = 1;
                    break;
                }
            }
        }
        if (is_dup == 0) // false == not duplicate
            n_unique++;
    }

    for (int i = 0; i < count_dom; i++)
    {
        free(domino_list[i].text);
    }
    free(domino_list);
    return n_unique; /* TODO */
}

uint64_t countTowers(const char *list)
{
    return 0; /* TODO */
}

#ifndef __PROGTEST__

int main(void)
{
    const char *str1 =
        " { 'Progtest Exam' ; [  1 | 2 ] ; [3   | 4 ] }{'PA1 2020/2021';[2|2];[3|1]}\n"
        "{'Progtest Exam' ; [ 2 | 1 ] ; [ 3 | 4 ] }\n"
        "{'Progtest Exam' ; [ 2 | 3 ] ; [ 1 | 4 ] }\n";
    const char *str2 =
        "{'Crash';  [1|2];[3|4]}\n"
        "{'MemLeak';[1|2];[3|4]}\n"
        "{'MemLeak';[2|3];[3|1]}\n"
        "{'MemLeak';[1|3];[3|2]}\n"
        "{'MemLeak';[1|4];[1|5]}\n"
        "{'MemLeak';[4|1];[1|5]}\n"
        "{'MemLeak';[4|1];[5|1]}\n"
        "{'MemLeak';[1|4];[5|1]}\n"
        "{'MemLeak';[1|5];[1|4]}\n"
        "{'MemLeak';[5|1];[1|4]}\n"
        "{'MemLeak';[5|1];[4|1]}\n"
        "{'MemLeak';[1|5];[4|1]}\n";
    const char *str3 =
        "{'-Wall -pedantic -Werror -Wno-long-long -O2';[2|2];[3|3]}\n"
        "{'-Wall -pedantic -Werror -Wno-long-long -O2';[4|4];[5|5]}\n"
        "{'-Wall -pedantic -Werror -Wno-long-long -O2';[3|4];[4|5]}\n";
    const char *str4 =
        "{'-fsanitize=address -g';[1|5];[5|7]}\n"
        "{'-fsanitize=address -g';[3|7];[1|9]}\n"
        "{'-fsanitize=address -g';[2|2];[4|7]}\n"
        "{'-fsanitize=address -g';[3|9];[2|6]}\n"
        "{'-fsanitize=address -g';[2|2];[2|2]}\n";

    assert(countCollectible(str1) == 0);
    assert(countUnique(str1) == 3);
    assert(countUnique(str2) == 4);
    assert(countUnique(str3) == 3);
    assert(countUnique(str4) == 5);
    assert(countCollectible(str5) == 28);
    // assert(countTowers(str3) == 10);
    // assert(countTowers(str4) == 114);

    return 0;
}
#endif /* __PROGTEST__ */
