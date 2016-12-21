//wyniki niepoprawne dla podpunktu 58.1 (s3) oraz 58.2 (mimo poprawnego algorytmu) 

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>  

using namespace std;
//106

class StationData {
	public:
		int time;
		int temperature;
		StationData(int t, int temp){
			time = t;
			temperature = temp;
		}
};

class ReturnedData {
	public:
		vector<int> incorrectMeasurements;
		vector<int> recordDays;
		ReturnedData(vector<int> iM, vector<int> rD){
			incorrectMeasurements = iM;
			recordDays = rD;
		}
};

int textToInt(string text, int systemType){ //zamiana binarneg tekstu na dziesiêtne liczby (systemType: dwójkowy - 2, dziesiêtny - 10, itp.)
	int wynik=0, i=0, znak=1; //i - znak ci¹gu, na który jest konwertowany na liczbê
	if(text[0]=='-'){
		znak=-1;
		i=1;
	}
	int d=text.length();
	for(;i<d;i++){
		wynik=wynik*systemType+(text[i]-'0'); //magiczna zamiana string na int?
	}
	return znak*wynik;
}

string numberToOtherSystem(int num, int systemType){
	string s="";
	char z;
	int znak=1;
	if(num<0){
		znak=-1; 
		num=-num;
	}
	if(!num) return "0";
	while(num>0){
		z='0'+num%systemType;
		s=z+s;
		num=num/systemType;
	}
	if(znak<0) s="-"+s;
	return s;
}

vector<StationData> LoadData(const char* fileName, int dataType){
	ifstream dane(fileName);
	vector<StationData> sd;
	string a, b;
	while(dane >> a >> b){
		sd.push_back(StationData(textToInt(a, dataType), textToInt(b, dataType)));
	}
	
	return sd;
}

ReturnedData checkStation(vector<StationData> station){
	int min = station[0].temperature;
    int startTime = 0;
    int previousRecord = station[0].temperature-1; //-1 ¿eby algorytm zaliczy³ te¿ pierwszy wynik jako rekordowy
    vector<int> incorrectMeasurements;
    vector<int> recordDays;
    for(int a=0; a<station.size(); a++){
		if((station[a].time-12)%24!=0){
			incorrectMeasurements.push_back(a);
		}
    	if(min>station[a].temperature){
    		min=station[a].temperature;
		}
		if(previousRecord < station[a].temperature){
			recordDays.push_back(a);
			previousRecord = station[a].temperature;
		}
	}
	cout << "Stacja min temp.: " << numberToOtherSystem(min, 2) << "(dziesietny:" << min << ")"<< endl;
	
	return ReturnedData(incorrectMeasurements, recordDays);
}

vector<int> SumAndRemoveDuplicates(vector<int> v1, vector<int> v2){
	for(int x=0; x<v2.size(); x++){
		v1.push_back(v2[x]);
	}
	
	for(int a=0; a<v1.size(); a++){
		for(int b=1; b<v1.size()-a; b++){
			if(v1[b-1] > v1[b]){
				int container = v1[b-1];
				v1[b-1] = v1[b];
				v1[b] = container;
			}
		}
	}
	
	for(int c=1; c<v1.size(); c++){
		if(v1[c-1] == v1[c]){
			v1.erase(v1.begin()+c);
			c--;
		}
	}
	
	return v1;
}

int main(){
    vector<StationData> station1 = LoadData("dane_systemy1.txt", 2);
    vector<StationData> station2 = LoadData("dane_systemy2.txt", 4);
    vector<StationData> station3 = LoadData("dane_systemy3.txt", 10);
    
    ReturnedData rd1 = checkStation(station1);
    ReturnedData rd2 = checkStation(station2);
    ReturnedData rd3 = checkStation(station3);
    
    int count = 0;
    int state = 12;
    for(int a=0; a<station1.size(); a++){
    	if(station1[a].time != state && station2[a].time != state && station3[a].time != state){
    		count++;
		}
		state+=24;
	}
	cout << "Liczba niepoprawnych: " << count <<endl;
	
	vector<int> firstTwoRecDays = SumAndRemoveDuplicates(rd1.recordDays, rd2.recordDays);
	vector<int> allRecordDays = SumAndRemoveDuplicates(firstTwoRecDays, rd3.recordDays);
	
	cout << "Liczba dni rekordowych: " << allRecordDays.size() <<endl;
	
	int maxTempJump = 0;
	for(int s=0; s<station1.size()-1; s++){
		for(int d=s+1; d<station1.size()-1; d++){
			int ti = station1[s].temperature;
			int tj = station1[d].temperature;
			int tempJump = (ti-tj)*(ti-tj) / abs(s-d);
			if(tempJump > maxTempJump){
				maxTempJump = tempJump;
			}
		}
	}
	
	cout << "Masymalny skok temperatury: " << maxTempJump <<endl;
    
    ofstream wyniki("wyniki.txt");
}
