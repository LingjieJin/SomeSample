#include <iostream>
#include "Studi.h"

using namespace std;

const int groesse=997;

int hashKey(Studi* s)
{
    // hier schreiben Sie fertig
    int hash =0;
    char* key = s->name;
    for(;*key;++key)
    {
        hash = hash*13+*key;
    }
    cout<<"Hash value is "<<hash<<endl;
    return hash%groesse;
}

bool Hinzufuegen(Studi* s, Studi* ht[groesse])
{
    // hier schreiben Sie fertig
    int satz = hashKey(s);
    if(ht[satz] == nullptr)
    {
        ht[satz] = s;
        cout<<"Speichern in Hashtable!"<<satz<<endl;
        return true;
    }
    cout<<"Kollision in Hashtable"<<satz<<endl;

    int insert = (satz +1)%groesse;
    while (insert!=satz)
    {
        if(ht[insert] == nullptr)
        {
            cout<<"Speichern in Hashtable!"<<insert<<endl;
            ht[insert] = s;
            return true;
        }
        cout<<"Kollision in Hashtable"<<insert<<endl;
        insert = (insert+1)%groesse;
    }
    cout<<"nicht genug!"<<endl;
    return false;
}

/*
int main()
{
    Studi* hashtable[groesse];
    for(int i=0;i<groesse;i++){
        hashtable[i]=nullptr;
    }
	Hinzufuegen(new Studi("Anne", "Boleyn", "11234567", 2, 3, 1507), hashtable);
	Hinzufuegen(new Studi("Annika","Biermann", "12345671", 15, 7, 1988), hashtable);
	Hinzufuegen(new Studi("Hans", "Mueller", "12345678", 24, 3, 1988), hashtable);
	Hinzufuegen(new Studi("Eva", "Friese", "17592856", 26, 9, 1989), hashtable);
	Hinzufuegen(new Studi("Chris", "Werbel", "23456711", 18, 3, 1988), hashtable);
	Hinzufuegen(new Studi("Regina", "Haumich", "23456789", 23, 5, 1989), hashtable);
	Hinzufuegen(new Studi("Vera", "Werner", "28561759", 14, 12, 1986), hashtable);
	Hinzufuegen(new Studi("Erich", "Foeller", "34567112", 21, 4, 1988), hashtable);
	Hinzufuegen(new Studi("Gerda", "Heinrich", "45671123", 24, 5, 1988), hashtable);
	Hinzufuegen(new Studi("Albert", "Werndt", "56175928", 20, 11, 1986), hashtable);
	Hinzufuegen(new Studi("Inge", "Juergens", "56711234", 27, 6, 1988), hashtable);
	Hinzufuegen(new Studi("Ralf", "Summs", "59285617", 8, 10, 1987), hashtable);
	Hinzufuegen(new Studi("Christa", "Dietrich", "61759285", 23, 10, 1989), hashtable);
	Hinzufuegen(new Studi("Karl", "Lohmann", "67112345", 30, 7, 1987), hashtable);
	Hinzufuegen(new Studi("Meike", "Neubert", "71123456", 2, 8, 1987), hashtable);
	Hinzufuegen(new Studi("Grit", "Hamann", "71592856", 29, 8, 1989), hashtable);
	Hinzufuegen(new Studi("Ivo", "Wernel", "75192856", 1, 7, 1989), hashtable);
	Hinzufuegen(new Studi("Olaf", "Probst", "75928561", 5, 9, 1987), hashtable);
	Hinzufuegen(new Studi("Xaver", "Wermer", "85617592", 17, 12, 1986), hashtable);
	Hinzufuegen(new Studi("Tine", "Uhlig", "92856175", 11, 11, 1986), hashtable);
    
    for(int i =0;i<groesse;i++)
    {
        if(hashtable[i]!=nullptr)
        {
            Studi* temp = hashtable[i];
            cout<<temp->name<<endl;
        }
    }
    cout<<"endl!"<<endl;
    
    
    
    return 0;
}
 */
