#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void* data, size_t sizeOfData)
{
	char char_array [sizeOfData];
	long long int sum = 0;
	memcpy ( char_array, data, sizeOfData);
	for (int i=0; i<sizeOfData; i++)
	{
		printf("%c", char_array[i]);
		sum+=char_array[i];
	}
	return sum;
}
int main()
{
	char * data = "To jest jakis tekst, ktory zostanie skopiowany do tablicy charowej, a nastepnie wyswietlony znak po znaku";
	printf("\n\nSuma znakow: %lld\n", copyArgumentAndPrintCharByCharReturningSumOfArguments(data, strlen(data)));
	return 0;
}
