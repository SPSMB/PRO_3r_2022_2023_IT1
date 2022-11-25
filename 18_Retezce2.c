#include <stdio.h>
#include <ctype.h>
#include <string.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'strncpy': This function or variable may be unsafe.
#pragma warning(disable:4996)

int main(void){
	
	/*
	const char * jmeno = "Tom";
	char jmeno2[100];

	strncpy(jmeno2, "Tom", 99);

	printf("Delka SIZEOF: %d\n", sizeof(jmeno));
	printf("Delka STRLEN: %d\n", strlen(jmeno));
	printf("-------------\n");
	printf("Delka SIZEOF: %d\n", sizeof(jmeno2));
	printf("Delka STRLEN: %d\n", strlen(jmeno2));
	*/


	/*
		Načtěte řetězec náhodných znaků ze standardního vstupu. 
		Uložte si ho. Vypište z tohoto řetězce na první řádek 
		jen číslice 0 – 9 a na druhý řádek vše ostatní.
	*/

	char zasobnik[200]; // sem budu ukladat znaky
	char cisla[200]; // sem budu hrnout cisla
	char znaky[200]; // sem budu davat znaky

	printf("Prosim zadejte nahodne znaky: ");
	scanf("%s", zasobnik);

	int uz = 0; // index do pole znaky
	int uc = 0; // index do pole cisla
	int i = 0; // index do zasobniku

	// cisla jsou od 0x30 do 0x39
	while(1){
		if(zasobnik[i] == '\0'){
			znaky[uz] = '\0';
			cisla[uc] = '\0';
			break;
		// } else if(isdigit(zasobnik[i])){ // include <ctype.h>
		} else if (zasobnik[i] >= 0x30 && zasobnik[i] <= 0x39 ) {
			cisla[uc] = zasobnik[i];
			uc++;
		} else {
			znaky[uz] = zasobnik[i];
			uz++;
		}
		i++;
	}

	printf("ZNAKY: \"%s\"\n", znaky);
	printf("CISLA: \"%s\"\n", cisla);

	return 0;
}