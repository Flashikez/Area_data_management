#pragma once
#include "structures\list\array_list.h"
#include "Okres.h"
using namespace structures;
using namespace std;

class Kraj
{
public:
	Kraj();
	~Kraj();
	void pridajOkres(Okres* pOkres);
	void vypisSumarne_UCH_vRokoch(int startRok, int konRok);


	double dajHodnotuNEZ(int mieraDISP, int pRok, int muzZena);
	double dajSUMPriemernyPocetEkoAkt(int pPocRok, int pKonRok);
	double dajSUMNajvacsiPoklesMuziZeny(int pPocRok, int pKonRok, double& hodnotaZeny);
	double dajSUMPomer_DispPocet_Absolv(int pPocRok, int pKonRok);
private:
	ArrayList<Okres*>* zoznamOKRESOV;

};

