#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

void PrintTab (int **tab, int a, int b) {
    for (int i = 0; i < a; i++){
        printf("\n");
        for (int j = 0; j < b; j++){
            printf("%d \t",tab[i][j]);
        }
    }
}
void PrintTab (int *tab, int a){
    for (int i = 0; i < a; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}


void BubbleSort(int *tab, int a){
    bool c = false;
    int tmp;
    do{
        c = false;
        for (int i = a-2; i >= 0; i--){
            if (tab[i]>tab[i+1]){
                tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
                c = true;
            }
        }
    }while(c);
}
void BubbleSortReverse(int *tab, int a){
    bool c = false;
    int tmp;
    do{
        c = false;
        for (int i = 1; i < a; i++){
            if (tab[i]>tab[i-1]){
                tmp = tab[i];
                tab[i] = tab[i-1];
                tab[i-1] = tmp;
                c = true;
            }
        }
    }while(c);
}
//void QuickSort


int main()
{
    int tab[] = {5,3,7,2,8,2,1,7,2};
    PrintTab(tab,9);
    BubbleSortReverse(tab,9);
    printf("\n");
    PrintTab(tab,9);
    return 0;
}
