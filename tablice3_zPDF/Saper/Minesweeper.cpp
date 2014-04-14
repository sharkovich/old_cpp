// Minesweeper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include <iomanip>


using namespace std;


void cls();
void generateField(int **tab, int ilePol);
void PrintTab (int **tab, int a, int b, int c);
void PrintField (char **tab, int ilepol);
bool CheckField (char **gr, int **fi, int a, int ii, int ij);
void ShowEmpty (char **txt, int **field, int a, int ii, int ij);
void set_color (int c);


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int poziom;
	do{
		cls();
		cout << "----- SAPER -----\n"
			"wybierz poziom trudnosci \n"
			"1. - latwy (pole 5x5)\n"
			"2. - sredni (pole 8x8)\n"
			"3. - trudny (pole 12x12)\n"
			"4. - zakoncz program\n";

		do{
			cin >> poziom;
		}while ((poziom > 4) || (poziom < 1));
		int n;
		cls();
		switch (poziom)
			{
		case 1:
			n = 5;
			break;
		case 2:
			n = 8;
			break;
		case 3:
			n = 12;
			break;
		case 4:
			cout << "Nacisnij ENTER aby zakonczyc..";
			cin.get();
			cin.get();
			return 0;
		default:
			return 0;
		}
		int **tabField = new int*[n];
		for (int i = 0; i < n; i++)
		{
			tabField[i] = new int[n];
		}
		char **tabResults = new char*[n];
		for (int i = 0; i < n; i++)
		{
			tabResults[i] = new char[n];
			for (int j = 0; j < n; j++)
			{
				tabResults[i][j] = 176;
			}
		}
		generateField(tabField, n);
		int win = true;
		PrintField(tabResults,n);
		do{

			cout << endl;
			int vi,hi;
			cout << "Podaj wspolrzedna pionowa pola: " << endl;
			do{
				cin >> vi;
				vi = --vi;
			}while (!((vi<n)&&(vi>=0)));
			cout << "Podaj wspolrzedna pozioma pola: " << endl;
			do{
				cin >> hi;
				hi = --hi;
			}while (!((hi<n)&&(hi>=0)));
			win = CheckField(tabResults,tabField,n,vi,hi);

		}while(win);



		cout << endl << "Czy chcesz powtorzyæ gre? T/N" << endl;
		char quitcheck;
		cin >> quitcheck;
		if ((quitcheck=='N')||(quitcheck=='n'))
		{
			cls();
			cout << "Nacisnij ENTER aby zakonczyc..";
			cin.get();
			cin.get();
			return 0;
		}
	
	}while(true);

}

bool CheckField (char **gr, int **fi, int a, int ii, int ij){
	if (fi[ii][ij] == 666) {
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if(fi[i][j] == 666) gr[i][j] = '*';
			}
		}
		gr[ii][ij] = 'X';
		PrintField(gr,a);
		cout << endl << "Przegrales!!" << endl;
		return false;
	}
	else if ((fi[ii][ij] != 0) && (fi[ii][ij] != 666)) {
		gr[ii][ij] = fi[ii][ij]+48;
		PrintField(gr,a);
		return true;
	}
	else if (fi[ii][ij] == 0) {
		ShowEmpty(gr,fi,a,ii,ij);
		PrintField(gr,a);
		return true;
	}

}

void ShowEmpty (char **txt, int **field, int a, int ii, int ij){

	if (txt[ii][ij]!=' '){
		txt[ii][ij] = ' ';	

		if ((ij+1 < a) && (ii-1 >= 0) && (field[ii-1][ij+1]==0)) ShowEmpty(txt,field,a,(ii-1),(ij+1));
		else if ((ij+1 < a) && (ii-1 >= 0) && (field[ii-1][ij+1]<666)) txt[ii-1][ij+1] = field[ii-1][ij+1]+48;
	
		if ((ij+1 < a) && (field[ii][ij+1]==0)) ShowEmpty(txt,field,a,ii,(ij+1));
		else if ((ij+1 < a) && (field[ii][ij+1]<666)) txt[ii][ij+1]= field[ii][ij+1]+48;
		
		if ((ij+1 < a) && (ii+1 < a) && (field[ii+1][ij+1]==0)) ShowEmpty(txt,field,a,(ii+1),(ij+1));
		else if ((ij+1 < a) && (ii+1 < a) && (field[ii+1][ij+1]<666)) txt[ii+1][ij+1]= field[ii+1][ij+1]+48;

		if ((ii-1 >= 0) && (field[ii-1][ij]==0)) ShowEmpty(txt,field,a,(ii-1),ij);
		else if ((ii-1 >= 0) && (field[ii-1][ij]<666)) txt[ii-1][ij] = field[ii-1][ij]+48;

		if ((ii+1 < a) && (field[ii+1][ij]==0)) ShowEmpty(txt,field,a,(ii+1),ij);
		else if ((ii+1 < a) && (field[ii+1][ij]<666)) txt[ii+1][ij] = field[ii+1][ij]+48;

		if ((ii-1 >= 0) && (ij-1 >= 0)  && (field[ii-1][ij-1]==0)) ShowEmpty(txt,field,a,(ii-1),(ij-1));
		else if ((ii-1 >= 0) && (ij-1 >= 0)  && (field[ii-1][ij-1]<666)) txt[ii-1][ij-1]= field[ii-1][ij-1]+48;

		
		if ((ij-1 >= 0) && (field[ii][ij-1]==0)) ShowEmpty(txt,field,a,ii,(ij-1));
		else if ((ij-1 >= 0) && (field[ii][ij-1]<666)) txt[ii][ij-1]= field[ii][ij-1]+48;
	
		if ((ii+1 < a) && (ij-1 >= 0) && (field[ii+1][ij-1]==0)) ShowEmpty(txt,field,a,(ii+1),(ij-1));	
		else if ((ii+1 < a) && (ij-1 >= 0) && (field[ii+1][ij-1]<666)) txt[ii+1][ij-1]= field[ii+1][ij-1]+48;
	}

}

void generateField(int **tab, int ilepol)
{
	int minecout = floor(ilepol*ilepol*0.3);

	for (int z = 0; z < minecout; z++)
	{
		int i, j;
		bool foo = true;
		do
		{
			i = rand() % ilepol;
			j = rand() % ilepol;

			if ( tab[i][j] != 0 )
			{
				tab[i][j] = 666;
				foo = false;
			}
		} while (foo);
	}
	for (int i = 0; i < ilepol; i++)
	{
		for (int j = 0; j < ilepol; j++)
		{
			int nearmines = 0;
			if (tab[i][j] != 666)
			{

				if ((j+1 < ilepol) && (i-1 > 0) && (tab[i-1][j+1]==666)) nearmines++;	
				if ((j+1 < ilepol) && (tab[i][j+1]==666)) nearmines++;
				if ((j+1 >= 0) && (i+1 < ilepol) && (tab[i+1][j+1]==666)) nearmines++;
				if ((i-1 >= 0) && (tab[i-1][j]==666)) nearmines++;
				if ((i+1 < ilepol) && (tab[i+1][j]==666)) nearmines++;
				if ((i-1 >= 0) && (j-1 >= 0)  && (tab[i-1][j-1]==666)) nearmines++;
				if ((j-1 >= 0) && (tab[i][j-1]==666)) nearmines++;
				if ((i+1 < ilepol) && (j-1 >= 0) && (tab[i+1][j-1]==666)) nearmines++;
				tab[i][j] = nearmines;
			}
		}

	}
}

void PrintField (char **tab, int a){

	cls();
	for (int i = 0; i < a+1; i++)
	{
		set_color(7);
		if (i!=0) cout << setw(1) << i << "|";

		else cout << setw(1) << " |";
	}
	for (int i = 0; i < a; i++)
	{
		cout << endl;
		for (int k = 0; k < a+1; k++)
		{
			if ((k==0)||(i==0)) set_color(7);
			else set_color(8);
			cout << setw(1) << "- ";
		}
		set_color(7);
		cout << endl << i+1 << "|";
		for (int j = 0; j < a; j++)
		{
			if (tab[i][j] == 176) set_color(8);
			else if ((tab[i][j] == '*')||(tab[i][j] == 'X')) set_color(4);
			else if (tab[i][j] < 60) set_color(2);
			cout << setw(1) << tab[i][j] << "|";
			set_color(7);
		}

	}
	set_color(7);
	cout << endl;
}

void cls()
{
   COORD coordScreen = {0,0};
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleScreenBufferInfo(hConsole, &csbi);
   dwConSize = csbi.dwSize.X*csbi.dwSize.Y;
   FillConsoleOutputCharacter(hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten);
   GetConsoleScreenBufferInfo(hConsole,&csbi);
   FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten);
   SetConsoleCursorPosition(hConsole,coordScreen);
}

void set_color(int c) {
     HANDLE uchwyt;
     uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(uchwyt,c);
}