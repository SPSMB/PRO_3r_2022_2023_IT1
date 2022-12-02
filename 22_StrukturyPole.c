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

typedef struct Clovek {
	char jmeno[50];
	char prijmeni[50];
	int vaha;
	int vyska;
} Clovek;

void vypisOsoby(Clovek * skupina, int pocet){

	for(int i = 0; i<pocet; i++){
		printf("Osoba %d: %s %s<\n", i, 
			skupina[i].jmeno, skupina[i].prijmeni);
	}
}

void nejvyssiOsoba(Clovek * skupina, int pocet){

	int max = 0;
	int indexNej = -1;
	for(int i = 0; i<pocet; i++){
		if(skupina[i].vyska > max){
			max = skupina[i].vyska;
			indexNej = i;
		}
	}
	printf("Nejvyssi osoba je %s %s, ma %d cm.\n",
		skupina[indexNej].jmeno, skupina[indexNej].prijmeni,
		max);
}

int main(void){
	
	Clovek skupina[8];

	strncpy(skupina[0].jmeno, "Tom", 50);
	strncpy(skupina[0].prijmeni, "Zimmerhakl", 50);
	skupina[0].vaha = 80;
	skupina[0].vyska = 180;
	strncpy(skupina[1].jmeno, "Josef", 50);
	strncpy(skupina[1].prijmeni, "Novotny", 50);
	skupina[1].vaha = 90;
	skupina[1].vyska = 170;
	skupina[2].vyska = 0;
	skupina[3].vyska = 0;
	skupina[4].vyska = 0;
	skupina[5].vyska = 0;
	skupina[6].vyska = 0;
	skupina[7].vyska = 0;

	vypisOsoby(skupina, 8);
	nejvyssiOsoba(skupina, 8);
	
	return 0;
}