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

int main(int argc, char ** argv){

	// 0. ukol - prevest retezec na cislo
	int64_t rodnecislo = strtoll(argv[1], NULL, 10);
	printf("Zadane rodne cislo je: %I64d\n", rodnecislo);

	// 1. podminka delitelnost 11



	return 0;
}

