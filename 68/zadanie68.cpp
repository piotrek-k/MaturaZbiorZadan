#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

bool jest_jednolity(string napis){
	for(int a=1; a<napis.length(); a++){
		if(napis[a-1] != napis[a]){
			return false;
		}
	}
	
	return true;
}

bool sa_anagramami(string n, string m){
	if(n.length() != m.length()){
		return false;
	}
	for(int a=0; a<n.length(); a++){
		bool znalezionoLitere = false;
		for(int b=0; b<m.length(); b++){
			if(n[a] == m[b]){
				znalezionoLitere = true;
				m[b] = '0';
				break;
			}
		}
		if(!znalezionoLitere){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream dane("dane_napisy.txt");
	
	string napis;
	int kolumna=0;
	string napisy[2];
	int podpunkt1 = 0;
	int podpunkt2 = 0;
	vector<string> podpunkt3_value;
	vector<int> podpunkt3_count;
	
	while(dane >> napis){
		napisy[kolumna] = napis;
		
		if(kolumna==1){
			//podpunkt 1
			if(napisy[0].length() == napisy[1].length() && jest_jednolity(napisy[0]) && jest_jednolity(napisy[1])){
				//cout << napisy[0] << " " << napisy[1] << endl;
				podpunkt1++;
			}
			
			if(sa_anagramami(napisy[0], napisy[1])){
				cout << napisy[0] << " " << napisy[1] << endl;
				podpunkt2++;
			}
		}
		
		bool znalezionoAnagram = false;
		for(int a=0; a<podpunkt3_value.size(); a++){
			if(sa_anagramami(podpunkt3_value[a], napis)){
				znalezionoAnagram = true;
				podpunkt3_count[a]++;
				break;
			}
		}
		if(!znalezionoAnagram){
			podpunkt3_value.push_back(napis);
			podpunkt3_count.push_back(1);
		}
		
		kolumna++;
		if(kolumna==2){
			kolumna=0;
		}
	}
	
	cout << "68.1. " << endl;
	cout << podpunkt1 << endl;
	cout << "68.2. " << endl;
	cout << podpunkt2 << endl;
	cout << "68.3. " << endl;
	int MAX = 0;
	for(int a=0; a<podpunkt3_count.size(); a++){
		if(podpunkt3_count[a] > MAX){
			MAX = podpunkt3_count[a];
		}
	}
	cout << MAX << endl;
}
