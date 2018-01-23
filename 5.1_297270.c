#include <string.h>
#include <stdio.h>

int porownaj(char godzina_1[8], char godzina_2[8])
{
	int wynik = 0;
	for (int i=0;i<8;i++)
		{
		if(godzina_1[i] > godzina_2 [i])
			{
			wynik+=1;
			break;
			}
		else if(godzina_1[i] < godzina_2 [i])
			{
			wynik-=1;
			break;
			}
		}
	return wynik;
}

void podajGodzine(char godzina[8], int ilosc_wywolan)
{
	while(1)
	{	
		printf("Podaj godzine nr %d [GG:MM:SS]: ", ilosc_wywolan);
		scanf("%s", godzina);
		if (godzina[0] > '2')
		{
			printf("Podales bledna godzine! ");
			continue;
		}
		else if (godzina[0] == '2' && godzina[1] > '3')
		{
			printf("Podales bledna godzine! ");
			continue;
		}
		else if (godzina[2] != ':' || godzina[5] != ':')
		{
			printf("Podales bledna godzine! ");
			continue;
		}
		else if (godzina[3] > '5' || godzina[6] > '5')
		{
			printf("Podales bledna godzine! ");
			continue;
		}
		else if (strlen(godzina) != 8)
		{
			printf("Podales bledna godzine! ");
			continue;
		}
		else
		{
			int warunek = 1;
			for (int i=0;i<8;i++)
				{
					if (godzina[i]>58 || godzina[i]<48)
					{
						warunek = 0;
						break;
					}
				}
			if (warunek)
				break;
		}
	}
}

int main()
{
	char godzina_1[8];
	char godzina_2[8];
	int wynik = 0;
	int ilosc_wywolan = 1;

	podajGodzine(godzina_1, ilosc_wywolan);
	ilosc_wywolan++;
	podajGodzine(godzina_2, ilosc_wywolan);

	wynik = porownaj(godzina_1, godzina_2);
	switch(wynik) {
		case 1: 
			printf("Godzina nr 1 [%s] jest wieksza\n", godzina_1);
			break;

		case -1: 
			printf("Godzina nr 2 [%s] jest wieksza\n", godzina_2);
			break;

		default:
			printf("Godziny nr 1 [%s] i nr 2 [%s] sa sobie rowne.\n", godzina_1, godzina_2);

	}
	return 0;
}
