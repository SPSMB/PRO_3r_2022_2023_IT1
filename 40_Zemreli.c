#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELKARETEZCE 15

#pragma warning(disable:4996)

// funkce vrati pocet radku
int pocetRadku(const char * nazevSouboru){

	FILE * f = fopen(nazevSouboru, "r");
	if(f == NULL){
		printf("Chyba, soubor se nepovedlo otevrit.\n");
		exit(1);
	}
	int pocet = 0;
	char c;
	do{
		c = fgetc(f);
		if(c == '\n'){
			pocet++;
		}
	}while(c != EOF);
	printf("Pocet radku v souboru je %d.\n", pocet);
	return pocet;
}

void alokujPamet(int ** hodnota, int ** rok, int ** tyden, 
	char *** cas_od, char *** cas_do, char *** vek_txt, int pRadku){

	int pocetBytu = 0;

	*hodnota = (int *) malloc(sizeof(int) * pRadku);
	*rok = (int *) malloc(sizeof(int) * pRadku);
	*tyden = (int *) malloc(sizeof(int) * pRadku);
	*cas_od = (char **) malloc(sizeof(char *) * pRadku);
	*cas_do = (char **) malloc(sizeof(char *) * pRadku);
	*vek_txt = (char **) malloc(sizeof(char *) * pRadku);

	pocetBytu += sizeof(int) * pRadku * 3;
	pocetBytu += sizeof(char) * pRadku * 3;

	for(int i=0; i<pRadku; i++){
		(*cas_od)[i] = (char *) malloc(sizeof(char) * DELKARETEZCE);
		(*cas_do)[i] = (char *) malloc(sizeof(char) * DELKARETEZCE);
		(*vek_txt)[i] = (char *) malloc(sizeof(char) * DELKARETEZCE);
		pocetBytu += sizeof(char) * DELKARETEZCE * 3;
	}

	printf("Bylo alokovano celkem %d bytu pameti.\n", pocetBytu);
}

void uvolniPamet(int ** hodnota, int ** rok, int ** tyden, 
	char *** cas_od, char *** cas_do, char *** vek_txt, int pRadku){

	for(int i=0; i<pRadku; i++){
		free((*cas_od)[i]);
		free((*cas_do)[i]);
		free((*vek_txt)[i]);
	}

	free(*hodnota);
	free(*rok);
	free(*tyden);
	free(*cas_od);
	free(*cas_do);
	free(*vek_txt);
}

int main(int argc, char ** argv){

	int pocatecniKapacita = pocetRadku("40_zemreli.csv");

	int * hodnota; 			/* pocet zemrelych pro danou kategorii a dany tyden */
	int * rok; 	  		 	/* rok */
	int * tyden;			/* tyden */
	char ** cas_od; 		/* prvni den sledovaneho tydne */
	char ** cas_do; 		/* posledni den sledovaneho tydne */
	char ** vek_txt;		/* vekova skupina (textove) */

	alokujPamet(&hodnota, &rok, &tyden, &cas_od, &cas_do, &vek_txt, pocatecniKapacita);



	uvolniPamet(&hodnota, &rok, &tyden, &cas_od, &cas_do, &vek_txt, pocatecniKapacita);
	printf("Uvolneni pameti uspesne.\n");
	return 0;
}


























