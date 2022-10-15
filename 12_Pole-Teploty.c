#include <stdio.h>

int main(void){

	printf("Zadejte prosim radu cisel, pro ukonceni zadejte pismeno.\n");

	int teploty[100];
	int pocet = 0;

	int i = 0;
	int kontrola;
	while(1){
		kontrola = scanf("%d", &teploty[i]);
		if(kontrola == 0){
			while(getchar()!='\n');
			break;
		}

		pocet++;
		i++;
	}

	int max_teplota = -1000;
	int min_teplota = 1000;
	int soucet = 0;

	for(int j = 0; j < pocet; j++){
		if(teploty[j] > max_teplota){
			max_teplota = teploty[j];
		}
		if(teploty[j] < min_teplota){
			min_teplota = teploty[j];
		}
		soucet += teploty[j];
	}

	printf("Minimalni teplota je %d\n", min_teplota);
	printf("Maximalni teplota je %d\n", max_teplota);
	printf("Prumerna teplota je %f\n", (float)soucet/pocet);

	return 0;
}