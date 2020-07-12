#pragma once
#include "UdajNEZ.h"
#include "structures\list\array_list.h"
using namespace std;
using namespace structures;
class ZaznamNEZ
{
public:
	ZaznamNEZ();
	~ZaznamNEZ();
	void pridajUDAJ(UdajNEZ* pUDAJ);
	void vypisZAZNAM(int pROK);
	double dajHodnotuVRoku_Muz_Zena_Spolu(int pROK, int muzZenaSpolu);
	
	
	
private:
	ArrayList<UdajNEZ*>* zoznamUDAJNEZ;
};

