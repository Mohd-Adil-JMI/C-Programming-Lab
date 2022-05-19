#include <stdio.h>
#include<math.h>
#include<string.h>
struct Complex
{
    float a;
    float b;
};

void add(struct Complex c1, struct Complex c2){
    printf("\nAddition : \n");
    printf("%0.3f + %0.3fi", c1.a+c2.a, c1.b+c2.b);
}

void subtract(struct Complex c1, struct Complex c2){
    printf("\nDifference : \n");
    printf("%0.3f + %0.3fi", c1.a-c2.a, c1.b-c2.b);
}

struct Complex multiply2(struct Complex c1, struct Complex c2){
    float x = (c1.a)*(c2.a) - (c1.b)*(c2.b);
    float y = (c1.a)*(c2.b) + (c1.b)*(c2.a);

    struct Complex ans;
    ans.a = x;
    ans.b = y;
    return ans;
}

void multiply(struct Complex c1, struct Complex c2){
    struct Complex ans = multiply2(c1, c2);
    printf("\nMultiplication : \n");
    printf("%0.3f + %0.3fi", ans.a, ans.b);
}

void divide(struct Complex c1, struct Complex c2){
    float deno = (c2.a)*(c2.a) + (c2.b)*(c2.b);

    c2.b = (-1)*c2.b;

    struct Complex ans = multiply2(c1, c2);
    ans.a = ans.a/deno;
    ans.b = ans.b/deno;

    printf("\nDivision : \n");
    printf("%0.3f + %0.3fi", ans.a, ans.b);
}
int main()
{
    char input[50];
    int l, i = 0, neg_a1 = 0, neg_b1 = 0, neg_a2 = 0, neg_b2 = 0;
    float a1 = 0, b1 = 0, a2 = 0, b2 = 0, a1_f = 0, b1_f = 0, a2_f = 0, b2_f = 0;
    fflush(stdin);
    printf("\nEnter the two complex Complexs in the following format:-\n");
    printf("'a1+(b1)i a2+(b2)i' :: ");
    gets(input);
    l = strlen(input);

    if (input[i] == '-')
    {
        i++;
        neg_a1 = 1;
    }
    while (input[i] != '+' && input[i] != '-' && input[i] != '.')
    {
        a1 = a1 * 10 + (input[i] - '0');
        i++;
    }
    if (input[i] == '.')
    {
        i++;
        int n = 1;
        while (input[i] != '+' && input[i] != '-')
        {
            a1_f = a1_f + (input[i] - '0') * pow(0.1, n);
            n++;
            i++;
        }
    }
    a1 = a1 + a1_f;
    if (neg_a1)
    {
        a1 = a1 * (-1);
    }

    if (input[i] == '-')
    {
        i++;
        neg_b1 = 1;
    }
    else
        i++;

    while (input[i] != 'i' && input[i] != '.')
    {
        b1 = b1 * 10 + (input[i] - '0');
        i++;
    }
    if (input[i] == '.')
    {
        i++;
        int n = 1;
        while (input[i] != 'i')
        {
            b1_f = b1_f + (input[i] - '0') * pow(0.1, n);
            n++;
            i++;
        }
    }
    b1 = b1 + b1_f;
    if (neg_b1)
    {
        b1 = b1 * (-1);
    }

    i += 2;

    if (input[i] == '-')
    {
        i++;
        neg_a2 = 1;
    }
    while (input[i] != '+' && input[i] != '-' && input[i] != '.')
    {
        a2 = a2 * 10 + (input[i] - '0');
        i++;
    }
    if (input[i] == '.')
    {
        i++;
        int n = 1;
        while (input[i] != '+' && input[i] != '-')
        {
            a2_f = a2_f + (input[i] - '0') * pow(0.1, n);
            n++;
            i++;
        }
    }
    a2 = a2 + a2_f;
    if (neg_a2)
    {
        a2 = a2 * (-1);
    }

    if (input[i] == '-')
    {
        i++;
        neg_b2 = 1;
    }
    else
        i++;

    while (input[i] != 'i' && input[i] != '.')
    {
        b2 = b2 * 10 + (input[i] - '0');
        i++;
    }
    if (input[i] == '.')
    {
        i++;
        int n = 1;
        while (input[i] != 'i')
        {
            b2_f = b2_f + (input[i] - '0') * pow(0.1, n);
            n++;
            i++;
        }
    }
    b2 = b2 + b2_f;
    if (neg_b2)
    {
        b2 = b2 * (-1);
    }
    struct Complex C1={a1,b1};
    struct Complex C2={a2,b2};
    add(C1, C2);
    subtract(C1,C2);
    multiply(C1,C2);
    divide(C1,C2);
    return 0;
}