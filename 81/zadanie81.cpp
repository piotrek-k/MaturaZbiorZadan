#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

class Punkt {
	public:
		double x;
		double y;
};

int main(){
	ifstream dane("wspolrzedne.txt");
	
	int liczba;
	Punkt punkty[100][3];
	
	int col = 0; //klumna z pliku
	int row = 0; //wiersz z pliku
	int type = 0; //x czy y
	while(dane >> liczba){
		if(type == 0){
			punkty[row][col].x = liczba;
			type = 1;
		}
		else {
			punkty[row][col].y = liczba;
			type = 0;
			col ++;
		}
		
		if(col == 3){
			col = 0;
			row ++;
		}
	}
	
	//cout << punkty[1][2].x;
	
	int podpunkt1 = 0;
	for(int a=0; a<100; a++){
		bool pierwszaCwiartka = true;
		for(int b=0; b<3; b++){
			if(punkty[a][b].x <= 0 || punkty[a][b].y <= 0 ){
				pierwszaCwiartka = false;
			}
		}
		if(pierwszaCwiartka){
			podpunkt1++;
		}
	}
	cout << "81.1." << endl;
	cout << podpunkt1 << endl;
	
	int podpunkt2 = 0;
	for(int a=0; a<100; a++){
		if((punkty[a][1].y - punkty[a][0].y)*(punkty[a][2].x - punkty[a][1].x) == (punkty[a][2].y - punkty[a][1].y)*(punkty[a][1].x - punkty[a][0].x)){ 
			podpunkt2++;
		}
	}
	cout << "81.2." << endl;
	cout << podpunkt2 << endl;
}
