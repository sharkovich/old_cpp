// kamila2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	printf("Podaj nazwe pliku (bez rozszezenia)\n");
	string nazwa;
	getline(cin,nazwa);
	string wiersz;
	int gdzie;
	nazwa += ".txt";
	system("cls");
	while (true){
		system("cls");
		printf("Menu:\n"
			"1. Wypisywani plku\n"
			"2. Dodanie wiersza na poczatku plku\n"
			"3. Dodanie wiersza na koncu pliku\n"
			"4. Dodanie wiersza w wyznaczonym miejscu\n"
			"5. Zamiana wiersza\n"
			"6. Usuwanie pierwszego wiersza\n"
			"7. Usuwanie ostaniego wiersza\n"
			"8. Usuwanie wskazanego wiersza\n"
			"9. Szukanie podanego wiersza\n"
			"Q - zakoncz\n");
		char odp;
		cin >> odp;
		cin.ignore();
		switch (toupper(odp))
		{
		case '1':
			system("cls");
			wypiszPlik(nazwa);
			cin.ignore();
			break;
		case '2':
			printf("Podaj wiersz który chcesz wpisaæ:\n");
			getline(cin,wiersz);
			dodajWierszPrzed(nazwa,wiersz);
			break;
		case '3':
			printf("Podaj wiersz który chcesz wpisaæ:\n");
			getline(cin,wiersz);
			dodajWierszPo(nazwa,wiersz);
			break;
		case '4':
			printf("Podaj wiersz który chcesz wpisaæ:\n");
			getline(cin,wiersz);
			printf("Gdzie chcesz wstawic wiersz?\n");
			cin >> gdzie;
			dodajWierszGdzie(nazwa,wiersz,gdzie);
			break;
		case '5':
			printf("Podaj wiersz który chcesz wpisaæ:\n");
			getline(cin,wiersz);
			printf("Gdzie chcesz zastapic wiersz?\n");
			cin >> gdzie;
			zamienWiersz(nazwa,wiersz,gdzie);
			break;
		case '6':
			usunPierwszy(nazwa);
			break;
		case '7':
			usunOstatni(nazwa);
			break;
		case '8':
			printf("Ktory wiersz chcesz usunac?\n");
			cin >> gdzie;
			usunWskazany(nazwa,gdzie);
			break;
		case '9':
			printf("Podaj wiersz który chcesz znalezc:\n");
			getline(cin,wiersz);
			znajdz(nazwa,wiersz);
			cin.ignore();
			break;
		case 'Q':
			return 0;
		default:
			break;
		}
	}

}

