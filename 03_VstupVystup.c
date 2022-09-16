#include <stdio.h>

int main(void){
	
	/*
	printf("Zadejte prumer kruhu: ");
	float prumer;
	scanf("%f", &prumer);

	printf("Obvod kruhu je %.3f\n", prumer*3.14);

	char str[81]; // retezec
	printf("Zadejte retezec, max 80 znaku: ");
	scanf("%81s", str);
	printf("Zadano: \"%s\"\n", str);
	*/

	// kontrola vstupu

	float polomer;
	int a;
	printf("Zadejte polomer koule: ");
	a = scanf("%f", &polomer);
	if(a != 1){
		printf("Navratova hodnota scanf: %d\n", a);
		printf("Nespravny vstup. Konec programu.");
		return 0;
	}
	printf("Vysledek: %f\n", 4.0/3.0 * 3.14 * polomer * polomer * polomer);
	printf("Navratova hodnota scanf: %d\n", a);

	// FGETS
	/*
	char retezec[100];
	printf("Zadejte text: ");
	fgets(retezec, 99, stdin);
	printf("Zadany text je \"%s\"", retezec);
	*/

	return 0;
}