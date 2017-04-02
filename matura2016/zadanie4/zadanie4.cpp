#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class Punkty {
	public:
		int x=0;
		int y=0;
};

int iloscPunktowNalezacychDoKola(Punkty punkty[10000], int zakres){
	int ile = 0;
	int a = 200;
	int b = 200;
	int r = 200;
	for(int q=0; q<zakres; q++){
		if(pow(punkty[q].x - a, 2) + pow(punkty[q].y - b, 2) <= pow(r, 2)){
			//cout << ile << ": " << punkty[q].x << " " << punkty[q].y << endl;
			ile++;
		}
	}
	return ile;
}

double szacujPI(Punkty punkty[10000], int zakres, int dokladnosc){
	int nk = iloscPunktowNalezacychDoKola(punkty, zakres);
	double wynik = round((nk / (double)zakres * 4) * dokladnosc) / (double)dokladnosc;
	return wynik;
}

int main(){
	ifstream dane("punkty.txt");
	ofstream daneDoWykresu("daneDoWykresu.txt");
	ofstream wynik("wyniki_4.txt");
	
	int liczba;
	int count = 0;
	int col = 0;
	Punkty punkty[10000] = {};
	
	while(dane >> liczba){
		//cout << tekst;
		
		if(col == 0){
			//cout << "\t";
			punkty[count].x = liczba;
		}
		if(col == 1){
			//cout << "\n";
			punkty[count].y = liczba;
		}	
		
		col ++;
		if(col == 2){
			col = 0;
			count ++;
		}
		
	}
	
	//zadanie 1
	int a = 200;
	int b = 200;
	int r = 200;
	
	cout << "Zadanie 1: " << endl;
	cout << "Nalezace do brzegu kola: " << endl;
	wynik << "Zadanie 1: " << endl;
	wynik << "Nalezace do brzegu kola: " << endl;
	for(int q=0; q<10000; q++){
		if(pow(punkty[q].x - a, 2) + pow(punkty[q].y - b, 2) == pow(r, 2)){
			cout << punkty[q].x << " " << punkty[q].y << endl;
			wynik << punkty[q].x << " " << punkty[q].y << endl;
		}
	}
	cout << "Nalezace do wznetrza kola: " ;
	wynik << "Nalezace do wznetrza kola: " ;
	int ile = 0;
	for(int q=0; q<10000; q++){
		if(pow(punkty[q].x - a, 2) + pow(punkty[q].y - b, 2) < pow(r, 2)){
			//cout << ile << ": " << punkty[q].x << " " << punkty[q].y << endl;
			ile++;
		}
	}
	cout << ile << endl;
	wynik << ile << endl;
	
	cout << "Zadanie 2: " << endl;
	wynik << "Zadanie 2: " << endl;
	double pi100 = szacujPI(punkty, 100, 10000);
	double pi1000 = szacujPI(punkty, 1000, 10000);
	double pi5000 = szacujPI(punkty, 5000, 10000);
	double piAll = szacujPI(punkty, 10000, 10000);
	cout << pi100 << endl;
	cout << pi1000 << endl;
	cout << pi5000 << endl;
	cout << piAll << endl;
	wynik << pi100 << endl;
	wynik << pi1000 << endl;
	wynik << pi5000 << endl;
	wynik << piAll << endl;
	
	cout << "Zadanie 3: " << endl;
	wynik << "Zadanie 3: " << endl;
	//cout << "" << M_PI;
	for(int w=1; w<=1700; w++){
		double e = M_PI - szacujPI(punkty, w, 100000);
		if(e < 0) {
			e = -e;
		}
		daneDoWykresu << e << endl;
		if(w == 1000 || w == 1700){
			cout << w << ": " << e << endl;
			wynik << w << ": " << e << endl;
		}
	}
}
