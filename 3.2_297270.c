#include <stdio.h>

void zCelsjuszaNaFahrenheita()
{
	double celsjusz = 0;
	printf("Wpisz temperature w stopniach Celsjusza: ");
	while (1)
	{
		scanf("%lf", &celsjusz);
		if (celsjusz < -273.15)
			printf("Nie istnieje tak niska temperatura! Podaj jeszcze raz: ");
		else
			break;
	}
	double fahrenheit = 32.f + (9.f/5.f)*celsjusz;
	printf("%lf°C = %lf°F\n\n", celsjusz, fahrenheit);
}

void zFahrenheitaNaCelsjusza()
{
	double fahrenheit = 0;
	printf("Wpisz temperature w stopniach Fahrenheita: ");
	while (1)
	{
		scanf("%lf", &fahrenheit);
		if (fahrenheit < -459.67)
			printf("Nie istnieje tak niska temperatura! Podaj jeszcze raz: ");
		else
			break;
	}
	double celsjusz = 5.f/9.f*(fahrenheit-32.f);
	printf("%lf°F = %lf°C\n\n", fahrenheit, celsjusz);
}

int main()
{
	int a = 0;
	while(a == 0)
	{
		printf("Wybierz rodzaj przeksztalcenia:\
		\n1. CELSJUSZ --> FAHRENHEIT\
		\n2. FAHRENHEIT --> CELSJUSZ\
		\n9. WYJSCIE Z PROGRAMU\n");
		scanf("%d", &a);
		switch(a)
		{
			case 1: 
				zCelsjuszaNaFahrenheita();
				break;
			case 2:
				zFahrenheitaNaCelsjusza();
				break;
			case 9:
				return 0;
			default: printf("Wpisales bledna liczbe!\n");
			
		}
		a = 0;
	}

}
