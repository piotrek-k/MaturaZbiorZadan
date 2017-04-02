#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream dane("dane_6_1.txt");
	ofstream wynik("wyniki_6_1.txt");
	string slowa[100];
	//string slowaZaszyfrowane[100];
	string tekst;
	int count = 0;
	int klucz = 107;
	
	cout << "Zadanie 6.1: " << endl;
	wynik << "Zadanie 6.1: " << endl;
	
	while(dane >> tekst){
		slowa[count] = tekst;
		string zaszyfrowane = "";
		
		for(int a =0; a < tekst.length(); a++){
			int kodLitery = tekst[a]-'A';
			int nowyKodLitery = (kodLitery + klucz) % 26;
			char litera = nowyKodLitery+'A';
			zaszyfrowane += litera;
		}
		
		cout << tekst << "->" << zaszyfrowane << endl;
		wynik << tekst << "->" << zaszyfrowane << endl;
	}
	
}
