#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Complex
{
    int real;
    int img;
};
void input(char *s, struct Complex *C1, struct Complex *C2)
{
    int v1 = 0;
    int f1=0;
    int i = 0;
    while (s[i] == '-')
    {
        f1=1;
        i++;
    }
    while (s[i] != '+' || s[i] == '-')
    {
        v1 = v1 * 10 + s[i] - '0';
        i++;
    }
    while (s[i] == '+' || s[i] == '-' || s[i] == 'i')
    {
        i++;
    }
    int v2 = 0;
    while (s[i] != ' ')
    {
        v2 = v2 * 10 + s[i] - '0';
        i++;
    }
    if (f1==1)
        C1->real = -v1;
    else
        C1->real = v1;
    
    C1->img = v2;
    while (s[i] == ' ')
    {
        i++;
    }
    int v3 = 0;
    int f2=0;
    while (s[i] == '-')
    {
        f2=1;
        i++;
    }
    while (s[i] != '+')
    {
        v3 = v3 * 10 + s[i] - '0';
        i++;
    }
    while (s[i] == '+' || s[i] == '-' || s[i] == 'i')
    {
        i++;
    }
    int v4 = 0;
    while (i<12)
    {
        v4 = v4 * 10 + s[i] - '0';
        i++;
    }
    if (f2==1)
        C2->real = -v3;
    else
        C2->real = v3;
    C2->img = v4;
}
void display(struct Complex C)
{
    printf("%d + i%d\n", C.real, C.img);
}
int main()
{
    struct Complex C1;
    struct Complex C2;
    char *string;
    gets(string);
    // puts(string);
    input(string, &C1, &C2);
    display(C1);
    display(C2);
    return 0;
}