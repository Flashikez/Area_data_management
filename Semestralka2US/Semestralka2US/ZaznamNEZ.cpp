#include "ZaznamNEZ.h"



ZaznamNEZ::ZaznamNEZ()
{
	zoznamUDAJNEZ = new ArrayList<UdajNEZ*>();
}


ZaznamNEZ::~ZaznamNEZ()
{
	for each (auto var in *zoznamUDAJNEZ)
	{
		delete var;
		var = nullptr;
	}
	delete[] zoznamUDAJNEZ;
}

void ZaznamNEZ::pridajUDAJ(UdajNEZ * pUDAJ)
{
	zoznamUDAJNEZ->add(pUDAJ);   // index 0 - rok 2001 index 1 - rok 2002 ....
}

void ZaznamNEZ::vypisZAZNAM(int pROK)
{

	try {

	(*zoznamUDAJNEZ)[pROK - 2001]->vypisINFO();
	}
	catch (exception e) {
		cout << "\n\n*******NEPLATNY ROK*******\n\n";
	}


}

double ZaznamNEZ::dajHodnotuVRoku_Muz_Zena_Spolu(int pROK, int muzZenaSpolu)
{



	try {
		return (*(*zoznamUDAJNEZ)[pROK - 2001])[muzZenaSpolu];
	}
	catch (exception e) {
		cout << "\n\n*******NEPLATNY ROK*******\n\n";
		}

	
}



