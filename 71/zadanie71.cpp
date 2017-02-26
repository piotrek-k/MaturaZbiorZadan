#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

double f(double x, double tab[5][4]){
	if(x >= 0 && x < 5){
		int col = floor(x); //zaokraglanie w dol w celu uzyskania numeru kolumny tablicy
		return tab[col][0] + tab[col][1]*x + tab[col][2]*x*x + tab[col][3]*x*x*x;
	}
	return 0;
}

double ekstremumWKolumnie(int col, double tab[5][4]){
	double delta = pow(2*tab[col][2], 2) - 12*tab[col][1]*tab[col][3];
	if(delta == 0){
		return (-2*tab[col][2])/(6*tab[col][3]);
	}
	else if(delta > 0){
		double q = (-2*tab[col][2] - sqrt(delta))/(6*tab[col][3]);
		double w = (-2*tab[col][2] + sqrt(delta))/(6*tab[col][3]);
		if(q >= col && q < col+1){
			//cout << col << " q OK" << endl;
			return q;
		}
		else if(w >= col && w < col+1){
			//cout << col << " w OK" << endl;
			return w;
		}
		else {
			//cout << "Jakis problem :/" << endl;
			//return 0;
		}
	}
}

double znajdzZero(double left, double right, double tab[5][4]){
	double dokladnosc = (right-left)/(double)100;
	if(dokladnosc < 1/(double)100000000000){
		return left;
	}
	double prevA = 0;
	double newLeft = 0;
	double newRight = 0;
	bool noZeros = true;
	for(double a=left; a<right; a+=dokladnosc){
		double calcF = f(a, tab);
		if(f(a, tab) == 0) {
			return a;
		}
		if(prevA == 0){
			prevA = a;
		}
		if(f(prevA,tab) * f(a,tab) < 0){
			//return znajdzZero(prevA, a, tab);
			newLeft = prevA;
			newRight = a;
			noZeros = false;
			break;
		}
		prevA = a;
	}
	if(!noZeros){
		return znajdzZero(newLeft, newRight, tab);
	}
	else {
		return -1;
	}
	
}

int main(){
	ifstream dane("funkcja.txt");
	
	double wspolczynniki[5][4] = {};
	
	//cout << pow(2, 2);
	
	double wsp = 0;
	int col = 0;
	int row = 0;
	while(dane >> wsp){
		wspolczynniki[col][row] = wsp;
		row++;
		if(row == 4){
			row = 0;
			col++;
		}
	}
	
	//podpunkt 1:
	cout << "71.1: " << endl;
	cout << "f(1.5) = " << f(1.5, wspolczynniki) << endl;
	
	cout << "71.2: ekstrema:" << endl;
	double MAX = 0;
	for(int a = 0; a<5; a++){
		double e = ekstremumWKolumnie(a, wspolczynniki);
		//cout << "X = " << e << " wartosc: " << f(e, wspolczynniki) << endl;
		if(f(e, wspolczynniki) > MAX){
			MAX = f(e, wspolczynniki);
		}
	}
	cout << "MAX: " << MAX << endl;
	
	cout << "71.3: " << endl;
	for(int a = 0; a<5; a++){
		double e = round(znajdzZero(a, a+1, wspolczynniki) * 100000) / 100000;
		//cout << "X = " << e << " wartosc: " << f(e, wspolczynniki) << endl;
		if(e != -1){
			cout << a << ": Miejsce zerowe: " << e << ", wartosc: " << f(e, wspolczynniki) << endl;
		}
		
	}
	
	//cout << "Done";
}
