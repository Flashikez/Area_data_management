#pragma once
#include <iostream>
#include <fstream>
#include "ZaznamUCH.h"
#include "ZaznamNEZ.h"
#include "structures\list\array_list.h"
using namespace std;
using namespace structures;
class Okres
{
public:
	Okres(string pNazov);
	~Okres();
	void pridajUCH(ZaznamUCH* pZAZ);
	void pridajNEZ(ZaznamNEZ* pZAZ);
	void vypisNEZ(int pRok, int volba);
	void vypisINFO(int pPocRok, int pKonRok);
	double dajHodnotuNEZ(int miera_EKOakt_dispP, int rok, int muzZenaSpolu);
	double dajHodnotuUCH(int pRok, int ztpMladAbsDlho);

	double dajPriemernyPocetEkoAkt(int startRok, int konRok);
	double dajPoklesMuziZeny_Miera(int startRok, int konRok, double& HodnotaZeny);
	double dajHodnotuNEZ(int index, int rok, double & hodnotaZena);
	double dajPomer_DispPocet_Absolv(int startRok, int konRok);
	

private:
	string nazov;
	ArrayList<ZaznamUCH*>* zoznamUCH;
	ArrayList <ZaznamNEZ*>* zoznamNEZ;

};

