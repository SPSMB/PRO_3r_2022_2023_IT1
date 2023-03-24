#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELKARETEZCE 15
#define DELKA 200

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

FILE * otevriSoubor(const char * nazevSouboru, char * mode){

	FILE * f = fopen(nazevSouboru,mode);

	if (f == NULL)
	{
		printf("nepovedlo se otevrit soubor %s\n", nazevSouboru);
		exit(0);
	}
	printf("povedlo se otevrit soubor %s\n", nazevSouboru);
	return f;
}

/*  radek - pole charu - obsah radku
	r - cislo radku 
	hodnota - pole s hodnotami
	rok - pole s roky
	tyden - pole s tydny
 */

void zpracujRadek(char * radek, int r, int * hodnota, int * rok, int * tyden, 
	char ** cas_od, char ** cas_do, char ** vek_txt){

	/*  1 ukazkovy radek:
		"832459719","9","5393","7700",
		"400000610015000","97","19","2011",
		"01","2011-W01","2011-01-03","2011-01-09",
		"0-14",
	*/

	int i = 0; 				/* index do pole radek */
	int s = 1; 				/* cislo sloupce */
	int t = 0; 				/* index do pole tmp */
	char tmp[DELKARETEZCE]; /* prostor pro uzitecny obsah */
	
	// ctu radek po 1 znaku od zacatku do konce
	while(radek[i] != '\n'){
		if(radek[i] == ','){
			tmp[t]='\0';
			t=0;
			// ukladam obsah tmp do velkeho pole
			if(s == 2) hodnota[r] = atoi(tmp);
			if(s == 8) rok[r] = atoi(tmp);
			if(s == 9) tyden[r] = atoi(tmp);
			if(s == 11) strncpy(cas_od[r],  tmp, DELKARETEZCE);
			if(s == 12) strncpy(cas_do[r],  tmp, DELKARETEZCE);
			if(s == 13) strncpy(vek_txt[r], tmp, DELKARETEZCE);
			s++;
		} else if(radek[i] == '"'){
			i++;
			continue; // chceme uvozovku zahodit
		} else { // jakykoliv jiny obsah nez carka nebo uvozovka
			// uzitecny obsah
			if(s==2 || s==8 || s==9 || s==11 || s==12 || s==13){
				tmp[t] = radek[i];
				t++;
			// neuzitecny obsah
			} else {
				i++;
				continue; // zahazujeme
			}
		}
		i++;
	}
	if(r > 4408) printf("Cislo radku: %d\n", r);
}

int main(int argc, char ** argv){

	const char * nazevSouboru = "40_zemreli.csv";
	int pocatecniKapacita = pocetRadku(nazevSouboru);

	int * hodnota; 			/* pocet zemrelych pro danou kategorii a dany tyden */
	int * rok; 	  		 	/* rok */
	int * tyden;			/* tyden */
	char ** cas_od; 		/* prvni den sledovaneho tydne */
	char ** cas_do; 		/* posledni den sledovaneho tydne */
	char ** vek_txt;		/* vekova skupina (textove) */

	alokujPamet(&hodnota, &rok, &tyden, &cas_od, &cas_do, &vek_txt, pocatecniKapacita);
	
	FILE * f = otevriSoubor(nazevSouboru, "r");
	char buf[DELKA];
	fscanf(f, "%*[^\n]\n"); 	/* nacteni 1 radku bez ulozeni */

	for(int i = 0; fgets(buf, DELKA, f) && i < pocatecniKapacita; i++){
		if(strlen(buf) > 14){
			zpracujRadek(buf, i, hodnota, rok, tyden, cas_od, cas_do, vek_txt);
			printf("%d: rok:%d, tyden:%d, vek:%s, hodnota:%d\n", i, rok[i], tyden[i], vek_txt[i], hodnota[i]);
		}
	}

	uvolniPamet(&hodnota, &rok, &tyden, &cas_od, &cas_do, &vek_txt, pocatecniKapacita);
	printf("Uvolneni pameti uspesne.\n");
	return 0;
}


























