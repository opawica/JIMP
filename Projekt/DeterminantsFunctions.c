#include <ncurses.h>
#include <stdio.h>
#include <math.h>
#include "Menu.h"
#include "MainFunctions.h"
#include "DrawingFunctions.h"
#include "DeterminantsFunctions.h"

int countSingleDeterminants(int matrix[3][3])
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

int countSmallDeterminants(int matrix[3][3])
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

int countDeterminant(int matrix[3][3])
{
	int determinant_value;
	determinant_value = (matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[1][0]*matrix[2][1]*matrix[0][2])+(matrix[2][0]*matrix[0][1]*matrix[1][2]);
	determinant_value = determinant_value-(matrix[0][2]*matrix[1][1]*matrix[2][0])-(matrix[1][2]*matrix[2][1]*matrix[0][0])-(matrix[2][2]*matrix[0][1]*matrix[1][0]);	
	return determinant_value;
}
