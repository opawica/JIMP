#ifndef MENU_INCLUDED
#define MENU_INCLUDED

void showTitle(int width, int height);

void showPressText(int width, int height);

int menuMoving(int pressed);

int menuMoving2(int pressed, int option, int min_option, int max_option);

void displayMenu(int height, int width, int option, const char *menu_1, const char *menu_2, const char *menu_3, const char *menu_4, const char *menu_5, const char *menu_6, int menu_size[6]);

#endif
