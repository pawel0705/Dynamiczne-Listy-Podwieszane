/** @file */
//#include "stdafx.h"
#include "loty.h"

/*
Funkcja o typie Pasazer.
Dodaje odpowiednio pasazera do struktury listy Rezerwacje.

parametry funkcji:
__________________
glowa -  wartosc glowy z listy Rezerwacje wskazujacej na liste Pasazerow 
nowy - zmienna pomocnicza o typie struktury Pasazer

wartosc zwracana:
_________________
glowa - zwrocenie glowy listy Pasazer

@autor Pawel Salicki
@data 2018-01-18
*/

Pasazer* dodajPasazera(Pasazer *glowa, Pasazer *nowy)
{
	Pasazer *pomocnicza; //utworzenie zmiennej pomocniczej o typie strukturalnym Pasazer
	
	if (glowa == NULL) //sprawdzenie czy glowa jest pierwszym elementem
	{
		glowa = nowy; //nadanie zawartosci przechowywanej w nowy do glowy
	}
	else //jezeli glowa nie jest pierwszym elementem
	{
		if (glowa->miejsce > nowy->miejsce) //sprawdzenie czy kolejny numer odczytany miejsca jest mniejszy od starego
		{
			glowa->poprzedni = nowy;  //przypisanie wartosci przechowywanej w nowy do poprzedniego elementu glowy
			nowy->nastepny = glowa; //przypisaie glowy do nastepnego elementu nowy
			glowa = nowy; //przypisanie zawartosci zawartej w nowy do glowa
		}
		else //przeciwny warunek kiedy nowy odczytany numer miejsca jest wiekszy od starszego
		{
			pomocnicza = glowa; //zainicjowanie wczesniej utworzonej zmiennej wartoscia zawarta w glowa
			
			while (pomocnicza->nastepny != NULL) //przejscie po kolejnych elementach w zmiennej pomocniczej do ostatniego elementu
			{
				pomocnicza = pomocnicza->nastepny;
			}
			if (pomocnicza->miejsce < nowy->miejsce) //sprawdzenie czy nowy odczytany numer miejsca jest wiekszy od starszego
			{
				pomocnicza->nastepny = nowy; //wskaznik wskazujacy na nastepny element wskazuje na wartosc zawarta w nowy
				nowy->poprzedni = pomocnicza; //nowy wskazuje na poprzednia wartosc ktora jest rowna pomocniczej
			}
			else
			{
				pomocnicza = glowa; //zainicjowanie wczesniej utworzonej pomocniczej wartoscia znajdujacej sie w glowie
				while (pomocnicza->miejsce < nowy->miejsce) //warunek sprawdzajacy czy wartosc nowego odczytanego miejsca jest wieksza od starego
				{
					pomocnicza = pomocnicza->nastepny; //przejscie do nastepnego elementu
				}
				if (pomocnicza->nastepny != NULL)  //warunek sprawdzajacy czy nastepny element istnieje
				{
					pomocnicza->nastepny->poprzedni = nowy; //przypisanie wartosci nowy
					nowy->poprzedni = pomocnicza; //przypisanie wartosci pomocnicza
					nowy->nastepny = pomocnicza->nastepny;
					pomocnicza->nastepny = nowy;
				}
				else
				{
					nowy->poprzedni = pomocnicza;
					nowy->nastepny = pomocnicza->nastepny;
					pomocnicza->nastepny = nowy;
				}
			}
		}
	}
	return glowa;
}