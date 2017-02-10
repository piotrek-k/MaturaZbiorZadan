#include <iostream>
#include <math.h>

using namespace std;

bool liczMandaty(int maxmandatow, int glosyNaQ){
	int glosyNaR = 100000 - glosyNaQ;
	int wyniki[2] = {glosyNaQ, glosyNaR};
	int mandatow[2] = {};
	
	//0 - q, 1 - r
	for(int m=0; m<maxmandatow; m++){
		double maxWSP = 0; //maksymalny wspolczynnik uzyskany przez komitet
		int komZMAX = -1; //komitet majacy aktualny wspó³czynnik maksymalny
		for (int a=0; a<2; a++){
			double wsp = wyniki[a] / (double)(2*mandatow[a]+1);
			if(wsp > maxWSP){
				maxWSP = wsp;
				komZMAX = a;
			}
		}
		mandatow[komZMAX]++;
	}
	
	//cout << "mandatow[0]: " << mandatow[0] << " mandatow[1]: " << mandatow[1] << endl; 
	//double mandatyQprzezMandatyR = mandatow[0] / (double)mandatow[1];
	
	return mandatow[0] == mandatow[1];
}

int main(){
	int liczbaMandatow[3] = {20, 40, 100};
	for(int x=0; x<3; x++){
		for(int a=10; a<100000; a++){
			if(liczMandaty(liczbaMandatow[x], a)){
				cout << liczbaMandatow[x] << " mandatow, pol na pol: liczba glosow na Q: " << a << endl;
				break;
			}
		}
	}
}
