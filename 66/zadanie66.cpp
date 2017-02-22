#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int sumaCyfr(int x){
	int suma = 0;
	while(x > 0){
		suma += x%10;
		x /= 10;
	}
	return suma;
}

bool liczbaPierwsza(int x){
	if(x < 2) {
		return false;
	}
	for(int a=2; a<x; a++){
		if(x%a == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream dane("trojki.txt");
	
	int liczba = 0;
	int kolumna = 0;
	int poprzednieLiczbyWWierszu[3] = {};
	int liczbyWWierszu[3] = {};
	vector<vector<int> > zadanie1;
	vector<vector<int> > zadanie2;
	vector<vector<int> > zadanie3;
	bool wierszTworzyTrojkat = false;
	bool poprzedniWierszTworzyTrojkat = false;
	int iloscWierszyTrojkatnych = 0;
	int aktualnaDlugoscCiagu = 0;
	int najdluszyCiag = 0;
	
	while(dane >> liczba){
		//cout << liczba << "\t";
		liczbyWWierszu[kolumna] = liczba;
		if(kolumna == 2){
			//cout <<endl;
			
			//podpunkt 1
			if(sumaCyfr(liczbyWWierszu[0]) + sumaCyfr(liczbyWWierszu[1]) == liczbyWWierszu[2]){
				vector<int> newVec(liczbyWWierszu, liczbyWWierszu + 3);
				zadanie1.push_back(newVec);
			}
			
			//podpunkt 2
			if(liczbaPierwsza(liczbyWWierszu[0]) && liczbaPierwsza(liczbyWWierszu[1]) && liczbyWWierszu[2] == liczbyWWierszu[0] * liczbyWWierszu[1]){
				vector<int> newVec(liczbyWWierszu, liczbyWWierszu + 3);
				zadanie2.push_back(newVec);
			}
			
			//podpunkt 3
			if(liczbyWWierszu[0]*liczbyWWierszu[0] + liczbyWWierszu[1]*liczbyWWierszu[1] == liczbyWWierszu[2]*liczbyWWierszu[2] ||
				liczbyWWierszu[0]*liczbyWWierszu[0] + liczbyWWierszu[2]*liczbyWWierszu[2] == liczbyWWierszu[1]*liczbyWWierszu[1] || 
				liczbyWWierszu[1]*liczbyWWierszu[1] + liczbyWWierszu[2]*liczbyWWierszu[2] == liczbyWWierszu[0]*liczbyWWierszu[0]){
				wierszTworzyTrojkat = true;
				if(poprzedniWierszTworzyTrojkat){
					vector<int> newVec(liczbyWWierszu, liczbyWWierszu + 3);
					vector<int> newVec2(poprzednieLiczbyWWierszu, poprzednieLiczbyWWierszu + 3);
					
					zadanie3.push_back(newVec2);
					zadanie3.push_back(newVec);
				}
			}
			
			//podpunkt 4
			if(liczbyWWierszu[0]+liczbyWWierszu[1] > liczbyWWierszu[2] && 
				liczbyWWierszu[1]+liczbyWWierszu[2] > liczbyWWierszu[0] && 
				liczbyWWierszu[0]+liczbyWWierszu[2] > liczbyWWierszu[1]){
				iloscWierszyTrojkatnych++;
				aktualnaDlugoscCiagu++;
			} else {
				if(aktualnaDlugoscCiagu > najdluszyCiag){
					najdluszyCiag = aktualnaDlugoscCiagu;
				}
				aktualnaDlugoscCiagu = 0;
			}
		}
		
		kolumna++;
		if(kolumna >= 3){
			kolumna = 0;
			//poprzednieLiczbyWWierszu = liczbyWWierszu;
			for(int a=0; a<3; a++){
				poprzednieLiczbyWWierszu[a] = liczbyWWierszu[a];
			}
			poprzedniWierszTworzyTrojkat = wierszTworzyTrojkat;
			wierszTworzyTrojkat = false;
		}
	}
	//cout << "sumaCyfr: " << sumaCyfr(17) << endl;
	//cout << "sumaCyfr: " << sumaCyfr(29) << endl;
	//cout << "sumaCyfr: " << sumaCyfr(10) << endl;
	
	/*cout << "liczbaPierwsza: " << liczbaPierwsza(10) << endl;
	cout << "liczbaPierwsza: " << liczbaPierwsza(7) << endl;
	cout << "liczbaPierwsza: " << liczbaPierwsza(556) << endl; */
	
	cout << "66.1. " << endl;
	for(int a=0; a<zadanie1.size(); a++){
		for(int b=0; b<3; b++){
			cout << zadanie1[a][b] << " ";
		}
		cout << endl;
	}
	
	cout << "66.2. " << endl;
	for(int a=0; a<zadanie2.size(); a++){
		for(int b=0; b<3; b++){
			cout << zadanie2[a][b] << " ";
		}
		cout << endl;
	}
	
	cout << "66.3. " << endl;
	for(int a=0; a<zadanie3.size(); a++){
		for(int b=0; b<3; b++){
			cout << zadanie3[a][b] << " ";
		}
		cout << endl;
	}
	
	cout << "66.4. " << endl;
	cout << "Ilosc wierszy trojkatnych: " << iloscWierszyTrojkatnych << endl;
	cout << "Najdluszy ciag: " << najdluszyCiag << endl;
}
