#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int przedzial3do5(int kule[])
{
	int kula;

	if(kule[3]<kule[4])
		kula = 4;
	else if (kule[3]>kule[4])
		kula = 3;
	else
		kula = 5;


	return kula;
}

int przedzial0do2(int kule[])
{
	int kula;

	if(kule[0]<kule[1])
		kula = 1;
	else if (kule[0]>kule[1])
		kula = 0;
	else
		kula = 2;


	return kula;
}

int przedzial6do8(int kule[])
{
	int kula;

	if(kule[6]<kule[7])
		kula = 7;
	else if (kule[6]>kule[7])
		kula = 6;
	else
		kula = 8;


	return kula;
}
int main()
{
	srand(time(NULL));	
	int losowana = rand()%9;
	int kule[9] = {};
	int ciezka = -1;
	kule[losowana]=1;

	printf("Wylosowano kule nr %d jako ciezsza kule.\n", losowana+1);

	if(kule[0]+kule[1]+kule[2]<kule[3]+kule[4]+kule[5])
		ciezka = przedzial3do5(kule);
	else if(kule[0]+kule[1]+kule[2]>kule[3]+kule[4]+kule[5])
		ciezka = przedzial0do2(kule);
	else
		ciezka = przedzial6do8(kule);

	printf("Kula ciezsza to kula o numerze %d\n", ciezka+1);

	return 0;
}
