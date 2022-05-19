#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int daysafterNmonths[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int leapdays(int m,int y)
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

    int no_of_leap_days = abs(leapdays(m1,y1)-leapdays(m2, y2));
    int no_of_days;
    if (y1 >= y2)
    {
        if (m1 >= m2)
        {
            if (d1 >= d2)
            {
                no_of_days = (y1 - y2) * 365 + (daysafterNmonths[m1 - 1] - daysafterNmonths[m2 - 1]) + (d1 - d2)+no_of_leap_days;
            }
            else
            {
                int tempm1 = m1 - 1;
                int tempd1 = 30 + d1;
                if (tempm1 >= m2)
                {
                    no_of_days = (y1 - y2) * 365 + (daysafterNmonths[tempm1 - 1] - daysafterNmonths[m2 - 1]) + (tempd1 - d2)+no_of_leap_days;
                }
                else
                {
                    int tempy1 = y1 - 1;
                    tempm1 += 12;
                    no_of_days = (tempy1 - y2) * 365 + (daysafterNmonths[tempm1 - 1] - daysafterNmonths[m2 - 1]) + (tempd1 - d2)+no_of_leap_days;
                }
            }
        }
        else
        {
            int tempy1 = y1 - 1;
            int tempm1 = m1 + 12;
            if (d1 >= d2)
            {
                no_of_days = (tempy1 - y2) * 365 + (daysafterNmonths[tempm1 - 1] - daysafterNmonths[m2 - 1]) + (d1 - d2);
            }
            else
            {
                tempm1--;
                int tempd1 = d1 + 30;
                no_of_days = (tempy1 - y2) * 365 + (daysafterNmonths[tempm1 - 1] - daysafterNmonths[m2 - 1]) + (tempd1 - d2)+no_of_leap_days;
            }
        }
    }
    else
    {
        if (m2 >= m1)
        {
            if (d2 >= 12)
            {
                no_of_days = (y2 - y1) * 365 + (daysafterNmonths[m2 - 1] - daysafterNmonths[m1 - 1]) + (d2 - d1)+no_of_leap_days;
            }
            else
            {
                int tempm2 = m2 - 1;
                int tempd2 = 30 + d2;
                if (tempm2 >= m1)
                {
                    no_of_days = (y2 - y1) * 365 + (daysafterNmonths[tempm2 - 1] - daysafterNmonths[m1 - 1]) + (tempd2 - d1)+no_of_leap_days;
                }
                else
                {
                    int tempy2 = y2 - 1;
                    tempm2 += 12;
                    no_of_days = (tempy2 - y1) * 365 + (daysafterNmonths[tempm2 - 1] - daysafterNmonths[m1 - 1]) + (tempd2 - d1);
                }
            }
        }
        else
        {
            int tempy2 = y2 - 1;
            int tempm2 = m2 + 12;
            if (d2 >= d1)
            {
                no_of_days = (tempy2 - y1) * 365 + (daysafterNmonths[tempm2 - 1] - daysafterNmonths[m1 - 1]) + (d2 - d1);
            }
            else
            {
                tempm2--;
                int tempd2 = d2 + 30;
                no_of_days = (tempy2 - y2) * 365 + (daysafterNmonths[tempm2 - 1] - daysafterNmonths[m1 - 1]) + (tempd2 - d1)+no_of_leap_days;
            }
        }
    }
    printf("Total number of days between (%s) is %d", date, no_of_days);
    return 0;
}