#include <stdio.h>
#include <errno.h>
#include <string.h>
#pragma warning(disable:4996)

int readline( char * buf, int max, FILE * f ){

	int a = fgetc(f);
	int pocet = 0;
	while(a != EOF && a != '\n' && pocet < max-1){
		buf[pocet] = a;
		pocet++;
		a = fgetc(f);
	}
	buf[pocet] = '\0'; 
	printf("Precteno %d znaku.\n", pocet);
	return pocet;
}


int main(int argc, char const *argv[])
{
	
	for(int i=0; i<42; i++){
		printf("%d: %s\n", i, strerror(i));
	}

	const char * nazevSouboru = "30_soubor3.txt";
	FILE * soubor = fopen(nazevSouboru, "r");
	printf("Oteviram soubor %s.\n", nazevSouboru);

	if(soubor == NULL){
		int chyba = errno;
		printf("Soubor %s se nepodarilo otevrit.\nCislo chyby: %d\nHlaska: %s\n", 
			nazevSouboru, chyba, strerror(chyba));
		return 0;
	}

	char text[150];

	readline(text,150,soubor);
	printf(">%s<\n",text);
	
	fseek(soubor, 2, SEEK_SET);
	readline(text,150,soubor);
	printf(">%s<\n",text);


	fclose(soubor);
	return 0;
}

