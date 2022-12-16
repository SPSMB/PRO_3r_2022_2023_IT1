#include <stdio.h>
#include <stdlib.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'strncpy': This function or variable may be unsafe.
#pragma warning(disable:4996)

void pridejCisla(int ** poleCisel, int * vyuzito, int * kapacita){

	int novyPocet = 0;
	printf("Kolik novych cisel? ");
	scanf("%d", &novyPocet);

	// inteligentni vypocet
	int noveVyuzito = *vyuzito + novyPocet; // novy pocet prvku v poli

	if( noveVyuzito > *kapacita){
		// musim alokovat nebo realokovat
		int novaKapacita = noveVyuzito * 3;
		printf("Alokuji nove pole o delce %d.\n", novaKapacita);
		
		int * novePole;
		if(*kapacita == 0){
			novePole = (int *) malloc(novaKapacita * sizeof(int));
		} else {
			novePole = (int *) realloc(*poleCisel, novaKapacita * sizeof(int));
		}
		*poleCisel = novePole;
		*kapacita = novaKapacita;

	} else {
		// nemusim alokovat
		printf("Potrebuji ulozit %d prvku, kapacita je %d.\n", noveVyuzito, *kapacita);
	}


	if(poleCisel != NULL){
		printf("Prosim zadejte jednotliva cisla oddelena mezerami:\n");
		int * pole = *poleCisel;
		for(int i = *vyuzito; i < noveVyuzito; i++){
			scanf("%d", &(pole[i]));
		}
	} else {
		printf("Alokace selhala.\n");
		free(*poleCisel);
	}
	*vyuzito = noveVyuzito;
}

void vypisPole(int * pole, int vyuzito){
	if(vyuzito == 0){
		printf("Pole je prazdne.\n");
	} else {
		for(int i = 0; i < vyuzito; i++){
			printf("%d ", pole[i]);
		}
		printf("\n");
	}
}

void hledejCislo(int * pole, int vel){

}

int main(void){
	
	int * poleCisel = NULL;
	int kapacita = 0;
	int vyuzito = 0;
	char volba;

	while(1){
		printf("Zadej P (Pridej) H (Hledej) V (Vypis) K (Konec): ");
		scanf("%c", &volba);

		if(volba == 'P'){
			pridejCisla(&poleCisel, &vyuzito, &kapacita);
		} else if(volba == 'H'){
			hledejCislo(poleCisel, vyuzito);
		} else if(volba == 'V'){
			vypisPole(poleCisel, vyuzito);
		} else if(volba == 'K'){
			break;
		} else {
			printf("Nezname zadani, prosim zkuste znovu.\n");
		}
		while(getchar() != '\n'); // vycisteni vstupu
	}

	return 0;
}