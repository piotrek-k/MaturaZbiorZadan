/*
* Coœ nie tak z podpunktem 5. Iloœæ czworok¹tów siê zgadza, ale ich wierzcho³ki ju¿ nie. Program z zestawu rozwi¹zañ podaje taki sam wynik jak mój, mo¿liwe ¿e odpowiedzi s¹ skopane.
*/

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
	ifstream dane("wspolrzedneTR.txt");
	
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
	
	int rowOfPointsWithMaxPerimeter = 0;
	double maxObw = 0;
	for(int a=0; a<100; a++){
		double obw = 0;
		for(int b=0; b<3; b++){
			int q = b;
			int w = (b+1 == 3) ? 0 : b+1;
			
			double dlugoscBoku = sqrt(pow((punkty[a][q].x - punkty[a][w].x), 2) + pow((punkty[a][q].y - punkty[a][w].y), 2));
			obw += dlugoscBoku;
		}
		if(obw > maxObw){
			maxObw = obw;
			rowOfPointsWithMaxPerimeter = a;
		}
	}
	cout << "81.3." << endl;
	cout << "Wsplorzedne wierzcholkow trojkata o najwiekszym obwodzie: " << punkty[rowOfPointsWithMaxPerimeter][0].x << ", " << punkty[rowOfPointsWithMaxPerimeter][0].y << ", " << punkty[rowOfPointsWithMaxPerimeter][1].x << ", " << punkty[rowOfPointsWithMaxPerimeter][1].y << ", " << punkty[rowOfPointsWithMaxPerimeter][2].x << ", " << punkty[rowOfPointsWithMaxPerimeter][2].y << endl;
	cout << "Max Obwod: " << maxObw << endl;
	
	int liczbaProstokatnych = 0;
	for(int a=0; a<100; a++){
		bool jestProstokatny = false;
		for(int b=0; b<3; b++){
			int q = b;
			int w = (b+1 >= 3) ? b+1-3 : b+1;
			int e = (b+2 >= 3) ? b+2-3 : b+2;
			
			double dlugoscBoku1 = pow((punkty[a][q].x - punkty[a][w].x), 2) + pow((punkty[a][q].y - punkty[a][w].y), 2);
			double dlugoscBoku2 = pow((punkty[a][w].x - punkty[a][e].x), 2) + pow((punkty[a][w].y - punkty[a][e].y), 2);
			double dlugoscBoku3 = pow((punkty[a][e].x - punkty[a][q].x), 2) + pow((punkty[a][e].y - punkty[a][q].y), 2);
			
			if(dlugoscBoku1 + dlugoscBoku2 == dlugoscBoku3){
				jestProstokatny = true;
			}
		}
		if(jestProstokatny) {
			liczbaProstokatnych++;
		}
	}
	
	cout << "81.4." << endl;
	cout << "Liczba trojkatow prostokatnych: " << liczbaProstokatnych << endl;
	
	cout << "81.5." << endl;
	for(int a=0; a<100; a++){
		//xb-xa, yb-ya; xc-xd, yc-yd
		//xd = xc-xb+xa
		//yd = yc-yb+ya
		int xd = punkty[a][2].x - punkty[a][1].x + punkty[a][0].x;
		int yd = punkty[a][2].y - punkty[a][1].y + punkty[a][0].y;
		
		if(xd == yd){
			cout << punkty[a][0].x << ", " << punkty[a][0].y << "; " << punkty[a][1].x << ", " << punkty[a][1].y << "; " << punkty[a][2].x << ", " << punkty[a][2].y << "; " << xd << ", " << yd << endl;
		}
	}
}
