#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class GatunekLiczba {
	public:
		int dlugoscGenu;
		int iloscWystapien;
};

vector<string> zwrocGeny(string genotyp){
	vector<string> result;
	bool dopiszDoGenu = false;
	string nowyGen = "";
	for(int a=0; a<genotyp.length(); a++){
		if(a<genotyp.length()-1 && genotyp[a] == 'A' && genotyp[a+1] == 'A' && !dopiszDoGenu){
			dopiszDoGenu = true;
			nowyGen = "";
		}
		if(dopiszDoGenu){
			nowyGen += genotyp[a];
		}
		if(a>0 && genotyp[a] == 'B' && genotyp[a-1] == 'B' && dopiszDoGenu){
			dopiszDoGenu = false;
			result.push_back(nowyGen);
		}
	}
	
	return result;
}

//sprawdz czy y zawiera sie w x
bool contains(string x, string y){
	int currentYpos = 0;
	for(int a=0; a<x.length(); a++){
		if(x[a] == y[currentYpos]){
			currentYpos++;
		}
		else {
			currentYpos = 0;
		}
		
		if(currentYpos == y.length()){
			return true;
		}
	}
	return false;
}

string odwroc(string x){
	string result = "";
	for(int a=x.length()-1; a>=0; a--){
		result += x[a];
	}
	return result;
}

bool palindrom(string x){
	int a=0;
	int b=x.length()-1;
	while(a<b){
		if(x[a] != x[b]){
			return false;
		}
		a++;
		b--;
	}
	return true;
}

int main(){
	ifstream dane("dane_geny.txt");
	string genotyp;
	
	vector<GatunekLiczba> zadanie1;
	int osobnikowMajacychMutacje = 0;
	int najwiekszaLiczbaGenowUOsobnika = 0;
	int najwiekszaDlugoscGenu = 0;
	
	int iloscOdpornych = 0;
	int iloscSilnieOdpornych = 0;
	
	while(dane >> genotyp){
		//podpunkt1
		bool znalezionoGen = false;
		for(int a=0; a<zadanie1.size(); a++){
			if(zadanie1[a].dlugoscGenu == genotyp.length()){
				zadanie1[a].iloscWystapien++;
				znalezionoGen = true;
			}
		}
		if(!znalezionoGen){
			GatunekLiczba gl;
			gl.dlugoscGenu = genotyp.length();
			gl.iloscWystapien = 1;
			zadanie1.push_back(gl);
		}
		
		//podpunkt2
		vector<string> geny = zwrocGeny(genotyp);
		bool maMutacje = false;
		for(int q=0; q<geny.size(); q++){
			//cout << "Test: " << test[q] << endl;
			if(contains(geny[q], "BCDDC")){
				maMutacje = true;
			}
			
			if(geny[q].length() > najwiekszaDlugoscGenu){
				najwiekszaDlugoscGenu = geny[q].length();
			}
		}
		if(maMutacje){
			osobnikowMajacychMutacje++;
		}
		if(geny.size() > najwiekszaLiczbaGenowUOsobnika){
			najwiekszaLiczbaGenowUOsobnika = geny.size();
		}
		
		//podpunkt3
		if(palindrom(genotyp)){
			iloscSilnieOdpornych++;
		}
		vector<string> odwrGeny = zwrocGeny(odwroc(genotyp));
		bool teSameGeny = true;
		for(int q=0; q<geny.size(); q++){
			bool znaleziono = false;
			for(int w=0; w<odwrGeny.size(); w++){
				if(geny[q] == odwrGeny[w]){
					odwrGeny.erase(odwrGeny.begin() + w);
					znaleziono= true;
				}
			}
			if(!znaleziono){
				teSameGeny = false;
				break;
			}
		}
		if(teSameGeny){
			iloscOdpornych++;
		}
	}
	
	cout << "69.1. " << endl;
	cout << "Gatunkow: " << zadanie1.size() << endl;
	int MAX = 0;
	for(int q=0; q<zadanie1.size(); q++){
		cout << zadanie1[q].dlugoscGenu << ": " << zadanie1[q].iloscWystapien << endl;
		if(zadanie1[q].iloscWystapien > MAX){
			MAX = zadanie1[q].iloscWystapien;
		}
	}
	cout << "Najwiecej osobnikow tego samego gatunku: " << MAX << endl;
	
	
	cout << "69.2. " << osobnikowMajacychMutacje << endl;
	
	cout << "69.3. " << endl << "najwiekszaLiczbaGenowUOsobnika: " << najwiekszaLiczbaGenowUOsobnika << endl;
	cout << "najwiekszaDlugoscGenu: " << najwiekszaDlugoscGenu << endl;
	
	cout << "69.4. " << endl;
	cout << "iloscOdpornych: " << iloscOdpornych << endl;
	cout << "iloscSilnieOdpornych: " << iloscSilnieOdpornych << endl;
	
	//cout << "Palindrom test: " << palindrom("PIOTREK") << " 2: " << palindrom("KOBYLAMAMALYBOK") << endl;
	//cout << "Odwroc test: " << odwroc("PIOTREK") << endl;
	
	//cout << "DDDD: " << contains("AACDBABBBCDAABCBBAAE", "BBBQ");
	//cout << "Test: " << zwrocGeny("AACDBABBBCDAABCBBAAE") << endl
}
