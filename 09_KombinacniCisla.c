
// kombinacni cisla
// 7.10.2022
// Tomas Zimmerhakl

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'scanf': This function or variable may be unsafe.
#pragma warning(disable:4996)


#include <stdio.h>

int faktorial(int x){
	int pom = 1;
	int vysledek = pom;
	if(x == 0) vysledek = 1;
	for(; pom <= x; pom++){
		vysledek *= pom;
	}
	return vysledek;
}

int kombinacniCislo(int n, int k){
	return (faktorial(n))/(faktorial(k)*faktorial(n-k));
}

int main(void){

	int n = 12;
	int k = 2;
	printf("Zadejte kombinacni cislo ve tvaru: n k:");
	scanf("%d %d", &n, &k);
	printf("%d nad %d: %d\n", n, k, kombinacniCislo(n,k));

	return 0;
}