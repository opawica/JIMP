#include <ncurses.h>
#include <stdio.h>
#include <math.h>
#include "Menu.h"
#include "MainFunctions.h"
#include "DrawingFunctions.h"
#include "DeterminantsFunctions.h"

void showTitle(int width, int height)
{
	const char title_text[] = "KALKULATOR MACIERZY 3x3";
	attron(A_BOLD);
	mvprintw( height/2-4, width/2 - sizeof(title_text)/2, title_text );
	attroff(A_BOLD);
}

void showPressText(int width, int height)
{
	const char whatever_text[] = "Nacisnij dowolny klawisz, aby kontynuowac...";
	mvprintw( height/2-1, width/2 - sizeof(whatever_text)/2, whatever_text );
}


int menuMoving(int pressed)
{
	if (pressed == '\033')
	    pressed = getch();
	return pressed;
}

int menuMoving2(int pressed, int option, int min_option, int max_option)
{
	if( pressed == 'A' && option != min_option )
	{
	    option--;
	}
	else if( pressed == 'B' && option != max_option )
	{
	    option++;
	}
	return option;
}

void displayMenu(int height, int width, int option, const char *menu_1, const char *menu_2, const char *menu_3, const char *menu_4, const char *menu_5, const char *menu_6, int menu_size[6])
{
	switch(option)
	{
		case 1:
		    mvprintw(height/2, width/2 - menu_size[1]/2, menu_2);
		    mvprintw(height/2+1, width/2 - menu_size[2]/2, menu_3);
		    mvprintw(height/2+2, width/2 - menu_size[3]/2, menu_4);
		    mvprintw(height/2+3, width/2 - menu_size[4]/2, menu_5);
		    mvprintw(height/2+5, width/2 - menu_size[5]/2, menu_6);
		    attron(A_REVERSE);
		    mvprintw(height/2-1, width/2 - menu_size[0]/2, menu_1);
		    break;

		case 2:
		    mvprintw(height/2-1, width/2 - menu_size[0]/2, menu_1);
		    mvprintw(height/2+1, width/2 - menu_size[2]/2, menu_3);
		    mvprintw(height/2+2, width/2 - menu_size[3]/2, menu_4);
		    mvprintw(height/2+3, width/2 - menu_size[4]/2, menu_5);
		    mvprintw(height/2+5, width/2 - menu_size[5]/2, menu_6);
		    attron(A_REVERSE);
		    mvprintw(height/2, width/2 - menu_size[1]/2, menu_2);
		    break;

		case 3:
		    mvprintw(height/2-1, width/2 - menu_size[0]/2, menu_1);
		    mvprintw(height/2, width/2 - menu_size[1]/2, menu_2);
		    mvprintw(height/2+2, width/2 - menu_size[3]/2, menu_4);
		    mvprintw(height/2+3, width/2 - menu_size[4]/2, menu_5);
		    mvprintw(height/2+5, width/2 - menu_size[5]/2, menu_6);
		    attron(A_REVERSE);
		    mvprintw(height/2+1, width/2 - menu_size[2]/2, menu_3);
		    break;

		case 4:
		    mvprintw(height/2-1, width/2 - menu_size[0]/2, menu_1);
		    mvprintw(height/2, width/2 - menu_size[1]/2, menu_2);
		    mvprintw(height/2+1, width/2 - menu_size[2]/2, menu_3);
		    mvprintw(height/2+3, width/2 - menu_size[4]/2, menu_5);
		    mvprintw(height/2+5, width/2 - menu_size[5]/2, menu_6);
		    attron(A_REVERSE);
		    mvprintw(height/2+2, width/2 - menu_size[3]/2, menu_4);
		    break;

		case 5:
		    mvprintw(height/2-1, width/2 - menu_size[0]/2, menu_1);
		    mvprintw(height/2, width/2 - menu_size[1]/2, menu_2);
		    mvprintw(height/2+1, width/2 - menu_size[2]/2, menu_3);
		    mvprintw(height/2+2, width/2 - menu_size[3]/2, menu_4);
		    mvprintw(height/2+5, width/2 - menu_size[5]/2, menu_6);
		    attron(A_REVERSE);
		    mvprintw(height/2+3, width/2 - menu_size[4]/2, menu_5);
		    break;

		case 6:
		    mvprintw(height/2-1, width/2 - menu_size[0]/2, menu_1);
		    mvprintw(height/2, width/2 - menu_size[1]/2, menu_2);
		    mvprintw(height/2+1, width/2 - menu_size[2]/2, menu_3);
		    mvprintw(height/2+2, width/2 - menu_size[3]/2, menu_4);
		    mvprintw(height/2+3, width/2 - menu_size[4]/2, menu_5);
		    attron(A_REVERSE);
		    mvprintw(height/2+5, width/2 - menu_size[5]/2, menu_6);
		    break;
	}
}
