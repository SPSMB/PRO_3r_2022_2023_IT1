#include <stdio.h>

// nasledujici radek potlaci pri kompilovani pres cl warning C4996: 
//   'scanf': This function or variable may be unsafe.
#pragma warning(disable:4996)

int main(void){
	
	int i, j;
	int kontrola; // pocet spravne nactenych vstupu
	printf("1: Zadejte 2 cela cisla oddelena pomlckou.\n");
	kontrola = scanf("%d-%d", &i, &j);
	
	printf("I: %d, J: %d.\n", i, j);
	if(kontrola == 2){
		// nic
	} else {
		printf("Nespravny vstup1, ale uzivatel muze pokracovat vstupem 2.\n");
		// vycisteni vstupniho zasobniku
		while(getchar() != '\n');
	}

	printf("2: Zadejte 2 cela cisla oddelena pomlckou.\n");
	kontrola = scanf("%d-%d", &i, &j);
	if(kontrola == 2){
		// nic
	} else {
		printf("Nespravny vstup2.\n");
		// vycisteni vstupniho zasobniku
		while(getchar() != '\n');
	}
	printf("I: %d, J: %d.\n", i, j);

	return 0;
}