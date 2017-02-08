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

# Excel
## Znajdowanie pierwszej wartości spełniającej warunek:
```
=PODAJ.POZYCJĘ(PRAWDA,E:E,0) //MATCH
```

## Zwracanie wartości komórki o jakimś indeksie:
```
=INDEKS(B:B, 3) //B:B - zakres, 3 - indeks
```

## Wiele warunków w jednym "if'ie":
```
ORAZ()
LUB()
```
