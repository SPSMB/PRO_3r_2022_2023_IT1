void vypisPole(int * pole, int vyuzito){
	if(vyuzito == 0){
		printf("Pole je prazdne.\n");
	} else {
		for(int i = 0; i < vyuzito; i++){
			printf("%d ", pole[i]);
		}
		printf("\n");
	}
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

void vypisTabulku1(int tabulka[3][4], int pRadku, int pSloupcu){
	for (int r = 0; r < pRadku; ++r){
		for(int s = 0; s < pSloupcu; ++s){
			printf("%3d ", tabulka[r][s]);
		}
		printf("\n");
	}
}

void vypisTabulku2(int ** tabulka, int pRadku, int pSloupcu){
	for (int r = 0; r < pRadku; ++r){
		for(int s = 0; s < pSloupcu; ++s){
			printf("%3d ", tabulka[r][s]);
		}
		printf("\n");
	}
}