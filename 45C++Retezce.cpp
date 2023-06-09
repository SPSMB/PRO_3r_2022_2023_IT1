#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void){
	
	string s1("Pocatecni retezec");
	string s2 = "druhy retezec";
	string s3(s1);
	string s4(s1, 8, 3);
	string s5("Treti retezec", 10);
	string s6(15, 'x');
	string s7(15, 42);

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: >" << s4 << "<" << endl;
	cout << "s5: >" << s5 << "<" << endl;
	cout << "s6: >" << s6 << "<" << endl;
	cout << "s7: >" << s7 << "<" << endl;

	cout << "Delka retezce s1: " << s1.size() << endl;
	cout << "Pristup k znaku 7: " << s1.at(7) << endl;
	cout << "Pristup k znaku 7: " << s1[7] << endl;
	cout << "Pridat dalsi retezec: " << s1.append(" uz neni.") << endl;
	s1.replace(5, 3, "novy");
	cout << s1 << endl;

	// funkce to_string

	float cisloPi = 3.1415F;
	string retezecPi = to_string(cisloPi);
	cout << "retezecPi: " << retezecPi << endl;
	cout << "cisloPi:   " << cisloPi << endl;

	// spojovani retezcu pres PLUS

	string s10, s11;
	cout << "zadejte 1. retezec: "; 
	cin >> s10;
	cout << "zadejte 2. retezec: "; 
	cin >> s11;
	string s12 = s10 + s11;
	cout << "Spojeno: S12: " << s12 << endl;


	return 0;
}
