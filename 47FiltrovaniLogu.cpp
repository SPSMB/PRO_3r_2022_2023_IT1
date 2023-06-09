#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	string poleS[10] = {
		string("deleted C:/Users/Tom/jedna.txt 2021-05-20"),
		string("created C:/Users/Tom/dva.txt 2021-05-11"),
		string("new C:/Users/Tom/tri.txt 2021-06-20"),
		string("created C:/Users/Tom/ctyri.txt 2021-07-03"),
		string("updated C:/Users/Tom/pet.txt 2021-07-03"),
		string("new C:/Users/Tom/sest.txt 2021-05-20"),
		string("deleted C:/Users/Tom/sedm.txt 2021-05-11"),
		string("new C:/Users/Tom/osm.txt 2021-05-20"),
		string("updated C:/Users/Tom/devet.txt 2021-05-11"),
		string("updated C:/Users/Tom/deset.txt 2021-07-03") 
	};

	int mesic, den, rok;

	cout << "Zadejte den: ";
	cin >> den;
	cout << "Zadejte mesic: ";
	cin >> mesic;
	cout << "Zadejte rok: ";
	cin >> rok; 

	string vstup;

	if(den < 10 && mesic < 10){
		vstup = to_string(rok) + "-0" + to_string(mesic) + "-0" + to_string(den);
	} else if(mesic < 10){
		vstup = to_string(rok) + "-0" + to_string(mesic) + "-" + to_string(den);
	} else if(den < 10){
		vstup = to_string(rok) + "-" + to_string(mesic) + "-0" + to_string(den);
	} else {
		vstup = to_string(rok) + "-" + to_string(mesic) + "-" + to_string(den);
	}

	cout << "Vstup: " << vstup << endl;

	int pocet = 0;
	for(int i = 0; i < 10; i++){
		if(poleS[i].find(vstup) != string::npos){
			cout << poleS[i] << endl;
			pocet++;
		}
	}

	if(pocet == 0){
		cout << "Zadanemu datu neodpovida zadny zaznam." << endl;
	}
	return 0;
}
