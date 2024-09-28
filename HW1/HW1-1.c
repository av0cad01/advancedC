#include <stdio.h>

int MaxQuantity(void);

int main(void) {
    printf("%d", MaxQuantity());
    return 0;
}

int MaxQuantity(void) {
    int length = 0;

    int num, max;
    int quantity = 0;

    printf("Введите длину последовательности и саму последовательность:");
    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        if (!i) {
            scanf("%d", &num);
            max = num;
            quantity += 1;
        } else {
            scanf("%d", &num);
            if (num > max) {
                max = num;
                quantity = 1;
            } else  if (num == max) {
                quantity += 1;
            }
        }
    }
    return quantity;
}