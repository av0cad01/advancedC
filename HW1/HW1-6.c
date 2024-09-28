#include <stdio.h>

#define BITPLACE    32-1
#define MASK        0b1

int BitwiseSum(int number);

int main(void) 
{
    int number;
    printf("Введите число для подсчета единичных бит:");
    scanf("%d", &number);
    printf("%d\n", BitwiseSum(number));
    return 0;
}

int BitwiseSum(int number)
{
    int sum = 0;
    for (int i = 0; i < BITPLACE; i++)
    {
        if (number & MASK)
            sum++;
        number = number >> 1;
    }
    return sum;
}