#include <iostream>
using namespace std;

void displayArray(int tab[], int active, int active2, int active3){
	cout << "----------" << endl;
	cout << "Tab"<< 8 << ": ";
	for(int a=0; a<8; a++){
		if(a == active && active != -1){
			cout << "(" << tab[a] << ")>> ";
		}
		else if(a == active2 && active2 != -1){
			cout << "[" << tab[a] << "]    ";
		}
		else if(a == active3 && active3 != -1){
			cout << "[" << tab[a] << "] <=";
		}
		else {
			cout << " " << tab[a] << "    ";
		}
		
	}
	cout << endl;
}

int main(){
	//sortowanie rosn�co
	int A[8] = {12, 4, 3, 2, 1, 10, 5, 11};
	int n = 8; //d�ugo�� ci�gu
	
	for(int j=n-2; j>=0; j--){ //sprawdzanie liczb od przedostatniej liczby do pierwszej
		displayArray(A, j, -1, -1);
		int x = A[j]; //warto�� aktualnie sprawdzanej liczby
		
		int i = j + 1; //pobranie indexu nast�pnej liczby
		while(i <= n-1 && x > A[i]){ //sprawdzanie czy nast�pna liczba jest mniejsza (sortowanie rosn�co, wi�c nie mo�e by� mniejsza)
			A[i-1] = A[i]; //je�li jest mniejsza, zamiana miejscami z poprzedzaj�c� j� liczb�
			displayArray(A, -1, -1, i-1);
			i = i+1; //przesuni�cie indeksu w prawo
		}
		A[i-1] = x; //i-1 to miejsce w ktorym nastepna liczba jest wieksza niz x
		displayArray(A, -1, i-1, -1);
	}
	displayArray(A, -1, -1, -1);
}
