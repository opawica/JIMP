#include <stdio.h>

int main()
{
	for (unsigned char ascii = 0; ascii<255; ascii++)
		printf("%d - %c\n", ascii, ascii);
	return 0;
}
