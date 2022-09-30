#include <stdio.h>

int nasob(int a, int b){
	return a*b;
}

int main(void){

	int vysledek;
	int a = 5;
	int b = 6;
	nasob(a,b);
	printf("vysledek: %d\n", vysledek);

	return 0;
}