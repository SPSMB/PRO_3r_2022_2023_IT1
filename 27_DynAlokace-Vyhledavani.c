#include <stdio.h>
#include <stdlib.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'strncpy': This function or variable may be unsafe.
#pragma warning(disable:4996)

void pridejCisla(int ** poleCisel, int * velPole){

	int novyPocet = 0;
	printf("Kolik novych cisel? ");
	scanf("%d", &novyPocet);

	int novaVel = *velPole + novyPocet; // nova velikost pole

	printf("Alokuji nove pole o delce %d.\n", novaVel);

	int * novePole;
	if(*velPole == 0){
		novePole = (int *) malloc(novaVel * sizeof(int));
	} else {
		novePole = (int *) realloc(*poleCisel, novaVel * sizeof(int));
	}

	if(novePole != NULL){
		printf("Prosim zadejte jednotliva cisla oddelena mezerami:\n");
		*poleCisel = novePole;
		for(int i = *velPole; i < novaVel; i++){
			scanf("%d", &(novePole[i]));
		}
		*velPole = novaVel;
	} else {
		printf("Alokace selhala.\n");
		free(*poleCisel);
	}

}

void vypisPole(int * pole, int vel){
	if(vel == 0){
		printf("Pole je prazdne.\n");
	} else {
		for(int i = 0; i < vel; i++){
			printf("%d ", pole[i]);
		}
		printf("\n");
	}
}

void hledejCislo(int * pole, int vel){

}

int main(void){
	
	int * poleCisel = NULL;
	int velPole = 0;
	char volba;

	while(1){
		printf("Zadej P (Pridej) H (Hledej) V (Vypis) K (Konec): ");
		scanf("%c", &volba);

		if(volba == 'P'){
			pridejCisla(&poleCisel, &velPole);
		} else if(volba == 'H'){
			hledejCislo(poleCisel, velPole);
		} else if(volba == 'V'){
			vypisPole(poleCisel, velPole);
		} else if(volba == 'K'){
			break;
		} else {
			printf("Nezname zadani, prosim zkuste znovu.\n");
		}
		while(getchar() != '\n'); // vycisteni vstupu
	}

	return 0;
}