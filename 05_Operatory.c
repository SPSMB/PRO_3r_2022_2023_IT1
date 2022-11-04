#include <stdio.h>
#include <stdlib.h>

// nasledujici radek potlaci pri kompilovani warning C4996: 
//   'scanf': This function or variable may be unsafe.
#pragma warning(disable:4996)

int main(void){
	/*
	int i = 14;
	int j = 4;
	printf(" i:%3d,  j:%2d,   i%%j: %2d\n",      i,  j,   i%j);
	printf("-i:%3d, -j:%2d, -i%%-j: %2d\n",     -i, -j, -i%-j);
	printf(" i:%3d,  j:%2d,   i/j: %2d\n",       i,  j,   i/j);
	printf("-i:%3d, -j:%2d, -i/-j: %2d\n",      -i, -j, -i/-j);
*/
int zustatek, roky;
float urok;
char typ;
/*
if(roky>2){
	//varienta A
	if(zustatek>10 && zustatek<250 && typ == 'a'){
		urok = 0.75;
	}
}
else if (roky<2 && roky>1){
	//varianta B,C,D 
	if(zustatek > 250 && typ == 'a'){
		urok = 0.75;
	}else if(zustatek < 250 && zustatek > 150){
		urok = 0.5;
	}

}
else {
	//varianta E
	if(typ != 'a'){
		urok = 0.25;
	}
}
*/

// vypinaci tlacitko
/*
int t=1; // tlacitko aktivni
int u=1; // uzivatel aktivni
int a=1; // aktualizace dostupna
int p=1; // program bezi = neulozena prace


if(p == 1){
	printf("Ukladam praci, zaviram program.\n");
	p = 0;
}

if(t == 1){
	if(u == 1){
		printf("Prihlasovaci obrazovka.\n");
	} else {
		if(a == 1){
			printf("Instalace a vypnuti.\n");
		} else {
			printf("Jenom vypnu.\n");
		}
	}
}

	int x = 1;
	int y = 2;
	printf("x&y: %d\n", x&y);
	printf("x&&y: %d\n", x&&y);*/


	float cislo;
	printf("Zadejte cislo: \n");
	scanf("%f", &cislo);
	if(cislo<0){
		printf("%f", cislo*(-1) );
	}else{
		printf("%f", cislo);
	}

	abs(cislo);

	return 0;
}