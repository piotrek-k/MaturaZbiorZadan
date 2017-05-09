#include <iostream>
using namespace std;

void sortujMalejaco(int *tab, int n){
	for(int a=0; a<n; a++){
		for(int b=1; b<n-a; b++){
			if(tab[b] > tab[b-1]){
				int oldTabB = tab[b];
				tab[b] = tab[b-1];
				tab[b-1] = oldTabB;
			}
		}
	}
}

void sortujRosnaco(int *tab, int n){
	for(int a=0; a<n; a++){
		for(int b=1; b<n-a; b++){
			if(tab[b] < tab[b-1]){
				int oldTabB = tab[b];
				tab[b] = tab[b-1];
				tab[b-1] = oldTabB;
			}
		}
	}
}

int main(){
	int tab[] = {4, 8, 1, 2, 0, 6, 4};
	
	sortujMalejaco(tab, 7);
	
	for(int a=0; a<7; a++){
		cout << tab[a] << " ";
	}
	
	cout << endl;
	
	sortujRosnaco(tab, 7);
	
	for(int a=0; a<7; a++){
		cout << tab[a] << " ";
	}
}
