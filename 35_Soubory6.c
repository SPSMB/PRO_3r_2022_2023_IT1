#include <stdio.h>
#include <string.h>

/* program cte, co uzivatel zada do konzole a to az
	po signal EOF (CTRL+Z) */

int main(){

	char nazev[100];
	char x;

	printf("Prosim zadejte nazev souboru: ");
	scanf("%s", nazev);
	getchar(); /*precte ze vstupu enter navic */
	FILE * s = fopen(nazev, "w");

	printf("Piste cokoliv, konec pres CTRL+Z:\n");

	do {
		x = getchar();
		if(x == EOF) break;
		fputc(x, s);
	} while(1);

	fclose(s);
	return 0;
}

