#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	char nazev[30] = "33_Soubory4.c";
	FILE * soubor = fopen(nazev, "r");

	char zasobnik[200];
#ifdef VARIANTA
	/* 1. varianta - po znacich */
	char c = ' ';
	while(c != EOF){
		c = fgetc(soubor); // cteni 1 znaku ze souboru
		putchar(c); // vypis do konzole

#elseif VARIANTA2
	while( !feof(soubor) ){
	/* 2 varianta - po radcich */
		fgets(zasobnik, 199, soubor);
		printf("%s", zasobnik);

#else 
	while( !feof(soubor) ){
	/* 3. varianta - po radcich */
		fscanf(soubor, "%199[^\n]\n", zasobnik);
		printf("%s\n", zasobnik);
#endif
	}

	return 0;
}

