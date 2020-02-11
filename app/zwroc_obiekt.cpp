/** @file */
//#include "stdafx.h"
#include "loty.h"

/*
Funkcja o typie Rezerwacje, ktorej zadaniem jest rozpoznanie danej wartosci w pliku i odpowiednie jej przypisanie do listy Rezerwacje.

parametry funkcji:
__________________
ciag_znakow - ciag znakow odczytanych z linii wczytanego pliku
glowa_rezerwacje - glowa listy rezerwacji

wartosc zwracana:
_________________
glowa_rezerwacje - zwraca informacje zawarte w liscie Rezerwacje do funkcji czytaj_plik

@autor Pawel Salicki
@data 2018-01-18
*/

Rezerwacje* zwroc_obiekt(std::string ciag_znakow, Rezerwacje *glowa_rezerwacje)
{
	Rezerwacje *tymczas = new Rezerwacje(); //zadeklarowanie tymczasowego pomocniczego wskaznika (utworzenie pustej listy Rezerwacje)
	std::string tmp; //zadeklarowanie zmiennej pomocniczej string
	Pasazer *tym_pasazer = new Pasazer(); //zadeklarowanie tymczasowego pomocniczego wskaznika (utworzenie pustej listy Pasazer)
	int ktory_element = 0; //zmienna typu int zliczajaca ilosc elementow w pliku

	tymczas->ident_lotu = "Brak danych"; //przypisanie poczatkowych wartosci danymi
	tymczas->lotnisko = "Brak danych"; //zabezpieczenie przed plikiem, w ktorym wskaznik znajduje sie na linii w ktorej nic nie ma
	tymczas->data = "Brak danych";
	tym_pasazer->imie = "Brak danych";
	tym_pasazer->miejsce = 0;

	for (int i = 0; i < ciag_znakow.length(); i++) //petla wykonujaca sie tyle razy ile jest znakow w linii odczytanego pliku
	{
		if (ciag_znakow[i] == ' ' || (ktory_element == 4 && i == ciag_znakow.length() - 1)) //warunek sprawdzajacy czy po odczytanej danej jest spacja lub jest to ostatni element w linii oraz ostatni znak
		{
			switch (ktory_element) //przelacz w zaleznosci od oczytanego elementu
			{
			case 0: //element pierwszy (identyfikator lotu)
				tymczas->ident_lotu = tmp; //tymczasowy wskaznik na Rezerwacje, ktory wskazuje na identyfikator lotu, przypisany jest to niego pomocniczy string tmp
				tmp = ""; //zainicjalizowanie tmp pusta wartoscia
				ktory_element++; //zikrementowanie zmiennej
				break; //zerwanie warunku
						//tak samo dalej
			case 1:
				tymczas->lotnisko = tmp;
				tmp = "";
				ktory_element++;
				break;

			case 2:
				tymczas->data = tmp;
				tmp = "";
				ktory_element++;
				break;

			case 3:
				tym_pasazer->imie = tmp;
				tmp = "";
				ktory_element++;
				break;

			case 4:								
				if (ciag_znakow[i] != ' ') 
					tmp += ciag_znakow[i];
				tym_pasazer->miejsce = atoi(&tmp[0]); //atoi jeko argument pobiera liczbe w postaci ciagu znakow ASCII, a nastepnie zwraca jej wartosc w formacie int
				tmp = "";
				ktory_element++;
				break;
			default:
				break;
			}
		}
		else
		{
			tmp += ciag_znakow[i]; //dodanie do stringa tmp odczytanego znaku
		}
	}

	tymczas->nastepny = NULL; //ustawienie wskaznikow pomocniczych na NULL, aby na nic nie wskazywaly
	tymczas->poprzedni = NULL;
	tymczas->lista = NULL;
	tymczas->miejsce = 0;
	tym_pasazer->nastepny = NULL;
	tym_pasazer->poprzedni = NULL;

	glowa_rezerwacje = dodajDoListyRezerwacji(tymczas, glowa_rezerwacje, tym_pasazer); //wywolanie funkcji dodajDoListyRezerwacji, przyjmuje glowe rezerwacji, wskaznik na tymczasowa liste rezerwacji oraz pasazera
	return glowa_rezerwacje; //zwrot glowy listy Rezerwacje
}
