#include "ZaznamUCH.h"



ZaznamUCH::ZaznamUCH(int pZTP,int pABS, int pMLAD, int pDLHO,int pRok)
{
	pocetABS = pABS;
	pocetDLHO = pDLHO;
	pocetMLAD = pMLAD;
	pocetZTP = pZTP;
	rok = pRok;
}


ZaznamUCH::~ZaznamUCH()
{
}



void ZaznamUCH::vypisINFO()
{
	
	std::cout <<"ROK:  "<< rok <<   "  Pocet ZTP: " << pocetZTP << " Pocet Absolventov: " << pocetABS << "  Pocet Mladistvych: " << pocetMLAD << "  Pocet Dlhodobo: " << pocetDLHO;
}

int ZaznamUCH::operator[](int index)
{
	switch (index)
	{
	case 0: {
		return pocetZTP;
		break;
	}
	case 1: {
		return pocetABS;
		break;
	}
	case 2: {
		return pocetMLAD;
		break;
	}
	case 3: {
		return pocetDLHO;
		break;
	}

	default:
		return -1;
		break;
	}
}

int ZaznamUCH::getABS()
{
	return pocetABS;
}

int ZaznamUCH::getZTP()
{
	return pocetZTP;
}

int ZaznamUCH::getMLAD()
{
	return pocetMLAD;
}

int ZaznamUCH::getDLHO()
{
	return pocetDLHO;
}
