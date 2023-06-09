#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void){
	
	int cislo;
	cout << "Zadejte cislo v dekadicke soustave: ";
	cin >> cislo;

	while(!cin) {
		cout << "Neplatny format, prosim zadejte cislo znovu.\n";
		cin.ignore(1000, '\n');
		cin.clear();
		cin >> cislo;
	}

	int podil = cislo;
	int zbytek;
	string vystup = "";
	while(podil != 0){
		zbytek = podil % 2;
		podil = podil / 2;
		vystup = to_string(zbytek) + vystup;
	}
	cout << "Cislo " << cislo << " je binarne " << vystup << endl;
	return 0;
}
