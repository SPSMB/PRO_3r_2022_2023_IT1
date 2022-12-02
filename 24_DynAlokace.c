#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'strncpy': This function or variable may be unsafe.
#pragma warning(disable:4996)

/* Vytvoříme jednoduchý program, který načte od uživatele 
	libovolný počet čísel. Program bude následně v zadaných 
	číslech vyhledávat a zjistí, kolikrát bylo nějaké číslo zadáno:
*/


int main(void){
	
	/*
	// staticka alokace - pole 1 o 10 polozkach
	int pole1[10];

	// dynamicka alokace
	int * pole2;
	int kapacita = 15;
	pole2 = (int *) malloc(kapacita*sizeof(int));

	for(int i = 0; i < kapacita; i++){
		pole2[i] = i;
		printf("%d\n", pole2[i]);
	}
	*/

	int pocet;		// pocet prvku v poli
	int h; 			// hledane cislo
	int cetnost; 	// pocet vyskytu hledaneho cisla

	// 1 Pokyn k uzivateli
	printf("Zadejte pocet cisel: ");
	scanf("%d", &pocet);

	// 2 Vyrobim pole
	int * pole1 = (int*) malloc(pocet*sizeof(int));

	// 3 Zadavani cisel
	printf("Zadejte vsechna cisla oddelena mezerami:\n");
	for(int i = 0; i < pocet; i++){
		scanf("%d", &(pole1[i]));
	}

	// 4 Jake cislo budeme hledat?
	printf("Jake cislo chces vyhledat? ");
	scanf("%d", &h);
	
	return 0;
}