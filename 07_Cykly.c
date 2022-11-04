#include <stdio.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'scanf': This function or variable may be unsafe.
#pragma warning(disable:4996)

int main(void){

	
	/*
	for(int k=2; k<1000; k*=2){
		printf("K: %d\n", k);
	}
	
	int pole_cisel[5] = {1,2,300,300,7};

	for(int i=0; i<5; i++){
		if(pole_cisel[i] == 300){
			printf("Nalezena hodnota 300 na pozici %d\n", i+1);
		}
	}
	*/

	/*
	for(int i=1; i<100; i++){
		if(i%10 == 0){
			continue;
		}
		printf("i: %d\n", i);
	}
	*/

	int cislo;
	int kontrola = 0;

	do{
		printf("Zadejte prosim cele cislo: ");
		kontrola = scanf("%d", &cislo);
		printf("Zadane cislo je: %d\n", cislo);
		printf("Kontrola: %d\n", kontrola);
		if(kontrola == 0){
			printf("Spatny vstup\n");
			while(getchar() != '\n');
		}
	}while(kontrola == 0);

	return 0;
}