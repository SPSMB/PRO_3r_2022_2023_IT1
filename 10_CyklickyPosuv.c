
// Cyklicky posuv
// 7.10.2022
// Tomas Zimmerhakl

#include <stdio.h>

void prohod(int *a, int *b, int *c, int *d){
	int x = *c;
	*c = *b;
	*b = *a;
	*a = *d;
	*d = x;
}

int main(void){

	int a = 5; 
	int b = 6; 
	int c = 7; 
	int d = 8;

	printf("Vypis pred prohozenim A-B-C-D: %d-%d-%d-%d\n", a, b, c, d);
	prohod(&a, &b, &c, &d);
	printf("Vypis pred prohozenim A-B-C-D: %d-%d-%d-%d\n", a, b, c, d);

	return 0;
}