#include "Kraj.h"



Kraj::Kraj()
{
	zoznamOKRESOV = new ArrayList<Okres*>();
}


Kraj::~Kraj()
{
	delete[] zoznamOKRESOV;
}

void Kraj::pridajOkres(Okres* pOkres)
{
	(zoznamOKRESOV)->add(pOkres);
}

void Kraj::vypisSumarne_UCH_vRokoch(int startRok, int konRok)
{

		for (int i = startRok ; i<= konRok; i++)
		{
			double spoluZTP = 0;
			double spoluABS = 0;
			double spoluMLAD = 0;
			double spoluDLHO = 0;

			for each (auto var in *zoznamOKRESOV)
			{
				spoluZTP += var->dajHodnotuUCH(i, 0);
				spoluABS += var->dajHodnotuUCH(i, 1);
				spoluMLAD += var->dajHodnotuUCH(i, 2);
				spoluDLHO += var->dajHodnotuUCH(i, 3);
			}
			cout << "\n\n " << i << "\n*******\n  ZTP: " << spoluZTP << "\n  Absolventi: " << spoluABS << "\n  Mladistvi: " << spoluMLAD << "\n  Dlhodobo nezamestnani: " << spoluDLHO;
		}
		
	
}




double Kraj::dajHodnotuNEZ(int mieraDISP, int pRok, int muzZena)
{
	double sumaDISP = 0;
	double sumaEKOAKT = 0;
	double suma2 = 0;
	double hodnota;
	double hodnota2;
	
		for each (auto var in *zoznamOKRESOV)
		{
			hodnota = var->dajHodnotuNEZ(2, pRok, muzZena); // 2-> index Disp.poctu v okrese
			sumaDISP += hodnota;
			hodnota2 = var->dajHodnotuNEZ(1, pRok, muzZena); // 1-> index EkoAkt v okrese
			sumaEKOAKT += hodnota2;
		}
		if (mieraDISP == 1) {
			return 100*(sumaDISP / sumaEKOAKT); // %
		}
		else {
			return sumaDISP;
		}
}

double Kraj::dajSUMPriemernyPocetEkoAkt(int pPocRok, int pKonRok)
{
	double sumaEkoAKT = 0;
	int pocetRokov = pKonRok - pPocRok + 1;
	for each (auto var in *zoznamOKRESOV)
	{
		for (int i = pPocRok ; i <= pKonRok; i++)
		{
			sumaEkoAKT += var->dajHodnotuNEZ(1, i, 3);
		}
	}

	return sumaEkoAKT / pocetRokov;
}

double Kraj::dajSUMNajvacsiPoklesMuziZeny(int pPocRok, int pKonRok, double & hodnotaZeny)
{
	double HornaSumaMuzi = 0;
	double HornaSumaZeny = 0;
	double DolnaSumaMuzi = 0;
	double DolnaSumaZeny = 0;
	for each (auto var in *zoznamOKRESOV)
	{
		hodnotaZeny = 0;
		 HornaSumaMuzi +=var->dajHodnotuNEZ(0, pKonRok, hodnotaZeny);
		 HornaSumaZeny += hodnotaZeny;
		 hodnotaZeny = 0;
		 DolnaSumaMuzi += var->dajHodnotuNEZ(0, pPocRok, hodnotaZeny);
		 DolnaSumaZeny += hodnotaZeny;
	}
	hodnotaZeny = DolnaSumaZeny - HornaSumaZeny;
	return DolnaSumaMuzi - HornaSumaMuzi;

}

double Kraj::dajSUMPomer_DispPocet_Absolv(int pPocRok, int pKonRok)
{
	
	double suma = 0;
	for each (auto var in *zoznamOKRESOV)
	{
		suma += var->dajPomer_DispPocet_Absolv(pPocRok, pKonRok);


	}
	return suma / zoznamOKRESOV->size();




}
