//znaleŸæ jakiœ porz¹dny algorytm na scalanie dwóch tablic

#include <iostream>
#include <fstream>
#include <vector>

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

vector<StationData> LoadData(const char* fileName){
	ifstream dane(fileName);
	vector<StationData> sd;
	string a, b;
	while(dane >> a >> b){
		sd.push_back(StationData(textToInt(a, 2), textToInt(b, 2)));
	}
	
	return sd;
}

ReturnedData checkStation(vector<StationData> station){
	int min = station[0].temperature;
    int startTime = 0;
    int previousRecord = station[0].temperature;
    vector<int> incorrectMeasurements;
    vector<int> recordDays;
    for(int a=0; a<station.size(); a++){
    	if(a==0){
    		startTime = station[a].time;
		} else {
			if((station[a].time-startTime)%24!=0){
				incorrectMeasurements.push_back(a);
			}
		}
    	if(min>station[a].temperature){
    		min=station[a].temperature;
		}
		if(previousRecord < station[a].temperature){
			recordDays.push_back(a);
		}
	}
	cout << "Stacja min temp.: " << min << endl;
	/*for(int x=0; x<incorrectMeasurements.size(); x++){
		cout << incorrectMeasurements[x] << endl;
	}*/
	
	return ReturnedData(incorrectMeasurements, recordDays);
}

/*vector<int> SumAndRemoveDuplicates(vector<int> v1, vector<int> v2){
	vector<int> sum;
	int bigger = 0;
	if(v1[v1.size()] > v2[v2.size()]){
		bigger= v1[v1.size()-1];
	}
	else {
		bigger= v2[v2.size()-1];
	}
	int v1Index = 0;
	int v2Index = 0;
	int a = 0;
	while(a<bigger){
		while(a<v1[v1Index] && a<v2[v2Index]){
			a++;
		}
		sum.push_back(a);
		while(a>=v1[v1Index]) {
			if(v1Index+1 > v1.size()-1){
				while(v2Index<v2.size()-1){
					sum.push_back(v2[v2Index]);
					v2Index++;
				}
				break;
			}
			v1Index++;
		}
		while(a>=v2[v2Index]) {
			if(v2Index+1 > v2.size()-1){
				break;
			}
			v2Index++;
		}
	}
	return sum;
} */

int main(){
	int arr[] = {11,14};
	std::vector<int> TestVector(arr, arr+2);
	int arr2[] = {11,14, 22, 33, 55};
	std::vector<int> TestVector2(arr2, arr2+4);
	vector<int> sum111 = SumAndRemoveDuplicates(TestVector, TestVector2);
	for(int x=0; x<sum111.size(); x++){
		cout << sum111[x] << endl;
	}
	
    vector<StationData> station1 = LoadData("dane_systemy1.txt");
    vector<StationData> station2 = LoadData("dane_systemy2.txt");
    vector<StationData> station3 = LoadData("dane_systemy3.txt");
    
    ReturnedData rd1 = checkStation(station1);
    ReturnedData rd2 = checkStation(station2);
    ReturnedData rd3 = checkStation(station3);
    
    vector<int> incMeas1 = rd1.incorrectMeasurements;
    vector<int> incMeas2 = rd2.incorrectMeasurements;
    vector<int> incMeas3 = rd3.incorrectMeasurements;
    
    vector<int> compared12;
    for(int a=0; a<incMeas1.size(); a++){
	    for(int b=0; b<incMeas2.size(); b++){
	    	if(incMeas1[a] == incMeas2[b]){
	    		compared12.push_back(incMeas1[a]);
			}
		}	
	}
	
	vector<int> comparedAll;
    for(int a=0; a<compared12.size(); a++){
	    for(int b=0; b<incMeas3.size(); b++){
	    	if(compared12[a] == incMeas3[b]){
	    		comparedAll.push_back(compared12[a]);
			}
		}	
	}
	
	/*for(int q=0; q<100; q++){
		cout<<incMeas1[q]<<" ";
		cout<<incMeas2[q]<<" ";
		cout<<incMeas3[q]<<" ";
		cout<<comparedAll[q]<<endl;
	}*/
	cout << "Liczba niepoprawnych: " << comparedAll.size();
    
    ofstream wyniki("wyniki.txt");
    //wyniki<<
}
