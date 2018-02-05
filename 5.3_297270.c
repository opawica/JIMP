#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generujMacierz(const int rozmiar, int macierz[rozmiar][rozmiar])
{
	for (int i=0;i<rozmiar;i++)
		for (int j=0;j<rozmiar;j++)
			macierz[i][j]=rand()%201-100;
}


void wypiszMacierz(const int rozmiar, int macierz[rozmiar][rozmiar])
{
	for (int i=0;i<rozmiar;i++)
		{
		for (int j=0;j<rozmiar;j++)
			printf("%d    ", macierz[i][j]);
		printf("\n");
		}
}


void konwertujMacierze(const int rozmiar, int macierz_1[rozmiar][rozmiar], int macierz_2[rozmiar][rozmiar], int macierz3d[rozmiar][rozmiar][rozmiar])
{
	for (int i=0;i<rozmiar;i++)
		for (int j=0;j<rozmiar;j++)
		{
			macierz3d[0][i][j]=macierz_1[i][j];
			macierz3d[1][i][j]=macierz_2[i][j];
		}
}


void wymnozMacierze(const int rozmiar, int macierz[rozmiar][rozmiar][rozmiar])
{
    int macierz_tymczasowa[1][rozmiar][rozmiar];
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<rozmiar;j++)
        	{
			int suma = 0;

            		for (int k=0;k<rozmiar;k++)
            		{
                		suma+=macierz[0][i][k] * macierz[1][k][j];
			}

            		macierz_tymczasowa[0][i][j] = suma;
        	}
	}
	for (int i=0;i<rozmiar;i++)
		for (int j=0;j<rozmiar;j++)
			macierz[0][i][j] = macierz_tymczasowa[0][i][j];
}


void odwroconaKonwersja(const int rozmiar, int macierz[rozmiar][rozmiar], int macierz3d[rozmiar][rozmiar][rozmiar])
{
	for (int i=0;i<rozmiar;i++)
		for (int j=0;j<rozmiar;j++)
		{
			macierz[i][j]=macierz3d[0][i][j];
		}
}


int main()
{
	srand(time(NULL));
	
	const int rozmiar = 2;
	int macierz_1[rozmiar]rozmiar];
	int macierz_2[rozmiar][rozmiar];
	int macierz3d[rozmiar][rozmiar][rozmiar];
	int macierz_wymnozona[rozmiar][rozmiar];


	generujMacierz(rozmiar, macierz_1);
	generujMacierz(rozmiar, macierz_2);

	printf("Macierz A:\n");
	wypiszMacierz(rozmiar, macierz_1);

	printf("Macierz B:\n");
	wypiszMacierz(rozmiar, macierz_2);

	konwertujMacierze(rozmiar, macierz_1, macierz_2, macierz3d);
	wymnozMacierze(rozmiar, macierz3d);
	odwroconaKonwersja(rozmiar, macierz_wymnozona, macierz3d);

	printf("\nMacierz A*B:\n");
	wypiszMacierz(rozmiar, macierz_wymnozona);
	return 0;
}
