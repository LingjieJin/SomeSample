#include "Studi.h"
#include <iostream>
#include <cstring>

using namespace std;

Studi* BinaereSuche(Studi* a[], int n, char matrikeln[9]);

/*
int main() {

	Studi* v[20];
	v[0]=new Studi("Anne", "Boleyn", "11234567", 2, 3, 1507);
	v[1]=new Studi("Annika", "Biermann", "12345671", 15, 7, 1988);
	v[2]=new Studi("Hans", "Mueller", "12345678", 24, 3, 1988);
	v[3]=new Studi("Eva", "Friese", "17592856", 26, 9, 1989);
	v[4]=new Studi("Chris", "Diebel", "23456711", 18, 3, 1988);
	v[5]=new Studi("Regina", "Haumich", "23456789", 23, 5, 1989);
	v[6]=new Studi("Vera", "Werner", "28561759", 14, 12, 1986);
	v[7]=new Studi("Erich", "Foeller", "34567112", 21, 4, 1988);
	v[8]=new Studi("Gerda", "Heinrich", "45671123", 24, 5, 1988);
	v[9]=new Studi("Albert", "Berndt", "56175928", 20, 11, 1986);
	v[10]=new Studi("Inge", "Juergens", "56711234", 27, 6, 1988);
	v[11]=new Studi("Ralf", "Summs", "59285617", 8, 10, 1987);
	v[12]=new Studi("Christa", "Dietrich", "61759285", 23, 10, 1989);
	v[13]=new Studi("Karl", "Lohmann", "67112345", 30, 7, 1987);
	v[14]=new Studi("Meike", "Neubert", "71123456", 2, 8, 1987);
	v[15]=new Studi("Grit", "Hamann", "71592856", 29, 8, 1989);
	v[16]=new Studi("Ivo", "Jeckel", "75192856", 1, 7, 1989);
	v[17]=new Studi("Olaf", "Probst", "75928561", 5, 9, 1987);
	v[18]=new Studi("Xaver", "Ziemer", "85617592", 17, 12, 1986);
	v[19]=new Studi("Tine", "Uhlig", "92856175", 11, 11, 1986);
	v[19]=new Studi("Tine", "Uhlig", "92856175", 11, 11, 1986);

    Studi* gesucht;
    gesucht = BinaereSuche(v,20,"92856175");
    if(gesucht != nullptr)
        gesucht->Ausgeben();
    // hier können Sie weitere Tests schreiben



	return 0;
}
 */
