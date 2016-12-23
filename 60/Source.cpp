//odpowiedzi na stronie 451
//wszystkie poprawne

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int nwd(int x, int y)
{
    if (x < y)
        return nwd(y,x);
    if (y == 0)
        return x;
    return nwd(y,x%y);
}
int main(){
	ifstream dane("liczby.txt");
	
	int liczbMniejszychNiz1000 = 0;
	int ktoraZKolei = 0;
	int ostatniaLiczbaMniejszaNiz1000 = 0;
	int przedostatniaLiczbaMniejszaNiz1000 = 0;
	int wszystkieLiczby[200];
	
	int liczba;
	while(dane >> liczba){
		//PODPUNKT 1:
		if(liczba < 1000){
			liczbMniejszychNiz1000++;
			przedostatniaLiczbaMniejszaNiz1000 = ostatniaLiczbaMniejszaNiz1000;
			ostatniaLiczbaMniejszaNiz1000 = liczba;
		}
		
		//PODPUNKT 2:
		//szukam dzielnikow:
		int x=liczba;
		vector<int> dzielniki;
		int dzielnik = 1;
		while(dzielnik <= liczba){
			if(liczba%dzielnik == 0){
				dzielniki.push_back(dzielnik);
			}
			dzielnik++;
		}
		
		if(dzielniki.size() == 18){
			cout << liczba;
			for(int a=0; a<dzielniki.size(); a++){
				cout << " " << dzielniki[a];
			}
			cout << endl;
		}
		
		wszystkieLiczby[ktoraZKolei] = liczba;
		ktoraZKolei++;
	}
	
	cout << "Liczb mniejszych ni¿ 1000: " << liczbMniejszychNiz1000 << endl;
	cout << "2 ostatnie iczby mniejsze ni¿ 1000: " << przedostatniaLiczbaMniejszaNiz1000 << ", " << ostatniaLiczbaMniejszaNiz1000 << endl;
	
	//PODPUNKT 3:
	
	int najwieksza = 0;
	for(int q=0; q<200; q++){
		bool wzgledniePierwsza = true;
		for(int w=0; w< 200; w++){
			if(q!=w && nwd(wszystkieLiczby[q], wszystkieLiczby[w]) > 1){
				wzgledniePierwsza = false;
				break;
			}
		}
		if(wzgledniePierwsza && najwieksza<wszystkieLiczby[q]){
			najwieksza = wszystkieLiczby[q];
		}
	}
	
	cout << "Najwieksza wzglednie pierwsza: " << najwieksza;
}
