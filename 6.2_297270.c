#include <stdio.h>
#include <string.h>
#include <time.h>

void applyingDayMonthYear (int *day, int *month, int *year)
{
    time_t rawtime;


    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);


    *month = timeinfo->tm_mon+1;
    *day = timeinfo->tm_mday;
    *year = timeinfo->tm_year+1900;
}

int getFirstDayOfTheMonth(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;


    int first_day;
    first_day = ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    if(first_day == 0)
    	first_day = 7;

    return first_day;
}

int getDaysInAMonth(int month, int year)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    	return 31;

    else if (month == 4 || month == 6 || month == 9 || month == 11)
	return 30;

    else if (month == 2)
	if (year%400==0 || (year%100==0 && year%4==0))
		return 29;
	else
		return 28;
}

void writeHeader(int month, int year)
{
    switch(month)
    {
        case 1:
            printf("Styczen");
            break;
        case 2:
            printf("Luty");
            break;
        case 3:
            printf("Marzec");
            break;
        case 4:
            printf("Kwiecien");
            break;
        case 5:
            printf("Maj");
            break;
        case 6:
            printf("Czerwiec");
            break;
        case 7:
            printf("Lipiec");
            break;
        case 8:
            printf("Sierpien");
            break;
        case 9:
            printf("Wrzesien");
            break;
        case 10:
            printf("Pazdziernik");
            break;
        case 11:
            printf("Listopad");
            break;
        case 12:
            printf("Grudzien");
            break;
           
    }

    printf(" %d\n", year);
}

void printCalendar(int number_of_days, int first_day, int day)
{
    printf("Pn Wt Sr Cz Pt Sb Nd\n");
    for (int i = 1; i<first_day;i++)
	{
		printf("   ");
	}


    for (int i = 1; i<=number_of_days;i++)
	{
	    if(i == day)
		printf("\x1b[31m");
	    printf("%2d ", i);
	    if(i == day)
		printf("\x1b[0m");


	    if ((first_day+i-1)%7==0)
		printf("\n");
	}

    printf("\n");
}

int main()
{
    int day, month, year;

    applyingDayMonthYear(&day, &month, &year);

    int first_day = getFirstDayOfTheMonth(1, month, year);
    int number_of_days = getDaysInAMonth(month, year);


    writeHeader(month, year);
    printCalendar(number_of_days, first_day, day);
    return 0;
}
