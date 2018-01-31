#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

enum ArgumentType {CHAR, STRING, INT, DOUBLE};

int getIntLength(int argument)
{
	int counter = 0;
	int temp = argument;
	while (temp>0)
	{
		temp=temp/10;
		counter+=1;	
	}
	return counter;
}

void stringPrinting(char* argument, unsigned width, int half)
{
	if (strlen((char*)argument) > width)
		printf("%s\n", (char**)argument);

	else
	{
		for (int i=0; i<half-(strlen((char*)argument)+1)/2;i++)
		{
			printf(" ");
		}
		printf("%s\n", (char**)argument);
	}
}

void charPrinting(char* argument, int half)
{
	if (isprint(*(char*)argument) == 0)
		printf("\n");
	else
	{
		for (int i=0; i<half-1;i++)
		{
			printf(" ");
		}
		printf("%c\n",*(char*)argument);
	}
	}

	void intPrinting(int* argument, unsigned width, int half)
	{
	int counter;
	int arg = *(int*)argument;
	counter = getIntLength(arg);
	if (counter > width)
	{
		printf("%d\n", arg);
	}
	else
	{
		for (int i=0; i<half-(counter+1)/2;i++)
		{
			printf(" ");
		}
		printf("%d\n", arg);
	}
}

void doublePrinting(double* argument, unsigned width, int half)
{
	char temp[50];
	snprintf(temp, 50, "%.2f", *(double*)argument);
	int temp_int = (int)(*(double*)argument);
	temp_int = getIntLength(temp_int);
	int decimals = 3;

	if (temp[strlen(temp)-1] == '0')
	{
		decimals--;
		if (temp[strlen(temp)-2] == '0')
		decimals = 0;
	}

	temp_int+=decimals;

	if (temp_int > width)
	{
		if (decimals == 0)
			printf("%.0f\n", *(double*)argument);
		else if (decimals == 2)
			printf("%0.1f\n", *(double*)argument);
		else
			printf("%0.2f\n", *(double*)argument);
	}

	else
	{
		for (int i=0; i<half-(temp_int+1)/2;i++)
		{
			printf(" ");
		}
		if (decimals == 0)
			printf("%.0f\n", *(double*)argument);
		else if (decimals == 2)
			printf("%0.1f\n", *(double*)argument);
		else
			printf("%0.2f\n", *(double*)argument);
	}
}

int printArgumentInTheMiddle(void* argument, enum ArgumentType type, unsigned width)
{
	int half = width/2;

	if (argument == NULL)
	{
		printf("\n");
		return 0;
	}

	else if (type == STRING)
		stringPrinting(argument, width, half);

	else if (type == CHAR)
		charPrinting(argument, half);

	else if (type == INT)
		intPrinting(argument, width, half);

	else if (type == DOUBLE)
		doublePrinting(argument, width, half);

	return 0;
}

int main()
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	enum ArgumentType type;

	printf("\n"
	"1 - CHAR\n"
	"2 - STRING\n"
	"3 - INT\n"
	"4 - DOUBLE\n"
	"Wybierz: ");

	int wybor;
	scanf("%d", &wybor);
	char zmienna_char;
	char* string;
	int zmienna_int;
	double zmienna_double;

	switch(wybor)
	{
		case 1:
			type = CHAR;
			printf("Wpisz JEDEN znak: ");
			scanf(" %c", &zmienna_char);
			printArgumentInTheMiddle(&zmienna_char, type, w.ws_col);
			break;
		case 2:
			type = STRING;
			printf("Wpisz tekst: ");
			scanf("%s", &string);
			printArgumentInTheMiddle(&string, type, w.ws_col);
			break;
		case 3:
			type = INT;
			printf("Wpisz liczbe calkowita: ");
			scanf("%d", &zmienna_int);
			printArgumentInTheMiddle(&zmienna_int, type, w.ws_col);
			break;
		case 4:
			type = DOUBLE;
			printf("Wpisz liczbe zmiennoprzecinkowa: ");
			scanf("%lf", &zmienna_double);
			printf("%.2f\n", zmienna_double);
			printArgumentInTheMiddle(&zmienna_double, type, w.ws_col);
			break;
		default:
			printf("BLAD! Nastepnym razem wybierz odpowiednia liczbe!\n");
	}
	

	return 0;
}

