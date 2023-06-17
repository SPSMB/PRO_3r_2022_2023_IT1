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

	/*Obdelnik();*/
	Obdelnik(int x, int y, int sirka, int vyska);
	~Obdelnik();
	int sirka(){
		return o_sirka;
	}
	void nastavRozmery(int x, int y){
		o_x = x;
		o_y = y;
	}
	void otoc(int x, int y, char smer);
	bool jeUvnitr(int x, int y);
	bool jeCtverec();
	void vypis();
};
/*
Obdelnik::Obdelnik(){
	o_x = 0;
	o_y = 0;
	o_sirka = 0;
	o_vyska = 0;
}
*/
Obdelnik::Obdelnik(int x = 0, int y = 0, int sirka = 0, int vyska = 0){
	o_x = x;
	o_y = y;
	o_sirka = sirka;
	o_vyska = vyska;
}

Obdelnik::~Obdelnik(){
	cout << "Konec objektu" << endl;
}

bool Obdelnik::jeUvnitr(int x, int y){
	if(  o_x <= x && x <= o_x + o_sirka &&
		 o_y <= y && y <= o_y + o_vyska){
		return true;
	} else {
		return false;
	}
}

bool Obdelnik::jeCtverec(){
	if(o_vyska == o_sirka){
		return true;
	} else {
		return false;
	}
}

void Obdelnik::vypis(){
	cout << "Obdelnik na souradnicich [" << o_x << "," << o_y 
	<< "] sirka:" << o_sirka << ", vyska:" << o_vyska << endl;
}

int main(){

	Obdelnik silnice1;
	Obdelnik silnice2(2,15);

	cout << "Sirka silnice je " << silnice2.sirka() << endl;

	silnice2.vypis();
	if(silnice2.jeCtverec()){
		cout << "je ctverec" << endl;
	} else {
		cout << "neni ctverec" << endl;
	}

	if(silnice2.jeUvnitr(-3,24)){
		cout << "Bod je uvnitr\n";
	} else {
		cout << "Bod je venku\n";
	}


	return 0;
}