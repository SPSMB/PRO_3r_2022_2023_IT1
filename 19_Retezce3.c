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

int main(void){
	
	char veta[200];

	printf("Prosim zadejte vetu, misto mezer pouzijte \"*\":\n");
	scanf("%s", veta);

	int i = 0; // index do retezce veta
	while(1){
		if(veta[i] == '*'){
			printf("\n");
		} else if(veta[i] == '\0'){
			break;
		} else {
			printf("%c", veta[i]);
		}
		i++;
	}

	return 0;
}