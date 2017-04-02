#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream dane("dane_6_3.txt");
	ofstream wynik("wyniki_6_3.txt");
	
	string tekst1;
	string tekst2;
	wynik << "Zadanie 6.3: " << endl;
	while(dane >> tekst1 >> tekst2){
		int przesuniecie = -1;
		for(int a=0; a<tekst1.length(); a++){
			int litera1 = tekst1[a]-'A';
			int litera2 = tekst2[a]-'A';
			int nowe_przesuniecie = ((25 - litera1) + litera2) % 26;
			
			if(przesuniecie != -1 && przesuniecie != nowe_przesuniecie){
				cout << tekst1 << endl;
				wynik << tekst1 << endl;
				break;
			}
			przesuniecie = nowe_przesuniecie;
		}
	}
}
