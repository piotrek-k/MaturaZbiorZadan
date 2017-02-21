#include <iostream>
#include<fstream>
using namespace std;

int nwd(int a, int b){
	if(a < b){
		return nwd(b, a);
	}
	if(b==0){
		return a;
	}
	return nwd(b, a%b);
}

class Ulamek {
	public:
	int licznik;
	int mianownik;
	double wartosc(){
		return licznik/(double)mianownik;
	};
	int getNWD(){
		return nwd(licznik, mianownik);
	};
};

int main(){
	ifstream dane("dane_ulamki.txt");
	ofstream wyniki("wyniki_ulamki.txt");
	int liczba = 0;
	int inlineCount = 0;
	
	int licznik = 0;
	int mianownik = 0;
	
	Ulamek minUlamek;
	
	int liczNieskracalne = 0;
	int sumaLicznikow = 0;
	long long sumaNowychLicznikow = 0;
	
	while(dane >> liczba){
		//cout << liczba << endl;
		
		if(inlineCount == 0){
			licznik = liczba;
		} else if(inlineCount == 1){
			mianownik = liczba;
			
			Ulamek ulamek;
			ulamek.licznik = licznik;
			ulamek.mianownik = mianownik;
		
			//podpunkt 1
			if(ulamek.wartosc() < minUlamek.wartosc()){
				minUlamek = ulamek;
			} else if(ulamek.wartosc() == minUlamek.wartosc() && ulamek.mianownik < minUlamek.mianownik){
				minUlamek = ulamek;
			}
			
			//podpunkt 2
			if(ulamek.getNWD() == 1){
				liczNieskracalne++;
			}
			
			//podpunkt 3
			Ulamek skrocony = ulamek;
			int nwd_skracanie = skrocony.getNWD();
			while(nwd_skracanie > 1){
				skrocony.licznik = skrocony.licznik / nwd_skracanie;
				skrocony.mianownik = skrocony.mianownik / nwd_skracanie;
				nwd_skracanie = skrocony.getNWD();
			}
			sumaLicznikow += skrocony.licznik;
			
			//podpunkt 4:
			long long nowyLicznik = (long long)ulamek.licznik*(2*2*3*3*5*5*7*7*13)/(long long)ulamek.mianownik;
			sumaNowychLicznikow += nowyLicznik;
		}
		
		inlineCount++;
		if(inlineCount >= 2){
			inlineCount = 0;
		}
	}
	
	cout << "65.1. MinUlamek: " << minUlamek.licznik << " " << minUlamek.mianownik << endl;
	cout << "65.2. LiczNieskracalne " << liczNieskracalne << endl;
	cout << "65.3. Suma licznikow: " << sumaLicznikow << endl;
	cout << "65.4. Licznik nowego ulamka: " << sumaNowychLicznikow << endl;
	
	wyniki << "65.1. MinUlamek: " << minUlamek.licznik << " " << minUlamek.mianownik << endl;
	wyniki << "65.2. LiczNieskracalne " << liczNieskracalne << endl;
	wyniki << "65.3. Suma licznikow: " << sumaLicznikow << endl;
	wyniki << "65.4. Licznik nowego ulamka: " << sumaNowychLicznikow << endl;
	
	/*cout << nwd(24, 10) << endl;
	cout << nwd(44, 4) << endl;
	cout << nwd(3, 7) << endl;*/
}
