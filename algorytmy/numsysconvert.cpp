#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string decimalToOther(int num, int to){
	string result;
	while(num > 0){
		char stringToAdd = num % to + '0';
		result = stringToAdd + result;
		num = num / (int)to;
	}
	return result;
}

int otherToDecimal(string o, int from){
	int result = 0;
	for(int a=0; a<o.length(); a++){
		int p = o.length()-1-a; //potega do ktorej trzeba podniesc 'from'
		int num = o[a]-'0'; //liczba przez ktora trzeba pomnozyc
		result += pow(from, p)*num;
	}	
	return result;
}

int main(){
	cout << "Convert 516 to 2: " << decimalToOther(516, 2) << endl;
	cout << "Convert 516 to 8: " << decimalToOther(516, 8) << endl;
	cout << "Convert 516 to 6: " << decimalToOther(516, 6) << endl;
	
	cout << "Convert 1: " << otherToDecimal(decimalToOther(516, 2), 2) << endl;
	cout << "Convert 2: " << otherToDecimal(decimalToOther(516, 8), 8) << endl;
	cout << "Convert 3: " << otherToDecimal(decimalToOther(516, 6), 6) << endl;
}
