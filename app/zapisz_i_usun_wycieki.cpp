/** @file */
//#include "stdafx.h"


#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


#include "loty.h"

/*
Funkcja typu void.
Zapisuje dane do pliku w odpowiedniej kolejnosci i ustawieniu.
Usuwa wycieki pamieci.

parametry funkcji:
__________________
glowa - glowa listy Rezerwacje

wartosc zwracana:
_________________
brak

@autor Pawel Salicki
@data 2018-01-18
*/

void zapisz_i_usun_wycieki(Rezerwacje *glowa)
{
	std::ofstream plik; //utworzenie zmiennej plik do zapisu

	while (glowa != NULL) //petla wykonujaca sie dopuki glowa listy nie jest rowna wartosci NULL
	{
		std::string nazwa_pliku = glowa->ident_lotu + ".txt"; //zmienna przechowujaca nazwe pliku do zapisu, pobiera ja z listy Rezerwacje (ident_lotu) i dodaje koncowke .txt
		plik.open(nazwa_pliku.c_str()/*, std::ios::out  | std::ios::trunc*/); //otwarcie pliku do zapisu
		std::string symbol_lotu = "Symbol lotu: " + glowa->ident_lotu; //zmienna przechowywujaca symbol lotu, pobiera go z listy Rezerwacje (ident_lotu)
		std::string lotnisko =    "Lotnisko:    " + glowa->lotnisko; //zmienna przechowywujaca nazwe lotniska, pobiera ja z listy Rezerwacje
		std::string data =        "Data:        " + glowa->data; //zmienna przechowywyjaca date, pobiera ja z listy Rezerwacje
		plik << symbol_lotu << "\n" << lotnisko << "\n" << data << "\n" << "\n" << "Lista pasazerow:" << "\n"; //wpisanie do pliku zmiennych
		Pasazer *wsk = glowa->lista; //utworzenie wskaznika pomocniczego przyjmujacego glowe listy rezerwacje wskazujaca na lista (Pasazerowie)
	
		while (wsk != NULL) //warunek spelniajacy sie az zainicjowany wczesniej wskaznik nie bedzie posiadac wartosci NULL
		{
			std::stringstream ss; //utworzenie zmiennej pozwalajacej wykonywanie operacji na napisach
			ss << wsk->miejsce; //wrzucenie do zmiennej ss numeru miejsca pasazera
			std::string miejsce = ss.str() + " "; //zapisanie do zmiennej miejsca pasazera
			std::string imie = wsk->imie; //zapis do zmiennej imienia pasazera
			plik << miejsce << imie << "\n"; //zapis do pliku miejsca i imienie pasazera
			Pasazer *tymczas = wsk; //utworzenie zmiennej pomocniczej
			wsk = wsk->nastepny; //przesuniecie wskaznika pomocniczego na nastepny element
			delete tymczas; //zwolnienie pamieci
		}
		
		std::stringstream ss; //utworzenie zmiennej pozwalajacej wykonywanie operacji na napisach
		ss << glowa->miejsce; //wczytanie do utworzonej zmiennej ss miejsca pasazera
		std::string miejsce = "Liczba miejsc: " + ss.str(); //zapis do zmiennej
		plik << miejsce; //zapis do pliku
		Rezerwacje *tmp = glowa; //utworzenie zmiennej pomocniczej do usuniecia danych
		glowa = glowa->nastepny; //przejscie na nastepny element
		delete tmp; //zwolnienie pamieci
		plik.close(); //zamkniecie pliku i zwolnienie bufora
	}
	std::cout << "Pliki zostaly wygenerowane do folderu z zawartoscia programu." << std::endl;
}
