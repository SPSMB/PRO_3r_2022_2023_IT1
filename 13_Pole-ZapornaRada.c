#include <stdio.h>

int main(void){

	// zadani hodnot a ulozeni do pole
	printf("Zadejte radu 10 cisel \n");
	int pole[10];
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &pole[i]);
	}

	int delka = 0;
	int max_delka = 0;
	int start_index = 0;

	// pruchod polem a zjisteni nejdelsi rady
	for (int i = 0; i < 10; ++i)
	{
		if(pole[i] < 0){
			delka++;
			if(delka > max_delka){
				max_delka = delka;
				start_index = i - delka + 1;
			}
		}else{
			delka = 0;
		}
	}

	// vypis nejdelsi rady
	int j = start_index;
	printf("Vypis nejdelsi rady\n");
	while(j < max_delka + start_index){
		printf("%d, ", pole[j]);
		j++;
	}

	return 0;
}