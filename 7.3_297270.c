#include <stdio.h>
#include <stdlib.h>

void sortPointersArray(int array[], int *pointers[], int size)
{
	int change = 1, min_element, min_element_position;
	int *temp;
	
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
			temp = pointers[i];
			pointers[i] = pointers[min_element_position];
			pointers[min_element_position] = temp;
		}
	}
}

void printing(int *pointers[], int size)
{
	for (int i=0; i<size; i++)
	{
		printf("%d\n", *pointers[i]);
	}
}

int main()
{
	int array[10] = {5,7,9,12,61,26,363,242,0,66};
	int size = sizeof(array)/sizeof(array[0]);
	int *pointers[size];
	for (int i=0; i<size; i++)
	{
		pointers[i] = &array[i];
	}
	printf("Nieposortowana tablica A:\n");
	printing(pointers, size);
	sortPointersArray(array, pointers, size);
	printf("Posortowana tablica A:\n");
	printing(pointers, size);
	return 0;
}
