#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month > 12 || month < 1) {
        printf("error: illegal month\n");
        exit(1);
    } else if (day > daytab[leap][month])
    {
        printf("error: illegal day of month\n");
        exit(1);
    } else {
        for (i = 0; i < month; i++) {
            day += daytab[leap][i];
        }
        return day;
    }
    
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (yearday > 365 && !leap || yearday > 366 && leap || yearday < 1) {
        printf("error: illegal day of year");
        exit(1);
    }
    for (i = 0; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main(int argc, char *argv[])
{
    int day, month, dayofyear;
    dayofyear = day_of_year( atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    printf("%-15s: %s-%s-%s\n", "Date", argv[1], argv[2], argv[3]);
    printf("%-15s: %d\n", "Day of year", dayofyear);
    month_day(atoi(argv[1]), dayofyear, &month, &day);
    printf("%-15s: %s-%d-%d\n", "Date", argv[1], month, day);
    return 0;
}