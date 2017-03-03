#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;

int main(){
	ifstream dane("tekst.txt");
	string slowo;
	int podpunkt1 = 0;
	int numOfLetters = 26;
	int podpunkt2[numOfLetters] = {};
	int maxDlugoscPodslowa = 0;
	int iloscNajdluzszychPodslow = 0;
	string pierwszeSlowo;
	
	while(dane >> slowo){
		
		//podpunkt 1
		char prevLetter = slowo[0];
		bool dwieTeSameLitery = false;
		for(int a=1; a<slowo.length(); a++){
			if(slowo[a] == prevLetter){
				dwieTeSameLitery = true;
				break;
			}
			
			prevLetter = slowo[a];	
		}
		
		if(dwieTeSameLitery){
			podpunkt1++;
		}
		
		//podpunkt 2
		for(int a=0; a<slowo.length(); a++){
			if(a < 0 || a > numOfLetters-1){
				cout << "blad" << endl;
			}
			podpunkt2[slowo[a] - 'A']++;
		}
		
		//podpunkt 3
		int chainLength = 0;
		for(int a=0; a<slowo.length(); a++){
			if(slowo[a] != 'A' && slowo[a] != 'E' && slowo[a] != 'I' && slowo[a] != 'O' && slowo[a] != 'U' && slowo[a] != 'Y'){
				chainLength++;
			}
			else{
				if(chainLength > maxDlugoscPodslowa){
					maxDlugoscPodslowa = chainLength;
					iloscNajdluzszychPodslow = 1;
					pierwszeSlowo = slowo;
				}
				else if(chainLength == maxDlugoscPodslowa){
					iloscNajdluzszychPodslow++;
				}
				chainLength = 0;
			}
		}
	}
	
	cout << "73.1: " << podpunkt1 << endl;
	cout << "73.2: " << endl;
	int allLettersSum = 0;
	for(int a=0; a<numOfLetters; a++){
		allLettersSum += podpunkt2[a];
	}
	for(int a=0; a<numOfLetters; a++){
		char x = 'A' + a;
		cout << x << ": " << podpunkt2[a] << " (" << round((podpunkt2[a]/(double)allLettersSum)*100*100)/100<< "%)" <<  endl;
	}
	cout << "73.3: " << endl << "maxDlugoscPodslowa: " << maxDlugoscPodslowa << endl << "iloscNajdluzszychPodslow: " << iloscNajdluzszychPodslow << endl << "pierwszeSlowo: " << pierwszeSlowo;
}
