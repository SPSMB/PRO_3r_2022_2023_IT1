#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Obdelnik {
private:
	int o_x;
	int o_y;
	int o_vyska;
	int o_sirka;

public:

	Obdelnik();
	Obdelnik(int x, int y, int sirka, int vyska);
	~Obdelnik();
	int sirka(){
		return o_sirka;
	}
	void nastavRozmery(int x, int y);
	void otoc(int x, int y, char smer);
	bool jeUvnitr(int x, int y);
};

Obdelnik::Obdelnik(){
	o_x = 0;
	o_y = 0;
	o_sirka = 0;
	o_vyska = 0;
}

Obdelnik::Obdelnik(int x, int y, int sirka, int vyska){
	o_x = x;
	o_y = y;
	o_sirka = sirka;
	o_vyska = vyska;
}

Obdelnik::~Obdelnik(){
	
}

int main(){

	Obdelnik silnice1;
	Obdelnik silnice2(10,20,500,10);

	cout << silnice2.sirka() << endl;

	return 0;
}