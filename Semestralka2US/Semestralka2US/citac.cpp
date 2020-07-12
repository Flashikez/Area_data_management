#include "citac.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#define POCET_RIADKOV_UCHADZACI 79
#define POCET_RIADKOV_MIERA 237
#define POCET_ROKOV 16
#define INDEX_KONIEC_BRATISLAVSKY 8
#define INDEX_KONIEC_TRNAVA 15
#define INDEX_KONIEC_TRENCIN 24
#define INDEX_KONIEC_NITRA 31
#define INDEX_KONIEC_ZILINA 42
#define INDEX_KONIEC_BANSKAB 55
#define INDEX_KONIEC_PRESOV 68
#define INDEX_KONIEC_KOSICE 79




void citac::citaj()
{
	ifstream in("./csv/Uchádzaèi o zamestnanie.csv");
	string okres;
	int pocetDlhoDob;
	int pocetZTP;
	int pocetABS;
	int pocetMLAD;
	string slovo;
	int rok;
	int pocetNacitanychOkresov = 0;
	vytvorKraje();

	if (in.is_open()) {

		in.ignore();		// prve 2 riadky nepotrebne
		getline(in, slovo);
		in.ignore();
		getline(in, slovo);
		for (int i = 0; i < POCET_RIADKOV_UCHADZACI; i++)
		{
			rok = 2001;
			getline(in, slovo, ';');
			okres = slovo;
			Okres *novyOkres = new Okres(okres);
			pocetNacitanychOkresov++;
			for (int j = 0; j < POCET_ROKOV; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (j == POCET_ROKOV - 1 && k == 3) {
						getline(in, slovo, '\n');
					}
					else {
						getline(in, slovo, ';');
					}
					switch (k)
					{
					case 0: {
						pocetZTP = stoi(slovo);
						break;
					}
					case 1: {
						pocetABS = stoi(slovo);
						break;
					}
					case 2: {
						pocetMLAD = stoi(slovo);
						break;
					}
					case 3: {
						pocetDlhoDob = stoi(slovo);
						break;
					}
					default:
						break;
					}

				}
				ZaznamUCH* novyZaznamUCH = new ZaznamUCH(pocetZTP, pocetABS, pocetMLAD, pocetDlhoDob, rok);
				novyOkres->pridajUCH(novyZaznamUCH);
				rok++;
			}
			okresyTAB->insert(okres, novyOkres);
			if (pocetNacitanychOkresov <= INDEX_KONIEC_BRATISLAVSKY) {
				(*krajeTAB)["Bratislavskì"]->pridajOkres(novyOkres);
			}
			else if (pocetNacitanychOkresov > INDEX_KONIEC_BRATISLAVSKY && pocetNacitanychOkresov <= INDEX_KONIEC_TRNAVA) {
				(*krajeTAB)["Trnavskì"]->pridajOkres(novyOkres);
			}
			else if (pocetNacitanychOkresov > INDEX_KONIEC_TRNAVA && pocetNacitanychOkresov <= INDEX_KONIEC_TRENCIN) {
				(*krajeTAB)["TrenŸiansky"]->pridajOkres(novyOkres);
			}
			 else if (pocetNacitanychOkresov > INDEX_KONIEC_TRENCIN && pocetNacitanychOkresov <= INDEX_KONIEC_NITRA) {
				(*krajeTAB)["Nitriansky"]->pridajOkres(novyOkres);
			}
			 else  if (pocetNacitanychOkresov > INDEX_KONIEC_NITRA && pocetNacitanychOkresov <= INDEX_KONIEC_ZILINA) {
				(*krajeTAB)["¦ilinskì"]->pridajOkres(novyOkres);
			}
			 else  if (pocetNacitanychOkresov > INDEX_KONIEC_ZILINA && pocetNacitanychOkresov <= INDEX_KONIEC_BANSKAB) {
				(*krajeTAB)["Banskobystrickì"]->pridajOkres(novyOkres);
			}
			 else  if (pocetNacitanychOkresov > INDEX_KONIEC_BANSKAB && pocetNacitanychOkresov <= INDEX_KONIEC_PRESOV) {
				(*krajeTAB)["Preçovskì"]->pridajOkres(novyOkres);
			}
			 else  if (pocetNacitanychOkresov > INDEX_KONIEC_PRESOV && pocetNacitanychOkresov <= INDEX_KONIEC_KOSICE){
				(*krajeTAB)["Koçickì"]->pridajOkres(novyOkres);
			}








		}
	}

	in.close();
	

	ifstream in2("./csv/Miera evidovanej nezamestnanosti.csv");
	double pocMUZI;
	double pocZENY;
	double pocSPOLU;
	string slovo2;
	string okres2;
	Okres* vyhlOKRES;
	ZaznamNEZ* novyZAZ;

	if (in2.is_open()) {

		in2.ignore();		// prve 2 riadky nepotrebne
		getline(in2, slovo2);
		in2.ignore();
		getline(in2, slovo2);

		for (int i = 0; i < POCET_RIADKOV_MIERA; i++)
		{
			if (i % 3 == 0) {
				getline(in2, slovo2, ';');
				okres2 = slovo2;
				try {

				vyhlOKRES = (*okresyTAB)[okres2];
				}
				catch (exception e) {
					cout << okres2 << endl;
				}

			}
			else {
				getline(in2, slovo2, ';');
			}

			getline(in2, slovo2, ';');
			novyZAZ = new ZaznamNEZ();
			for (int j = 0; j < POCET_ROKOV; j++)
			{
				 
				UdajNEZ* novyUDAJ;
				for (int k = 0; k < 3; k++)
				{
					if (j == POCET_ROKOV - 1 && k == 2) {
						getline(in2, slovo2, '\n');
					}
					else {
						getline(in2, slovo2, ';');
					}

					switch (k)
					{
					case 0: {
						pocSPOLU = stod(slovo2);
						break;
					}
					case 1: {
						pocMUZI = stod(slovo2);
						break;
					}
					case 2: {
						pocZENY = stod(slovo2);
						break;
					}
					default:
						break;
					}

				}
				novyUDAJ = new UdajNEZ(pocSPOLU, pocMUZI, pocZENY);
				novyZAZ->pridajUDAJ(novyUDAJ);
				

			}
			vyhlOKRES->pridajNEZ(novyZAZ);
		}




	}
	in2.close();







	
}

void citac::vyhladajPodlaNazvuOKR(string pOkres,int pPocRok, int pKonRok)
{
	try {

		(*okresyTAB)[pOkres]->vypisINFO(pPocRok, pKonRok);
	}
	catch (exception e) {

		cout << "\n Okres so zadanym nazvom sa v databaze nenachadza \n";
	}


}

void citac::zobrazSTATNEZ(string pOKres, int pROK, int pVOLBA)
{
	try {
		
		(*okresyTAB)[pOKres]->vypisNEZ(pROK, pVOLBA);
	}
	catch (exception e) {

		cout << "\n Okres so zadanym nazvom sa v databaze nenachadza \n";
	}


}

citac::citac()
{
	okresyTAB = new HashTable<string, Okres*>();
	krajeTAB = new HashTable<string, Kraj*>();
	citaj();
}


citac::~citac()
{
	for each (auto var in *okresyTAB)
	{
		
		delete var->accessData();
	}
	
	delete[] okresyTAB;

	for each (auto var in *krajeTAB)
	{
		delete var->accessData();
	}
	delete[] krajeTAB;



}

void citac::vypisZoradene(int rok, int muzZena, int mieraDISP,int ascDesc)
{
	if (mieraDISP == 1) {
		mieraDISP--;
	}
	UnsortedSequenceTable <SortKey, string>* tabulka = new UnsortedSequenceTable<SortKey, string>();
	for each (auto var in *okresyTAB)
	{
		SortKey novy(var->getKey(), var->accessData()->dajHodnotuNEZ(mieraDISP, rok, muzZena));
		tabulka->insert(novy, var->getKey());
	}
	HeapSort<SortKey, string>* bob = new HeapSort<SortKey, string>();
	bob->sort(*tabulka);
	
	stringstream vypis;
	string vypisString;
	cout << "\n*******************************************************\n\n";
	for each (auto var in *tabulka)
	{
		if (ascDesc == 1) {
			vypis.str("");
			vypis << setw(26) << var->accessData() << "   "<< setw(30) << var->getKey().getHodnota() << "\n";
			vypisString = vypisString + vypis.str();
		}
		else {
			vypis.str("");
			vypis << setw(26) << var->accessData() << "   " << setw(30) << var->getKey().getHodnota() << "\n";
			vypisString = vypis.str() + vypisString;
		}
	}
	cout << vypisString;
	delete tabulka;
	delete bob;




}

void citac::vypisNajlepsiNajhorsiOKRES(int pVolba, int pPocRok, int pKonRok)
{
		

		double najvacsi;
		double najmensi;
	switch (pVolba)
	{
	case 1: {
		string nazovNajvacsieho;
		string nazovNajmensieho;
		double najvacsi = INTMAX_MIN;
		double najmensi = INTMAX_MAX;

		for each (auto var in *okresyTAB)
		{
			double hodnota = var->accessData()->dajPriemernyPocetEkoAkt(pPocRok, pKonRok);
			if (hodnota > najvacsi) {
				nazovNajvacsieho = var->getKey();
				najvacsi = hodnota;
			}
			if (hodnota < najmensi) {
				nazovNajmensieho = var->getKey();
				najmensi = hodnota;
			}
		}
		cout << "\n*******************************\n   Najvacsi priemerny pocet ekonomicky akt.ludi mal  " << nazovNajvacsieho  << " s hodnotou: " << najvacsi;
		cout << "\n  Najmensi priemerny pocet ekonomicky akt.ludi mal " << nazovNajmensieho  << " s hodnotou: " << najmensi;
		break;
	}
	case 2: {
		string nazovMuzi;
		string nazovZeny;
		double najvacsiMuzi = INTMAX_MIN;
		double najvacsiZeny = INTMAX_MIN;
		for each (auto var in *okresyTAB)
		{
			double hodnota_zeny;
			double hodnota = var->accessData()->dajPoklesMuziZeny_Miera(pPocRok, pKonRok, hodnota_zeny);
			if (hodnota > najvacsiMuzi) {
				nazovMuzi = var->getKey();
				najvacsiMuzi = hodnota;
			}
			if (hodnota_zeny > najvacsiZeny) {
				nazovZeny = var->getKey();
				najvacsiZeny = hodnota_zeny;
			}
		}
		cout << "\n*******************************\n (MUZI)  Najvacsi pokles miery evidovanej nezamestnanosti za sledovane obdobie mal:  " << nazovMuzi << " s hodnotou : " << najvacsiMuzi;
		cout << "\n\n (ZENY) Najvacsi pokles miery evidovanej nezamestnanosti za sledovane obdobie mal:  " << nazovZeny << " s hodnotou : " << najvacsiZeny;
		break;
	}
	case 3: {
		double najvacsi = INTMAX_MIN;
		string nazovNajvacsi;
		for each (auto var in *okresyTAB)
		{
			double hodnota = var->accessData()->dajPomer_DispPocet_Absolv(pPocRok, pKonRok);
			if (hodnota > najvacsi) {
				nazovNajvacsi = var->getKey();
				najvacsi = hodnota;
			}

		}
		cout << "\n*******************************\n  Najvacsi pomer (DISP.pocet uchadzacov / pocet absolventov) za dane obdobie ma :  " << nazovNajvacsi << " s hodnotou : " << najvacsi;
		break;
	}
	default: {
		cout << "\n*******ZLA VOLBA********\n";
		return;
		break;
		}
	}
}

void citac::vypisNajlepsiNajhorsiKRAJ(int pVolba, int pPocRok, int pKonRok)
{


	switch (pVolba)
	{
	case 1: {
		string nazovNajvacsieho;
		string nazovNajmensieho;
		double najvacsi = INTMAX_MIN;
		double najmensi = INTMAX_MAX;

		for each (auto var in *krajeTAB)
		{
			double hodnota = var->accessData()->dajSUMPriemernyPocetEkoAkt(pPocRok, pKonRok);
			if (hodnota > najvacsi) {
				nazovNajvacsieho = var->getKey();
				najvacsi = hodnota;
			}
			if (hodnota < najmensi) {
				nazovNajmensieho = var->getKey();
				najmensi = hodnota;
			}
		}
			cout << "\n*******************************\n   Najvacsi priemerny pocet ekonomicky akt.ludi mal  " << nazovNajvacsieho << " kraj " << " s hodnotou: " << najvacsi;
			cout << "\n  Najmensi priemerny pocet ekonomicky akt.ludi mal " << nazovNajmensieho << " kraj " << " s hodnotou: " << najmensi;
			break;
	}
	case 2: {
		string nazovMuzi;
		string nazovZeny;
		double najvacsiMuzi = INTMAX_MIN;
		double najvacsiZeny = INTMAX_MIN;
		for each (auto var in *krajeTAB)
		{
			double hodnota_zeny;
			double hodnota = var->accessData()->dajSUMNajvacsiPoklesMuziZeny(pPocRok, pKonRok, hodnota_zeny);
			if (hodnota > najvacsiMuzi) {
				nazovMuzi = var->getKey();
				najvacsiMuzi = hodnota;
			}
			if (hodnota_zeny > najvacsiZeny) {
				nazovZeny = var->getKey();
				najvacsiZeny = hodnota_zeny;
			}
		}
		cout << "\n*******************************\n (MUZI)  Najvacsi pokles miery evidovanej nezamestnanosti za sledovane obdobie mal:  " << nazovMuzi << " kraj " << " s hodnotou : " << najvacsiMuzi;
		cout << "\n\n (ZENY) Najvacsi pokles miery evidovanej nezamestnanosti za sledovane obdobie mal:  " << nazovZeny << " kraj " << " s hodnotou : " << najvacsiZeny;
		break;
	}
	case 3: {
		double najvacsi = INTMAX_MIN;
		string nazovNajvacsi;
		for each (auto var in *krajeTAB)
		{
		  double hodnota =  var->accessData()->dajSUMPomer_DispPocet_Absolv(pPocRok, pKonRok);
		  if (hodnota > najvacsi) {
			  nazovNajvacsi = var->getKey();
			  najvacsi = hodnota;
			}

		}
		cout << "\n*******************************\n  Najvacsi pomer (DISP.pocet uchadzacov / pocet absolventov) za dane obdobie ma :  " << nazovNajvacsi << " kraj " <<" s hodnotou : " << najvacsi;
		break;
	}



	default: {

		cout << "\n*******ZLA VOLBA********\n";
		return;
		break;
	}

	}





}

void citac::vytvorKraje()
{
	Kraj* bratislavsky = new Kraj();
	krajeTAB->insert("Bratislavskì", bratislavsky);
	Kraj* trnavsky = new Kraj();
	krajeTAB->insert("Trnavskì", trnavsky);
	Kraj* tn = new Kraj();
	krajeTAB->insert("TrenŸiansky", tn);
	Kraj* nit = new Kraj();
	krajeTAB->insert("Nitriansky", nit);
	Kraj* za = new Kraj();
	krajeTAB->insert("¦ilinskì", za);
	Kraj* bb = new Kraj();
	krajeTAB->insert("Banskobystrickì", bb);
	Kraj* pr = new Kraj();
	krajeTAB->insert("Preçovskì", pr);
	Kraj* ke = new Kraj();
	krajeTAB->insert("Koçickì", ke);

}



void citac::zobrazSumarnePreKraj(string nazovKraja, int startRok, int konRok)
{

	try {
		cout << "\n************************* \n  " << nazovKraja << " kraj:  ";
		(*krajeTAB)[nazovKraja]->vypisSumarne_UCH_vRokoch(startRok, konRok);
	}
	catch (exception e) {
		cout << "\n\n*************Kraj s tymto nazvom neexistuje****************\n\n";

	}

	



}

void citac::zoradKrajePodlaKriterii(int pRok, int pMuzZena, int pMierDISP, int ascDesc)
{

	UnsortedSequenceTable <SortKey, string>* tabulka = new UnsortedSequenceTable<SortKey, string>();
	for each (auto var in *krajeTAB)
	{
		SortKey novy(var->getKey(), var->accessData()->dajHodnotuNEZ(pMierDISP, pRok, pMuzZena));
		tabulka->insert(novy, var->getKey());
	}
	HeapSort<SortKey, string>* bob = new HeapSort<SortKey, string>();
	bob->sort(*tabulka);

	stringstream vypis;
	string vypisString;
	cout << "\n*******************************************************\n\n";
	for each (auto var in *tabulka)
	{
		if (ascDesc == 1) {
			vypis.str("");
			vypis << setw(26) << var->accessData() << "   " << setw(30) << var->getKey().getHodnota() << "\n";
			vypisString = vypisString + vypis.str();
		}
		else {
			vypis.str("");
			vypis << setw(26) << var->accessData() << "   " << setw(30) << var->getKey().getHodnota() << "\n";
			vypisString = vypis.str() + vypisString;
		}
	}
	cout << vypisString;
	delete tabulka;
	delete bob;



}

