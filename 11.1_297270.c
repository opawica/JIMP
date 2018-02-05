#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wygenerujDoPliku(FILE *file, int args_number)
{
	int generated_number;
	for (int i=0; i< args_number; i++)
	{
		generated_number = rand()%1001;
		fprintf(file, "%d\n", generated_number);
	}
}

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		printf("Podales zla ilosc argumentow. Jako argumenty podaj ilosc liczb do wylosowania i nazwe pliku,\
do ktorego chcesz zapisac liczby\n");
		return 0;
	}
	srand(time(NULL));
	FILE *file;
	file = fopen(argv[2], "w");
	int args_number = strtol(argv[1], NULL, 10);
	wygenerujDoPliku(file, args_number);
	fclose(file);
	return 0;
}
