#include <stdio.h>
#include <stdarg.h>
//Niestety nie wiem, czy zrozumialem zamysl. Chcialem uzyc wspomnianej przez Pana funkcji, ale z tego, co widzialem, musialbym podac argumenty juz w wywolaniu funkcji, wiec nie moglem tego powiazac ze scanfem.

//void printfAndScanfMerged(char*text, int n, ...)
void printfAndScanfMerged(char*text)
{
  int val;
  //va_list vl;
  //va_start(vl,n);
  //for (int i=0;i<n;i++)
  //{
    //val=va_arg(vl,int);
    //printf (" [%.2f]",val);
  //}
  while(*text!='\0')
  {
	if (*text == '%')
	{
		scanf(" %d", &val);
		text+=2;
	}
  	printf("%c",*text++);
  }
  //va_end(vl);
}

int main ()
{
  char* text = "Podaj krotszy bok prostokata: %d. Teraz podaj dluzszy: %d";
  printfAndScanfMerged (text);
  //printfAndScanfMerged (text, 2);
  return 0;
}
