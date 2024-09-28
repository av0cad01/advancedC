#include <stdio.h>

int MaskNumber(unsigned int number, unsigned int bitRange);
int pow2(unsigned int number);

int main(void) 
{
    unsigned int number;
    unsigned int bitRange;
    printf("Введите число и количество младших бит:");
    scanf("%d%d", &number, &bitRange);
    printf("%d\n", MaskNumber(number, bitRange));
    return 0;
}

int MaskNumber(unsigned int number, unsigned int bitRange)
{
    int mask = pow2(bitRange) - 1;
    printf("%d\n", mask);
    return (number & mask);
}

//Возведение в степень по основанию 2
int pow2(unsigned int number)
{
    int base = 1;
    base = base << number;
    return base;
}