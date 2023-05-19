#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	int teplota = 35;
	int * adr_teplota = & teplota;
	int & ref_teplota = teplota;

	cout << "Teplota: " << teplota << endl;
	cout << "Adresa promenne teplota 1: " << adr_teplota << endl;
	cout << "Adresa promenne teplota 2: " << &teplota << endl;

	ref_teplota++;

	cout << "Hodnota pres ukazatel: " << *adr_teplota << endl;
	cout << "Hodnota z reference: " << ref_teplota << endl;
	cout << "Adresa reference teplota: " << &ref_teplota << endl;

	double a1 = 5;
	double a2 = 5.;
	double a3 = 5.1234;
	float a4 = 10.0/5;
	double a5 = 3e5; // 3 * 100 000

	cout << "A1: " << a1 << endl;
	cout << "A2: " << a2 << endl;
	cout << "A3: " << a3 << endl;
	cout << "A4: " << a4 << endl;
	cout << "A5: " << a5 << endl;

	bool info = true;
	info = false;
	info = 1;
	if(info){
		cout << "Jsem uvnitr" << endl;
	} else {
		cout << "jsem venku" << endl;
	}

	/*
	int a, b;
	cout << "Zadejte dve cela cisla: ";
	cin >> a >> b;
	bool rovnovaha = a==b;
	cout << "Vysledek porovnani je " << rovnovaha << endl;
	*/

	cout << "Cislo 100 v soustave 2: " 
		  << setbase(0) << 100 << endl;

	return 0;
}
