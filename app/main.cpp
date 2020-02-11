//#include "stdafx.h"
#include "loty.h"

/*
Glowna funkcja programu. Program zaczyna dzialanie od niej pierwszej.
main(...) odczytuje parametry wprowadzone przez uzytkownika.
W zaleznosci od ich wprowadzenia wywoluje dalsza prace programu, lub ja zakancza.

parametry funkcji:
__________________
argc - liczba calkowita, ilosc wprowadzonych argumentow z linii polecen przez uzytkownika
*argv[] - tablica przechowujaca znaki, zawiera sciezke wywolania i podane parametry

wartosc zwracana:
_________________
return 0 - funkcja zakancze program poprzez liczbe calkowita

@autor Pawel Salicki
@data 2018-01-18
*/

int main(int argc, char *argv[])
{
	const std::string FILE = "-i"; //string przechowywyjacy znak -i, zalozeniem jest ze po tym parametrze uzytkownik wpisze nazwe programu
	const std::string HELP = "-h"; //string przechowywyjacy znak -h, parametr odpowiadajacy za wyswietlenie pomocniczego komunikatu
	std::string NAME = ""; //wstepnie zadeklarowana pusta wartoscia nazwe pliku wprowadzanego przez uzytkownika

	if (argc > 1) //warunek if sprawdzajacy liczbe wpisanych parametrow, sprawdza czy zostalo cos wpisane wiecej oprocz nazwy programu
	{
		for (int i = 1; i < argc; i++) //petla przechodzaca po parametrach wprowadzonych przez uzytkownika, zaczyna od 1, bo pierwszy parametr to nazwa programu
		{
			if (argv[i] == HELP) //jezeli wprowadzony parametr to -h, wywola funkcje pomoc()
			{
				pomoc();
			}
			else if (argv[i] == FILE) //jezeli wprowadzony parametr to -i
			{
				if (argc < 3) //jezeli liczba wprowadzonych parametrow jest mniejsza od trzech (zabezpieczenie przed uzytkownikiem, ktory nie wpisal nic po parametrze -i)
				{
					std::cout << "Nie wprowadziles nazwy pliku!" << std::endl;
					return 0;
				}
				else //w przeciwnym wypadku zostaje odczytana nazwa po parametrze -i, zosaje wczytana do zmiennej NAME, a nastepnie zostaje wywolana funkcja czytaj_plik
				{
					NAME = argv[++i];
					czytaj_plik(NAME);  // OK!
				}
			}
			else if (argv[i] != HELP || argv[i] != FILE) //warunek sprawdzajacy czy po nazwie prrogramu uzytkownik wpisal cos innego niz -h oraz -i
			{
				std::cout << "Podales zly parametr. Wpisz -h by wyswietlic pomoc!" << std::endl;
				return 0;
			}
			else //przypadek gdy uzytkownik wprowadzil cos, co nie zostalo przewidziane
				return 0;
		}
	}
	return 0; //zakonczenie programu zwracaniem calkowitej wartosci
}