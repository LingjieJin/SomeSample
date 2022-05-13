#include "Studi.h"
#include <iostream>
#include <string.h>

using namespace std;

Studi::Studi(char* n,char* v,char matri[],int t,int m,int j)
{
	//cout << "Hallo, das ist Konstruktor" << endl;
	name = new char[strlen(n) + 1];
	for (int i = 0; i < strlen(n) +1; i++) {
		name[i] = n[i];
	}
	vorname = new char[strlen(v) + 1];
	for (int i = 0; i < strlen(v) +1; i++) {
		vorname[i] = v[i];
	}
	for (int i = 0; i < 9; i++) {
		matrikel[i] = matri[i];
	}
	tag = t;
	monat = m;
	jahr = j;
}


Studi::~Studi()
{
	cout << "Tschuess, das ist Destruktor" << endl;
}

void Studi::Ausgeben()
{
    cout << name << " " << vorname << " Geburtstag:" << tag << "." << monat << "." << jahr << " Matrikelnum:" << matrikel << endl;
}

bool kleiner(Studi* s1, Studi* s2)
{
	if(strcmp(s1->matrikel, s2->matrikel)<0)
    {
        cout << s1->name<< " ist kleiner als "<<s2->name<<endl;
        return true;
    }
    else
    {
        cout << s1->name<< " ist groesser als "<<s2->name<<endl;
        return false;
    }
}
