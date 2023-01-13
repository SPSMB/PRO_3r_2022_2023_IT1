#include <stdio.h>
#pragma warning(disable:4996)

int main(int argc, char const *argv[])
{
	FILE * soubor = fopen("30_soubor1.txt", "r");

	int a;
	do {
		fscanf(soubor, "%d", &a);
		printf("Nacetl jsem %d\n", a);
	} while (a != 0);

	fclose(soubor);
	return 0;
}