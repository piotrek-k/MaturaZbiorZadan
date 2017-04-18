#include<iostream>
#include<string>
#include<fstream>
#include<math.h>

using namespace std;

unsigned long int binToDec(string num){
	unsigned long int wynik=0;
	//cout << "Length: " << num.length() << endl;
	for(int a=num.length()-1; a>=0; a--){
		if(num[num.length()-1-a] == '1'){
			//cout << a << endl;
			unsigned long int toAdd = 1;
			for(int x=0; x<a; x++){
				toAdd *= 2;
			}
			wynik += toAdd;
			
			//wynik += pow(2, a);
		}
	}
	
	return wynik;
}

int main(){
	fstream dane("liczby.txt");
	ofstream wynik("wynik4.txt");
	
	//cout << "BINTODEC: " << binToDec("101") << endl;
	
	string tekst;
	int podp1 = 0;
	int podp2PodPrzez2 = 0;
	int podp2PodPrzez8 = 0;
	unsigned long int maxWartosc = 0;
	long int minWartosc = -1;
	int pozMaxWartosc = 0;
	int pozMinWartosc = 0;
	int nrWiersza = 0;
	while(dane >> tekst){
		nrWiersza++;
		//cout << tekst << endl;
		
		//podpunkt 1
		int iloscJedynek = 0;
		int iloscZer = 0;
		for(int a=0; a<tekst.length(); a++){
			if(tekst[a] == '1'){
				iloscJedynek ++;
			}
			else if(tekst[a] == '0'){
				iloscZer ++;
			}
		}
		if(iloscZer > iloscJedynek){
			podp1 ++;
		}
		
		//podpunkt 2
		unsigned long int dec = binToDec(tekst);
		//cout << dec << " " << tekst << endl;
		//cout << dec << endl;
		if(dec % 2 == 0){
			podp2PodPrzez2++;
		}
		if(dec % 8 == 0){
			podp2PodPrzez8++;
		}
		
		//podpunkt 3
		if(dec > maxWartosc){
			maxWartosc = dec;
			pozMaxWartosc = nrWiersza;
		}
		if(dec < minWartosc || minWartosc == -1){
			minWartosc = dec;
			pozMinWartosc = nrWiersza;
		}
	}
	
	cout << "4.1: " << endl;
	cout << podp1 << endl;
	cout << "4.2: " << endl;
	cout << "Podzielnych przez 2: " << podp2PodPrzez2 << endl;
	cout << "Podzielnych przez 8: " << podp2PodPrzez8 << endl;
	cout << "4.3: " << endl;
	cout << "Pozycja najmniejszej: " << pozMinWartosc << " (" << minWartosc << ")" << endl;
	cout << "Pozycja najwiekszej: " << pozMaxWartosc << " (" << maxWartosc << ")" << endl;
	
	wynik << "4.1: " << endl;
	wynik << podp1 << endl;
	wynik << "4.2: " << endl;
	wynik << "Podzielnych przez 2: " << podp2PodPrzez2 << endl;
	wynik << "Podzielnych przez 8: " << podp2PodPrzez8 << endl;
	wynik << "4.3: " << endl;
	wynik << "Pozycja najmniejszej: " << pozMinWartosc << " (" << minWartosc << ")" << endl;
	wynik << "Pozycja najwiekszej: " << pozMaxWartosc << " (" << maxWartosc << ")" << endl;
}
