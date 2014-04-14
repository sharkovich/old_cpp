// projekt_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>


using namespace std;

void cls(HANDLE);

int main()
{
	HANDLE hS;
	hS = GetStdHandle(STD_OUTPUT_HANDLE);
	string nazwa;
	int a;
	double b;
	wielomian *pocz = NULL;
	char menu;

	printf ("Podaj nazwe pliku na ktorym chcesz operowac:");
	getline(cin,nazwa);

	while (true)
	{
		cls(hS);
		printf("Menu\n"
			"1 - Utworz liste\n"
			"2 - Wczytaj liste z pliku\n"
			"Q - Zakoncz program\n");
		menu = getchar();
		switch (toupper(menu))
		{
		case '1':
			tworzListe(pocz);
			break;
		case '2':
			wczytajListeZPliku(nazwa,pocz);
			cin.ignore();cin.ignore();
			break;
		case 'Q':
			return 0;
		}
		while (true)
		{

			cls(hS);
			printf("Menu\n"
				"1 - Wypisz liste \n"
				"2 - Zapisz liste do pliku\n"
				"3 - Kasuj element o danym wspolczynniku\n"
				"4 - Policz ilosc elementow listy\n"
				"5 - Usun liste\n"
				"Q - Zakoncz program\n");
			menu = getchar();
			switch (toupper(menu))
			{
			case '1':
				cls(hS);
				piszListe(pocz);
				cin.ignore();cin.ignore();
				break;
			case '2':
				cls(hS);
				zapiszListeDoPliku(nazwa,pocz);
				printf ("Gotowe!");
				cin.ignore();cin.ignore();
				break;
			case '3':
				cls(hS);
				printf("Przy jakiej potedze chcesz wyszukaæ wspolczynnik (0-4)?\n");
				cin >> a;
				printf("Podaj wartosc wspolczynnika\n");
				cin >> b;
				kasuj(szukaj(pocz,a,b));
				cin.ignore();cin.ignore();
				break;
			case '4':
				cls(hS);
				printf("Liczba elementow listy: %d",policzListe(pocz));
				cin.ignore();cin.ignore();
				break;
			case '5':
				cls(hS);
				zwolnijListe(pocz);
				printf("Gotowe!");
				cin.ignore();cin.ignore();
				break;

			case 'Q':
				return 0;
			}
		}
	}


	return 0;
}

void cls( HANDLE hConsole )
{
   COORD coordScreen = { 0, 0 }; 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
      return;
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   if( !FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
      dwConSize, coordScreen, &cCharsWritten ))
      return;
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
      return;
   if( !FillConsoleOutputAttribute( hConsole, csbi.wAttributes,
      dwConSize, coordScreen, &cCharsWritten ))
      return;
   SetConsoleCursorPosition( hConsole, coordScreen );
}