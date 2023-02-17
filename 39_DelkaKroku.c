#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void vypis2DPole(int ** tabulka, int pRadku, int pSloupcu) {
	for(int r=0; r<pRadku; r++){
		for(int s=0; s<pSloupcu; s++){
			if(s == pSloupcu-1){
				printf("%d\n", tabulka[r][s]);
			} else {
				printf("%d,", tabulka[r][s]);
			}
		}
	}
}

/*
	f - ukazatel na otevreny soubor typu FILE *
	tabulka - tabulka, kam ukladam data z CSV souboru
	pSlupcu - pocet sloupcu tabulky
	cisloRadku - cislo radku v tabulce, kam prave ukladame
*/
void nactiRadek(FILE * f, int ** tabulka, int cisloRadku, int pSloupcu){
	int r = cisloRadku;
	for(int s=0; s<pSloupcu; s++){
		if(s != pSloupcu-1){
			fscanf(f, "%d,", &(tabulka[r][s]));
		} else {
			fscanf(f, "%d", &(tabulka[r][s]));
		}
	}
}

void nactiDataZeSouboru(char * nazevSouboru, int ** tabulka, int pRadku, int pSloupcu){

	FILE * f = fopen(nazevSouboru,"r");

	for(int r=0; r<pRadku; r++){
		nactiRadek(f, tabulka, r, pSloupcu);
	}

	fclose(f);
}


int main(int argc, char ** argv){

	char * nazevSouboru = "delkaKroku.csv";

	int pRadku = 20;
	int pSloupcu = 4;

	int ** tabulka = (int **) malloc(pRadku * sizeof(int *));

	for(int i=0; i<pRadku; i++){
		tabulka[i] = (int *) malloc(pSloupcu * sizeof(int));
	}

	nactiDataZeSouboru(nazevSouboru, tabulka, pRadku, pSloupcu);
	vypis2DPole(tabulka, pRadku, pSloupcu);

	// uvolneni pameti na konci programu

	for(int i=0; i<pRadku; i++){
		free(tabulka[i]);
	}
	free(tabulka);

	return 0;

}


























