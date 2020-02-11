/*** @file */
#ifndef loty_hpp
#define loty_hpp

//#include "stdafx.h"

#include <string>
#include <time.h>
#include <fstream>
#include <sstream>
#include <iostream>

/**
Struktura listy dwukierunkowej o nazwie Pasazer. Przechowuje dane na temat pasazera.

@autor Pawel Salicki
@data 2018-01-18
*/

struct Pasazer
{
	std::string imie; ///<imie pasazera
	int miejsce; ///<numer miejsca pasazera
	Pasazer *nastepny; ///<wskaznik do nastepnego elementu listy
	Pasazer *poprzedni; ///<wskaznik do poprzedniego elementu listy
};

/**
Struktura listy dwukierunkowej o nazwie Rezerwacje. Przechowuje informacje na temat lotu.

@autor Pawel Salicki
@data 2018-01-18
*/

struct Rezerwacje
{
	std::string ident_lotu; ///<identyfikator lotu
	std::string lotnisko; ///<nazwa lotniska
	std::string data; ///<data lotu
	int miejsce; ///<ilosc zarezerwowanych miejsc
	Rezerwacje *nastepny; ///<wskaznik do nastepnego elementu
	Rezerwacje *poprzedni; ///<wskaznik do poprzedniego elementu
	Pasazer *lista; ///<wskaznik na strukture Pasazer
};

/**
Deklaracje funkcji uzytych w programie.

@autor Pawel Salicki
@data 2018-01-18
*/

Pasazer* dodajPasazera(Pasazer *glowa, Pasazer *nowy);

Rezerwacje* dodajDoListyRezerwacji(Rezerwacje *nowy, Rezerwacje *glowa, Pasazer* tym_pasazer);


Rezerwacje* zwroc_obiekt(std::string ciag_znakow, Rezerwacje *glowa_rezerwacje);

void pomoc();

void zapisz_i_usun_wycieki(Rezerwacje *glowa);

void czytaj_plik(std::string nazwa);


#endif
