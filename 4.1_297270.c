#include <stdio.h>
#include <math.h>

void zerowyWspolczynnik (double b, double c)
{
	if (b == 0)
		if (c == 0)
			printf("Nieskonczenie wiele miejsc zerowych\n");
		else
			printf("Brak miejsc zerowych\n");
	else
		printf("x = %f\n", (-c)/b);
}

void rozwiazanieUrojone (double a, double b, double c, float delta)
{
	double rzeczywista, urojona;
	rzeczywista = -b/(a*2.f);
	urojona = sqrt(delta*(-1.f))/(2.f*a);
	printf("x1 = %lf - %lfi\n", rzeczywista, urojona);
	printf("x2 = %lf + %lfi\n", rzeczywista, urojona);
}

void rozwiazanieRzeczywiste (double a, double b, float delta)
{
	if (delta == 0)
		printf("x = %f\n", (-b)/2.f*a);
	else
	{
		printf("x1 = %lf\n", ((-b)-sqrt(delta))/2.f*a);
		printf("x2 = %lf\n", ((-b)+sqrt(delta))/2.f*a);	
	}
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
	while (program == 'T' || program == 't')
	{
		printf("Wprowadz a, b, c.\n");	
		double a,b,c;
		printf("a = ");
		scanf("%lf", &a);
		printf("b = ");
		scanf("%lf", &b);
		printf("c = ");
		scanf("%lf", &c);
		if (a == 0)
			zerowyWspolczynnik(b, c);
		else 
		{
			float delta = b*b - 4.f*a*c;
			if (delta < 0)
				rozwiazanieUrojone(a, b, c, delta);
			else
				rozwiazanieRzeczywiste(a, b, delta);
		}
		program = dzialanieProgramu();
		if (program == 'T' || program == 't')
			continue;
		else
			return 0;
	}
}
