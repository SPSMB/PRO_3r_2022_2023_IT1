
#include <stdio.h>
#include "29_knihovna_pole.c"

#define KONSTANTA1 9
#define KONSTANTA2 9

#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define VARIANTA2 /* spusti se druha varinta programu */
#ifdef VARIANTA1 /* pokud je definovan token VARIANTA1, spustila bz se prvni varianta programu */

int main(){
	printf("Max: %d\n", MAX(9,15));
	printf("%d\n", 5^2);
	return 0;
}

#else

int main(int argc, char const *argv[])
{

	const int velPole = 8;

#ifndef VARIANTA1
	if(8>5){
		printf("PrvniA2\n");
	} else {
		printf("DruhyB2\n");
	}
#else
	8>5 ? printf("PrvniA1\n") : printf("DruhyB1\n");
#endif
	int pole1[KONSTANTA1] = {6,9,8,2,4,6,3,8};
	int pole2[KONSTANTA1] = {3,6,9,8,2,4,6,3};

	int * pole2D[2] = {pole1, pole2};

	vypisPole(pole1, KONSTANTA1);
	vypisTabulku2(pole2D, 2, KONSTANTA1);
	bubble_sort(pole1, KONSTANTA1, pole1);
	vypisPole(pole1, KONSTANTA1);

	return 0;
}

#endif
