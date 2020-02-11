/** @file */


//#include "stdafx.h"
#include "loty.h"

/*
Funkcja odczytujaca plik.

parametry funkcji:
__________________
nazwa - przyjmuje nazwe wprowadzona przez uzytkownika

wartosc zwracana:
_________________
brak

@autor Pawel Salicki
@data 2018-01-18
*/

void czytaj_plik(std::string nazwa)
{
	Rezerwacje *glowa = new Rezerwacje(); //utworzenie glowy pustej listy dwukierunkowej Rezerwacje
	glowa = NULL; //zadeklarowanie glowy listy wartoscia NULL
	
	
	
	std::ifstream plik(nazwa, std::ios_base::in); //zadeklarowanie zmiennej odczytujacej plik o nazwie wprwowadzonej przez uzytkownika do zapisu
	std::string linia; //string pomocniczy do przechowywania znakow z odczytanego pliku
	
	if (plik.is_open()) //warunek sprawdzajacy czy otwarcie pliku zostalo zakonczone sukcesem
	{
		while (!plik.eof()) //petla wykonujaca sie dopoki wskaznik w pkiku nie znajdzie sie na koncu
		{
			getline(plik, linia); //odczytywanie z pliku
			glowa = zwroc_obiekt(linia, glowa); //wywolanie funkcji przyjmujacej wczytana linie i glowe listy, przypisanie odczytanych wartosci do glowy listy
		}
		plik.close(); //zamkniecie pliku i zwolnienie bufora
	}
	else //warunek jezeli plik nie zostanie otwarty
	{
		std::cout << "Wprowadz poprawna nazwe pliku, by uruchomic program!" << std::endl; //wyswietlenie komunikatu o bledzie
		plik.close();
	}
	zapisz_i_usun_wycieki(glowa); //wywolanie funkcji do zapisu do pliku i kasowania wyciekow pamieci, przyjmuje glowe listy Rezerwacje
}
