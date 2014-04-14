// TabGen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>

#include <stdio.h>
#include <time.h>



using namespace std;

void PrintTab (int **tab, int a, int b, int c) {
	cout << "+";
	for (int i = 0; i < b; i++)
	{
		if (i+1!=b){
			cout << "------";		
		}else{
			cout << "-----";
		}
	}
	cout << "+";
    for (int i = 0; i < a; i++){
        cout << endl << "|";
        for (int j = 0; j < b; j++){
            cout<< setw(c) << tab[i][j] << "|";

        }
    }
	cout << endl << "+";
	for (int i = 0; i < b; i++)
	{
		if (i+1!=b){
			cout << "------";		
		}
		else{
			cout << "-----";
		}
	}
	cout << "+" << endl;
}


//metoda na sprawdzenie czy dany element znaduje siê w tablicy
bool CheckTable (int **tab, int a, int b,int value) {

    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if (tab[i][j]==value){
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int a,b;
    printf("Podaj wymiary tablicy\n"
           "n:");
    cin>>a;
    printf("m:");
    cin>>b;
    srand(time(NULL));
    //generowanie tablicy dynamicznej
    int **tab = new int *[a];
    for (int i = 0; i < a; i++){
        tab[i] = new int [b];
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            tab[i][j] = 0;
        }
    }

    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            do{
                int tmp = rand()%999+1;
                if (!CheckTable(tab,a,b,tmp)) tab[i][j]=tmp;
            }while(tab[i][j]==0);
        }
    }


    PrintTab(tab,a,b,5);
    printf("\n");

    printf("\n");
    system("pause");
    return 0;
}
