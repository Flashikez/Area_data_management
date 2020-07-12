#include "UdajNEZ.h"



UdajNEZ::UdajNEZ(double pSPOLU, double pMUZI, double pZENY)
{
	spoluNEZ = pSPOLU;
	muziNEZ = pMUZI;
	zenyNEZ = pZENY;
}


UdajNEZ::~UdajNEZ()
{
}

void UdajNEZ::vypisINFO()
{
	try {

		std::cout << "\n MUZI: " << muziNEZ << "\n ZENY: " << zenyNEZ << "\n SPOLU: " << spoluNEZ;
	}
	catch (std::exception e) {
		std::cout << "\n\n*********** Tento zaznam nie je vyplneny *****************\n\n";
	}

}

double UdajNEZ::operator[](int muziZenySpolu)
{
	switch (muziZenySpolu)
	{
	case 1:
		return muziNEZ;
		break;
	case 2:
		return zenyNEZ;
		break;
	case 3:
		return spoluNEZ;
		break;

	default:
		return -1;
		break;
	}
}
