#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;
enum TKierunek {prawo=1, dol, lewo, gora};
int main()
{
    int tab1[3][3];

    srand(time(NULL));
    for (int i = 0; i<3;i++){
        for (int j = 0; j<3; j++){
            tab1[i][j]=rand()%10;
            if(tab1[i][j]%2==0)
                cout<<tab1[i][j]<<"       "<<i<<" "<<j<<"  - element parzysty"<<endl;
                //printf("Wartoœæ elementu: %d \t Indeksy: [&d][%d]", tab1[i][j],i,j);
            if((i+j)%2!=0)
                cout<<tab1[i][j]<<"       "<<i<<" "<<j<<"  - suma indeksow nieparzysta"<<endl;
        }
    }
    cout<<endl;
    for (int i = 0; i<3;i++){
        cout<<endl;
        for (int j = 0; j<3; j++){
        cout<<tab1[i][j]<<" ";
        }
    }


    printf("\n");
    system("pause");
    return 0;
}
