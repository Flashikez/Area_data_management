#include "Okres.h"



Okres::Okres(string pNazov)
{
	nazov = pNazov;
	zoznamUCH = new ArrayList<ZaznamUCH*>();
	zoznamNEZ = new ArrayList<ZaznamNEZ*>();
}


Okres::~Okres()
{
	for each (auto var in *zoznamNEZ)
	{
		delete var;
		var = nullptr;
	}
	delete[] zoznamNEZ;
	zoznamNEZ = nullptr;

	for each (auto var in *zoznamUCH)
	{
		delete var;
		var = nullptr;
	}
	delete[] zoznamUCH;
	zoznamUCH = nullptr;
}

void Okres::pridajUCH(ZaznamUCH* pZAZ)
{
	zoznamUCH->add(pZAZ);  // index 0 -rok 2001 , 1-rok 2002 ...
}

void Okres::pridajNEZ(ZaznamNEZ * pZAZ)
{
	zoznamNEZ->add(pZAZ);  // index 0 - MIERA ,1 - EKON.AKT , 2-DISP.P
}

void Okres::vypisNEZ(int pRok, int volba)
{
	cout << "\n\n ------------------------     " << nazov << "      ---------------------------------------- \n\n";
	switch (volba)
	{
	case 1:
		cout << "\n Miera evidovanej nezamestnanosti (%d)";
		break;
	case 2:
		cout << "\n Ekonomicky aktivne obyvatelstvo";
		break;
	case 3:
		cout << "\n Disp.pocet uchadzacov o zamestnanie";
		break;


		
	default:
		break;
	}
	try {
		if (volba == 4) {
			cout << "\n\n *******NEPLATNA VOLBA******** \n\n";
		}
		else {
			if ((*zoznamNEZ)[volba - 1] == nullptr) {
				cout << "\n\n *******ZAZNAM NEEXISTUJE******** \n\n";
			}
			else {

		(*zoznamNEZ)[volba-1]->vypisZAZNAM(pRok);
			}

		}

	}
	catch (exception e) {
		cout << "\n\n *******NEPLATNA VOLBA******** \n\n";
	}

}


void Okres::vypisINFO(int pPocRok, int pKonRok)
{
	// 0 - 2001            
	// 1 - 2002 ...

	int start = pPocRok - 2001; // 2005      4     2001   0
	int koniec = pKonRok- 2001 ; // 2008      7     2016   15

	cout << nazov << "\n\n";
	try {


	for (start; start <= koniec; start++)
	{
		
		(*zoznamUCH)[start]->vypisINFO();
		cout << "\n";

	}
	}
	catch (exception e) {
		cout << "\n Bolo zadane zle rozpatie rokov \n";
	}

}

double Okres::dajHodnotuNEZ(int miera_EKOakt_dispP, int rok, int muzZenaSpolu)
{
	return (*zoznamNEZ)[miera_EKOakt_dispP]->dajHodnotuVRoku_Muz_Zena_Spolu(rok, muzZenaSpolu);
}

double Okres::dajHodnotuUCH(int pRok, int ztpMladAbsDlho)
{
	return (*(*zoznamUCH)[pRok - 2001])[ztpMladAbsDlho];

}

double Okres::dajPriemernyPocetEkoAkt(int startRok, int konRok)
{
	double suma = 0;
	int pocetRokov = konRok - startRok + 1;
	for (startRok; startRok <= konRok; startRok++)
	{
		suma += (*zoznamNEZ)[1]->dajHodnotuVRoku_Muz_Zena_Spolu(startRok, 3);
	}
	return suma / pocetRokov;

	
	

}

double Okres::dajPoklesMuziZeny_Miera(int startRok, int konRok,double & HodnotaZeny)
{


	HodnotaZeny = ((*zoznamNEZ)[0]->dajHodnotuVRoku_Muz_Zena_Spolu(startRok, 2)) - ((*zoznamNEZ)[0]->dajHodnotuVRoku_Muz_Zena_Spolu(konRok, 2));
	return ((*zoznamNEZ)[0]->dajHodnotuVRoku_Muz_Zena_Spolu(startRok, 1)) - ((*zoznamNEZ)[0]->dajHodnotuVRoku_Muz_Zena_Spolu(konRok, 1));



}

double Okres::dajHodnotuNEZ(int index, int rok, double & hodnotaZena)
{
	hodnotaZena = (*zoznamNEZ)[index]->dajHodnotuVRoku_Muz_Zena_Spolu(rok, 2);
	return (*zoznamNEZ)[index]->dajHodnotuVRoku_Muz_Zena_Spolu(rok, 1);


}

double Okres::dajPomer_DispPocet_Absolv(int startRok, int konRok)
{
	
	double sucetPomerov = 0;
	int pocetRokov = konRok - startRok + 1;
	try {

	for (startRok; startRok <= konRok; startRok++)
	{
		double pomer;
		pomer = ((*zoznamNEZ)[2]->dajHodnotuVRoku_Muz_Zena_Spolu(startRok, 3)) / (*(*zoznamUCH)[startRok - 2001])[1];
		sucetPomerov += pomer;
	}
	}
	catch (exception e) {
		cout << "\n********ZLY ROK*********\n";
	}
	return sucetPomerov / pocetRokov;
}





