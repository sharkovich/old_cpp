#ifndef __obsluga_plikow_h
#define __obsluga_plikow_h
#include<string>

void zapiszListeDoPliku (std::string nazwa, wielomian *pocz);
void wczytajListeZPliku (std::string, wielomian *&pocz);
void wypiszPlik (std::string);

#endif 