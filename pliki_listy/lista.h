#ifndef __lista_h
#define __lista_h

struct wielomian {
	double a4;
	double a3;
	double a2;
	double a1;
	double a0;
	wielomian *nast;
};


void piszListe(wielomian *pocz);
void tworzListe (wielomian *&pocz);

void dolaczPocz (wielomian *&pocz, double w4, double w3, double w2, double w1, double w0);
wielomian* wstawPo (wielomian *wsk, double w4, double w3, double w2, double w1, double w0);
	
wielomian* szukaj(wielomian *wsk, int ktora_p, double wart);

void kasuj(wielomian* wsk);
void zwolnijListe(wielomian * &pocz);

int policzListe (wielomian *&pocz);

void sortujListe(wielomian *&pocz);


#endif 