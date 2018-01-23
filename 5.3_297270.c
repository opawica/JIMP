#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generujMacierz(int macierz[2][2])
{
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			macierz[i][j]=rand()%201-100;
}


void wypiszMacierz(int macierz[2][2])
{
	for (int i=0;i<2;i++)
		{
		for (int j=0;j<2;j++)
			printf("%d    ", macierz[i][j]);
		printf("\n");
		}
}


void konwertujMacierze(int macierz_1[2][2], int macierz_2[2][2], int macierz3d[2][2][2])
{
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			{
			macierz3d[0][i][j]=macierz_1[i][j];
			macierz3d[1][i][j]=macierz_2[i][j];
			}
}


void wymnozMacierze(int macierz[2][2][2])
{
    int macierz_tymczasowa[1][2][2];
	for (int i=0;i<2;i++)
		{
		for (int j=0;j<2;j++)
        		{
			int suma = 0;
            		for (int k=0;k<2;k++)
            			{
                		suma+=macierz[0][i][k] * macierz[1][k][j];
				}
            		macierz_tymczasowa[0][i][j] = suma;
        		}
		}
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			macierz[0][i][j] = macierz_tymczasowa[0][i][j];
}


void odwroconaKonwersja(int macierz[2][2], int macierz3d[2][2][2])
{
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
		{
			macierz[i][j]=macierz3d[0][i][j];
		}
}


int main()
{
	srand(time(NULL));
	
	int macierz_1[2][2];
	int macierz_2[2][2];
	int macierz3d[2][2][2];
	int macierz_wymnozona[2][2];


	generujMacierz(macierz_1);
	generujMacierz(macierz_2);

	printf("Macierz A:\n");
	wypiszMacierz(macierz_1);

	printf("Macierz B:\n");
	wypiszMacierz(macierz_2);

	konwertujMacierze(macierz_1, macierz_2, macierz3d);
	wymnozMacierze(macierz3d);
	odwroconaKonwersja(macierz_wymnozona, macierz3d);

	printf("\nMacierz A*B:\n");
	wypiszMacierz(macierz_wymnozona);
	return 0;
}
