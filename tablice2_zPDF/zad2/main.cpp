#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;



int main()
{
    cout << "Punkt a:" << endl;
    int a[5][5];
    int tmp = 1;
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            a[i][j]=tmp++;
        }
    }


    for (int i=0;i<5;i++){
        cout<<endl;
        for (int j=0;j<5;j++){
            cout<<a[i][j]<<" ";
        }
    }

    cout <<endl<<endl<<"Punkt b:" << endl;

     for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            a[i][j]=(i+j)%2;
        }
    }
    for (int i=0;i<5;i++){
        cout<<endl;
        for (int j=0;j<5;j++){
            cout<<a[i][j]<<" ";
        }
    }
    cout <<endl<<endl<<"Punkt c:" << endl;

     for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            a[i][j]=(j-i);
        }
    }
    for (int i=0;i<5;i++){
        cout<<endl;
        for (int j=0;j<5;j++){
            cout<<a[i][j]<<" ";
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
