#include <stdio.h>
#include<stdlib.h>

int daysafterNmonths[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int leapyear(int m,int y)//from 0 year to y years
{
   if (m<=2)
   {
       y--;
   }
   return (y / 4) - (y / 100) + (y / 400);
}
int main()
{
    int d1 = 0, m1 = 0, y1 = 0;
    int d2 = 0, m2 = 0, y2 = 0;
    char date[21];
    printf("Enter the two Dates : ");
    gets(date);
    int i = 0;
    while (date[i] != '-')
    {
        d1 = d1 * 10 + date[i] - '0';
        i++;
    }
    while (date[i] == '-')
    {
        i++;
    }
    while (date[i] != '-')
    {
        m1 = m1 * 10 + date[i] - '0';
        i++;
    }
    while (date[i] == '-')
    {
        i++;
    }
    while (date[i] != ',')
    {
        y1 = y1 * 10 + date[i] - '0';
        i++;
    }
    while (date[i] == ',')
    {
        i++;
    }
    while (date[i] != '-')
    {
        d2 = d2 * 10 + date[i] - '0';
        i++;
    }
    while (date[i] == '-')
    {
        i++;
    }
    while (date[i] != '-')
    {
        m2 = m2 * 10 + date[i] - '0';
        i++;
    }
    while (date[i] == '-')
    {
        i++;
    }
    while (i < 21)
    {
        y2 = y2 * 10 + date[i] - '0';
        i++;
    }
if (m1 > 12|| m1 < 0 || m2 > 12|| m2 < 0 || d1>31 ||d1<0||d2>31 ||d2<0)
{
    printf("Invalid Date\n");
    exit(0);
}

    int no_of_leap_year = abs(leapyear(m1,y1)-leapyear(m2, y2));
    int no_of_days=abs((y1*365+d1+daysafterNmonths[m1-1])-(y2*365+d2+daysafterNmonths[m2-1]))+no_of_leap_year;
    
    printf("Total number of days between (%s) is %d", date, no_of_days);
    return 0;
}

