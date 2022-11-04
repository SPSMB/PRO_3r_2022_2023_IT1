#include <stdio.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'scanf': This function or variable may be unsafe.
#pragma warning(disable:4996)

int main(void){

	int rok;
	int i = 0;
	while(i<5){
		printf("Zadejte rok: ");
		scanf("%d", &rok);
	
		if((rok%4 == 0) && (rok%100 != 0 || rok%400 == 0 )){
			printf("Rok %d je prestupny.\n", rok);
		} else {
			printf("Rok %d neni prestupny.\n", rok);
		}
		i++;
	}

	return 0;
}