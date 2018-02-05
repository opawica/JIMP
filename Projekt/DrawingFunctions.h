#ifndef DRAWING_FUNCTIONS_INCLUDED
#define DRAWING_FUNCTIONS_INCLUDED

void drawResultMatrix(int width, int matrix[3][3], int current_pos_x, int current_pos_y, int extra);
int drawScalar(int width, int matrix[3][3], int current_pos_x, int current_pos_y, char current_element[4], char temp_element);
int drawMatrix(int width, int matrix[3][3], int current_pos_x, int current_pos_y, char current_element[4], char temp_element, int second_matrix);

#endif
