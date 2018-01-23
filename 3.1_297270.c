#include <stdio.h>
#include <math.h>

void kwadrat()
{
	double bok = 1;
	printf("\nPodaj bok kwadratu: ");
	while (1)
	{
		scanf("%lf", &bok);
		if (bok <= 0)
			printf("Bok musi byc dodatni! Podaj bok jeszcze raz: ");
		else
			break;	
	}
	double pole = bok*bok;
	double obwod = 4*bok;
	printf("Pole = %lf\n", pole);
	printf("Obwod = %lf\n\n", obwod);
}

void prostokat()
{
	double bok_a = 1;
	double bok_b = 1;
	printf("\nPodaj boki prostokata:\n");
	while (1)
	{
		printf("a = ");
		scanf("%lf", &bok_a);
		printf("b = ");
		scanf("%lf", &bok_b);
		if (bok_a <= 0 || bok_b <= 0)
			printf("Boki musza byc dodatnie! Podaj boki jeszcze raz...\n");
		else
			break;
	}
	double pole = bok_a*bok_b;
	double obwod = 2*bok_a+2*bok_b;
	printf("Pole = %lf\n", pole);
	printf("Obwod = %lf\n\n", obwod);
}

void trojkat()
{
	double bok_a = 1;
	double bok_b = 1;
	double bok_c = 1;
	int warunek = 1;
	printf("\nPodaj boki trojkata:\n");
	while (1)
	{
		printf("a = ");
		scanf("%lf", &bok_a);
		printf("b = ");
		scanf("%lf", &bok_b);
		printf("c = ");
		scanf("%lf", &bok_c);
		if (bok_a <= 0 || bok_b <= 0 || bok_c <= 0)
		{
			printf("Podales bledne wymiary! Podaj boki jeszcze raz...\n");
			continue;
		}
		else if (bok_a >= bok_b + bok_c || bok_b >= bok_a + bok_c || bok_c >= bok_b + bok_a)
		{
			printf("Podales bledne wymiary! Podaj boki jeszcze raz...\n");
			continue;
		}
		else if (bok_a <= fabs(bok_b - bok_c) || bok_b <= fabs(bok_a - bok_c) || bok_c <= fabs(bok_b - bok_a))
		{
			printf("Podales bledne wymiary! Podaj boki jeszcze raz...\n");
			continue;
		}
		else
			break;
	}
	double obwod = bok_a+bok_b+bok_c;
	double p = obwod/2;
	double pole = sqrt(p*(p-bok_a)*(p-bok_b)*(p-bok_c));
	printf("Pole = %lf\n", pole);
	printf("Obwod = %lf\n\n", obwod);
}

void kolo()
{
	double promien = 1;
	printf("\nPodaj dlugosc promienia kola: ");
	while (1)
	{
		scanf("%lf", &promien);
		if (promien <= 0)
			printf("Promien musi byc dodatni! Podaj promien jeszcze raz: ");
		else
			break;
	}
	double pole = M_PI*promien*promien;
	double obwod = 2*M_PI*promien;
	printf("Pole = %lf\n", pole);
	printf("Obwod = %lf\n\n", obwod);
}

int main()
{
	int a = 0;
	while(a == 0)
	{
		printf("Wybierz figure:\
		\n1. KWADRAT\
		\n2. PROSTOKAT\
		\n3. TROJKAT\
		\n4. KOLO\
		\n9. WYJSCIE Z PROGRAMU\n");
		scanf("%d", &a);
		switch(a)
		{
			case 1: 
				kwadrat();
				break;
			case 2:
				prostokat();
				break;
			case 3:
				trojkat();
				break;
			case 4:
				kolo();
				break;
			case 9:
				return 0;
			default: printf("Wpisales bledna liczbe!\n");
			
		}
		a = 0;
	}

}
