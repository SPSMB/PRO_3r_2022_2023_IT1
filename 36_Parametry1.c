#include <stdio.h>
#include <string.h>

/* program vypise vsechny parametry, 
   ktere byly zadany pri spusteni programu */

int main(int argc, char ** argv){

	printf("Tento program byl spusten s %d parametry.\n", 
		argc - 1);

	for(int i = 0; i < argc; i++){
		printf("%d: %s\n", i, argv[i]);
	}

	return 0;

}

