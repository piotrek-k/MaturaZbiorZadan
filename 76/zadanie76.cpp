#include<iostream>
#include<fstream>
using namespace std;

string szyfruj(string tekst, int klucz[], int keyLength){
	int keyPos = 0;
	int arrayLength = keyLength;
	for(int a=0; a<tekst.length(); a++){
		char temp = tekst[klucz[keyPos]-1];
		tekst[klucz[keyPos]-1] = tekst[a];
		tekst[a] = temp;
		keyPos++;
		if(keyPos == arrayLength){
			keyPos = 0;
		}
	}
	return tekst;
}

string odszyfruj(string tekst, int klucz[], int keyLength){
	int krok = tekst.length();
	for(int a=tekst.length()-1; a>=0; a--){
		int pos = (krok-1)%keyLength;
		char temp = tekst[klucz[pos]-1];
		tekst[klucz[pos]-1] = tekst[a];
		tekst[a] = temp;
		
		krok--;
	}
	return tekst;
}

void zadanie1(){
	ifstream dane("szyfr1.txt");
	ofstream wynik("wyniki_szyfr1.txt");
	string napisy[6];
	for(int a=0; a<6; a++){
		dane >> napisy[a];
	}
	int szyfr[50];
	for(int a=0; a<50; a++){
		dane >> szyfr[a];
	}
	
	cout << "76.1: " << endl;
	for(int a=0; a<6; a++){
		cout << szyfruj(napisy[a], szyfr, 50) << endl;
		wynik << szyfruj(napisy[a], szyfr, 50) << endl;
	}
}

void zadanie2(){
	ifstream dane("szyfr2.txt");
	ofstream wynik("wyniki_szyfr2.txt");
	string napisy[1];
	for(int a=0; a<1; a++){
		dane >> napisy[a];
	}
	int szyfr[15];
	for(int a=0; a<15; a++){
		dane >> szyfr[a];
	}
	
	cout << "76.2: " << endl;
	for(int a=0; a<1; a++){
		cout << szyfruj(napisy[a], szyfr, 15) << endl;
		wynik << szyfruj(napisy[a], szyfr, 15) << endl;
	}
}

void zadanie3(){
	ifstream dane("szyfr3.txt");
	ofstream wynik("wyniki_szyfr3.txt");
	string napisy[1];
	for(int a=0; a<1; a++){
		dane >> napisy[a];
	}
	int szyfr[] = {6,2,4,1,5,3};
	
	cout << "76.3: " << endl;
	for(int a=0; a<1; a++){
		cout << odszyfruj(napisy[a], szyfr, 6) << endl;
		wynik << odszyfruj(napisy[a], szyfr, 6) << endl;
	}
}

int main(){
	zadanie1();
	zadanie2();
	zadanie3();
}
