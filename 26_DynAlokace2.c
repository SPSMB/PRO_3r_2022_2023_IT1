#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'strncpy': This function or variable may be unsafe.
#pragma warning(disable:4996)


int main(void){
	
	printf("Ukazka, ze dynamicka alokace muze selhat.\n");
	int k = 10;
	int * pole1 = (int *) malloc(k * sizeof(int));

	if(pole1 == NULL){
		printf("Alokace se nezdarila.\n");
	} else {
		printf("Alokace je ok.\n");
	}

	int novyPocet;
	printf("Na kolik zvetsime pole? ");
	scanf("%d", &novyPocet);

	int * novePole = (int *) realloc(pole1, novyPocet * sizeof(int) );
	if(novePole == NULL){
		printf("Realokace se nezdarila.\n");
		free(pole1);
		return 1;
	} else {
		printf("Realokace je ok.\n");
		pole1 = novePole; // presun ukazatelu
	}

	// uvolnim pamet
	free(pole1);

	return 0;
}