#include <stdio.h>

#define K   26

void CeaserFont(void);

int main(void) 
{
    CeaserFont();
    return 0;
}

void CeaserFont(void)
{
    int shift = 0;
    char n = 0;
    printf("Введите сдвиг и текст для шифрования:");
    scanf("%d", &shift);
    while ((n = getchar()) != '.') {
        if (n >= 'a' && n <= 'z')
            putchar(((n - 'a' + shift) % K) + 'a');
        else if (n >= 'A' && n <= 'Z')
            putchar(((n - 'A' + shift) % K) + 'A');
        else
            putchar(n);
    }
    putchar('.');
}