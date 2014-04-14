#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;


void PrintMatrix (int **tab, int a, int b) {
    for (int i = 0; i < a; i++){
        printf("\n");
        for (int j = 0; j < b; j++){
            printf("%d \t",tab[i][j]);
        }
    }
}

int main()
{
    printf("--------- Menu ---------\n"
           "1. Transpozycja macierzy\n"
           "2. Suma/roznica macierzy\n"
           "3. Iloczyn macierzy\n"
           "Wybierz opcje:");
    int wybor;
    cin>>wybor;
    printf("\n");
    srand(time(NULL));
    int a = 3;
    int b = 4;
    int **tab = new int *[a];
    for (int i = 0; i < a; i++){
        tab[i] = new int [b];
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            tab[i][j] = rand()%10;
        }
    }
    PrintMatrix(tab,a,b);
    int a2 = 3;
    int b2 = 5;
    int **tab2 = new int *[a2];
    for (int i = 0; i < a2; i++){
        tab2[i] = new int [b2];
    }
    for (int i = 0; i < a2; i++){
        for (int j = 0; j < b2; j++){
            tab2[i][j] = rand()%10;
        }
    }

    printf("\nMacierz2:");
    PrintMatrix(tab2,a2,b2);

    switch(wybor){
        case 1:{
            int **tabt = new int *[b];
            for (int i = 0; i < b; i++){
                tabt[i] = new int [a];
            }
            for (int i = 0; i < a; i++){
                for (int j = 0; j < b; j++){
                    tabt[j][i] = tab[i][j];
                }
            }
            printf("\nMacierz AT");
            PrintMatrix(tabt,b,a);
            break;
        }
        case 2:{
            if ((a!=a2) && (b!=b2)){
                printf("\nNie da sie dodac/odjac tych macierzy!");
            } else {
                int **tab3 = new int *[b];
                for (int i = 0; i < b; i++){
                    tab3[i] = new int [a];
                }
                for (int i = 0; i < a; i++){
                    for (int j = 0; j < b; j++){
                        tab3[i][j] = tab[i][j]+tab2[i][j];
                    }
                }
                printf("\nMacierz3:");
                PrintMatrix(tab3,a,b);
            } break;
        }
        case 3:{
            if (b!=a2){
                printf("\nNie da sie pomnozyc tych macierzy!");
            } else {
                int **tab3 = new int *[a];
                for (int i = 0; i < a; i++){
                    tab3[i] = new int [b2];
                }
                for (int i = 0; i < a; i++){
                    for (int j = 0; j < b2; j++){
                        tab3[i][j] = 0;
                    }
                }
                for (int i = 0; i < a; i++){
                    for (int j = 0; j < b2; j++){
                        for (int k = 0; k < b; k++){
                            tab3[i][j] += tab[i][k] * tab2[k][j];
                        }
                    }
                }

                printf("\nMacierz2:");
                PrintMatrix(tab3,a,b);
            }break;
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
