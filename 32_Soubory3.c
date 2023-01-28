#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	const char * nazev = "01.exe";
	FILE * soubor1 = fopen(nazev, "r");
	if(soubor1 == NULL){
		printf("Otevreni souboru se nezdarilo\n");
		return 0;
	}

	char retezec[200];
	fgets(retezec, 199, soubor1);

	for(int i = 0; i < 200; i++){
		printf("%x.", (unsigned char)retezec[i]);
	}

	printf("\n%s\n", retezec);

	fclose(soubor1);
	return 0;
}

