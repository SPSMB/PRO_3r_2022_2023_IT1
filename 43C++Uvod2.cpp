#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main(void){
	
	/*
	int a = 100;
	float b = 3.1415F;

	const char * r = "Testovaci zprava";

	// vypis s pomoci mapnipulatoru

	cout << "A1: >" << a << "<" << endl;
	cout << "A2: >" << setw(5) << a << "<" << endl;
	cout << "A3: >" << setw(10) << setfill('_') << a << "<" << endl;

	cout << "B1: >" << b << "<" << endl;
	cout << "B2: >" << setw(10) << setfill(' ') << b << "<" << endl;
	cout << "B3: >" << setw(10) << setprecision(3) << b << "<" << endl;
	cout << "B4: >" << setw(20) << setprecision(20) << b << "<" << endl;
	cout << "B5: >" << setw(10) << setfill(' ') << left << b << "<" << endl;
	cout << "B6: >" << setw(10) << fixed << setprecision(2) << b << "<" << endl;

	cout << "Retezec1: >" << setw(20) << uppercase << r << "<" << endl;
	cout << "Retezec2: >" << nouppercase << r << "<" << endl;
	*/

	// Tabulka nasobilky

	/*
	cout << "   ";
	for(int i=1; i<=10; i++){
		cout << setw(3) << right 
			 << setfill(' ') << i << " ";
	}
	cout << endl;

	cout << setw(4*10+3-1) << setfill('_') << "_" << endl;

	for(int r=10; r <=20; r++){

		cout << r << ":";
		
		for(int s=1; s<=10; s++){

			cout << setw(3) << right 
			     << setfill(' ') <<r*s << " ";

		}
		cout << endl;

	}
	*/

	// Vstup od uzivatele

	int x;
	double y;
	int auto;
	char retezec[100];
	char znak;
	
	cout << "Zadejte int: ";
	cin >> x;
	while(!cin){
		cout << "Spatne zadani, zkuste znovu.\n";
		cin.clear();
		// vycisteni vstupniho zasobniku
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cin >> x;
	}


	cout << "Zadejte double: ";
	cin >> y;
	// vycisteni vstupniho zasobniku
	cin.ignore(1000,'\n');

	cout << "Zadejte znak: ";
	cin >> znak;
	// vycisteni vstupniho zasobniku
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	
	cout << "Zadejte retezec: ";
	cin.getline(retezec, 100);

	
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Znak: >" << znak << "<" << endl;
	cout << "Retezec: >" << retezec << "<" << endl;

	return 0;
}
