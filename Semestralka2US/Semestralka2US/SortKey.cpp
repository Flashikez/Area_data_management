#include "SortKey.h"
#include <iomanip>



SortKey::SortKey(string pNazov, double pHodnota)
{
	nazovOkresu = pNazov;
	hodnota = pHodnota;
}


SortKey::~SortKey()
{
}

string SortKey::dajData()
{
	string vypis;
	
	if (hodnota - int(hodnota) == 0) { // NEMA DESAT.MIESTO
		vypis = nazovOkresu + "                 " + to_string(int(hodnota)) + "\n";
	}
	else {
		vypis = nazovOkresu + "                 " + to_string(int(hodnota)) + "\n";
	}
	return vypis;
}

bool SortKey::operator>(const SortKey & pravy)
{
	return this->hodnota > pravy.hodnota;
}

bool SortKey::operator<(const SortKey & pravy)
{
	return this->hodnota < pravy.hodnota;
}

bool SortKey::operator==(const SortKey & pravy)
{
	if (nazovOkresu.compare(pravy.nazovOkresu) == 0 && hodnota == pravy.hodnota) {
		return true;
	}
	else {
		return false;
	}
}

double SortKey::getHodnota()
{
	return hodnota;
}

string SortKey::getNazovOkres()
{
	return nazovOkresu;
}

