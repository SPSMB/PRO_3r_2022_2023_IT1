#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* program kopiruje soubor
   pri spusteni programu> KOP soubor1 soubor2
    - KOP - jmeno tohoto programu
    - soubor1 - soubor, ktery ma byt kopirovan
    - soubor2 - jmeno noveho souboru
 */

FILE * otevriSoubor(char * jmeno, char * rezim){

	FILE * f = fopen(jmeno, rezim);
	if(f == NULL){
		printf("Soubor %s nebylo mozne otevrit.\n", jmeno);
		exit(1);
	} else {
		return f;
	}

}

#define CONST 10000

int main(int argc, char ** argv){

	FILE * sOdkud, * sKam; /* deklarace promennych */

	if(argc == 3){
		sOdkud = otevriSoubor(argv[1],"r");
		sKam = otevriSoubor(argv[2], "w");
	} else {
		printf("Zadan nespravny pocet parametru.\n");
		printf("Zadano: %d, ocekavano: %d", argc, 3);
		return 0;
	}

	char x; /* pro variantu 1 */
	char radek[CONST]; /* pro variantu 2 */
	int citac = 0; 
	char * indikator;

	do {
		indikator = fgets(radek, CONST, sOdkud);
		if(indikator == NULL) break;
		fputs(radek, sKam);
		/*
		x = fgetc(sOdkud);
		if(x == EOF) break;
		fputc(x, sKam);
		*/

		citac++;
	} while(1);

	printf("Uspesne zkopirovano %d radku.", citac);

	fclose(sOdkud);
	fclose(sKam);
	return 0;

}

















/*
	do {
		x = getchar();
		if(x == EOF) break;
		fputc(x, s);
	} while(1);
	*/