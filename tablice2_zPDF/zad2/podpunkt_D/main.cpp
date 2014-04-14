#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

using namespace std;


void ZmienKierunek (int *kier){
    if (*kier==4) *kier=1;
    else *kier=*kier+1;
    return;
}
void Nastepne (int *i,int *j, int *kk){
     switch (*kk){
     case 1: *i=*i+1;  break;
     case 2: *j=*j+1;  break;
     case 3: *i=*i-1;  break;
     case 4: *j=*j-1;  break;
     }
return;
}

void Poprzednie (int *i,int *j, int *kk){
     switch (*kk){
     case 1: *i=*i-1; break;
     case 2: *j=*j-1; break;
     case 3: *i=*i+1; break;
     case 4: *j=*j+1; break;
     }
return;
}


int main()
{
    int kierunek;
    kierunek = 1;
    int i,j,k;

    int tab[5][5];
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            tab[i][j]=0;
        }
    }


    i=-1;j=0;
    for (k=1;k<=25;k++){

        Nastepne(&i,&j,&kierunek);
        if (i>4 || j>4 || i<0 || j<0){
            Poprzednie(&i,&j,&kierunek);
            ZmienKierunek(&kierunek);
            Nastepne(&i,&j,&kierunek);
        }else if (tab[i][j]!=0){
            Poprzednie(&i,&j,&kierunek);
            ZmienKierunek(&kierunek);
            Nastepne(&i,&j,&kierunek);
        }
        tab[i][j]=k;
    }

    for (i=0;i<5;i++){
        cout<<endl;
            for (j=0;j<5;j++){
            printf("%d \t",tab[j][i]);
            }
    }

    printf("\n");
    system("pause");
    return 0;
}
