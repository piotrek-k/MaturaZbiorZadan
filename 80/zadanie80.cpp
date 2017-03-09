#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include<string>

using namespace std;

int main(){
	ifstream dane("dane_trojkaty.txt");
	int liczba = 0;
	int liczby[500] = {};
	int count = 0;
	while(dane >> liczba){
		liczby[count] = liczba;
		count++;
	}
	
	//podpunkt 1
	cout << "80.1." <<endl;
	for(int a=0; a<500-2; a++){
		if(pow(liczby[a], 2) + pow(liczby[a+1], 2) == pow(liczby[a+2], 2) ||
			pow(liczby[a+2], 2) + pow(liczby[a+1], 2) == pow(liczby[a], 2) ||
			pow(liczby[a], 2) + pow(liczby[a+2], 2) == pow(liczby[a+1], 2)){
				
			cout << liczby[a] << " " << liczby[a+1] << " " << liczby[a+2] << endl;
		}
	}
	
	//sortowanie rosnaco
	for(int q=0; q<500-1; q++){
		for(int w=0; w<500-q-1; w++){
			if(liczby[w] > liczby[w+1]){
				int temp = liczby[w];
				liczby[w] = liczby[w+1];
				liczby[w+1] = temp;
			}
		}
	}
	
	//podpunkt 2
	//liczby posortowane sa rosnaco, wiec najwiekszy obwod powstanie z liczb znajdujacych sie na koncu tablicy
	cout << "80.2." << endl;
	int i = 500-3;
	bool kontynuuj = true;
	while(kontynuuj && i>0){
		if(liczby[i]+liczby[i+1] > liczby[i+2]){
			kontynuuj = false; //znaleziono najwiekszy obwod, przerwij szukanie
			break;
		}
		i--;
	}
	int obwMAX = liczby[i]+liczby[i+1]+liczby[i+2];
	cout << "Max obwod: " << obwMAX << endl;
	
	//podpunkt 3
	cout << "80.3." << endl;
	int nieprzystajacych = 0;
	for(int a=0; a<500-2; a++){
		for(int b=a+1; b<500-1; b++){
			for(int c=b+1; c<500; c++){
				if(liczby[a]+liczby[b] > liczby[c] && liczby[a]+liczby[c] > liczby[b] && liczby[c]+liczby[b] > liczby[a]){
					nieprzystajacych++;
				}
				
			}
		}
	}
	cout << "Nieprzystajacych: " << nieprzystajacych << endl;
}
