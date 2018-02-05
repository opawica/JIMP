#include <ncurses.h>
#include <stdio.h>
#include <math.h>
#include "Menu.h"
#include "MainFunctions.h"
#include "DrawingFunctions.h"
#include "DeterminantsFunctions.h"

int main()
{
	initscr();
	int width = 0;
	int height = 0;
	getmaxyx(stdscr, height, width);
	
	showTitle(width, height);
	showPressText(width, height);
	noecho();

	int menu_size[6] = {};
	const char menu_1[] = "OBLICZANIE WYZNACZNIKA";
	menu_size[0] = sizeof(menu_1);
	const char menu_2[] = "OBLICZANIE RZEDU MACIERZY";
	menu_size[1] = sizeof(menu_2);
	const char menu_3[] = "DODAWANIE MACIERZY";
	menu_size[2] = sizeof(menu_3);
	const char menu_4[] = "MNOZENIE MACIERZY";
	menu_size[3] = sizeof(menu_4);
	const char menu_5[] = "MNOZENIE MACIERZY PRZEZ SKALAR";
	menu_size[4] = sizeof(menu_5);
	const char menu_6[] = "WYJSCIE";
	menu_size[5] = sizeof(menu_6);

	int option = 1;
	int after_splash = 0;
	int pressed;
	const short int min_option = 1;
	const short int max_option = 6;
	do
	{
		pressed = getch();
		pressed = menuMoving(pressed);
		clear();
		option = menuMoving2(pressed, option, min_option, max_option);
       
		if(pressed == 10 && after_splash)
		{
			switch(option)
			{
				case 1:
					determinant(width, height);
					break;
				case 2:
					rank(width, height);
					break;
				case 3:
					addMatrix(width, height);
					break;
				case 4:
					multiplyMatrix(width, height);
					break;
				case 5:
					multiplyMatrixAndScalar(width, height);
					break;
				case 6:
					endwin();
					return 0;
			}
		}
		after_splash = 1;
		showTitle(width, height);
		displayMenu(height, width, option, menu_1, menu_2, menu_3, menu_4, menu_5, menu_6, menu_size);
		attroff( A_REVERSE );

	} while(1);
	endwin();
}
