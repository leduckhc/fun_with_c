#include "common.h"

#include <stdio.h>
#include <stdlib.h>

void linearSearch(int arr[], int n_arr, int query)
{
  for (int i = 0; i < n_arr; i++) {
    if (query == arr[i]) printf("found %d", arr[i]);
  }
}

/**
 * This is just for fun. And it works.
 **/
int main(int argc, char **argv)
{
  int a     = 42;
  int *piA  = NULL;
  piA       = &a;
  int arr[] = {3, 4, 7, 8, 5};

  printf("a = %d, piA = %p\n", a, piA);

  if (a == 42) printf("This is cool\n");

  // print_numbers();
  linearSearch(arr, 5, 8);

  printf("\n");
  return 0;
}
