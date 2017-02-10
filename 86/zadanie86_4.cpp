#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream dane("dane_wybory.txt");
	
	string okreg;
	int wyniki[5] = {};
	
	int modelStandardowy[5] = {};
	int modelRegionalny[5] = {};
	
	int sumaGlosowRegion[5] = {};
	
	int count = 1;
	
	while(dane >> okreg && dane >> wyniki[0] && dane >> wyniki[1] && dane >> wyniki[2] && dane >> wyniki[3] && dane >> wyniki[4]){
		//PODZIA£ STANDARDOWY
		
		int mandatow[5] = {}; //zdobytych mandatow w okregu przez kazdy komitet w danym okregu
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
			modelStandardowy[q] += mandatow[q];
		}
		
		//PODZIA£ REGIONALNY
		for(int q=0; q<5; q++){
			sumaGlosowRegion[q] += wyniki[q];
		}
		
		if(count%5==0){
			int regMandatow[5] = {};
			for(int m=0; m<100; m++){
				double maxWSP = 0; //maksymalny wspolczynnik uzyskany przez komitet
				int komZMAX = -1; //komitet majacy aktualny wspó³czynnik maksymalny
				for (int a=0; a<5; a++){
					double wsp = sumaGlosowRegion[a] / (double)(2*regMandatow[a]+1);
					if(wsp > maxWSP){
						maxWSP = wsp;
						komZMAX = a;
					}
				}
				regMandatow[komZMAX]++;
			}
			
			for(int q=0; q<5; q++){
				modelRegionalny[q] += regMandatow[q];
			}
			
			for(int q=0; q<5; q++){
				sumaGlosowRegion[q] =0;
			}
			
			count=0;
		}
		
		count ++;
	}
	
	cout << "Liczba mandatow w modelu standardowym: " << endl;
	for(int w=0; w<5; w++){
		cout << "K"<<w+1<<": "<<modelStandardowy[w]<<"\t";
	}
	
	cout << endl << "Liczba mandatow w modelu regionalnym: " << endl;
	for(int w=0; w<5; w++){
		cout << "K"<<w+1<<": "<<modelRegionalny[w]<<"\t";
	}
	
}

