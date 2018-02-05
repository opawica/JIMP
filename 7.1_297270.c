#include <stdio.h>

double countWeightedAverage(int * tabBeginning, int * tabEnding)
{
	double sum = 0, weights_sum = 0, average;

	for (int i = 0; tabBeginning<=tabEnding;i++)
	{
		sum+= i*(*tabBeginning);
		weights_sum+=i;
		tabBeginning+=1;
	}
	average = sum/weights_sum;

	return average;
}

int main()
{
	int tab[] = {12, 42, 121, 141, 9, 1, 19, 12, 19, 0};
	const int size = sizeof(tab)/sizeof(tab[0]);
	printf("Srednia wazona wynosi: %f", countWeightedAverage(&tab[0], &tab[size-1]));

	return 0;
}
