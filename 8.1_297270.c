#include <stdio.h>
#include <stdlib.h>

void convertAndPrintHex(int n)
{
	long quotient, remainder;
	long decimalnum = (long)n;
	int i, j = 0;
	char hexadecimalnum[100];
	quotient = decimalnum;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
		    hexadecimalnum[j++] = 48 + remainder;
		else
		    hexadecimalnum[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	for (i = j-1; i >= 0; i--)
	    printf("%c", hexadecimalnum[i]);
}

void convertAndPrintOctal(int n)
{
	long remainder, quotient;
	long decimalnum = (long)n;
	int octalNumber[100], i = 1, j;
	quotient = decimalnum;
	while (quotient != 0)
	{
		octalNumber[i++] = quotient % 8;
		quotient = quotient / 8;
	}
	for (j = i - 2; j > 0; j--)
		printf("%d", octalNumber[j]);
}

void changeValues(int tab2[], int a, int b)
{
	int temp = tab2[a];
	tab2[a]=tab2[b];
	tab2[b] = temp;
}

void sortArray(int tab2[], int final_size)
{
	for (int i=0; i<final_size-1; i++)
		for(int j=i+1; j<final_size; j++)
			if(tab2[j] < tab2[i])
				changeValues(tab2, i, j);
}

int countSum(int tab[], int final_size)
{
	int sum = 0;
	for(int i=0;i<final_size;i++)
		sum+=tab[i];
	return sum;
}
double countAverage(int tab[], int final_size, int sum)
{
	double average;
	average = (double)sum/(double)final_size;
	return average;
}

int countMedian(int tab[], int final_size)
{
	int tab2[final_size];
	for (int i=0; i<final_size; i++)
		tab2[i]=tab[i];

	sortArray(tab2, final_size);

	double median;
	if (final_size%2==0)
		median = (tab2[final_size-2]+tab2[final_size-1])/2;
	else
		median = tab2[final_size/2];

	return median;
}

int countDominant(int tab[], int final_size)
{
	int tab2[final_size];
	for (int i =0;i<final_size;i++)
		tab2[i] = 0;
	for (int i=1; i<final_size; i++)
		for (int j=0; j<i; j++)
			if(tab[j] == tab[i])
			{
				tab2[j]++;
				break;
			}
	int max_pos = 0;
	for (int i = 1;i<final_size;i++)
		if (tab2[i]>tab2[max_pos])
			max_pos = i;
	return tab[max_pos];
}



int main()
{
	printf("Witaj! Mozesz rozpoczac wpisywanie liczb.\n");
	int tmp;
	int i=0;
	int length = sizeof (int) * 1;
	int *tab = malloc (length);

	while (scanf("%d", &tmp) != EOF)
	{
		if (i == length-1)
		{
			length+=sizeof (int)*10;			
			tab = realloc(tab, length);
			if(tab == NULL )
			{
	     			printf("BLAD! Nie miescimy sie w pamieci!\n");
				return 0;
			}
		}
		tab[i] = tmp;
		i++;
	}
	int final_size = i;

	if (final_size == 0)
	{
		printf("Blad! Nie wczytales zadnej liczby!\n");
	}
	else
	{
		int sum, dominant, median;
		double average;
		sum = countSum(tab, final_size);
		average = countAverage(tab, final_size, sum);
		median = countMedian(tab, final_size);
		dominant = countDominant(tab, final_size);
		printf("Suma: %d ", sum);
			convertAndPrintHex(sum);
			printf(" ");
			convertAndPrintOctal(sum);
		printf("\nSrednia: %lf ", average);
		if ((int)average == average)
		{
			convertAndPrintHex((int)average);
			printf(" ");
			convertAndPrintOctal((int)average);
		}
		printf("\nMediana: %d ", median);
			convertAndPrintHex(median);
			printf(" ");
			convertAndPrintOctal(median);
		printf("\nDominanta: %d ", dominant);
			convertAndPrintHex(dominant);
			printf(" ");
			convertAndPrintOctal(dominant);
	}
	printf("\n");
	return 0;
}
