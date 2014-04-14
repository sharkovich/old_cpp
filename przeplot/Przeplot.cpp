// Przeplot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdio>



int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Ile rzêdów danych chcesz wpisaæ?\n";
	int n;
	std::cin>> n;
	std::cout << "Ile danych chcesz wpisaæw rzêdzie?\n";
	int m;
	std::cin >> m;

	int **dane = new int*[n];

	for (int i = 0; i < n; i++)
	{
		dane[i] = new int[m];
		std::cout << "Podaj dane dla " << i <<". rzedu" << std::endl;
		for (int j = 0; j < m; j++)
		{
			std::cin >> dane[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j  < m; j ++)
		{
			std::cout << dane[i][j] << " ";
		}
	}
	std::cout << "Co chcesz zrobiæ?\n1. - przeplot\n2. - reprzeplot;p\n";
	int wybor;
	do{
		std::cin >> wybor;
	}while ((wybor != 1) && (wybor != 2));
	switch (wybor)
	{
	case 1:
		std::cout << std::endl << std::endl << "Przeplot:" << std::endl;
		for (int j = 0; j < m; j++)
		{
			std::cout << std::endl;
			for (int i = 0; i < n; i++)
			{
				std::cout << dane[i][j] << " ";
			}
		}
		break;
	case 2:
		std::cout << std::endl << std::endl << "Deprzeplot:" << std::endl;
		for (int j = 0; j < m; j++)
		{
			std::cout << std::endl;
			for (int i = 0; i < n; i++)
			{
				std::cout << dane[i][j] << " ";
			}
		}
	default:
		break;
	}

	std::cout << std::endl;
	system("PAUSE");
	return 0;
}

