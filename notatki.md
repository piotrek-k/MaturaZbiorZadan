# C++
## Wypisywanie liczby do 2 miejsc po przecinku
```
printf("%.2f", x);
```

## Konwersja char/int
```
char a = '4';
int ia = a - '0';
```
Analogicznie int to char:
```
char c = i +'0';
```

## Tworzenie tablicy
```
int wyniki[5] = {}; //nawiasy klamrowe nadają wartości domyślne. Ich brak powoduje pojawienie się nieprawidłowych wartości na start
```

## Sortowanie bąbelkowe
Na przykładzie funkcji sortującej ciąg znaków
```
string sortString(string s){
	for(int a=0; a<s.length()-1; a++){
		for(int b=0; b<s.length()-1-a; b++){ //pętla jest krótsza o "a", ponieważ wiadomo, że po każdym wywołaniu pierwszej pętli na koncu ciagu bedzie wartoc najwieksza
			if((int)s[b] > s[b+1]){
				char temp = s[b];
				s[b] = s[b+1];
				s[b+1] = temp;
			}
		}
	}
	return s;
}
```

## Kod ASCII znaku
```
cout << (int)'A' << endl; //65
cout << 'C'-'A' << endl; //zwroci index litery 'C' w alfabecie (2)
```

## Wskaźniki //td
`*` służy do uzyskiwania wartości z adresu

`&` służy do uzyskiwania adresu zmiennej
```
int x = 9; //decleration 
int *p = &x; //decleration 

cout << x; // 9 
cout << *p; // 9 

cout << &x; // address of x 
cout << p; // address of x 
cout << &p; // address of p
```

## Największy wspólny dzielnik
```
int nwd(int x, int y)
{
    if (x < y)
        return nwd(y,x);
    if (y == 0)
        return x;
    return nwd(y,x%y);
}
```
Najmniejsza wspólna wielokrotność:
```
NWW(a,b) = (a*b)/nwd(a, b)
```

## Zaokrąglanie liczb
```
#include <cmath>
round(3.49); //3 - zaokrąglanie naturalne
floor(3.50); //3 - w dół
ceil(3.49); //4 - w górę
```

## Pobieranie danych z pliku
```
#include <fstream>
[...]
ifstream dane("liczby.txt");
int liczba;
while(dane >> liczba)
{
    [...]
}
```

## Zapisywanie danych do pliku
```
ofstream out("wyniki.txt",fstream::app);
out << "Tekst" << endl;
```

## Konwersja do liczby dziesiętnej z postaci innego typu //td
```
int toDecimal(string num, int from){
	int output = 0;
	for(int x=0; x < num.length(); x++){
		output = output * from + (num[x]-'0');
	}
	return output;
}
```

## Konwersja z dziesiętnej do innego typu //td
```
string decToOtherSystem(int num, int to){
	string output;
	char z;
	if(!num) return "0";
	while(num>0){
		z = '0' + num%to;
		output = z + output;
		num = num/to;
	}
	
	return output;
}
```

## Obliczanie sumy cyfr liczby x
```
int sumaCyfr(int x){
	int suma = 0;
	while(x > 0){
		suma += x%10;
		x /= 10;
	}
	return suma;
}
```

## Konwersja tablicy do wektora
```
int tab[a] = {}; //a - liczba elementow
vector<int> newVec(tab, tab + a);
```

## Zamiana miejscami obiektow w vectorze
```
vector<string> vec;
iter_swap(vec.begin() + b, vec.begin() + b+1); //zamiana miejscami
```


# Excel
## Znajdowanie pierwszej wartości spełniającej warunek:
```
=PODAJ.POZYCJĘ(PRAWDA,E:E,0) //MATCH
=PODAJ.POZYCJĘ(PRAWDA,D3:D110<3,0)
```
`Ctrl`+`Shift`+`Enter` (curly braces) jeśli pojawia się `#N/D!`

## Zwracanie wartości komórki o jakimś indeksie:
```
=INDEKS(B:B, 3) //B:B - zakres, 3 - indeks
```

## Wiele warunków w jednym "if'ie":
```
ORAZ()
LUB()
```

## Wyszukiwanie wartości z jednej kolumny, zwrócenie wartości z innej kolumny
```
=WYSZUKAJ.PIONOWO(500,B:F, 3, FAŁSZ)
```
Znajdzie liczbę `500` w kolumnie `B`, zwróci liczbę z kolumny `D` (ponieważ jest trzecia z kolei). `FAŁSZ` oznacza że dopasowanie ma być dokładne.

## Znajdowanie wartości która da w innej komórce konkretną wartość
`Dane` -> `Analiza warunkowa`

## Zliczanie wystąpień wartości w kolumnie
```
=LICZ.JEŻELI(A:A, "Test")
```
## Łączenie dwóch ciągów znaków
```
=ZŁĄCZ.TEKSTY(B2, C2)
```
## Pobieranie długości ciągu znaków
```
=DŁ("Test")
```
## Pobieranie fragmentu tekstu
```
=FRAGMENT.TEKSTU("Test",1,1) //zwróci 'T'
```
## Konwersja tekstu na liczbę
```
=WARTOŚĆ(A2)
```
