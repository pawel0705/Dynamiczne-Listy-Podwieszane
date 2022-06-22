# Loty-projekt prostej bazy danych
Program konsolowy napisany w C++ imitujący prostą bazę danych. Utworzona na podwieszanych dynamicznych listach.

# Opis programu

Program korzysta z dynamicznych struktur danych i przygotowuje posortowane listy pasażerów. Program odczytuje tekstowy plik zawierający dane. Jego zawartość jest następująca:
[symbol lotu] 
[lotnisko startowe] 
[data lotu]
[nazwisko pasażera] 
[nr miejsca]
 
Na podstawie odczytanego pliku, program generuje pliki o nazwach z symbolem lotu. W ich zawartości znajduje się posegregowana lista pasażerów, według numerów ich miejsc w samolocie. W pliku tym znajdują się też informacje o nazwie lotniska, liczbie wszystkich miejsc, dacie lotu i nazwie masta, w którym znajduje się lotnisko. Program jest uruchamiany przy pomocy linii poleces po wpisaniu parametru -i <nazwa pliku wejściowego>. Po wpisaniu parametru -h, program wyświetla uzytkownikowi pomoc.
