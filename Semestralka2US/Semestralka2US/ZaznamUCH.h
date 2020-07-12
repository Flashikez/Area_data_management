#pragma once
#include <iostream>
class ZaznamUCH
{
public:

	ZaznamUCH(int pZTP, int pABS, int pMLAD, int pDLHO,int pRok);
	~ZaznamUCH();
	void vypisINFO();
	int operator[](int index);

	int getABS();
	int getZTP();
	int getMLAD();
	int getDLHO();
private:

	int pocetZTP;
	int pocetABS;
	int pocetMLAD;
	int pocetDLHO;
	int rok;
};

