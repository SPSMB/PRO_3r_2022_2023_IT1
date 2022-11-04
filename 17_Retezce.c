#include <stdio.h>
#include <string.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'strncpy': This function or variable may be unsafe.
#pragma warning(disable:4996)

int main(void){

	/*
	const char * a = "Stredni prumyslova skola";
	int i = 1;
	char b; b = *a;

	while(b != '\0'){
		printf("%c\n", b);
		b = *(a+i);
		i+=1;
	}
	*/

	// kopirovani retezce
	// ------------------
	char a[50] = "";
	// takto ne
	// a = "AHOJ";
	strncpy(a, "AHOJ", 4);
	printf("%s\n", a);

	const char * c = "Konstantni retezec";
	char b[50] = "Stredni prumyslova skola";
	char d[50] = "Stredni prumyslova skola";
	strncpy(a, c, 50);
	printf("%s\n", a);

	// porovnani retezcu
	// -----------------
	int vysledek = (c == "Konstantni retezec");
	printf("vysledek porovnani: %d\n", vysledek);
	int vysledek2 = (*b == *d);
	printf("vysledek porovnani2: %d\n", vysledek2);

	// spravne porovnani - funkce strcmp
	int vysledek3 = strcmp(b,d);
	printf("Spravne porovnani STRCMP: %d\n", vysledek3);

	// sizeof vs strlen
	// ----------------
	// konstantni retezce
	printf("Velikost C: (SIZEOF): %d\n", sizeof(c));
	printf("Velikost C: (STRLEN): %d\n", strlen(c));
	// pole charu
	printf("Velikost D: (SIZEOF): %d\n", sizeof(d));
	printf("Velikost D: (STRLEN): %d\n", strlen(d));

	// vypis neexistujiho znaku z konst retezce
	// ----------------------------------------
	printf("Vypis49: %c\n", c[100]);
	printf("Vypis49: %c\n", c[200]);
	printf("Vypis49: %c\n", c[300]);
	// Nasledujici radek vede K PADU PROGRAMU, protoze saham do pameti, ktera neexistuje !!!
	// printf("Vypis49: %c\n", c[40000000000]); 
	printf("Vypis50: -------------\n");


	// vyhledani podretezce
	// --------------------
	char r[50] = "Toto je ukazkovy retezec.";
	char pod[50] = "ukazkovy";

	char * uk = strstr(r, pod);
	printf("ukazkovy retezec: adresa: %p\n", r);
	printf("nalez: adresa: %p\n", uk);
	printf("Pozice nalezeneho retezce: %d\n", uk-r);

	// nahrazeni retezce - tupe, neumi nahradit text za jinak dlouhy text
	// ------------------------------------------------------------------
	char rr[50] = "V mem pokoji je zeleny fikus.";
	char stary[50] = "zeleny";
	char novy[50] = "ruzovy";

	char * u = strstr(rr, stary);
	if(u != NULL){
		strncpy(u, novy, strlen(novy));
	} else {
		printf("Neni co nahradit, protoze podretezec jsme nenasli.\n");
	}
	printf("Nahrazeny retezec: >%s<\n", rr );


	// nahrazeni retezce - inteligentni, umi nahradit text za libovolne dlouhy jiny text
	// ---------------------------------------------------------------------------------
	char rrr[50] = "V mem pokoji je zeleny fikus.";
	char sstary[50] = "zeleny";
	char nnovy[50] = "oranzovy";
	char uschovna[50];

	int drrr = strlen(rrr);
	int dStary = strlen(stary); 

	char * u1 = strstr(rrr, sstary);
	if(u != NULL){
		// 1. ukladam zbytek puvodniho retezce za nalezenym podretezcem do uschovny
		strncpy(uschovna, u1+dStary, drrr-(u1-rrr)+dStary);
		printf("Uschovna: >%s<\n", uschovna);
		// 2. Oriznu puvodni retezec v miste nalezu podretezce:
		rrr[u1-rrr] = '\0';
		// 3. slepim puvodni retezec, novy retezec a uschovnu:
		strcat(rrr, nnovy);
		strcat(rrr, uschovna);
		printf("Nahrazeny retezec: >%s<\n", rrr);
	} else {
		printf("Neni co nahradit, protoze podretezec jsme nenasli.\n");
	}

	return 0;
}