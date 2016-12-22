//nieznacznie inne wyniki w podpunkcie 3
//odpowiedzi na stronie 450

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int odwrocLiczbe(int x){
	int odwrocona = 0;
	while(x>0){
		odwrocona *= 10;
		odwrocona += x%10;
		x/=10;
	}
	return odwrocona;
}

int iloczynCyfr(int x){
	int iloczyn = 1;
	while(x>0){
		iloczyn*=x%10;
		x/=10;
	}
	return iloczyn;
}

int main(){
	ifstream dane("liczby.txt");
	int a; //pobrana z pliku liczba
	int liczTrzyRozneNieparzyste = 0; //licznik liczb o trzech ró¿nych nieparzystych dzielnikach
	int iloscPalindromow = 0; //licznik liczb ktorych suma z ich odwrotnoscia jest palindromem
	int liczLiczbyzMoca[8]; //licznik liczb o mocy od 1 do 8
	//ustawianie domyœlnych wartoœci tablicy
	for(int t=0; t<8; t++){
		liczLiczbyzMoca[t] = 0;
	}
	
	int minimalnaOMocy1 = -1; //-1 oznacza ¿e zmienna jest niezdefiniowana
	int maksymalnaOMocy1 = 0;
	
	while(dane >> a){
		//PODPUNKT 1:
		int dzielnik = 2;
		int ostDzielnik = 0;
		int iloscRoznychDzielnikow = 0;
		bool jestParzysty = false;
		int b = a;
		while(b > 1){
			while(b%dzielnik==0){
				if(ostDzielnik != dzielnik){
					iloscRoznychDzielnikow ++;
					if(dzielnik % 2 == 0){
						jestParzysty = true;
					}
				}
				ostDzielnik = dzielnik;
				b/=dzielnik;
				cout << dzielnik << " ";
			}
			
			dzielnik++;
		}
		cout << a <<  ": Roznych dzielnikow: " << iloscRoznychDzielnikow << " Parzysty: " << jestParzysty;
		if(iloscRoznychDzielnikow == 3 && jestParzysty == false){
			liczTrzyRozneNieparzyste++;
		}
		
		
		//PODPUNKT 2:
		int a2 = odwrocLiczbe(a);
		cout << " odwroc: " << a2;
		int suma = a + a2;
		cout << " suma: " << suma;
		if(suma == odwrocLiczbe(suma)){
			cout << "palinrom";
			iloscPalindromow++;
		}
		
		//PODPUNKT 3:
		int moc = 0;
		int sprawdzanaLiczba = a;
		
		while(sprawdzanaLiczba > 10){
			moc++;
			sprawdzanaLiczba = iloczynCyfr(sprawdzanaLiczba);
		}
		if(moc <= 8 && moc >= 1){
			//liczbOMocy1do8++;
			liczLiczbyzMoca[moc-1]++;
		}
		if(moc == 1 && minimalnaOMocy1 == -1){
			minimalnaOMocy1 = a;
		}
		if(moc==1 && minimalnaOMocy1 > a){
			minimalnaOMocy1 = a;
		}
		if(moc == 1 && maksymalnaOMocy1 < a){
			maksymalnaOMocy1 = a;
		}
		cout << " moc: " << moc << endl;
	}
	
	//ODPOWIEDZI:
	cout << "Ilosc 3 roznych nieparzystych: " << liczTrzyRozneNieparzyste << endl;
	cout << "Ilosc palindromow: " << iloscPalindromow << endl;
	//cout << "liczbOMocy1do8: " << liczbOMocy1do8 << endl;
	for(int t=0; t<8; t++){
		cout<< "Moc " << t+1 << ": " << liczLiczbyzMoca[t] << endl;
	}
	cout << "minimalnaOMocy1: " << minimalnaOMocy1 << endl;
	cout << "maksymalnaOMocy1: " << maksymalnaOMocy1 << endl;
}
