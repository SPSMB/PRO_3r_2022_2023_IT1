#include <stdio.h>

int main(void){
	
	char z1 = 'z';
	char z2 = '\'';
	char z3 = '\n';
	char z4 = '\\';
	char z5 = 'a';
	printf("Vypis1: %c\n", z1);
	printf("Vypis2: %c\n", z2);
	printf("Vypis3: >%c<\n", z3);
	printf("Vypis4: %c\n", z4);
	printf("Vypis5: dec:%d, hex:%x\n", 
		z5, z5);

	float f1 = 0.2F;
	printf("\nVypis6: %.3f\n", f1);
	printf("Vypis7: %e\n", f1);
	printf("Vypis8: %g\n", f1);

	float f2 = 5e3;
	printf("\nVypis9: %.3f\n", f2);
	printf("Vypis10 %e\n", f2);
	printf("Vypis11: %g\n", f2);

	// pretypovani
	unsigned int k1 = 3254927976;
	int k2 = (int) k1;
	printf("%d", k2);
	
	// ZMENA 2


	return 0;
}