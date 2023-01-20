#include <stdio.h>
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
	const char * nazevSouboru = "30_soubor1.txt";
	FILE * soubor = fopen(nazevSouboru, "r");
	printf("Oteviram soubor %s.\n", nazevSouboru);

	// int a = 0;
	char text[150];
/*
	do {
		fscanf(soubor, "%d", &a);
		printf("Nacetl jsem %d\n", a);
	} while (a != 0);
*/
	readline(text,150,soubor);
	//fgets(text, 150, soubor);
	printf(">%s<",text);
	fclose(soubor);
	return 0;
}

