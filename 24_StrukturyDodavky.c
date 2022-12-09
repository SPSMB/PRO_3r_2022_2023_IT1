#include <stdio.h>
#include <string.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'strncpy': This function or variable may be unsafe.
#pragma warning(disable:4996)

/*
	Vytvořte strukturu, která bude 
	uchovávat datum.
	Pak vytvořte funkci, která porovná 2 datumy 
	a vrátí ukazatel na ten, který je později.

*/

typedef struct Dodavka {
	char SPZ[50];
	int kapacita;
	int dojezd;
	int rokV;
	char jmeno[50];
} Dodavka;

void vypisDodavky(Dodavka * skupina, int pocet){

	for(int i = 0; i<pocet; i++){
		printf("Dodavka %d: Jmeno: %s, SPZ: %s, Kapacita: %d, Rok: %d, Dojezd: %d\n", i, 
			skupina[i].jmeno, skupina[i].SPZ, 
			skupina[i].kapacita, skupina[i].rokV, skupina[i].dojezd);
	}
}

void nejvyssiDojezd(Dodavka * skupina, int pocet){

	int max = 0;
	int indexNej = -1;
	for(int i = 0; i<pocet; i++){
		if(skupina[i].dojezd > max){
			max = skupina[i].dojezd;
			indexNej = i;
		}
	}
	printf("Dodavka s nejvyssim dojezdem je %d: SPZ: %s, ridic %s, dojezd: %d, kapacita %d\n",
		indexNej, 
		skupina[indexNej].SPZ, skupina[indexNej].jmeno,
		skupina[indexNej].dojezd, skupina[indexNej].kapacita);
}

void naplnSkupinuDodavek(Dodavka * skupina, int pocet){
	strncpy(skupina[0].jmeno, "Josef Novak", 49);
	strncpy(skupina[0].SPZ, "1AB3519", 50);
	skupina[0].kapacita = 10;
	skupina[0].dojezd = 300;
	skupina[0].rokV = 2010;
	strncpy(skupina[1].jmeno, "Petr Rychly", 49);
	strncpy(skupina[1].SPZ, "4A51111", 50);
	skupina[1].kapacita = 8;
	skupina[1].dojezd = 400;
	skupina[1].rokV = 2000;
	strncpy(skupina[2].jmeno, "Jana Kratka", 49);
	strncpy(skupina[2].SPZ, "3SJ 2233", 50);
	skupina[2].kapacita = 9;
	skupina[2].dojezd = 250;
	skupina[2].rokV = 2015;

}

int main(void){
	
	Dodavka skupina[3];
	naplnSkupinuDodavek(skupina, 3);

	vypisDodavky(skupina, 3);
	nejvyssiDojezd(skupina, 3);
	
	return 0;
}