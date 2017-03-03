#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Haslo {
	public:
		string content;
		int count;
};

vector<Haslo> sortPasswords(vector<Haslo> vec){
	for(int a=0; a<vec.size()-1; a++){
		for(int b=0; b<vec.size()-1-a; b++){
			if((int)vec[b].content[0] > (int)vec[b+1].content[0]){
				iter_swap(vec.begin() + b, vec.begin() + b+1);
			}
		}
	}
	
	return vec;
}

string sortString(string s){
	for(int a=0; a<s.length()-1; a++){
		for(int b=0; b<s.length()-1-a; b++){
			if((int)s[b] > s[b+1]){
				char temp = s[b];
				s[b] = s[b+1];
				s[b+1] = temp;
			}
		}
	}
	return s;
}

int main(){
	//cout << "sort: " << sortString("czterdziesci") << endl;
	
	ifstream dane("hasla.txt");
	string haslo;
	int haslaZSamychCyfr = 0;
	vector<Haslo> wszystkieHasla;
	int haslaZ4KolejnymiZnakami = 0;
	int mocnychHasel = 0;
	while(dane >> haslo){
		//podpunkt 1
		bool wszystkieSaLiczbami = true;
		for(int a=0; a<haslo.size(); a++){
			if((int)haslo[a] < (int)'0' || (int)haslo[a] > (int)'9'){
				wszystkieSaLiczbami = false;
				break;
			}
		}
		if(wszystkieSaLiczbami){
			haslaZSamychCyfr++;
		}
		
		//podpunkt 2
		bool znaleziono = false;
		for(int a=0; a<wszystkieHasla.size(); a++){
			if(wszystkieHasla[a].content == haslo){
				wszystkieHasla[a].count++;
				znaleziono = true;
			}
		}
		if(!znaleziono){
			Haslo h;
			h.content = haslo;
			h.count = 1;
			wszystkieHasla.push_back(h);
		}
		
		//podpunkt 3
		for(int a=0; a<haslo.size()-3; a++){
			string fourLetterString = string() + haslo[a]+ haslo[a+1] + haslo[a+2] + haslo[a+3];
			//cout << "fls: " << fourLetterString;
			string sortedFLS = sortString(fourLetterString);
			bool found4 = false;
			int liczbaKolejnychZnakow = 1;
			for(int b=0; b<sortedFLS.length(); b++){
				if((int)sortedFLS[b]+1 == (int)sortedFLS[b+1]){
					liczbaKolejnychZnakow++;
					if(liczbaKolejnychZnakow == 4){
						haslaZ4KolejnymiZnakami++;
						found4 = true;
						break;
					}
				}
				else {
					liczbaKolejnychZnakow = 1;
				}
			}
			if(found4){
				break;
			}
		}
		
		//podpunkt 4
		bool znakNumeryczyny = false;
		bool malaLitera = false;
		bool duzaLitera = false;
		for(int a=0; a<haslo.size(); a++){
			if((int)haslo[a] >= (int)'0' && (int)haslo[a] <= (int)'9'){
				znakNumeryczyny = true;
			}
			if((int)haslo[a] >= (int)'a' && (int)haslo[a] <= (int)'z'){
				malaLitera = true;
			}
			if((int)haslo[a] >= (int)'A' && (int)haslo[a] <= (int)'Z'){
				duzaLitera = true;
			}
		}
		if(znakNumeryczyny && malaLitera && duzaLitera){
			mocnychHasel++;
		}
	}
	
	cout << "74.1: " << endl;
	cout << "Ilosc hasel zlozonych z samych cyfr: " << haslaZSamychCyfr << endl;
	cout << "74.2: " << endl;
	vector<Haslo> sorted = sortPasswords(wszystkieHasla);
	for(int a=0; a<sorted.size(); a++){
		if(sorted[a].count > 1){
			cout << sorted[a].content << endl;
		}
	}
	
	cout << "74.3: " << endl;
	cout << "haslaZ4KolejnymiZnakami: " << haslaZ4KolejnymiZnakami << endl;
	
	cout << "74.4: " << endl;
	cout << "Ilosc mocnych hasel: " << mocnychHasel << endl;
}
