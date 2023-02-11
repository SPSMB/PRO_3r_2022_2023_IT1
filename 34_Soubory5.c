#include <stdio.h>
#include <string.h>

/* program cte radu radu cisel zakoncenou nulou 
	a uklada do souboru */

int main(){

	FILE * soubor = fopen("soubor1.txt", "w");
	
	printf("Prosim zadejte radu cisel zakoncenou 0:\n");

	int a; /* docasna promenna na cislo */
	char r[100];

	do{

		scanf("%d", &a);
		sprintf(r, "%d", a); /* konverze intu na string */
		/*fprintf(soubor, "%d ", a);*/
		fputs(r, soubor);
		if(a != 0){
			fputc('_', soubor);
		} 
		printf("ok\n");

	}while(a != 0);
	
	fclose(soubor);

	

	return 0;
}

