#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

class Okrag {
	public:
		double x = 0;
		double y = 0;
		double r = 0;
};

double wartBezwz(double x){
	if(x < 0){
		x = -x;
	}
	return x;
}

int main(){
	ifstream dane("okregi.txt");
	
	int column = 0;
	int count = 0;
	double liczba;
	Okrag okregi[2000] = {};
	while(dane >> liczba){
		if(column == 0){
			okregi[count].x = liczba;
		}
		else if(column == 1){
			okregi[count].y = liczba;
		}
		else if(column == 2){
			okregi[count].r = liczba;
		}
		
		column ++;
		if(column == 3){
			column = 0;
			count++;
		}
	}
	
	//podpunkt 1 i 2
	int okregiNaJedejCwiartce = 0;
	int cwiartka1 = 0;
	int cwiartka2 = 0;
	int cwiartka3 = 0;
	int cwiartka4 = 0;
	int okregiNieZawierajaceSieWJednejCwiartce = 0;
	int lustrzanychPar = 0;
	int parProstopadlych = 0;
	int dlugoscLancucha = 1;
	int MAXdlugoscLancucha = 0;
	Okrag poprzedniOkrag;
	for(int a=0; a<2000; a++){
		if(wartBezwz(okregi[a].x) > okregi[a].r && wartBezwz(okregi[a].y) > okregi[a].r){
			okregiNaJedejCwiartce++;
			if(okregi[a].x > 0 && okregi[a].y > 0){
				cwiartka1++;
			}
			else if(okregi[a].x > 0 && okregi[a].y < 0){
				cwiartka4++;	
			}
			else if(okregi[a].x < 0 && okregi[a].y > 0){
				cwiartka2++;
			}
			else if(okregi[a].x < 0 && okregi[a].y < 0){
				cwiartka3++;
			}
		}
		if(wartBezwz(okregi[a].x) <= okregi[a].r || wartBezwz(okregi[a].y) <= okregi[a].r){
			okregiNieZawierajaceSieWJednejCwiartce++;
		}

		for(int b=0; b<a; b++){
			if(okregi[a].r == okregi[b].r){
				if((okregi[a].x == -okregi[b].x && okregi[a].y == okregi[b].y) ||
					(okregi[a].y == -okregi[b].y && okregi[a].x == okregi[b].x)){
					lustrzanychPar++;
				}
			}
		} 
		
		for(int b=0; b<2000; b++){
			if(okregi[a].r == okregi[b].r){
				if(okregi[a].x == -okregi[b].y && okregi[a].y == okregi[b].x){
					parProstopadlych++;
				}
			}
		}
		
		if(a <= 1000){
			double AB = sqrt((okregi[a].x - poprzedniOkrag.x)*(okregi[a].x - poprzedniOkrag.x) + (okregi[a].y - poprzedniOkrag.y)*(okregi[a].y - poprzedniOkrag.y));
			if(wartBezwz(okregi[a].r - poprzedniOkrag.r) < AB && AB < okregi[a].r + poprzedniOkrag.r){
				dlugoscLancucha++;
			}
			else {
				dlugoscLancucha = 1;
			}
			
			if(dlugoscLancucha > MAXdlugoscLancucha){
				MAXdlugoscLancucha = dlugoscLancucha;
			}
			
			poprzedniOkrag = okregi[a];
		}
	}
	
	cout << "79.1. " << endl;
	cout << "Cwiartka 1: " << cwiartka1 << endl;
	cout << "Cwiartka 2: " << cwiartka2 << endl;
	cout << "Cwiartka 3: " << cwiartka3 << endl;
	cout << "Cwiartka 4: " << cwiartka4 << endl;
	cout << "Przecinajace osie: " << okregiNieZawierajaceSieWJednejCwiartce << endl;
	
	cout << "79.2. " << endl;
	cout << "Lustrzanych par: " << lustrzanychPar << endl;
	
	cout << "79.3. " << endl;
	cout << "Prostopadlych par: " << parProstopadlych << endl;
	
	cout << "79.4. " << endl;
	cout << "Najwieksza dlugosc lancucha: " << MAXdlugoscLancucha << endl;
}
