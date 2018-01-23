#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zamienWartosci(int tab2[], int a, int b)
{
	int temp = tab2[a];
	tab2[a]=tab2[b];
	tab2[b] = temp;
}

void losuj(int tab[], int rozmiar)
{
	for (int i=0; i<rozmiar; i++)
		tab[i] = rand();
}

void wyswietl(int tab[], int rozmiar)
{
	printf("Elementy tablicy: \n");	
	for(int i=0; i<rozmiar; i++)
		printf("%d\n", tab[i]);
}
void srednia(int tab[], int rozmiar)
{
	long long int suma = 0;
	double srednia;
	for(int i=0; i<rozmiar; i++)
		suma=suma+tab[i];
	srednia = suma/rozmiar;

	printf("Srednia wynosi: %lf\n", srednia);
}

void sortujTablice(int tab2[], int rozmiar)
{
	for (int i=0; i<rozmiar-1; i++)
		for(int j=i+1; j<rozmiar; j++)
			if(tab2[j] < tab2[i])
				zamienWartosci(tab2, i, j);
}

void mediana(int tab[], int rozmiar)
{
	int tab2[rozmiar];
	for (int i=0; i<rozmiar; i++)
		tab2[i]=tab[i];

	sortujTablice(tab2, rozmiar);

	double mediana;
	mediana = (tab2[4]+tab2[5])/2;

	printf("Mediana wynosi: %lf\n", mediana);
}
void minmax(int tab[], int rozmiar)
{
	int min = tab[0],max = tab[0];
	for (int i=1; i<rozmiar; i++)
		if(tab[i]>max)
			max = tab[i];
		else if (tab[i]<min)
			min = tab[i];

	printf("Wartosc minimalna: %d\nWartosc maksymalna: %d\n", min, max);
}
void kontynuuj()
{
	char ch;
	printf("Nacisnij ENTER, by kontynuowac");
	scanf("%c",&ch);
	getchar();

	printf("\e[2J\e[H");
}
int main()
{
	int tab[10] = {};
	const int rozmiar = sizeof(tab)/sizeof(tab[0]);

	srand(time(NULL));

	int wybor = 1;
	while (wybor != 9)
	{
		printf("Wybierz funkcje\n"
		"1. Losowanie tablicy 10 liczb\n"
		"2. Wyswietlanie jej\n"
		"3. Liczenie sredniej liczb\n"
		"4. Liczebnie mediany liczb\n"
		"5. Maksymalny/minimalny element tablicy\n"
		"9. Wyjscie\n");
		scanf("%d", &wybor);
		printf("\e[2J\e[H");
		switch(wybor)
		{
			case 1:
				losuj(tab, rozmiar);
				kontynuuj();
				break;
			case 2:
				wyswietl(tab, rozmiar);
				kontynuuj();
				break;
			case 3:
				srednia(tab, rozmiar);
				kontynuuj();
				break;
			case 4:
				mediana(tab, rozmiar);
				kontynuuj();
				break;
			case 5:
				minmax(tab, rozmiar);
				kontynuuj();
				break;
		}
	}
	return 0;
}
