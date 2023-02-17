#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>

/* program, ktery nacte pri spusteni rodne cislo z 
   prikazove radky a zkontroluje, ze je platne.

   Rodne cislo je v CR vzdy delitelne 11 beze zbytku. 
   Krome toho je druhe dvojcisli v rozsahu 01-12 nebo 51-62
   a treti dvojcisli je v rozsahu 01-30.

   */

// 9254151225, 9202150694

int main(int argc, char ** argv){

	// 1. ukol - prevest retezec na cislo
	int64_t rodnecislo = strtoll(argv[1], NULL, 10);
	printf("Zadane rodne cislo je: %I64d\n", rodnecislo);

	// 2. podminka delitelnost 11
	if(rodnecislo % 11 == 0){
		printf("Rodne cislo je delitelne jedenacti.\n");
	} else{
		printf("Rodne cislo neni platne, protoze nesplnuje podminku delitelnosti jedenacti.\n");
		return 0;
	}

	// 3. podminka - druhe dvojcisli je 01 - 12
	// 				- nebo 51 - 62

	int mesic = (rodnecislo / 1000000) % 100;

	if( (mesic >= 1 && mesic <= 12) || (mesic >= 51 && mesic <= 62) ){
		printf("Mesic %d je OK.\n", mesic);
	} else {
		printf("Rodne cislo neni platne, protoze mesic %d neni ve spravnem rozsahu.\n", mesic);
		return 0;
	}

	// 3. podminka jinak
	// pouzijeme funkci atoi(); 
	char rc[11]; // vyrobim jinou promennou na string
	strcpy(rc, argv[1]); // zkopiruji si RC
	rc[4] = '\0'; // ukoncim ho po 4 znacich
	int mesic2 = atoi(rc+2); // prevedu na INT
	if( (mesic2 >= 1 && mesic2 <= 12) || (mesic2 >= 51 && mesic2 <= 62) ){
		printf("Mesic2 %d je OK.\n", mesic);
	} else {
		printf("Rodne cislo neni platne, protoze mesic %d neni ve spravnem rozsahu.\n", mesic2);
		return 0;
	}

	//4. podminka - overujeme, ze den je v rozsahu 1-30
	int den = (rodnecislo / 10000) % 100;

	if(mesic >= 1 && den <= 30){
		printf("Den %d je OK.\n", den);
	} else {
		printf("Rodne cislo neni platne, protoze den %d neni ve spravnem rozsahu.\n", den);
		return 0;
	}

	printf("Rodne cislo %s je platne.\n", argv[1]);
	return 0;
}

