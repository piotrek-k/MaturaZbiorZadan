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
	//sortowanie rosn¹co
	int A[8] = {12, 4, 3, 2, 1, 10, 5, 11};
	int n = 8; //d³ugoœæ ci¹gu
	
	for(int j=n-2; j>=0; j--){ //sprawdzanie liczb od przedostatniej liczby do pierwszej
		displayArray(A, j, -1, -1);
		int x = A[j]; //wartoœæ aktualnie sprawdzanej liczby
		
		int i = j + 1; //pobranie indexu nastêpnej liczby
		while(i <= n-1 && x > A[i]){ //sprawdzanie czy nastêpna liczba jest mniejsza (sortowanie rosn¹co, wiêc nie mo¿e byæ mniejsza)
			A[i-1] = A[i]; //jeœli jest mniejsza, zamiana miejscami z poprzedzaj¹c¹ j¹ liczb¹
			displayArray(A, -1, -1, i-1);
			i = i+1; //przesuniêcie indeksu w prawo
		}
		A[i-1] = x; //i-1 to miejsce w ktorym nastepna liczba jest wieksza niz x
		displayArray(A, -1, i-1, -1);
	}
	displayArray(A, -1, -1, -1);
}
