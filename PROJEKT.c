#include <ncurses.h>
#include <stdio.h>
#include <math.h>

void drawResultMatrix(int width, int matrix[3][3], int current_pos_x, int current_pos_y, int extra)
{
	for (int i = 0 ; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char temp[4] = {};
			sprintf(temp, "%d", matrix[i][j]);
			mvprintw( 4+2*i+extra, width/2-7+7*j, temp);	
		}
	}
}

int drawScalar(int width, int matrix[3][3], int current_pos_x, int current_pos_y, char current_element[4], char temp_element)
{
	int k, scalar = 0;
	current_pos_y = 6;
	echo();
	current_pos_x = width/2;
	mvprintw(current_pos_y, current_pos_x, "_");
	move(current_pos_y , current_pos_x);	
	for (k = 0; k < 4; k++)
	{
		temp_element = getch();
		if (temp_element >= 48 && temp_element <= 57)
		{
			current_element[k] = temp_element;
			move(current_pos_y , ++current_pos_x);
			if (temp_element == 48 && k == 0)
				break;
			continue;
		}
		if (temp_element == 10)
			if (k <= 0)
				{
				k = -1;
				move(current_pos_y , current_pos_x);
				continue;
				}
			else
				break;
		else
		{
			k = -1;
			move(current_pos_y , current_pos_x);
		}

	}
	for (int l = 0; l < k;l++)
	{
		scalar+=(current_element[l]-48)*pow(10,k-l-1);
	}
	return scalar;
}


int drawMatrix(int width, int matrix[3][3], int current_pos_x, int current_pos_y, char current_element[4], char temp_element, int second_matrix)
{
	int k;

	for (int i = 0 ; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mvprintw( 4+2*i+second_matrix, width/2-7+7*j, "_");	
		}
	}

	echo();

	for (int i = 0 ; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			current_pos_y = 4+2*i+second_matrix;
			current_pos_x = width/2-7+7*j;
			move(current_pos_y , current_pos_x);
			for (k = 0; k < 4; k++)
			{
				temp_element = getch();
				if (temp_element >= 48 && temp_element <= 57)
				{
					current_element[k] = temp_element;
					move(current_pos_y , ++current_pos_x);
					if (temp_element == 48 && k == 0)
						break;
					continue;
				}
				if (temp_element == 10)
					if (k <= 0)
						{
						k = -1;
						move(current_pos_y , current_pos_x);
						continue;
						}
					else
						break;
				else
				{
					k = -1;
					move(current_pos_y , current_pos_x);
				}

			}
			for (int l = 0; l < k;l++)
			{
				matrix[i][j]+=(current_element[l]-48)*pow(10,k-l-1);
			}
		}
	}

	return current_pos_y;
}

int countSingleDets(int matrix[3][3])
{
	int det = 0, is_first_rank = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] != 0)
				is_first_rank = 1;
		if (is_first_rank)
			break;
	}

	return is_first_rank;
}

int countSmallDets(int matrix[3][3])
{
	int det = 0, is_second_rank = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			det = matrix[i][j]*matrix[i+1][j+1];
			det = det - matrix[i+1][j]*matrix[i][j+1];
		}
		if (det != 0)
		{
			is_second_rank = 1;
			break;
		}
	}

	return is_second_rank;
}

int countDet(int matrix[3][3])
{
	int determinant_value;
	determinant_value = (matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[1][0]*matrix[2][1]*matrix[0][2])+(matrix[2][0]*matrix[0][1]*matrix[1][2]);
	determinant_value= determinant_value-(matrix[0][2]*matrix[1][1]*matrix[2][0])-(matrix[1][2]*matrix[2][1]*matrix[0][0])-(matrix[2][2]*matrix[0][1]*matrix[1][0]);	
	return determinant_value;
}

void determinant(int width, int height)
{
	clear();

	int current_pos_x, current_pos_y;
	char current_element[4] = {};
	char temp_element;
	int matrix[3][3] = {};

	const char det_title[] = "OBLICZANIE WYZNACZNIKA MACIERZY 3x3";
	const char det_subtitle[] = "(wartosci naturalne, max. 9999)";
	const char det_result[] = "Wyznacznik tej macierzy wynosi:";
	attron(A_BOLD);
	mvprintw( 1, width/2 - sizeof(det_title)/2, det_title);
	attroff(A_BOLD);
	attron(A_UNDERLINE);
	mvprintw( 2, width/2 - sizeof(det_subtitle)/2, det_subtitle);
	attroff(A_UNDERLINE);

	current_pos_y = drawMatrix(width, matrix, current_pos_x, current_pos_y, current_element, temp_element, 0);

	char det[20];
	sprintf(det, "%d", countDet(matrix));

	mvprintw(current_pos_y+2, 0, det_result);
	attron(A_BOLD);
	mvprintw(current_pos_y+2, sizeof(det_result), det);
	attroff(A_BOLD);

	noecho();
	getch();
	clear();
}

void rank(int width, int height)
{
	clear();

	int current_pos_x, current_pos_y;
	char current_element[4] = {};
	char temp_element;
	int matrix[3][3] = {};

	const char rank_title[] = "OBLICZANIE RZEDU MACIERZY 3x3";
	const char rank_subtitle[] = "(wartosci naturalne, max. 9999)";
	const char rank_result[] = "Rzad tej macierzy wynosi:";
	attron(A_BOLD);
	mvprintw( 1, width/2 - sizeof(rank_title)/2, rank_title);
	attroff(A_BOLD);
	attron(A_UNDERLINE);
	mvprintw( 2, width/2 - sizeof(rank_subtitle)/2, rank_subtitle);
	attroff(A_UNDERLINE);

	current_pos_y = drawMatrix(width, matrix, current_pos_x, current_pos_y, current_element, temp_element, 0);

	char rank[1];
	int det_ = countDet(matrix);
	if (det_ != 0)
		sprintf(rank, "%d", 3);
	else if (countSmallDets(matrix))
		sprintf(rank, "%d", 2);
	else if (countSingleDets(matrix))
		sprintf(rank, "%d", 1);
	else
		sprintf(rank, "%d", 0);

	mvprintw(current_pos_y+2, 0, rank_result);
	attron(A_BOLD);
	mvprintw(current_pos_y+2, sizeof(rank_result), rank);
	attroff(A_BOLD);

	noecho();
	getch();
	clear();
}

void addMatrix(int width, int height)
{
	clear();

	int current_pos_x, current_pos_y;
	char current_element[4] = {};
	char temp_element;
	int matrix[3][3] = {};
	int matrix2[3][3] = {};

	const char det_title[] = "DODAWANIE MACIERZY 3x3";
	const char det_subtitle[] = "(wartosci naturalne, max. 9999)";
	attron(A_BOLD);
	mvprintw( 1, width/2 - sizeof(det_title)/2, det_title);
	attroff(A_BOLD);
	attron(A_UNDERLINE);
	mvprintw( 2, width/2 - sizeof(det_subtitle)/2, det_subtitle);
	attroff(A_UNDERLINE);

	current_pos_y = drawMatrix(width, matrix, current_pos_x, current_pos_y, current_element, temp_element, 0);
	mvprintw(current_pos_y+1, width/2, "+");
	current_pos_y = drawMatrix(width, matrix2, current_pos_x, current_pos_y, current_element, temp_element, current_pos_y/2+2);
	mvprintw(current_pos_y+1, width/2, "=");

	for (int i = 0;i<3;i++)
		for (int j = 0; j < 3; j++)
			matrix2[i][j]+=matrix[i][j];
	drawResultMatrix(width, matrix2, current_pos_x, current_pos_y, current_pos_y/2+6);

	noecho();
	getch();
	clear();
}

void multiplyMatrix(int width, int height)
{
	clear();

	int current_pos_x, current_pos_y;
	char current_element[4] = {};
	char temp_element;
	int matrix[3][3] = {};
	int matrix2[3][3] = {};
	int result_matrix[3][3] = {};

	const char det_title[] = "MNOZENIE MACIERZY 3x3";
	const char det_subtitle[] = "(wartosci naturalne, max. 9999)";
	attron(A_BOLD);
	mvprintw( 1, width/2 - sizeof(det_title)/2, det_title);
	attroff(A_BOLD);
	attron(A_UNDERLINE);
	mvprintw( 2, width/2 - sizeof(det_subtitle)/2, det_subtitle);
	attroff(A_UNDERLINE);

	current_pos_y = drawMatrix(width, matrix, current_pos_x, current_pos_y, current_element, temp_element, 0);
	mvprintw(current_pos_y+1, width/2, "*");
	current_pos_y = drawMatrix(width, matrix2, current_pos_x, current_pos_y, current_element, temp_element, current_pos_y/2+2);
	mvprintw(current_pos_y+1, width/2, "=");

	for (int i = 0;i<3;i++)
		for (int j = 0; j < 3; j++)
			result_matrix[i][j] = matrix[i][0]*matrix2[0][j]+matrix[i][1]*matrix2[1][j]+matrix[i][2]*matrix2[2][j];
	drawResultMatrix(width, result_matrix, current_pos_x, current_pos_y, current_pos_y/2+6);

	noecho();
	getch();
	clear();
}

void multiplyMatrixAndScalar(int width, int height)
{
	clear();

	int current_pos_x, current_pos_y, scalar;
	char current_element[4] = {};
	char temp_element;
	int matrix[3][3] = {};

	const char det_title[] = "MNOZENIE MACIERZY 3x3 PRZEZ SKALAR";
	const char det_subtitle[] = "(wartosci naturalne, max. 9999)";
	attron(A_BOLD);
	mvprintw( 1, width/2 - sizeof(det_title)/2, det_title);
	attroff(A_BOLD);
	attron(A_UNDERLINE);
	mvprintw( 2, width/2 - sizeof(det_subtitle)/2, det_subtitle);
	attroff(A_UNDERLINE);

	scalar = drawScalar(width, matrix, current_pos_x, current_pos_y, current_element, temp_element);
	mvprintw(7, width/2, "*");
	current_pos_y = drawMatrix(width, matrix, current_pos_x, 7, current_element, temp_element, 4);
	mvprintw(current_pos_y+1, width/2, "=");

	for (int i = 0;i<3;i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j]*=scalar;
	drawResultMatrix(width, matrix, current_pos_x, current_pos_y, current_pos_y/2+6);

	noecho();
	getch();
	clear();
}

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
