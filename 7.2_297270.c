#include <stdio.h>
#include <stdarg.h>

void printfAndScanfMerged(const char*text)
{

  while(*text!='\0')
  {
	if (*text == '%')
	{
		scanf(" %d", &val);
		text+=2;
	}
  	printf("%c",*text++);
  }
}

int main ()
{
  const char* text = "Podaj krotszy bok prostokata: %d. Teraz podaj dluzszy: %d";
  printfAndScanfMerged (text);
  return 0;
}
