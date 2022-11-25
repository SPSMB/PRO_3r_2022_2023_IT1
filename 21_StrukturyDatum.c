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



int main(void){
	
	Datum d1;
	Datum d2;
	Datum * p; // pozdejsi datum

	d1.rok = 2022; d1.mesic = 12; d1.den = 5;
	d2.rok = 2022; d2.mesic = 11; d2.den = 10;

	p = pozdejsiDatum(&d1, &d2);

	printf("Pozdejsi datum je %d.%d.%d\n", p->den, p->mesic, p->rok);

	return 0;
}