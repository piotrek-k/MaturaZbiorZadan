#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

bool startsWith(string bigger, string smaller){
	bool isDifferent = false;
	for(int a=0; a<smaller.length(); a++){
		if(smaller[a] != bigger[a]){
			isDifferent = true;
			break;
		}
	}
	return !isDifferent;
}

int main(){
	ifstream dane("napisy.txt");
	
	string napis;
	int col = 0;
	string napisy[2];
	int podpunkt1 = 0;
	string podpunkt1_a;
	vector< vector<string> > podpunkt2;
	
	while(dane >> napis){
		napisy[col] = napis;
		
		if(col == 1){
			//podpunkt 1
			if(napisy[0].length()/napisy[1].length() >= 3 || napisy[1].length()/napisy[0].length() >= 3){
				podpunkt1++;
				if(podpunkt1 == 1){
					podpunkt1_a = napisy[0] + " " + napisy[1];
				}
			}
			
			//podpunkt 2
			if(startsWith(napisy[1], napisy[0])){
				//cout << napisy[0] << " " << napisy[1] << endl;
				vector <string> newV;
				newV.push_back(napisy[0]);
				newV.push_back(napisy[1]);
				podpunkt2.push_back(newV);
			}
			
			/*
			W podpunkcie trzecim trzeba w ka¿dej parze porównaæ ci¹gi znaków  zaczynaj¹c od koñca, zliczyæ jak d³ugie s¹ to ci¹gi.
			Nastêpnie je¿eli osi¹gniêto liczbê maksymaln¹ d³ugoœci ci¹gu, dopisaæ napisy do tablicy/wektora. Je¿eli przekorczono wartoœæ max
			wyzerowaæ tablicê, dodaæ napis do nowej, pustej.
			*/
		}
		
		
		
		col++;
		if(col == 2){
			col = 0;
		}
	}
	
	//podpunkt1
	cout << "72.1. " << endl << podpunkt1 << " (" << podpunkt1_a << ")" << endl;
	
	cout << "72.2. " << endl;
	for(int a=0; a<podpunkt2.size(); a++){
		cout << podpunkt2[a][0] << " " << podpunkt2[a][1] << endl;
	}
}
