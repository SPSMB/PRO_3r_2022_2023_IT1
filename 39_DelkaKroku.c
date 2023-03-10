#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

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
	if(f == NULL){
		printf("Chyba, soubor se nepovedlo otevrit.\n");
		exit(1);
	}

	for(int r=0; r<pRadku; r++){
		nactiRadek(f, tabulka, r, pSloupcu);
	}

	fclose(f);
}

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

void alokujTabulku(int *** tabulka, int pRadku, int pSloupcu){

	*tabulka = (int **) malloc(pRadku * sizeof(int *));

	for(int i=0; i<pRadku; i++){
		(*tabulka)[i] = (int *) malloc(pSloupcu * sizeof(int));
	}

}

void uvolneniPameti(int ** tabulka, int pRadku){
	for(int i=0; i<pRadku; i++){
		free(tabulka[i]);
	}
	free(tabulka);
}

void analyza1(int ** tabulka, int pRadku, int pSloupcu){
	int soucetDo30 = 0; int soucetDo60 = 0; int soucetNad60 = 0;
	int pocetDo30 = 0; int pocetDo60 = 0; int pocetNad60 = 0;

	for(int r = 0; r < pRadku; r++){
		if(tabulka[r][1] < 30){
			pocetDo30++;
			soucetDo30+=tabulka[r][3];
		} else if(tabulka[r][1] > 60){
			pocetNad60++;
			soucetNad60+=tabulka[r][3];
		} else {
			pocetDo60++;
			soucetDo60+=tabulka[r][3];
		}
	}

	printf("Prumerna delka kroku ve skupine do 30 let je %.2f\n", (double)soucetDo30/pocetDo30);
	printf("Prumerna delka kroku ve skupine do 60 let je %.2f\n", (double)soucetDo60/pocetDo60);
	printf("Prumerna delka kroku ve skupine nad 60 let je %.2f\n", (double)soucetNad60/pocetNad60);
}


int main(int argc, char ** argv){

	char * nazevSouboru = "39_delkaKroku.csv";

	int pRadku = pocetRadku(nazevSouboru);
	int pSloupcu = 4;

	int ** tabulka;
	alokujTabulku(&tabulka, pRadku, pSloupcu);
	nactiDataZeSouboru(nazevSouboru, tabulka, pRadku, pSloupcu);
	vypis2DPole(tabulka, pRadku, pSloupcu);
	analyza1(tabulka, pRadku, pSloupcu);
	uvolneniPameti(tabulka, pRadku); // uvolneni pameti na konci programu

	return 0;
}


























