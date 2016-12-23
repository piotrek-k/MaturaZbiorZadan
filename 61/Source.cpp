#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool jestTrzeciaPotega(int liczba){
	int x = 1;
	while(x*x*x < liczba){
		x++;
	}
	if(x*x*x == liczba){
		return true;
	}
	else {
		return false;
	}
}

int main(){
	ofstream wynik1;
   	wynik1.open("wynik1.txt");
   	ofstream wynik2;
   	wynik2.open("wynik2.txt");
	
	ifstream dane("ciagi.txt");
	int iloscWyrazowCiagu = 0;
	int ileCiagowArym = 0;
	int najwiekszaRoznica = 0;
	
	while(dane >> iloscWyrazowCiagu){
		
		vector<int> wyrazyCiagu;
		bool ciagArtym = true;
		int roznica = -1;
		int poprzedniaRoznica = -1;
		int najwiekszaBedacaSzescianem = 0;
		int poprzedniWyraz = -1;
		
		for(int a=0; a<iloscWyrazowCiagu; a++){
			
			int nowyWyraz = 0;
			dane >> nowyWyraz;
			wyrazyCiagu.push_back(nowyWyraz);
			
			poprzedniaRoznica = roznica;
			if(poprzedniWyraz != -1){
				roznica = nowyWyraz - poprzedniWyraz;
			}
			if(roznica!=-1 && poprzedniaRoznica!=-1 && poprzedniaRoznica!=roznica){
				ciagArtym = false;
			}
			
			if(jestTrzeciaPotega(nowyWyraz) && nowyWyraz > najwiekszaBedacaSzescianem){
				najwiekszaBedacaSzescianem = nowyWyraz;
			}
			
			poprzedniWyraz = nowyWyraz;
		}
		
		//PODPUNKT 1:
		if(ciagArtym){
			ileCiagowArym++;	
			if(najwiekszaRoznica < roznica){
				najwiekszaRoznica = roznica;
			}
		}
		
		
		//PODPUNKT 2:
		if(najwiekszaBedacaSzescianem != 0){
			wynik2 << "Najwieksza liczba bedaca szescianem: " << najwiekszaBedacaSzescianem << endl;
		}
	}
	
	wynik1 << "Liczba ciagow arytmetycznych: " << ileCiagowArym << endl;
	wynik1 << "Najwieksza roznica w ciagu arytmetycznym: " << najwiekszaRoznica << endl;
	
	wynik1.close();
	wynik2.close();
	
	//PODPUNKT 3:
	ifstream bledne("bledne.txt");
	ofstream wynik3("wynik3.txt");
	while(bledne >> iloscWyrazowCiagu){
		int roznica = -1;
		int poprzedniWyraz = -1;
		vector<int> roznice;
		vector<int> wyrazy;
		int blednyWyraz = 0;
		
		for(int a=0; a<iloscWyrazowCiagu; a++){
			int nowyWyraz = 0;
			bledne >> nowyWyraz;
			wyrazy.push_back(nowyWyraz);
			//wynik3 << nowyWyraz << " ";
			
			if(poprzedniWyraz != -1){
				roznica = nowyWyraz - poprzedniWyraz;
				roznice.push_back(roznica);
			}
			poprzedniWyraz = nowyWyraz;
		}
		wynik3 << endl;
		
		if(roznice[0] != roznice[1] && roznice[1] == roznice[2]){
			blednyWyraz = wyrazy[0];
		}
		else if(roznice[0] != roznice[2] && roznice[1] != roznice[2] && roznice[2] == roznice[3]){
			blednyWyraz = wyrazy[1];
		}
		else {
			for(int i=0; i+1 <= roznice.size(); i++){
				if(roznice[i] != roznice[0]){
					blednyWyraz = wyrazy[i+1];
					break;
				}
			}
		}
		
		wynik3 << "Bledny wyraz: " << blednyWyraz << endl;
	}
	wynik3.close();
}
