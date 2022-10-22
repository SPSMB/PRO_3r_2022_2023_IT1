#include <stdio.h>

void vypisPole1(int pole[], int vel){
	for(int i = 0; i < vel; i++){
		printf("%d, ", pole[i]);
	}
	printf("\n");
}

void vypisPole2(int * pole, int vel){
	for(int i = 0; i < vel; i++){
		printf("%d, ", pole[i]);
	}
	printf("\n");
}

void bubble_sort(const int * pole1, int vel, int * pole2){
	int help;
	for (int i = 0; i < vel; ++i){
		pole2[i] = pole1[i];
	}

	for (; vel > 2;vel--){	
		for (int i = 0; i < vel-1; ++i){
			if(pole2[i] > pole2[i+1]){
				help = pole2[i];
				pole2[i] = pole2[i+1];
				pole2[i+1] = help;
			}
		}
	}
}

int main(void){

	int pole1[7] = {9, 5, 6, 12, 1 ,8 ,3};
	int pole2[7] = {0};
	vypisPole1(pole1, 7);
	vypisPole2(pole2, 7);
	bubble_sort(pole1, 7, pole2);
	vypisPole1(pole1,7);
	vypisPole2(pole2,7);


	return 0;
}