#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int ciagFib(int x){
	if(x <= 2){
		return 1;
	}
	return ciagFib(x-1) + ciagFib(x-2);
}

bool liczbaPierwsza(int x){
	if(x<2) return false;
	for(int a=2; a<x; a++){
		if(x%a==0){
			return false;
		}
	}
	return true;
}

string decToOtherSystem(int x, int sys){
	string output;
	char z;
	if(!x) return "0";
	while(x>0){
		z = x%sys + '0';
		output = z + output;
		x /= sys;
	}
	return output;
}

int main(){
	vector<vector<string> > podpunkt4;
	
	//podpuntkt 1
	cout << "67.1. " << endl;
	cout << ciagFib(10) << endl;
	cout << ciagFib(20) << endl;
	cout << ciagFib(30) << endl;
	cout << ciagFib(40) << endl;
	
	//podpunkt 2
	cout << "67.2. " << endl;
	for(int a=1; a<=40; a++){
		int l = ciagFib(a);
		if(liczbaPierwsza(l)){
			cout << l << endl;
		}
	}
	
	//podpunkt 3
	cout << "67.3. " << endl;
	ofstream fraktal("binarny_fraktal_fibonacciego.txt");
	int dlugosc40 = decToOtherSystem(ciagFib(40), 2).length();
	for(int a=1; a<=40; a++){
		int l = ciagFib(a);
		int iloscJedynek = 0;
		string inBin = decToOtherSystem(l, 2);
		for(int a=0; a<dlugosc40-inBin.length(); a++){
			cout << "0";
			fraktal << "0 ";
		}
		cout << inBin << endl;
		for(int q=0; q<inBin.length(); q++){
			fraktal << inBin[q] << " ";
			if(inBin[q] == '1'){
				iloscJedynek++;
			}
		}
		fraktal << endl;
		
		if(iloscJedynek == 6){
			vector<string> tmp;
			tmp.push_back(inBin);
			podpunkt4.push_back(tmp);
		}
	}
	
	//podpunkt4
	cout<<"67.4." << endl;
	for(int w=0; w<podpunkt4.size(); w++){
		cout<<podpunkt4[w][0]<<endl;
	}
	
}
