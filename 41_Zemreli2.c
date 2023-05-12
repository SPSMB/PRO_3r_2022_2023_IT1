#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DELKARETEZCE 20
#define DELKA 200

#pragma warning(disable:4996)

typedef struct zaznam{
	int hodnota;
	int rok;
	int tyden;
	char cas_od[DELKARETEZCE];
	char cas_do[DELKARETEZCE];
	char vek_txt[DELKARETEZCE];
} Zaznam;

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

void alokujPamet(Zaznam ** databaze, int pRadku){

	*databaze = (Zaznam*) malloc(sizeof(Zaznam) * pRadku);
	printf("Bylo alokovano celkem %d bytu pameti.\n", sizeof(Zaznam) * pRadku);
}

void uvolniPamet(Zaznam ** databaze, int pRadku){

	free(*databaze);
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

void zpracujRadek(char * radek, int r, Zaznam * databaze){

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
			if(s == 2) databaze[r].hodnota = atoi(tmp);
			if(s == 8) databaze[r].rok = atoi(tmp);
			if(s == 9) databaze[r].tyden = atoi(tmp);
			if(s == 11) strncpy(databaze[r].cas_od,  tmp, DELKARETEZCE);
			if(s == 12) strncpy(databaze[r].cas_do,  tmp, DELKARETEZCE);
			if(s == 13) strncpy(databaze[r].vek_txt, tmp, DELKARETEZCE);
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
}

void vypisFiltr(Zaznam * db, int vel, int * nalezy, int pocetNalezu){
	
	int nalez = 0;
	if(pocetNalezu != 0){
		printf("--------------------------------------------------------\n");
		
		for(int i=0; i<vel; i++){

			if(nalezy[i] == 1){
				if (nalez%15 == 0) printf("ID   |ROK  |TYDEN|HODN.|KATEGORIE|OD        |DO        |\n");
				nalez++;
				printf("%5d|%5d|%5d|%5d|%9s|%10s|%10s|\n",i,db[i].rok, db[i].tyden, 
						db[i].hodnota,db[i].vek_txt, db[i].cas_od, db[i].cas_do);

			}
		}
		printf("--------------------------------------------------------\nK");
	}
	printf("Filtru odpovídá %d záznamů.\n", pocetNalezu);
}

/* Filtr vypisuje jen zaznamy pro urcitou kategorii (kat) mezi urcitymi datumy (dat1 - dat2)  
   vypis - kdyz je 0, nevypisuje nic
   vystup - 's' - vraci soucet z filtrovaych hodnot
   	 		'p' - vraci prumer z filtrovanych hodnot
*/
int filtr(Zaznam * db, int vel, char * kat, char * dat1, char * dat2, int vypis, char vystup){
	int pocet = 0;
	int soucet = 0;

	int * nalezy = (int*) calloc(vel, sizeof(int));
	for(int i=0; i<vel; i++){
		/*if(strcmp(db[i].vek_txt,kat) == 0){*/ /* toto bz bzlo skvele, kdyby tam nebyla kategorie 85+*/
		if((strcmp(db[i].cas_od,dat2) <= 0) && 
		   (strcmp(db[i].cas_do,dat1) >= 0) && 
		   (db[i].vek_txt[0] == kat[0])		&& 
		   (db[i].vek_txt[1] == kat[1])){
			nalezy[i] = 1;
			soucet += db[i].hodnota;
			pocet++;
		}		
	}
	
	if(vypis != 0){
		vypisFiltr(db, vel, nalezy, pocet);
	}
	
	free(nalezy);
	if(vystup == 's'){
		return soucet;
	} else if(pocet != 0) {
		return soucet/pocet;
	} else {
		return -1;
	}
}

int pocetDnuOdPocatku(int rok, int mesic, int den){
	
	int pocetDni = 0;
	// 1) resim roky
	pocetDni = rok * 365;

	// 2) resim mesice
	int mesice[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=0; i<mesic-1 ;i++){
		pocetDni += mesice[i];
	}

	// 3) resim dny
	pocetDni += den;

	return pocetDni;
}

double pocetLetMeziDatumy(char * datum1, char * datum2){

	int rok1, mesic1, den1;
	int rok2, mesic2, den2;

	sscanf(datum1,"%d-%d-%d", &rok1, &mesic1, &den1);
	sscanf(datum2,"%d-%d-%d", &rok2, &mesic2, &den2);

	// printf("Test: rok: %d, mesic: %d, den %d", rok1, mesic1, den1);

	int celkovyPocet1 = pocetDnuOdPocatku(rok1, mesic1, den1);
	int celkovyPocet2 = pocetDnuOdPocatku(rok2, mesic2, den2);

	int rozdilVeDnech = celkovyPocet2 - celkovyPocet1;
	return (double)rozdilVeDnech/365;
}

/* funkce vrati procentualni narust zmeny z hodnoty1 na hodnotu2 */
double procentualniNarust(int hodnota1, int hodnota2){
	return ((100*(hodnota2/(double)hodnota1))-100);
}

void analyzaCovidu1(Zaznam * db, int velDB, char * kategorie, char * datum2){

	printf("Analyza covidu 1\n");
	char datum1[DELKARETEZCE] = "2020-01-01";

	int soucetZa9let = filtr(db, velDB, kategorie, "2011-01-01", "2019-12-31", 0, 's');
	int rocniPrumerBezCovidu = soucetZa9let / 9;
	printf("Krok cislo 1b: Rocni prumer za roky 2011-2019 v kategorii %s je %d.\n", 
		kategorie, rocniPrumerBezCovidu);

	int soucetzaXlet = filtr(db, velDB, kategorie, datum1, datum2, 0, 's');
	double pocetLet = pocetLetMeziDatumy(datum1, datum2);
	int prumer1 = (int) round(soucetzaXlet/pocetLet);
	printf("Krok cislo 2a: Rocni prumer za obdobi %s - %s v kategorii %s je %d.\n", 
		datum1, datum2, kategorie, prumer1);

	printf("Tedy ve sledovanem obdobi (%.2f) zemrelo o %.0f vice lidi nez je bezne.\n", 
		pocetLet, soucetzaXlet - (rocniPrumerBezCovidu*pocetLet));
	printf("Narust je %.2f%%\n", procentualniNarust(rocniPrumerBezCovidu, prumer1));
}

// provadi analyzu pro kazdou vekovou skupinu zvlast
void analyzaCovidu2(Zaznam * db, int velDB, char * datum2){

	analyzaCovidu1(db, velDB, "0-14", datum2);
	analyzaCovidu1(db, velDB, "15-44", datum2);
	analyzaCovidu1(db, velDB, "45-", datum2);
	analyzaCovidu1(db, velDB, "65-", datum2);
	analyzaCovidu1(db, velDB, "75-", datum2);
	analyzaCovidu1(db, velDB, "85-", datum2);
}

void obsluhaUzivatele(Zaznam * db, int velDB){

	char vstup = 'X';
	while(1){
		printf("\nZadejte:\n");
		printf(" F <kategorie> <od> <do>: Filtr zemrelych v kategorii od do.\n");
		printf(" S <kategorie> <od> <do>: Soucet zemrelych v kategorii od do.\n");
		printf(" P <kategorie> <od> <do>: Prumer zemrelych v kategorii od do.\n");
		printf(" A <do>:                  Analyza covidu\n");
		printf(" B <do>:                  Analyza covidu pro vsechny vekove skupiny\n");
		printf(" D <od> <do>:             Pocet let mezi datumy od od\n");
		printf(" K:                       Konec programu.\n");

		scanf("%c", &vstup);
		char kategorie[DELKARETEZCE];
		char datum1[DELKARETEZCE];
		char datum2[DELKARETEZCE];
		if(vstup == 'F'){
			scanf("%s %s %s", kategorie, datum1, datum2);
			printf("Filtruji data v kategorii %s od data %s do data %s.\n",
				kategorie, datum1, datum2);
			int vystup = filtr(db, velDB, kategorie, datum1, datum2, 1, 's');
		} else if(vstup == 'S'){
			scanf("%s %s %s", kategorie, datum1, datum2);
			int soucet = filtr(db, velDB, kategorie, datum1, datum2, 0, 's');
			printf("Soucet zemrelych osob v kategorii %s od data %s do data %s je %d.\n", 
				kategorie, datum1, datum2, soucet);
		} else if(vstup == 'P'){
			scanf("%s %s %s", kategorie, datum1, datum2);
			int prumer = filtr(db, velDB, kategorie, datum1, datum2, 0, 'p');
			if(prumer == -1){
				printf("Nema smysl pocitat prumer z 0 hodnot.\n");
			} else {
				printf("Prumer zemrelych osob v kategorii %s od data %s do data %s je %d.\n", 
					kategorie, datum1, datum2, prumer);
			}
		} else if(vstup == 'A'){
			scanf("%s", datum2);
			analyzaCovidu1(db, velDB, "celkem", datum2);
		} else if(vstup == 'B'){
			scanf("%s", datum2);
			analyzaCovidu2(db, velDB, datum2);
		} else if(vstup == 'D') {
			scanf("%s %s", datum1, datum2);
			double pocet = pocetLetMeziDatumy(datum1, datum2);
			printf("Pocet let mezi %s a %s je %.2f", datum1, datum2, pocet);
		} else if(vstup == 'K') {
			break;
		} else {
			printf("Nezname zadani, prosim zkuste to znovu.\n");
		}
		while(getchar()!='\n'); // vycisteni vstupu
	}
}

int main(int argc, char ** argv){

	system("chcp 65001");
	const char * nazevSouboru = "40_zemreli.csv";
	int pocatecniKapacita = pocetRadku(nazevSouboru);

	Zaznam * databaze;

	alokujPamet(&databaze, pocatecniKapacita);
	
	FILE * f = otevriSoubor(nazevSouboru, "r");
	char buf[DELKA];
	fscanf(f, "%*[^\n]\n"); 	/* nacteni 1 radku bez ulozeni */

	for(int i = 0; fgets(buf, DELKA, f) && i < pocatecniKapacita; i++){
		if(strlen(buf) > 14){
			zpracujRadek(buf, i, databaze);
			/*printf("%d: rok:%d, tyden:%d, vek:%s, hodnota:%d\n", i, 
				databaze[i].rok, databaze[i].tyden, databaze[i].vek_txt, databaze[i].hodnota);
			*/
		}
	}
	
	obsluhaUzivatele(databaze, pocatecniKapacita);

	uvolniPamet(&databaze, pocatecniKapacita);
	printf("Uvolneni pameti uspesne.\n");
	return 0;
}

























