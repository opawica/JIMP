#include <stdio.h>
#include <math.h>

void stopnieNaRadiany()
{
	double stopnie = 0;
	printf("Wpisz ilosc stopni: ");
	scanf("%lf", &stopnie);
	double radiany = stopnie*M_PI/180.f;
	printf("%lf° = %lfrad\n\n", stopnie, radiany);
}

void radianyNaStopnie()
{
	double radiany = 0;
	printf("Wpisz ilosc w radianach: ");
	scanf("%lf", &radiany);
	double stopnie = radiany*180.f/M_PI;
	printf("%lfrad = %lf°\n\n", radiany, stopnie);
}

int main()
{
	int a = 0;
	while(a == 0)
	{
		printf("Wybierz rodzaj przeksztalcenia:\
		\n1. STOPNIE --> RADIANY\
		\n2. RADIANY --> STOPNIE\
		\n9. WYJSCIE Z PROGRAMU\n");
		scanf("%d", &a);
		switch(a)
		{
			case 1: 
				stopnieNaRadiany();
				break;
			case 2:
				radianyNaStopnie();
				break;
			case 9:
				return 0;
			default: printf("Wpisales bledna liczbe!\n");
		}
		a = 0;
	}

}
