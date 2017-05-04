#include <iostream>
using namespace std;

int NWD(int x, int y){
	if(x < y){
		return NWD(y, x);
	}
	if(y == 0){
		return x;
	}
	return NWD(y, x%y);
}

int NWD2(int x, int y){
	if(x < y){
		return NWD2(y, x);
	}
	if(x == y){
		return x;
	}
	return NWD2(y, x-y);
}

int NWW(int x, int y){
	return x*y/NWD(x, y);
}

int main(){
	cout << "NWD:" << NWD(24, 12) << endl;
	cout << "NWD:" << NWD(40, 36) << endl;
	cout << "NWD:" << NWD(1989, 867) << endl;
	
	cout << "NWD2:" << NWD2(24, 12) << endl;
	cout << "NWD2:" << NWD2(40, 36) << endl;
	cout << "NWD2:" << NWD2(1989, 867) << endl;
	
	cout << "NWW:" << NWW(24, 12) << endl;
	cout << "NWW:" << NWW(40, 36) << endl;
	cout << "NWW:" << NWW(1989, 867) << endl;
}
