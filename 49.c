#include <stdio.h>

int d(void){
	int x = 5;
	int y = 6 + x;
}	

int main(int argc, char const *argv[])
{

	long int bin, hex, i, zbytek;
	printf("Zadejte: ");
	scanf("%ld", &bin);
	while(bin != 0){
		zbytek = bin % 10;
		hex = hex + zbytek*i;
		i *= 2;
		bin/=10;
	}
	printf("16tkova hodnota: %lx", hex);

	return 0;
}