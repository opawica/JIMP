#include <ncurses.h>
#include <stdio.h>
#include <math.h>
#include "Menu.h"
#include "MainFunctions.h"
#include "DrawingFunctions.h"
#include "DeterminantsFunctions.h"

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
