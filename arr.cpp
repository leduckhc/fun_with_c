
#include <iostream>
#include <stdio.h>
#include <string.h>

void pr(int A[], int sz)
{
    // int sz = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < sz; ++i)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void f(int a[])
{
    a[0] = 10;
    pr(a, 4);
}

int main()
{
    int A[] = {1, 2, 3, 4};
    pr(A, 4);

    f(A);
    pr(A, 4);

    std::cout << strlen("hello world") << "\n";

    return 0;
}
