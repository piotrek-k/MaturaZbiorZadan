//w trakcie podpunktu 3

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ifstream dane("dane_obrazki.txt");
	string linijka;
	//string obrazki[200][20][20] = {{{0}}};
	
	int liczLinijki = 0;
	int liczObrazki = 0;
	
	int pixeliCzarnych = 0;
	int pixeliBialych = 0;
	int maxCzarnych = 0;
	int liczRewersy = 0;
	
	bool sprawdzRekurencje = true;
	int rekurencja[10][10] = {{ 0 }};
	int liczRekurencyjne = 0;
	
	bool poprawneBityParzystosci = true;
	int jedynekWLinijce = 0;
	int liczPoprawne = 0;
	
	//int obrazek[20][20] = { { 0 } };
	while(dane >> linijka){
		for(int a=0; a<linijka.length(); a++){
			//obrazki[liczObrazki][liczLinijki][a] = linijka[a];
			int aktWartosc = linijka[a] - '0';
			
			if(linijka[a] == '0'){
				pixeliBialych++;
			}
			else {
				pixeliCzarnych++;	
				jedynekWLinijce++;
			}
			
			if(a == 20 && aktWartosc != jedynekWLinijce%2){
				poprawneBityParzystosci = false;
			}
			
			if(sprawdzRekurencje){
				if(liczLinijki < 10){
					if(a < 10){
						rekurencja[liczLinijki][a] = aktWartosc;
					}
					else if(a >= 10 && a<20 && rekurencja[liczLinijki][a-10] != aktWartosc) {
						sprawdzRekurencje = false;
					}
				}
				else if (liczLinijki < 20) {
					if(a < 10 && rekurencja[liczLinijki-10][a] != aktWartosc){
						sprawdzRekurencje = false;
					}
					else if(a >= 10 && a<20 && rekurencja[liczLinijki-10][a-10] != aktWartosc){
						sprawdzRekurencje = false;
					}
				}
			}
		}
		jedynekWLinijce = 0;
		liczLinijki++;
		if(liczLinijki == 20){
			//obrazki[liczObrazki] = obrazek;
			//obrazek = new int[20][20];
			if(sprawdzRekurencje == true){
				liczRekurencyjne++;
				if(liczRekurencyjne == 1){
					for(int n=0; n<20; n++){
						int newN = (n >= 10) ? n-10 : n;
						for(int m=0; m<20; m++){
							if(m>=10){
								cout << rekurencja[newN][m-10];
							}
							else {
								cout << rekurencja[newN][m];
							}
						}
						cout << endl;
					}
				}
				for(int z=0; z<10; z++){
					for(int x=0; x<10; x++){
						rekurencja[x][z] = 0;
					}
				}
			}
			if(poprawneBityParzystosci){
				liczPoprawne++;
			}
			poprawneBityParzystosci= true;
			sprawdzRekurencje = true; //wartosc domyslna do nastepnego obrazka
			if(pixeliCzarnych > pixeliBialych){
				liczRewersy++;
			}
			if(maxCzarnych < pixeliCzarnych){
				maxCzarnych = pixeliCzarnych;
			}
			liczLinijki = 0;
			liczObrazki++;
			pixeliCzarnych = 0;
			pixeliBialych = 0;
		}
	}
	
	//PODPUNKT 1:
	cout << "Rewersow: " << liczRewersy << endl;
	cout << "Najwiecej czarnych: " << maxCzarnych << endl;
	
	//PODPUNKT 2:
	cout << "Rekurencyjne: " << liczRekurencyjne << endl;
	
	//PODPUNKT 3:
	cout << "Poprawne: " << liczPoprawne << endl;
	
	dane.close();
	//return 0;
}
