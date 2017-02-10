#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream dane("dane_wybory.txt");
	
	string okreg;
	int wyniki[5] = {};
	int max_mandatow[5] = {};
	while(dane >> okreg && dane >> wyniki[0] && dane >> wyniki[1] && dane >> wyniki[2] && dane >> wyniki[3] && dane >> wyniki[4]){
		int mandatow[5] = {}; //zdobytych mandatow w okregu przez kazdy komitet
		for(int m=0; m<20; m++){
			double maxWSP = 0; //maksymalny wspolczynnik uzyskany przez komitet
			int komZMAX = -1; //komitet majacy aktualny wspó³czynnik maksymalny
			for (int a=0; a<5; a++){
				double wsp = wyniki[a] / (double)(2*mandatow[a]+1);
				if(wsp > maxWSP){
					maxWSP = wsp;
					komZMAX = a;
				}
			}
			mandatow[komZMAX]++;
		}
		
		for(int q=0; q<5; q++){
			if(max_mandatow[q] < mandatow[q]){
				max_mandatow[q] = mandatow[q];
			}
		}
	}
	
	cout << "Maksymalna liczba zdobytych mandatow w jedym okregu:" <<endl;
	for(int w=0; w<5; w++){
		cout << "K"<<w+1<<": "<<max_mandatow[w]<<"\t";
	}
}

