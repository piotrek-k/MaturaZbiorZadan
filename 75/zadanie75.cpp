#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

char encryptLetter(char l, int keyA, int keyB){
	int letterNumber = l - 'a';
	letterNumber *= keyA;
	letterNumber += keyB;
	if(letterNumber > 25){
		letterNumber = letterNumber % 26;
	}
	char newLetter = letterNumber + 'a';
	return newLetter;
}

string encrypt(string text, int keyA, int keyB){
	string result = string();
	for(int a=0; a<text.length(); a++){
		result += encryptLetter(text[a], keyA, keyB);
	}
	
	return result;
}


int main(){
	cout << "test: " << 'c' - 'a' << endl;
	
	ifstream dane("tekst.txt");
	string slowo;
	vector<string> podpunkt1;
	vector<string> podpunkt2;
	while(dane >> slowo){
		//podpunkt1
		if(slowo[0] == 'd' && slowo[slowo.length()-1] == 'd'){
			podpunkt1.push_back(slowo);
		}
		
		//podpunkt2
		if(slowo.length() >= 10){
			podpunkt2.push_back(slowo);
		}
	}
	
	cout << "75.1: " << endl;
	for(int a=0; a<podpunkt1.size(); a++){
		cout << podpunkt1[a] << endl;
	}
	
	cout << "75.2: " << endl;
	for(int a=0; a<podpunkt2.size(); a++){
		cout << encrypt(podpunkt2[a], 5, 2) << endl;
	}
	
	cout << "75.3: " << endl;
	ifstream dane2("probka.txt");
	string probka;
	int count = 0;
	string decrypted;
	string encrypted;
	vector<vector<int> > kluczeSzyfrujace;
	vector<vector<int> > kluczeDeszyfrujace;
	int countKey1 = 1;
	int countKey2 = 1;
	while(dane2 >> probka){
		if(count == 0){
			decrypted = probka;
		}
		else if(count == 1){
			encrypted = probka;
			bool encFound = false;
			bool decFound = false;
			for(int a=0; a<=25; a++){
				for(int b=0; b<=25; b++){
					if(encrypted == encrypt(decrypted, a, b) && !encFound){
						cout << "Klucz szyfrujacy " << countKey1 << ": (" << a << ", " << b << ")" << endl;
						countKey1++;
						encFound = true;
					}
					if(decrypted == encrypt(encrypted, a, b) && !decFound){
						cout << "Klucz deszyfrujacy " << countKey2 << ": (" << a << ", " << b << ")" << endl;
						countKey2++;
						decFound = true;
					}
				}
				if(encFound && decFound){
					break;
				}
			}
		}
		
		count++;
		if(count == 2){
			count = 0;
		}
	}
}
