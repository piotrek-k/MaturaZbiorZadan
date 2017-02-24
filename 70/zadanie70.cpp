#include<iostream>
#include<math.h>
using namespace std;

double f(double x){
	return (x*x*x*x/(double)500)-(x*x/(double)200)-(3/(double)250);
}

double g(double x){
	return -(x*x*x/(double)30)+(x/(double)20)+(1/(double)6);
} 

int main(){
	//podpunkt 1
	double dokladnosc = 10000000;
	double szerokosc = 10 - 2;
	double wysokosc = (19*125+61)/(double)125 + (32*3+2)/(double)3;
	double jednostkaX = szerokosc/(double)dokladnosc;
	double jednostkaY = wysokosc/(double)dokladnosc;
	double startX = 2;
	double startY = (19*125+61)/(double)125;
	double polePozostMaterialu = 0.0;
	
	for(int a=0; a<dokladnosc; a++){
		double X = startX + a*jednostkaX;
		double nextX = startX + (a+1)*jednostkaX;
		double H1 = f(X);
		double H2 = -g(X);
		polePozostMaterialu += jednostkaX*H1;
		polePozostMaterialu += jednostkaX*H2;
	}
	
	cout << "polePozostMaterialu: " << polePozostMaterialu << endl;
	
	//podpunkt 2
	double dlugoscTasmy = szerokosc*2 + wysokosc;
	for(int a=0; a<dokladnosc; a++){
		double X = startX + a*jednostkaX;
		double nextX = startX + (a+1)*jednostkaX;
		double Y = f(X);
		double nextY = f(nextX);
		double Y2 = g(X);
		double nextY2 = g(nextX);
		
		dlugoscTasmy += sqrt((nextX-X)*(nextX-X) + (nextY-Y)*(nextY-Y));
		dlugoscTasmy += sqrt((nextX-X)*(nextX-X) + (nextY2-Y2)*(nextY2-Y2));
	}
	
	cout << "dlugoscTasmy: " << ceil(dlugoscTasmy) << endl;
	
	//podpunkt 3
	double iloscPasow = ceil(szerokosc/0.25);
	double sumaDlugosci = 0;
	for(int a=0; a<iloscPasow; a++){
		double X = startX + szerokosc - a*0.25;
		double X2 = startX + szerokosc - (a+1)*0.25;
		double topY = f(X2);
		double bottomY = g(X2);
		double dlugoscPasa = floor(topY - bottomY);
		sumaDlugosci += dlugoscPasa;
	}
	
	cout << "sumaDlugosci: " << sumaDlugosci << endl;
}
