#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

string skrot(string wiadomosc, string kod, bool wyswietlSzczegoly){
	int brakujacychZnakow = wiadomosc.length()%8; //do wielokrotnosci liczby 8
	for(int a=0; a<8-brakujacychZnakow; a++){
		wiadomosc += '.';
	}
	
	if(wyswietlSzczegoly){
		cout << "Dlugosc wiadomosci: "<< wiadomosc.length() << endl;
	}
	
	int lettersCount = 0;
	while(lettersCount < wiadomosc.length()){
		int pozycja = lettersCount % 8;
		kod[pozycja] = ((int)kod[pozycja] + (int)wiadomosc[lettersCount]) % 128;
		lettersCount++;
	}
	
	if(wyswietlSzczegoly){
		cout << "S: ";
		for(int a=0; a<kod.length(); a++){
			cout << (int)kod[a] << " ";
		}
		cout << endl;
	}
	
	string wynik;
	for(int a=0; a<8; a++){
		wynik = wynik + char(65 + kod[a] % 26);
	}
	
	return wynik;
}

string odszyfruj(int skrot[8], int d, int n){
	string wynik;
	for(int a=0; a<8; a++){
		int x = (skrot[a] * d % n);
		wynik += (char)x;
	}
	
	return wynik;
}

int main(){
	string wiadomosci[11];
	int podpisy[11][8];
	
	/*
	 * WCZYTYWANIE DANCH
	 */
	
	ifstream dane_wiadomosci("wiadomosci.txt");	
	ifstream dane_podpisy("podpisy.txt");
	
	string line;
	int count = 0;
	while(getline(dane_wiadomosci, line)){
		wiadomosci[count] = line;
		count++;		
	}
	count = 0;
	int column = 0;
	int podpis;
	while(dane_podpisy >> podpis){
		if(count >= 8){
			count = 0;
			column++;
		}
		podpisy[column][count] = podpis;
		count++;		
	}
	
	//cout << "Skrot: " << skrot("test1", "ALGORYTM");
	
	cout << "78.1."<<endl;
	cout << skrot(wiadomosci[0], "ALGORYTM", true) << endl;
	
	cout << "78.2." << endl;
	for(int a=0; a<11; a++){
		cout << a+1 << ": " << odszyfruj(podpisy[a], 3, 200) << endl;
	}
	
	cout << "78.3. Wiadomosci wiarygodne:" <<endl;
	for(int a=0; a<11; a++){
		if(skrot(wiadomosci[a], "ALGORYTM", false) == odszyfruj(podpisy[a], 3, 200)){
			cout << a+1 << " ";
		}
	}
	
	return 0;
}
