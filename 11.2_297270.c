//[11.2_*]Proszę o napisanie programu, który posortuje te liczby do innego pliku, lub wyświetli. W tym celu program przyjmuje argumenty takie jak nazwa pliku wejściowego i nazwa pliku wyjściowego, natomiast jeśli nie podamy nazwy pliku wyjściowego to posortowane dane powinny zostać wyświetlone na ekran.
//Pytanie pomocnicze: jak to sortować jeśli wczytany plik nie zmieści się w pamięci?

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int getNumbersFromFile(FILE *file,int *tab, size_t size)
{
	int tmp, numbers_counter = 0;
	while (fscanf(file, "%d", &tmp) == 1)
	{
		if (tab == tab + size) 
		{
			size *= 2;
			int *pointer = realloc(tab, (size + 1) * sizeof *pointer);
			if (!pointer) 
			{
				free(tab);
				return -1;
			}
			pointer[size+1] = 0;
			tab = pointer;
		}
		*tab = tmp;
		++tab;
		numbers_counter++;
	}
	return numbers_counter;
}

void sortNumbers(int array[], int size)
{
	int change = 1, min_element, min_element_position;
	int temp;
	for (int i=0; i<size-1;i++)
	{	
		min_element = array[i];
		min_element_position = i;
		change = 0;
		for (int j=i+1; j<size; j++)
		{
			if (min_element > array[j])
			{
				min_element = array[j];
				min_element_position = j;
				change = 1;
			}
		}
		if (change)
		{
			temp = array[i];
			array[i] = array[min_element_position];
			array[min_element_position] = temp;
		}
	}
}

void printSortedNumbers(int array[], int size)
{
	for (int i=0; i<size; i++)
	{
		printf("%d\n", array[i]);
	}
}

void printSortedNumbersToFile(FILE* file, int array[], int size)
{
	for (int i= 0; i<size;i++)
	{
		fprintf(file, "%d\n", array[i]);
	}
}

int main(int argc, char * argv[])
{
	if (argc != 3 && argc!= 2)
	{
		printf("Podales zla ilosc argumentow!\n");
		return 0;
	}

	FILE *file;
	file = fopen(argv[1], "r");

	int * tab;
	size_t size = 64;
	tab = malloc(sizeof *tab * (size + 1));
	tab[size+1] = 0;
	int numbers_counter;

	numbers_counter = getNumbersFromFile(file, tab, size);
	sortNumbers(tab, numbers_counter);

	if (argc == 3)
	{
		file = fopen(argv[2], "w");
		printSortedNumbersToFile(file, tab, numbers_counter);
		fclose(file);
	}
	else
	{
		printSortedNumbers(tab, numbers_counter);
	}
	return 0;
}
