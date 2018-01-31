#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losujMacierz(const int rozmiar, double macierz[rozmiar][rozmiar])
{
	for (int i=0;i<rozmiar;i++)
		for (int j=0;j<rozmiar;j++)
				macierz[i][j]=rand()%11;
}


void wypiszMacierz(const int rozmiar, double macierz[rozmiar][rozmiar])
{
	for (int i=0;i<rozmiar;i++)
	{
		for (int j=0;j<rozmiar;j++)
			printf("%lf ", macierz[i][j]);
		printf("\n");
	}
}


double liczWyznacznik(const int rozmiar, double macierz[rozmiar][rozmiar])
{
	double wyznacznik;
	wyznacznik = (macierz[0][0]*macierz[1][1]*macierz[2][2])+(macierz[1][0]*macierz[2][1]*macierz[0][2])+(macierz[2][0]*macierz[0][1]*macierz[1][2]);
	wyznacznik= wyznacznik-(macierz[0][2]*macierz[1][1]*macierz[2][0])-(macierz[1][2]*macierz[2][1]*macierz[0][0])-(macierz[2][2]*macierz[0][1]*macierz[1][0]);	
	return wyznacznik;
}


int main()
{
	srand(time(NULL));
	const int rozmiar = 3;
	double macierz[rozmiar][rozmiar];

	losujMacierz(rozmiar, macierz);
	wypiszMacierz(rozmiar, macierz);

	double det = liczWyznacznik(rozmiar, macierz);

	printf("\nWyznacznik tej macierzy wynosi: %lf\n", det);
	return 0;
}
