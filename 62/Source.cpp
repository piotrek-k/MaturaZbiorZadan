//wszystkie odpowiedzi poprawne oprócz podpunktu 4, aczkolwiek prawdopodobnie jest to pomy³ka w odpowiedziach gdy¿ w pliku liczby2 szóstek jest 411

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int toDecimal(string num, int from){
	int output = 0;
	for(int x=0; x < num.length(); x++){
		output = output * from + (num[x]-'0');
	}
	return output;
}

string decToOtherSystem(int num, int to){
	string output;
	char z;
	if(!num) return "0";
	while(num>0){
		z = '0' + num%to;
		output = z + output;
		num = num/to;
	}
	
	return output;
}

int main(){
	ifstream liczby1("liczby1.txt");
	ifstream liczby2("liczby2.txt");
	
	//cout << "10010 to dec" << decToOtherSystem(10010, 10) << endl;
	//cout << "10010 to bin" << decToOtherSystem(10010, 2) << endl;
	//cout << "12 to bin" << decToOtherSystem(12, 2) << endl;
	
	string numFromFile;
	string num2FromFile;
	int min = -1;
	int max = 0;
	vector<vector<int> > wszystkieCiagi;
	vector<int> ciagLiczb;
	
	vector<int> wszystkieLiczby1;
	
	while(liczby1 >> numFromFile){
		int numberAsDec = toDecimal(numFromFile, 8);
		wszystkieLiczby1.push_back(numberAsDec);
		if(min == -1) {
			min = numberAsDec;
		}
		
		if(min > numberAsDec){
			min = numberAsDec;
		}
		if(max < numberAsDec){
			max = numberAsDec;
		}
		
		
	}
	
	int q = 0;
	int taSamaWartosc = 0;
	int l1jestWieksze = 0;
	int countSix = 0;
	int countSixInOct = 0;
	while(liczby2 >> num2FromFile){
		int numAsInt = toDecimal(num2FromFile, 10);
		string numAsOctal = decToOtherSystem(numAsInt, 8);
		//string numAsOctalAsString = numAsOctal + "";
		
		if(numAsInt == wszystkieLiczby1[q]){
			taSamaWartosc++;
		}
		else if(numAsInt < wszystkieLiczby1[q]){
			l1jestWieksze++;
		}
		
		for(int w=0; w<num2FromFile.length(); w++){
			if(num2FromFile[w] == '6'){
				countSix++;
			}
		}
		
		for(int e=0; e<numAsOctal.length(); e++){
			if(numAsOctal[e] == '6'){
				countSixInOct++;
			}
		}
		
		if(ciagLiczb.size() == 0){
			ciagLiczb.push_back(numAsInt);
		}
		else if(ciagLiczb[ciagLiczb.size()-1] <= numAsInt){
			ciagLiczb.push_back(numAsInt);
		}
		else {
			wszystkieCiagi.push_back(ciagLiczb);
			ciagLiczb.clear();
			ciagLiczb.push_back(numAsInt);
		}
		
		q++;
	}
	
	//PODPUNKT 1:
	cout << "Liczby 1, najmniejsza: " << decToOtherSystem(min, 8) << endl;
	cout << "Liczby 1, najwieksza: " << decToOtherSystem(max, 8) << endl;
	
	//PODPUNKT 2:
	cout << "Nadluzszy niemalejacy ciag: " << endl;
	int maxLength = 0;
	int maxIndex = 0;
	for(int a=0; a<wszystkieCiagi.size(); a++){
		if(wszystkieCiagi[a].size() > maxLength){
			maxIndex = a;
			maxLength = wszystkieCiagi[a].size();
		}
	}
	for(int b=0; b<wszystkieCiagi[maxIndex].size(); b++){
		cout << wszystkieCiagi[maxIndex][b] << ", ";
	}
	cout << endl;
	
	//PODPUNKT 3:
	cout << "W obu plikach ta sama wartosc: " << taSamaWartosc << endl;
	cout << "W obu plikach liczba 1 wieksza: " << l1jestWieksze << endl;
	
	//PODPOUNKT 4:
	cout << "Ilosc 6 w liczach2 (dec): " << countSix << endl;
	cout << "Ilosc 6 w liczach2 (oct): " << countSixInOct << endl;
	
	return 0;
}
