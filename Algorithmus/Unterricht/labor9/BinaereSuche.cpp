/*
 Loesung fuer Labor 9 und 10
 Matrikelnummer: XXX
 */

#include "Studi.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

Studi* BinaereSuche(Studi* a[], int n, char matrikeln[9])
{
    // hier schreiben Sie fertig !
    int head= 0;
    int tail = n-1;
    
    while(head <= tail)
    {
        int mid = (head +tail)/2;
        Studi* temp = a[mid];
        if(strcmp(temp->matrikel, matrikeln)==0)
        {
            cout<<"gleich"<<head<<" und "<<tail<<endl;
            return temp;
        }
        else
        {
            if(strcmp(temp->matrikel, matrikeln)<0)
            {
                cout<<"groesser"<<head<<" und "<<tail<<endl;
                head = mid +1;
            }
            else
            {
                cout<<"kleiner"<<head<<" und "<<tail<<endl;
                tail = mid -1;
            }
        }
    }
    return nullptr;
    
}


