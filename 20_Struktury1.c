#include <stdio.h>
#include <string.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'strncpy': This function or variable may be unsafe.
#pragma warning(disable:4996)

/*
	Načtěte dlouhý řetězec ze vstupu, kde bude místo mezer 
	použit znak „*“. Podle tohoto oddělovače pak text 
	rozdělte na slova. Slova zobrazte tak, aby bylo 
	jedno slovo na jednom řádku.

*/

typedef struct clovek {
	char jmeno[50];
	char prijmeni[50];
	unsigned int vaha;
	unsigned int vyska;
} Clovek;

void vypis( Clovek c ){
	printf("-------------\n");
	printf("Jmeno: %s\n", c.jmeno);
	printf("Prijmeni: %s\n", c.prijmeni);
	printf("Vaha: %d\n", c.vaha);
	printf("Vyska: %d\n", c.vyska);
}

void vypisCloveka( Clovek * c ){
	printf("-------------\n");
	printf("Jmeno: %s\n", c->jmeno);
	printf("Prijmeni: %s\n", c->prijmeni);
	printf("Vaha: %d\n", c->vaha);
	printf("Vyska: %d\n", c->vyska);
}

int main(void){
	
	// struct clovek tom; // kdybych nepouzil typedef
	Clovek tom;
	strncpy(tom.jmeno, "Tom", 50);
	strncpy(tom.prijmeni, "Zimmerhakl", 50);
	tom.vaha = 80;
	tom.vyska = 180;
	Clovek reditel;
	strncpy(reditel.jmeno, "Vaclav", 50);
	strncpy(reditel.prijmeni, "Bohata", 50);

	vypis(tom); // vypis pomoci promenne
	vypisCloveka(&reditel); // vypis pomoci ukazatele

	return 0;
}