#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool liczbaPierwsza(int n){
	for(int a=2; a<n; a++){
		if(n%a==0){
			return false;
		}
	}
	return true;
}

//Sortowanie dodatkowo, poza treœci¹ zadania, zignorowaæ
vector<string> sortujVector(vector<string> v){
	for(int a=0; a<v.size()-1; a++){
		for(int b=0; b<v.size()-1-a; b++){
			int indexLitery = 0;
			while(indexLitery < v[b].length()-1){
				if((int)v[b][indexLitery] > (int)v[b+1][indexLitery]){
					string temp = v[b];
					v[b] = v[b+1];
					v[b+1] = temp;
					break;
				}
				if((int)v[b][indexLitery] == (int)v[b+1][indexLitery]){
					indexLitery++;
				}
				else {
					break;
				}
			}
		}
	}
	return v;
}

int main(){
	ifstream dane("dane_PR/NAPIS.TXT");
	ofstream wynik("ZADANIE5.TXT");
	
	string wiersz;
	int napisyPierwsze = 0;
	vector<string> rosnace;
	vector<string> wszystkie;
	vector<string> powtarzaSie;
	
	while(dane >> wiersz){
		
		bool juzIstnieje = false;
		for(int q=0; q<wszystkie.size(); q++){
			if(wszystkie[q] == wiersz){
				powtarzaSie.push_back(wiersz);
				juzIstnieje = true;
			}
		}
		if(!juzIstnieje){
			wszystkie.push_back(wiersz);
		}
		
		//cout << wiersz << endl;
		
		int sumaASCII = 0;
		bool rosnacy = true;
		int poprzedniaWartosc = -1;
		for(int a=0; a<wiersz.length(); a++){
			sumaASCII += wiersz[a];
			if(poprzedniaWartosc != -1 && poprzedniaWartosc >= (int)wiersz[a]){
				rosnacy = false;
			}
			
			poprzedniaWartosc = wiersz[a];
		}
		if(liczbaPierwsza(sumaASCII)){
			napisyPierwsze++;
		}
		if(rosnacy){
			rosnace.push_back(wiersz);
		}
		
	}
	
	cout << "Podpunkt a:"<< endl;
	cout << napisyPierwsze << endl;
	cout << "Podpunkt b:"<< endl;
	for(int q=0; q<rosnace.size(); q++){
		cout << rosnace[q] << endl;
	}
	cout << "Podpunkt c:"<< endl;
	for(int q=0; q<powtarzaSie.size(); q++){
		cout << powtarzaSie[q] << endl;
	}
	
	wynik << "Podpunkt a:"<< endl;
	wynik << napisyPierwsze << endl;
	wynik << "Podpunkt b:"<< endl;
	for(int q=0; q<rosnace.size(); q++){
		wynik << rosnace[q] << endl;
	}
	wynik << "Podpunkt c:"<< endl;
	for(int q=0; q<powtarzaSie.size(); q++){
		wynik << powtarzaSie[q] << endl;
	}
	
	
	//Sortowanie dodatkowo, poza treœci¹ zadania, zignorowaæ
	vector<string> sortrosnace = sortujVector(rosnace);
	cout <<endl<< "B sort:"<< endl;
	for(int q=0; q<sortrosnace.size(); q++){
		cout << sortrosnace[q] << endl;
	}
	vector<string> sortPowt = sortujVector(powtarzaSie);
	cout <<endl<< "C sort:"<< endl;
	for(int q=0; q<sortPowt.size(); q++){
		cout << sortPowt[q] << endl;
	}
}
