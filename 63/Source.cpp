#include <iostream>
#include <fstream>

using namespace std;


int toDecimal(string number, int type){
	int output = 0;
	for(int x=0; x<number.length(); x++){
		output = output * type + (number[x] - '0');
	}
	return output;
}

int main(){
	string wiersz;
	ifstream dane("ciagi.txt");
	int countNoNeighbours = 0;
	int countHalfPrime = 0;
	
	int max = 0;
	int min = -1;
	
	while(dane >> wiersz){
		bool eqSeq = true; //czy ci¹g jest identyczny?
		
		if(wiersz.length()%2==0){
			int half = wiersz.length()/2;
			for(int x=0; x<half; x++){
				if(wiersz[x] != wiersz[half+x]){
					eqSeq = false;
				}
			}
		}
		else {
			eqSeq = false;
		}
		
		//PODPUNKT 1:
		if(eqSeq){
			cout << "Ciag dwucykliczny: " << wiersz << endl;
		}
		
		//PODPUNKT 2:
		bool oneAsNeighbours = false; //czy wystêpuj¹ dwie s¹siadujace jedynki?
		
		for(int x=0; x<wiersz.length(); x++){
			if(x<wiersz.length()-1){
				if(wiersz[x] == '1' && wiersz[x+1] == '1'){
					oneAsNeighbours = true;
					break;
				}
			}
		}
		if(!oneAsNeighbours){
			countNoNeighbours++;
		}
		
		
		//PODPUNKT 3:
		//cout << endl << "Wiersz: " << wiersz << " ";
		int asDec = toDecimal(wiersz, 2);
		int primaryAsDec = asDec;
		cout << endl << "Liczba: " << primaryAsDec;
		int numberOfFactors = 0;
		int factor = 2;
		//int check = 1;
		
		if(min == -1){
			min = primaryAsDec;
		}
		
		while(asDec>1 && factor <= asDec){
			if(asDec % factor == 0){
				bool isPrime = true;
				for(int q=2; q<factor; q++){
					if(factor % q == 0){
						isPrime = false;
						break;
					}
				}
				if(isPrime){
					numberOfFactors++;
					cout << factor << ", ";
					asDec /= factor;
					//check *= factor;
					factor = 1; //(zmieni sie na 2 pod koniec petli while)
				}
			}
			factor++;
		}
		
		if(numberOfFactors == 2){
			//cout << "----------------------------" << endl;
			countHalfPrime++;
			if(max < primaryAsDec){
				max = primaryAsDec;
			}
			if(min > primaryAsDec){
				min = primaryAsDec;
			}
		}
		
	}
	
	//PODPUNKT 2:
	cout << "Ciagi bez sasiadujacych jedynek: " << countNoNeighbours << endl;
	
	//PODPUNKT 3:
	cout << "Ilosc polpierwszych: " << countHalfPrime << " min: " << min << " max: " << max;
}
