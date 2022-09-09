#include <stdio.h>
// test 02
// test 03
// test 04
int main(void){
	printf("Toto je muj prvni program.\n");

	int rychlost; 	// deklarace
	rychlost = 25; 	// prirazeni hodnoty
	printf("Rychlost poprve je %d\n", rychlost);
	rychlost = 40; 	// zmenim hodnotu
	printf("Rychlost podruhe je %d\n", rychlost);
	printf("Adresa promenne rychlost: %p\n", &rychlost);

	int * adr_rychlost; // deklaruji promennou typu ukazatel
	adr_rychlost = &rychlost; // priradil jsem adresu

	printf("Adresa prom. rychlost: %p\n", adr_rychlost);

	printf("Hodnotu promenne rychlost z ukazatele: %d\n", *adr_rychlost);
	rychlost = 50;
	printf("Vypis: %d\n", * adr_rychlost); // CO SE VYPISE?
	rychlost = 60;
	/*printf("Vypis2: %d\n", adr_rychlost); // CO SE VYPISE?
	*/
	printf("Vypis3: %p\n", adr_rychlost); // CO SE VYPISE?
	adr_rychlost = NULL;
	printf("Vypis 4: %p\n", adr_rychlost); // CO SE VYPISE?
	/*printf("Vypis 5: %d\n", *adr_rychlost); // TOTO NEJDE - nelze vypsat hodnotu z neexistujici adresy
	*/

	// VYPISY
	printf("Vypis6: procento: %% \n");
	printf("Vypis7: rychlost hexa: %x\n", rychlost);

	printf("Vypis8: %c %c %d \n", 'a', 65, rychlost);
	printf("Vypis9: %010d\n", rychlost);

	rychlost = 0x50;
	printf("Vypis10: rychlost = %x", rychlost);

	return 0;
}