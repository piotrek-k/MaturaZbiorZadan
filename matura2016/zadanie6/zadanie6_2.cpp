#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream dane("dane_6_2.txt");
	ofstream wynik("wyniki_6_2.txt");
	
	string tekst;
	int klucz = 0;
	
	cout << "Zadanie 6.2"<< endl;
	wynik << "Zadanie 6.2"<< endl;
	while(dane >> tekst >> klucz){
		string odszyfrowany = "";
		
		for(int a=0; a<tekst.length(); a++){
			int idZnaku = tekst[a]-'A';
			int x = ((idZnaku - klucz) % 26);
			if(x==0){
				x=-26;
			}
			int staryZnakID = 0;
			if(x<0){
				staryZnakID = 26+x;
			}
			else {
				staryZnakID = x;
			}
			
			char staryZnak = staryZnakID+'A';
			odszyfrowany += staryZnak;
		}
		//cout << (char)(26+'A');
		
		cout << tekst << "->" << odszyfrowany << endl;
		wynik <<  odszyfrowany << endl;
	}
}
