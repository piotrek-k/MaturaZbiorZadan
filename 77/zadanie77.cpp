#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

string encode(string line, string key, bool zwrocLiczbePowtorzen){
	int keyPosition = 0; //pozycja odczytywanej litery w kluczu
	int linePosition = 0; //pozycja odczytywanej litery z tekstu z pliku
	int powtorzenKlucza = 1;
	
	for(int a=0; a<line.length(); a++){
		if((int)line[a] >= 'A' && (int)line[a] <= 'Z'){
			if(keyPosition >= key.length()){
				keyPosition = 0;
				powtorzenKlucza++;
			}
			int placesToMove = key[keyPosition] - 'A'; //o ile zmienic literê z tekstu
			int newLetterNumber = ((line[a] - 'A') + placesToMove) % 26; //nowy kad ASCII dla znaku z tekstu
			line[a] = (char)(newLetterNumber + 'A');
			keyPosition ++;
		}
	}
	
	//cout << line << endl;
	
	if(zwrocLiczbePowtorzen){
		cout << "Liczba powtorzen: " << powtorzenKlucza << endl;
	}
	
	return line;
}

string decode(string line, string key){
	int keyPosition = 0; //pozycja odczytywanej litery w kluczu
	int linePosition = 0; //pozycja odczytywanej litery z tekstu z pliku
	
	for(int a=0; a<line.length(); a++){
		if((int)line[a] >= 'A' && (int)line[a] <= 'Z'){
			if(keyPosition >= key.length()){
				keyPosition = 0;
			}
			int placesToMove = key[keyPosition] - 'A'; //o ile zmienic literê z tekstu
			int newLetterNumber = ((line[a] - 'A') - placesToMove); //nowy kad ASCII dla znaku z tekstu
			while(newLetterNumber < 0){
				newLetterNumber = 26 + newLetterNumber;
			}
			line[a] = (char)(newLetterNumber + 'A');
			keyPosition ++;
		}
	}
	
	return line;
}

int main(){
	ifstream dane("dokad.txt");
	
	string line;
	string key = "LUBIMYCZYTAC";
	
	cout << "77.1" << endl;
	if(dane.is_open()){
		while(getline(dane, line)){
			
			cout << encode(line, key, true) << endl;
			
		}
		dane.close();
	}
	
	ifstream daneSzyfr("szyfr.txt");
	
	string tekst;
	string zaszyfrowanyTekst;
	string klucz;
	int count = 0;
	
	cout << "77.2" << endl;
	if(daneSzyfr.is_open()){
		while(getline(daneSzyfr, line)){
			if(count == 0){
				tekst = line;
				zaszyfrowanyTekst = line;
			}
			else if(count == 1){
				klucz = line;
			}
			count ++;
		}
		daneSzyfr.close();
	}
	
	cout << decode(tekst, klucz) << endl;
	
	cout << "77.3" <<endl;
	int countLetters[26] = {};
	int iloscLiter = 0;
	for(int a = 0; a< zaszyfrowanyTekst.length(); a++){
		if((int)zaszyfrowanyTekst[a] >= 'A' && (int)zaszyfrowanyTekst[a] <= 'Z'){
			int letterNumber = zaszyfrowanyTekst[a] - 'A';
			countLetters[letterNumber] ++;
			iloscLiter++;
		}
	}
	double k; //indeks koincydencji
	for(int a = 0; a< 26; a++){
		//cout << (char)(a + 'A') << ": " << countLetters[a] << endl;
		k += countLetters[a] * (countLetters[a] - 1);
	}
	k = k / (double)(iloscLiter*(double)(iloscLiter-1));
	
	double d = (0.0285)/(double)(k-0.0385); //szacowana iloœc liter w kluczu
	d = round(d*100)/100; //zaokraglone do 2 miejsc po przecinku
	
	cout << "Dokladna wartosc klucza: " << klucz.length() << endl;
	cout << "Oszacowana wartosc klucza: " << d << endl;
	
}	
