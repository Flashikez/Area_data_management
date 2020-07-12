#pragma once
#include "Okres.h"
#include "Kraj.h"
#include "structures\table\hash_table.h"
#include "structures\table\sorted_sequence_table.h"
#include "structures\table\unsorted_sequence_table.h"
#include "SortKey.h"

#include "structures\table\sorting\heap_sort.h"
using namespace std;
using namespace structures;
class citac
	
{
	
public:
	void citaj();
	void vyhladajPodlaNazvuOKR(string pOkres,int pPocRok,int pKonRok);  // Zadanie 1
	void zobrazSTATNEZ(string pOKres, int pROK, int pVOLBA);
	citac();
	~citac();
	void vypisZoradene(int rok, int muzZena, int mieraDISP, int ascDesc);  // Zadanie 2
	void vypisNajlepsiNajhorsiOKRES(int pVolba, int pPocRok, int pKonRok);
	void vypisNajlepsiNajhorsiKRAJ(int pVolba, int pPocRok, int pKonRok);
	void vytvorKraje();
	void zobrazSumarnePreKraj(string nazovKraja, int startRok, int konRok);
	void zoradKrajePodlaKriterii(int pRok, int pMuzZena, int pMierDISP, int ascDesc);

private:
	HashTable<string, Okres*>* okresyTAB;
	HashTable<string, Kraj*>* krajeTAB;

};

