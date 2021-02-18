
#include <string>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define HEX(x) setw(2) << setfill('0') << "0x" << hex << uppercase << (int)(x)

int main()
{
    unsigned char uc = 'A';
    printf("0x%x\n", uc);
    // memcpy()
    return 0;
}
