#include <ncurses.h>
#include <stdio.h>
#include <math.h>
#include "Menu.h"
#include "MainFunctions.h"
#include "DrawingFunctions.h"
#include "DeterminantsFunctions.h"

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
	int det_ = countDeterminant(matrix);
	if (det_ != 0)
		sprintf(rank, "%d", 3);
	else if (countSmallDeterminants(matrix))
		sprintf(rank, "%d", 2);
	else if (countSingleDeterminants(matrix))
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
