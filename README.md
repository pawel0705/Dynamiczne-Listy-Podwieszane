# Loty-projekt prostej bazy danych
 Prosta baza danych utworzona na podwieszanych dynamicznych listach w C++.

// TODO W programie znajduje się fragment tworzonej tymczasowej listy, której pamięć jest alokowana, ale nie jest później zwalniana. Należy zaimplementować obsługę czyszczenia tego obszaru pamięci.

# Opis programu

Program korzysta z dynamicznych struktur danych i przygotowuje posortowane listy pasażerów. Program odczytuje tekstowy plik zawierający dane. Jego zawartość jest następująca:
<symbol lotu> <lotnisko startowe> <data lotu> <nazwisko pasażera> <nr miejsca>
 
Na podstawie odczytanego pliku, program generuje pliki o nazwach z symbolem lotu. W ich zawartości znajduje się posegregowana lista pasażerów, według numerów ich miejsc w samolocie. W pliku tym znajdują się też informacje o nazwie lotniska, liczbie wszystkich miejsc, dacie lotu i nazwie masta, w którym znajduje się lotnisko. Program jest uruchamiany przy pomocy linii poleces po wpisaniu parametru -i <nazwa pliku wejściowego>. Po wpisaniu parametru -h, program wyświetla uzytkownikowi pomoc.
