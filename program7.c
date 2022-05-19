#include <stdio.h>

int main()
{
    char text[1000];
    printf("Text->");
    gets(text);
    int spaces = 0, tabs = 0, sentences = 0, lines = 0, vowels = 0;
    for (int i = 0; text[i] != '0'; i++)
    {
        if (text[i] == ' ')
        {
            ++spaces;
        }
        else if (text[i] == '\t')
        {
            tabs++;
        }
        if (text[i] == '.')
        {
            sentences++;
        }
        else if (text[i] == '\n')
        {
            lines++;
        }
        else if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
                 text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U')
        {
            vowels++;
        }
    }
    printf("\nTotal space in piece of text is -> %d", spaces);
    printf("\nTotal tabs in piece of text is -> %d", tabs);
    printf("\nTotal sentences in piece of text is -> %d", sentences);
    printf("\nTotal lines in piece of text is -> %d", lines);
    printf("\nTotal no of vowel in peace of text is -> %d", vowels);
    return 0;
}