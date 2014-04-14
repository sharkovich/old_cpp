#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int a[11] = {3,6,2,4,7,5,4,2,6,4,1};
    int b[11]= {3,6,2,4,7,5,4,2,6,4,1};
    int tmp = a[0];
    //aby zmieniæ kierunek tudzie¿ iloœæ elementów
    for (int i = 0 ; i < 11; i+=3){
        b[i] = tmp;
        tmp=a[i];
    } b[0]=tmp;
    for (int i = 0; i < 11; i++){
        printf("%d  ",b[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
