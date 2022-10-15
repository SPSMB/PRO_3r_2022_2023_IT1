#include <stdio.h>

int main(void){

	int parkoviste[10];
	int x = 200;
	parkoviste[0] = 10;
	parkoviste[5] = 15;


	printf("Prvek na indexu 5 klasicky: %d\n", 
		parkoviste[5]);
	printf("Prvek na indexu 5 pres uk : %d\n", 
		*(parkoviste+5));

	printf("Zacatek pole poprve  je na adrese: %p\n", 
		&(parkoviste[0]));
	printf("Zacatek pole podruhe je na adrese: %p\n", 
		parkoviste);

	printf("Velikost parkoviste v bytech: %d\n", 
		sizeof(parkoviste));
	printf("Velikost promenne x v bytech: %d\n",
		sizeof(x));

	return 0;
}