#include "stdafx.h"

using namespace std;

void piszListe(wielomian *pocz)
{
	if (pocz != NULL)
		do {
			printf("%4.2fx^4 + %4.2fx^3 + %4.2fx^2 + %4.2fx^1 + %4.2f\n",pocz->a4,pocz->a3,pocz->a2,pocz->a1,pocz->a0);
			pocz = pocz->nast;
		} while(pocz != NULL);
	else printf("Lista pusta\n");
}

void tworzListe (wielomian *&pocz)
{
	char odp; wielomian *ost; double w4,w3,w2,w1,w0;
	cout << "Podaj pierwszy element listy\n";
	printf("Wspolczynnik przy potedze stopnia 4:");
	cin >> w4;
	printf("Wspolczynnik przy potedze stopnia 3:");
	cin >> w3;
	printf("Wspolczynnik przy potedze stopnia 2:");
	cin >> w2;
	printf("Wspolczynnik przy potedze stopnia 1:");
	cin >> w1;
	printf("Wyraz wolny:");
	cin >> w0;
	dolaczPocz(pocz,w4,w3,w2,w1,w0);
	ost = pocz;
	cout << "Czy nastepny element? (T/N)> "; cin >> odp;
	while (toupper(odp) != 'N')
	{
		printf("Wspolczynnik przy potedze stopnia 4:");
		cin >> w4;
		printf("Wspolczynnik przy potedze stopnia 3:");
		cin >> w3;
		printf("Wspolczynnik przy potedze stopnia 2:");
		cin >> w2;
		printf("Wspolczynnik przy potedze stopnia 1:");
		cin >> w1;
		printf("Wyraz wolny:");
		cin >> w0;
		ost = wstawPo(ost,w4,w3,w2,w1,w0);
		printf("Czy nastepny element? (T/N)> ");
		cin >> odp;
	}
}

void dolaczPocz (wielomian *&pocz, double w4, double w3, double w2, double w1, double w0)
{
	wielomian *nowy = new wielomian;
	nowy->a4 = w4;
	nowy->a3 = w3;
	nowy->a2 = w2;
	nowy->a1 = w1;
	nowy->a0 = w0;
	nowy->nast = pocz;
	pocz = nowy;
}

wielomian* wstawPo (wielomian *wsk, double w4, double w3, double w2, double w1, double w0)
{
	wielomian *nowy = new wielomian;
	nowy->a4 = w4;
	nowy->a3 = w3;
	nowy->a2 = w2;
	nowy->a1 = w1;
	nowy->a0 = w0;
	nowy->nast = wsk->nast;
	wsk->nast = nowy;
	return nowy;
}

wielomian* szukaj(wielomian *wsk, int ktora_p, double wart)
{

	switch (ktora_p)
	{
	case 1:
		while ((wsk != NULL) && (wsk->a1 != wart)) {
			wsk = wsk->nast;
		}
		break;
	case 2:
		while ((wsk != NULL) && (wsk->a2 != wart)) {
			wsk = wsk->nast;
		}
		break;
	case 3:
		while ((wsk != NULL) && (wsk->a3 != wart)) {
			wsk = wsk->nast;
		}
		break;
	case 4:
		while ((wsk != NULL) && (wsk->a4 != wart)) {
			wsk = wsk->nast;
		}
		break;
	case 0:
		while ((wsk != NULL) && (wsk->a0 != wart)) {
			wsk = wsk->nast;
		}
		break;
	default:
		break;
	}
	if (wsk == NULL) 
	{
		printf("Nie znaleziono wartoœci\n");
		return NULL;
	}
	else return wsk;
}

void kasuj(wielomian* wsk)
{
	if (wsk == NULL) return;
	wielomian *pom;
	if (wsk->nast != NULL)
	{
		pom = wsk->nast;
		*wsk = *pom;
		delete pom;
	}
	printf("Gotowe!\n");
}

void zwolnijListe(wielomian * &pocz)
{
	wielomian *temp;
	while (pocz != NULL)
	{
		temp = pocz;
		pocz = pocz->nast;
		delete temp;
	}
}

int policzListe (wielomian *&pocz)
{
	int liczba = 0;
	if (pocz != NULL)
		do {
			liczba++;
			pocz = pocz->nast;
		} while(pocz != NULL);
	else 
	{
		return 0;
	}
	return liczba;
}
void zamiana (wielomian* wsk1, wielomian* wsk2)
{
	wielomian *pom = NULL;
	*pom = *wsk1;
	*wsk1 = *wsk2;
	*wsk2 = *wsk1;
	delete pom;
}