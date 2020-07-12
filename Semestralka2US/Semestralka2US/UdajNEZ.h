#pragma once
#include <iostream>
class UdajNEZ
{
public:
	UdajNEZ(double pSPOLU,double pMUZI,double pZENY);
	~UdajNEZ();
	void vypisINFO();

	
	
	double operator[](int muziZenySpolu);
private:
	double spoluNEZ;
	double muziNEZ;
	double zenyNEZ;

};

