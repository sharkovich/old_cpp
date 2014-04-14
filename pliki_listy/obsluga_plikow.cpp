#include "stdafx.h"
#include "lista.h"
#include "obsluga_plikow.h"
#include <fstream>
#include <sstream>

using namespace std;

void zapiszListeDoPliku (string nazwa, wielomian *pocz)
{
	fstream plik;
	nazwa += ".txt";
	plik.open(nazwa, ios::out);
	int licznik = 1;
	if (pocz != NULL)
	do {
			plik << "Wielomian nr " << licznik << "\n" ;
			plik << pocz->a4 << " \t\tx^4\n";
			plik << pocz->a3 << " \t\tx^3\n";
			plik << pocz->a2 << " \t\tx^2\n";
			plik << pocz->a1 << " \t\tx^1\n";
			plik << pocz->a0 << " \t\tWyraz wolny\n";
			pocz = pocz->nast;
			licznik++;
	} while(pocz != NULL);
	plik.close();
}

void wczytajListeZPliku (string nazwa, wielomian *&pocz)
{
	fstream plik;
	nazwa += ".txt";
	double w0,w1,w2,w3,w4;
	wielomian *ost;
	plik.open(nazwa, ios::in); 

	if ( plik.good() )
	{
		string napis;
		getline(plik,napis);
		if (napis.substr(0,9).compare("Wielomian")==0)
		{
			getline(plik,napis);
			
			w4 = strtod(napis.c_str(),NULL);
			getline(plik,napis);
			w3 = strtod(napis.c_str(),NULL);
			getline(plik,napis);
			w2 = strtod(napis.c_str(),NULL);
			getline(plik,napis);
			w1 = strtod(napis.c_str(),NULL);
			getline(plik,napis);
			w0 = strtod(napis.c_str(),NULL);
		} else
		{
			printf ("Blad w pliku!");
			return;
		}
		dolaczPocz(pocz,w4,w3,w2,w1,w0);
		ost=pocz;

		while ( !plik.eof() )
		{

			getline(plik,napis);
			
			if (napis.substr(0,9).compare("Wielomian")==0)
			{
				getline(plik,napis);
				w4 = strtod(napis.c_str(),NULL);
				getline(plik,napis);
				w3 = strtod(napis.c_str(),NULL);
				getline(plik,napis);
				w2 = strtod(napis.c_str(),NULL);
				getline(plik,napis);
				w1 = strtod(napis.c_str(),NULL);
				getline(plik,napis);
				w0 = strtod(napis.c_str(),NULL);
				ost = wstawPo(ost,w4,w3,w2,w1,w0);
			}


		}
		plik.close();
		printf("Gotowe!");
	} else printf("Error! Nie udalo otworzyc sie pliku!");

}
void wypiszPlik (string nazwa)
{	
	fstream plik;
	nazwa += ".txt";
	plik.open(nazwa, ios::in); 
	if ( plik.good() )
	{
		string napis;
		while ( !plik.eof() )
		{
			getline(plik,napis);
			cout << napis << endl;
		}
		plik.close();
	} else printf("Error! Nie udalo otworzyc sie pliku!");
}