#include <stdio.h>

void szukanieLiczby(int liczba, int max, int min)
{
	int szukana = max/2;
	while(szukana != liczba)
	{
		if(liczba>szukana)
		{
			min = szukana+1;
			szukana = (max+min)/2;
		}
		else if(liczba<szukana)
		{
			max = szukana-1;
			szukana = (max+min)/2;
		}
	}
	printf("\nTwoja liczba to: %d\n", szukana);
}

char dzialanieProgramu ()
{
	char program[20];
	printf("\nCzy chcesz wyliczyc pierwiastki dla innego rownania? (T/N): ");
	scanf("%19s", program);
	return program[0];
}

int main()
{
	char  program = 'T';
	int min, max;
	int liczba;
	while (program == 'T' || program == 't')
	{
		min = 1;
		max = 10;
		printf("Prosze wpisac liczbe z przedzialu [%d,%d]: ", min, max);
		scanf("%d", &liczba);
		if (liczba > max)
		{
			printf("Wpisales zbyt duza liczbe.\
			\nNastapi jej zmniejszenie do odpowiadajacej przedzialowi");
			liczba = 10;
		}
		else if (liczba < min)
		{
			printf("Wpisales zbyt mala liczbe.\
			\nNastapi jej zwiekszenie do odpowiadajacej przedzialowi");
			liczba = 1;
		}
		szukanieLiczby(liczba, max, min);
		program = dzialanieProgramu();
		if (program == 'T' || program == 't')
			continue;
		else
			return 0;
	}
}
