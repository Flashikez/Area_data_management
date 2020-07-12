#pragma once
#include <iostream>
#include <sstream>

using namespace std;
class SortKey
{
public:
	SortKey(string pNazov,double pHodnota);
	~SortKey();
	string dajData();
	bool operator>(const SortKey& pravy);
	bool operator<(const SortKey& pravy);
	bool operator==(const SortKey& pravy);
	double getHodnota();
	string getNazovOkres();

private:
	string nazovOkresu;
	double hodnota;
	
};

