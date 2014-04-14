#include "stdafx.h"
#include "ob_plikow.h"
#include <string>


using namespace std;

void wypiszPlik (string nazwa_p){
	
	fstream plik; // tworzenie obiektu klasy fstream

	plik.open(nazwa_p, ios::in); // wywo³anie funkcji open, ktora otwiera plik. Za argumenty przyjmuje nazwe pliku oraz parametry otwaracia opisane gdziendziej

	int licznik = 0; // inicjalizacja zmiennej odpowiadajacej za numerowanie wierszy
	if ( plik.good() ) //wykona siê jezeli plik istnieje oraz nie jest uszkodzony
	{
		string napis;
		while ( !plik.eof() ) // petla ktora wykonuje sie do poki plik sie nie skonczy
		{
			licznik++;
			getline(plik,napis); //pobranie lini. Za argumenty przyjmuje pierw obiekt, z ktorego pobiera dana linie. Drugim argumentem jest nazwa zmiennej do ktorej zapisuje linie
			//wypisywanie lini poprzedzone numerem wiersza
			printf("%d-",licznik);
			cout << napis << endl;
		}
		plik.close(); // zamkniecie plku, bardzo wa¿ne!
	} else printf("Error! Nie udalo otworzyc sie pliku!");
}


void dodajWierszPo(string nazwa_p, string napis)
{
	fstream plik;
	
	napis += "\n"; // konkatenacja, czyli polaczenie 2 stringow. mozna to tak¿e zapisaæ jako napis = napis + "\n"; 
	// \n to znak nowej linii
	plik.open(nazwa_p, ios::out | ios::app); // ios::app - dodawanie na koncu pliku bez mozliwosci modyfikacji poprzedniego tekstu
	if( plik.good())
    {
        plik.write( &napis[0], napis.length() ); //write zapisuje do pliku. jako pierwszy argument przyjmuje co ma zapisac, index [0] oznacza ze zapsywac ma od pierwszego elementu stringa
		// drugi argument to ile znakow ma zapisac
        plik.close();
    }
}
void dodajWierszPrzed(string nazwa_p, string napis)
{
	//tworzymy i otwieramy 2 pliki - jeden bedacy naszym glownym, i drugi tymczasowy ("tmp")
	fstream plik;
	fstream tmp;
	napis += "\n";
	plik.open(nazwa_p, ios::in);
	tmp.open("tmp",ios::out);
	
	if ( plik.good() )
	{
		//przepisanie pliku glownego do pliku tymczasowego
		string tmpS;
		while ( !plik.eof() )
		{
			getline(plik,tmpS);
			tmpS += "\n";
			tmp.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();
		//koniec przepisywania

		//otwarcie tych samych plikow tylko w innych trybach
		plik.open(nazwa_p, ios::out | ios::trunc);
		tmp.open("tmp",ios::in);

		//zapisanie podanego wiersza na poczatku pliku
        plik.write(&napis[0], napis.length());

		//przepisanie reszty pliku
		while ( !tmp.eof() )
		{
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();
	}

}

void dodajWierszGdzie(string nazwa_p, string napis, int gdzie)
{
	fstream plik;
	fstream tmp;
	napis += "\n";
	plik.open(nazwa_p, ios::in);
	tmp.open("tmp",ios::out);
	if ( plik.good() )
	{
		string tmpS;
		while ( !plik.eof() )
		{
			getline(plik,tmpS);
			tmpS += "\n";
			tmp.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();

		plik.open(nazwa_p, ios::out | ios::trunc);
		tmp.open("tmp",ios::in);
		
		//tutaj przepisujemy plik do wiersza w ktorym mielismy wstawic tekst
		int licznik=1;
		while ( licznik < gdzie )
		{
			licznik ++;
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}

		//wstawienie tekstu
        plik.write(&napis[0], napis.length());
		//przepisanie reszty pliku
		while ( !tmp.eof() )
		{
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();
	}
}

void usunPierwszy (string nazwa_p)
{
	fstream plik;
	fstream tmp;
	plik.open(nazwa_p, ios::in);
	tmp.open("tmp",ios::out);
	if ( plik.good() )
	{
		string tmpS;
		while ( !plik.eof() )
		{
			getline(plik,tmpS);
			tmpS += "\n";
			tmp.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();

		plik.open(nazwa_p, ios::out | ios::trunc);
		tmp.open("tmp",ios::in);
		

		getline(tmp,tmpS); //zignorowanie pierwszej linijki pliku poprzez pobranie jej i nic nie robienie z nia

		//przepisanie reszty pliku
		while ( !tmp.eof() )
		{
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();
	}
}

void zamienWiersz(string nazwa_p, string napis, int gdzie)
{
	fstream plik;
	fstream tmp;
	napis += "\n";
	plik.open(nazwa_p, ios::in);
	tmp.open("tmp",ios::out);
	
	if ( plik.good() )
	{
		string tmpS;
		while ( !plik.eof() )
		{
			getline(plik,tmpS);
			tmpS += "\n";
			tmp.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();

		plik.open(nazwa_p, ios::out | ios::trunc);
		tmp.open("tmp",ios::in);
		
		//przepisanie pliku do danego wiersza
		int licznik=1;
		while ( licznik < gdzie )
		{
			licznik ++;
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}
		//zapisanie podanego tekstu
        plik.write(&napis[0], napis.length());
		//zignorowanie linijki, ktora w orginalnym pliku miala byc zastapiona
		getline(tmp,tmpS);

		//przepisanie 
		while ( !tmp.eof() )
		{
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();
	}
}

void usunWskazany(string nazwa_p, int gdzie)
{
	fstream plik;
	fstream tmp;
	plik.open(nazwa_p, ios::in);
	tmp.open("tmp",ios::out);
	if ( plik.good() )
	{
		string tmpS;
		while ( !plik.eof() )
		{
			getline(plik,tmpS);
			tmpS += "\n";
			tmp.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();

		plik.open(nazwa_p, ios::out | ios::trunc);
		tmp.open("tmp",ios::in);
		
		//odliczenie odpowiedniego wiersza przepisujac 
		int licznik=1;
		while ( licznik < gdzie )
		{
			licznik ++;
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}
		
		getline(tmp,tmpS);//zignorowanie wiersza ktory mial zostac usuniety

		//przepisanie reszty
		while ( !tmp.eof() )
		{
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();
	}
}
void znajdz(string nazwa_p, string szukany)
{
	fstream plik;
	plik.open(nazwa_p, ios::in);

	int licznik = 0;
	if ( plik.good() )
	{
		string napis;
		while ( !plik.eof() )
		{
			licznik++;
			getline(plik,napis);
			if (napis.compare(szukany) == 0) //porownanie 2 stringow - aktualnie przezytanego z pliku oraz podanego do wyszukania
			{
				printf("%d-",licznik);
				cout << napis << endl;
			}
		}
		plik.close();
	} 
}

void usunOstatni(string nazwa_p)
{
	fstream plik;
	fstream tmp;
	plik.open(nazwa_p, ios::in);
	tmp.open("tmp",ios::out);
	
	int ile = 0;
	if ( plik.good() )
	{
		//przepisywanie pliku glownego do pliku tymczasowego
		//wraz z policzeniem ile jest wierszy
		string tmpS;
		while ( !plik.eof() )
		{
			ile ++;
			getline(plik,tmpS);
			tmpS += "\n";
			tmp.write(&tmpS[0], tmpS.length());
		}
		plik.close();
		tmp.close();

		plik.open(nazwa_p, ios::out | ios::trunc);
		tmp.open("tmp",ios::in);

		//przepisanie calego pliku bez ostatniego wiersza.
		for (int i = 0; i < ile-1; i++)
		{
			getline(tmp,tmpS);
			tmpS += "\n";
			plik.write(&tmpS[0], tmpS.length());
		}
		
		plik.close();
		tmp.close();
	}
}
/*	
	Mam nadzieje ze wszystko jest dobrze, i ze wytlumaczy³em ca³kiem spoko jak to ma dzia³ac
	¯ycze wiêc powodzenia Kochanie :**
*/