// zad3_tablice(3).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

enum kierunek {lewo=1, prawo, gora, dol};

int Index(int kier, int a, int b, int p, int q){
	switch (kier)
	{
	case 1:
		if (a - 1 < 0) return p-1;
		else return a - 1;
		break;
	case 2:
		if (a + 1 >= p) return 0;
		else return a + 1;
		break;
	case 3:
		if (b - 1 < 0) return q-1;
		else return b - 1;
		break;
	case 4:
		if (b + 1 >= q) return 0;
		else return b + 1;
		break;
	default:
		break;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{

	int tab[6][5] = {
	{2,0,2,1,1},
	{3,1,2,0,2},
	{1,3,3,1,0},
	{0,2,2,0,2},
	{1,3,3,1,1},
	{2,1,0,2,0}
	};
	int sumaWzorow = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (tab[i][j]==0)
			{
				if ((tab[Index(3,j,i,5,6)][j]==1) &&
					(tab[Index(4,j,i,5,6)][j]==1) &&
					(tab[i][Index(1,j,i,5,6)]==2) &&
					(tab[i][Index(2,j,i,5,6)]==2)){
					sumaWzorow++;
				cout << i << "," << j << " = znaleziono" << endl;
				}else cout << i << "," << j << endl;
			}	
		}
	}
	cout << endl << sumaWzorow << endl;
	system("PAUSE");
	cout << endl;
	return 0;
}

