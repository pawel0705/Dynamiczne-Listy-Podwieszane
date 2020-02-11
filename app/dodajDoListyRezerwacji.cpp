/** @file */
//#include "stdafx.h"
#include "loty.h"

/*
Funkcja o typie struktury Rezerwacje. 
Jej zadaniem jest uzupelnienie struktury Rezerwacje danymi odczytanimi z pobranego pliku z rezerwacjami.

parametry funkcji:
__________________
nowy - pomocnicza zmienna o stukturze listy Rezerwacje
glowa - glowa listy Rezerwacje
tym_pasazer - pomocnicza zmienna o strukturze listy Pasazer
Powyzsze parametry zostaly utworzone w funckji zwroc_obiekt(...)

wartosc zwracana:
_________________
glowa - zwrot glowy listy Rezerwacje

@autor Pawel Salicki
@data 2018-01-18
*/

Rezerwacje* dodajDoListyRezerwacji(Rezerwacje *nowy, Rezerwacje *glowa, Pasazer *tym_pasazer)
{
	bool czy_istnieje = false; //stworzeniue zmiennej pomocniczej typu bool i zainicjalizowanie jej false
	Rezerwacje *tmp; //utworzenie wskaznika pomocniczego na liste Rezerwacje
	
	if (glowa == NULL) //sprawdzenie czy glowa listy na nic nie wskazuje (dodanie pierwszego elementu)
	{
		glowa = nowy; //nadanie glowie wartosci przechowywanej we wczesniejszej stworzonej pomocniczej zmiennej
		glowa->lista = dodajPasazera(glowa->lista, tym_pasazer); //glowa wskazuje na liste (Pasazerowie), do tego jest przypisywana funkcja, ktora jest jednoczesnie wywolana dodajPasazera; przyjmuje wartosc glowy z listy Rezerwacje wskazujacej na liste Pasazerow oraz zmienna pomocnicza o typie struktury Pasazer tym_pasazer, funkcja dodaje do listy Rezerwacje pasazera
		glowa->miejsce++; //inkrementacja ilosci miejsc
	}
	else // lista juz cos zawiera
	{
		tmp = glowa; //przypisanie do zmiennej pomocniczej wartosci zawartych w glowa
	
		while (tmp != NULL) //petla wykonujaca sie tyle razy dopoki tmp nie bedzie mial wartosci
		{
			if (tmp->ident_lotu == nowy->ident_lotu) //sprawdzenie czy identyfikator lotu jest taki sam jak w tmp oraz nowy
			{
				czy_istnieje = true; //jezeli tak, to zmiana wartosci czy_istnieje na true;
				tmp->lista = dodajPasazera(tmp->lista, tym_pasazer); // tmp wskazuje na liste(Pasazerowie), do tego jest przypisywana funkcja, ktora jest jednoczesnie wywolana dodajPasazera; przyjmuje wartosc glowy z listy Rezerwacje wskazujacej na liste Pasazerow oraz zmienna pomocnicza o typie struktury Pasazer tym_pasazer
				tmp->miejsce++; //inkrementacja liczby miejsc
			}
			tmp = tmp->nastepny; //przejscie do nastepnego elementu tmp
		}

		if (!czy_istnieje) //warunek sprawdzajacy czy ifentyfikator lotu juz istnieje
		{
			if (tmp == NULL) //jesli tmp jest puste
			{
				tmp = glowa; //glowa listy zostaje przypisana do tmp
				while (tmp->nastepny != NULL)  //dopoki istnieje nastepny element
					tmp = tmp->nastepny; //przechodzenie na nastepny element
			}
			tmp->nastepny = nowy; 
			nowy->poprzedni = tmp;
			nowy->lista = dodajPasazera(nowy->lista, tym_pasazer); // nowy wskazuje na liste(Pasazerowie), do tego jest przypisywana funkcja, ktora jest jednoczesnie wywolana dodajPasazera; przyjmuje wartosc glowy z listy Rezerwacje wskazujacej na liste Pasazerow oraz zmienna pomocnicza o typie struktury Pasazer tym_pasazer
			nowy->miejsce++; //inkrementacja liczby miejsc
		}
	}
	return glowa; //zwrot glowy listy
}