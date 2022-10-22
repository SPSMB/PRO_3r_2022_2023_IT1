#include <stdio.h>

int main(void){

	float pole1[100];

	// %d - int
	// %g - float nebo double v lidsky citelnem formatu
	// %e - float / double matematicky, semilogarimticky tvar 10e3
	// %f - float / double ve formatu vzdy desetinneho cisla 5.000000
	printf("Pole 1 ma velikost %d\n", sizeof(pole1));

	int pole2[100] = {5, 120};

	for( int i = 0; i < 100; i++){
		printf("%3d ", pole2[i]);
		if((i+1)%10 == 0){
			printf("\n");
		}
	}
	printf("----------------------------------\n\n");

	// nacitam radu cisel zakoncenou nulou a scitam pocty jednotlivych cisel mezi 1 a 100
	int cetnosti[100] = {0};
	int x;
	printf("Zadavejte cisla od 1 do 100, pro ukonceni 0.\n");
	while(1){
		scanf("%d", &x);
		if(x == 0){
			break;
		} else if(x > 0 && x < 100){
			cetnosti[x]++;
		}
	}

	// vypisovaci cast
	for(int k = 0; k<100; k++){
		if(cetnosti[k] > 0){
			printf("Pocet %d: %d\n", k, cetnosti[k]);
		}
	}

	return 0;
}