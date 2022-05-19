#include <stdio.h>
#include <stdlib.h>
struct Student
{
    char name[20];
    int roll_number;
    int subject1;
    int subject2;
    int subject3;
    float percentage;
} st[1000];
int count = 0;

void insert()
{
    struct Student s;
    printf("Name : ");
    scanf(" %[^\n]", s.name);
    printf("Roll Number : ");
    scanf("%d", &s.roll_number);
    printf("Marks in Subject1 : ");
    scanf("%d", &s.subject1);
    printf("Marks in Subject2 : ");
    scanf("%d", &s.subject2);
    printf("Marks in Subject3 : ");
    scanf("%d", &s.subject3);
    s.percentage = (float)(s.subject1 + s.subject2 + s.subject3) / 3;
    st[count++] = s;
}
void delete ()
{
    printf("Index : ");
    int index;
    scanf("%d", &index);
    for (int i = index; i < count; i++)
    {
        st[i] = st[i + 1];
    }
    count--;
}
void update()
{
    printf("Index : ");
    int index;
    scanf("%d", &index);
    printf("Name : ");
    scanf(" %[^\n]", st[index].name);
    printf("Roll Number : ");
    scanf("%d", &st[index].roll_number);
    printf("Marks in Subject1 : ");
    scanf("%d", &st[index].subject1);
    printf("Marks in Subject2 : ");
    scanf("%d", &st[index].subject2);
    printf("Marks in Subject3 : ");
    scanf("%d", &st[index].subject3);
}
void display()
{
    for (int i = 0; i < count; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%.2f\n", st[i].name, st[i].roll_number, st[i].subject1, st[i].subject2, st[i].subject3, st[i].percentage);
    }
}
int main()
{
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    if (ptr == NULL)
    {
        printf("\nError opening file");
    }
    else
    {
        while (fscanf(ptr, "%[^\t]\t%d\t%d\t%d\t%d\t%f\n", st[count].name, &st[count].roll_number, &st[count].subject1, &st[count].subject2, &st[count].subject3, &st[count].percentage) != EOF)
        {
            count++;
        }
    }
    int ch;
    while (1)
    {
        printf("\n1. Insert Row\n2. Delete Row\n3. Update Row\n4. Display\n5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        getchar();
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            update();
            break;
        case 4:
            display();
            break;
        case 5:
        {
            printf("\n**Exiting**\n");
            int i = 0;
            ptr = fopen("data.txt", "w");
            while ( i<count)
            {
                fprintf(ptr, "%s\t%d\t%d\t%d\t%d\t%.2f\n", st[i].name, st[i].roll_number, st[i].subject1, st[i].subject2, st[i].subject3, st[i].percentage);
                i++;
            }
            fclose(ptr);
            exit(0);
        }
        default:
            printf("Wrong Input.\n");
            break;
        }
    }

    return 0;
}