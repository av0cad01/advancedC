#include <stdio.h>

#define K   32
int ShiftNumber(unsigned int number, unsigned int shift);

int main(void) 
{
    unsigned int number;
    unsigned int shift;
    printf("Введите число и сдвиг:");
    scanf("%d%d", &number, &shift);
    printf("%d\n", ShiftNumber(number, shift));
    return 0;
}

int ShiftNumber(unsigned int number, unsigned int shift)
{
    return ((number >> shift) | (number << (K - shift)));
}