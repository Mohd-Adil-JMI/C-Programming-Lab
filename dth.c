#include <stdio.h>
#include <stdlib.h>
void dectohex();
void hextodec();
int power(int a, int b);

int main()
{
    while (1)
    {
        int ch;
        printf("Enter 1 for Decimal to Hexadecimal Conversion\n");
        printf("Enter 2 for Hexadecimal to Decimal Conversion\n");
        printf("Enter 3 to Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            dectohex();
            break;
        case 2:
            hextodec();
            break;
        case 3:
            printf("Exiting\n");
            exit(0);
        }
    }

    return 0;
}

int power(int a, int b)
{
    int pow = 1;
    for (int i = 1; i <= b; i++)
    {
        pow = pow * a;
    }
    return pow;
}

void dectohex()
{
    int decimalNum, remainder, i = 0;
    char hexnum[20];
    printf("Enter any decimal number: ");
    scanf("%d", &decimalNum);
    while (decimalNum != 0)
    {
        remainder = decimalNum % 16;
        if (remainder < 10)
            remainder = remainder + 48;
        else
            remainder = remainder + 55;
        hexnum[i] = remainder;
        i++;
        decimalNum = decimalNum / 16;
    }
    printf("\nEquivalent Value in Hexadecimal = ");
    for (i = i - 1; i >= 0; i--)
        printf("%c", hexnum[i]);
    printf("\n");
}

void hextodec()
{
    int decimalNum = 0, remainder, i = 0, len = 0;
    char hexnum[20];
    printf("Enter any Hexadecimal Number: ");
    scanf("%s", hexnum);
    while (hexnum[i] != '\0')
    {
        len++;
        i++;
    }
    len--;
    i = 0;
    while (len >= 0)
    {
        remainder = hexnum[len];
        if (remainder >= 48 && remainder <= 57)
            remainder = remainder - 48;
        else if (remainder >= 65 && remainder <= 70)
            remainder = remainder - 55;
        else if (remainder >= 97 && remainder <= 102)
            remainder = remainder - 87;
        else
        {
            printf("\nYou've entered an invalid Hexadecimal digit");
        }
        decimalNum = decimalNum + (remainder * power(16, i));
        len--;
        i++;
    }
    printf("\nEquivalent Decimal Value = %d\n", decimalNum);
}
