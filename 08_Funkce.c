#include <stdio.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'scanf': This function or variable may be unsafe.
#pragma warning(disable:4996)

double nasob(double a, double b){
	return a*b;
}

void nasob2(int a, int b){
	printf("Nasob2: %d\n ", a*b);
}

void nasob3(int * a, int *b, int * vysledek){
	*a = 8;
	int x = *a;
	printf("Adresa uvnitr funkce nasob3 a: %p\n", a);
	int y = *b;
	*vysledek = x*y;

	// alternativa:
	// *vysledek = (*a)*(*b);
}

int main(void){

	int vysledek;

	double a = 3.15;
	double b = 7.99;
	nasob2(a,b);

	// int a = 51234;
	// printf("Adresa uvnitr funkce main a: %p\n", &a);
	// int b = 91234;
	// nasob3(&a, &b, &vysledek);
	// printf("vysledek: %d\n", vysledek);
	// printf("A ve funkci main: %d", a);
	/*vysledek = nasob(a,b);*/
	//printf("vysledek: %f\n", nasob(a,b));
	//nasob2(a,b);

	return 0;
}