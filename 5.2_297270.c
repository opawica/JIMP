#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losujMacierz(double macierz[3][3], int rozmiar)
{
	for (int i=0;i<rozmiar;i++)
		for (int j=0;j<rozmiar;j++)
				macierz[i][j]=rand()%11;
}


void wypiszMacierz(double macierz[3][3], int rozmiar)
{
	for (int i=0;i<rozmiar;i++)
		{
		for (int j=0;j<rozmiar;j++)
			printf("%lf ", macierz[i][j]);
		printf("\n");
		}
}


double liczWyznacznik(double macierz[3][3])
{
	double wyznacznik;
	wyznacznik = (macierz[0][0]*macierz[1][1]*macierz[2][2])+(macierz[1][0]*macierz[2][1]*macierz[0][2])+(macierz[2][0]*macierz[0][1]*macierz[1][2]);
	wyznacznik= wyznacznik-(macierz[0][2]*macierz[1][1]*macierz[2][0])-(macierz[1][2]*macierz[2][1]*macierz[0][0])-(macierz[2][2]*macierz[0][1]*macierz[1][0]);	
	return wyznacznik;
}


int main()
{
	srand(time(NULL));
	
	double macierz[3][3];
	double det;

	losujMacierz(macierz, 3);
	wypiszMacierz(macierz, 3);

	det = liczWyznacznik(macierz);


	printf("\nWyznacznik tej macierzy wynosi: %lf\n", det);
	return 0;
}
