#include <stdio.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'scanf': This function or variable may be unsafe.
#pragma warning(disable:4996)

// 2D POLE

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

void BestGroup(int ** tabulka, int pRadku, int pSloupcu){
	int nejSkupina = -1;
	float prumery[100] = {0};
	for (int r = 0; r < pRadku; ++r){
		// pocitam prumery
		int soucet = 0;
		for(int s = 0; s < pSloupcu; ++s){
			soucet+=tabulka[r][s];
		}
		prumery[r] = (float)soucet/pSloupcu;
	}

	// hledam maximum v poli prumery
	float max = 0.0;
	for(int i = 0; i < 100; i++){
		if(prumery[i] > max){
			nejSkupina = i;
		}
	}
	printf("Nejlepsi skupina je na indexu %d s prumerem %g.\n", 
		nejSkupina, prumery[nejSkupina]);
	printf("----------------\n");
}

void AvgAvg(int ** tabulka, int pRadku, int pSloupcu){
	float prumery[100] = {0};
	int celkovySoucet = 0;
	for (int r = 0; r < pRadku; ++r){
		// pocitam prumery
		int soucet = 0;
		for(int s = 0; s < pSloupcu; ++s){
			soucet+=tabulka[r][s];
			celkovySoucet+=tabulka[r][s];
		}
		prumery[r] = (float)soucet/pSloupcu;
		printf("Prumer skupiny s indexem %d je %g.\n", r, prumery[r]);
	}
	printf("Prumer ze vsech skupin je %g\n", (float)celkovySoucet/(pRadku*pSloupcu));
	printf("----------------\n");
}

void MaxScore(int ** tabulka, int pRadku, int pSloupcu){
	int dosazenoMax;
	for(int r = 0; r < pRadku; ++r){
		dosazenoMax = 0;
		for(int s = 0; s < pSloupcu; ++s){
			if(tabulka[r][s] == 10) dosazenoMax = 1;
		}

		if(dosazenoMax){
			printf("ve skupine s indexem %d bylo dosazano maximalni skore.\n", r);
		}
	}
	printf("----------------\n");
}


int main(void){

	// inicializace 2D pole - varianta 1
	int tabulka1[3][4] = {
		{2,4,6,8},
		{3,6,9,12},
		{4,8,12,16}
	};
	// inicializace 2D pole - varianta 2
	int pole_r0[4] = {2,4,4,5};
	int pole_r1[4] = {6,8,3,2};
	int pole_r2[4] = {10,7,1,4};
	int pole_r3[4] = {5,6,7,1};
	int pole_r4[4] = {9,8,8,1};
	int * tabulka2[5] = {pole_r0, pole_r1, pole_r2, pole_r3, pole_r4};

	vypisTabulku1(tabulka1, 3, 4);
	printf("----\n");
	vypisTabulku2(tabulka2, 5, 4);

	AvgAvg(tabulka2, 5, 4);
	BestGroup(tabulka2, 5, 4);
	MaxScore(tabulka2, 5, 4);


	return 0;
}