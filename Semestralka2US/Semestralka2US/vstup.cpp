#include "vstup.h"



vstup::vstup()
{
	cita = new citac();
}


vstup::~vstup()
{
	delete cita;
}

void vstup::cykluj()
{
	int volba;
	string nazovOkresu;
	string nazovKraju;
	int pocRok;
	int konRok;
	int muzZena;
	int mierDISP;
	int ascDesc;
	int volba3;
	while (1) {
		vypisMenu();
		
		cout << "\n Volba:  ";
		cin >> volba;
		cin.ignore();
		switch (volba)
		{
		case 1: {
			cout << "\nZadaj nazov okresu napr. ''Bratislava I''     :";

			getline(cin, nazovOkresu);

			cout << "\nZadaj pociatocny rok     :";

			cin >> pocRok;
			cout << "\nZadaj konecny rok     :";

			cin >> konRok;
			cout << "\n\n";

			nazovOkresu.insert(0, "Okres ");

			cita->vyhladajPodlaNazvuOKR(nazovOkresu, pocRok, konRok);

			break;
		}

		case 2: {
			cout << "\nZadaj nazov okresu napr. ''Bratislava I''     :";

			getline(cin, nazovOkresu);
			cout << "\nZadaj pociatocny rok     : ";

			cin >> pocRok;
			cout << "\nMiera(1) , EKO.AKT(2),DISP.POCET(3)    : ";
			int volba2;
			cin >> volba2;
			nazovOkresu.insert(0, "Okres ");
			cita->zobrazSTATNEZ(nazovOkresu, pocRok, volba2);
			break;
		}

		case 3: {
			cout << "\nZadaj rok     : ";
			cin >> pocRok;
			 cout << "\n MUZI(1) ZENY(2)    : ";
			 cin >> muzZena;
			 cout << "\n MIERA(1) DISP.POCET(2)    : ";
			 cin >> mierDISP;
			 cout << "\n ASCENDING(1) DESCENDING(2) : ";
			 cin >> ascDesc;
			 cita->vypisZoradene(pocRok, muzZena, mierDISP,ascDesc);
			break;
		}	
		case 4:{
			cout << "\n1. Najvacsi a najmensi priemerny pocet ekon.akt obyvatelstva";
			cout << "\n2. Najvacsi pokles miery evidovanej nezamestnanosti pre muzov a zeny";
			cout << "\n3. Najlepsi pomer medzi disp.poctom uchadzacov a poctom uchadzacov absolventov \n";
			cout << "Volba:  ";
			cin >> volba3;
			cout << "\nZadaj pociatocny rok : ";
			cin >> pocRok;
			cout << "\nZadaj konecny rok :";
			cin >> konRok;
			cita->vypisNajlepsiNajhorsiOKRES(volba3, pocRok, konRok);


			break;
		}
			  
		case 5: {

			cout << "\nZadaj nazov kraja napr. ''Bratislavskì''     :";

			getline(cin, nazovKraju);

			cout << "\nZadaj pociatocny rok     :";

			cin >> pocRok;
			cout << "\nZadaj konecny rok     :";

			cin >> konRok;
			cout << "\n\n";

			cita->zobrazSumarnePreKraj(nazovKraju, pocRok, konRok);
		}

			break;
		case 6: {
			cout << "\nZadaj rok     : ";
			cin >> pocRok;
			cout << "\n MUZI(1) ZENY(2)    : ";
			cin >> muzZena;
			cout << "\n MIERA(1) DISP.POCET(2)    : ";
			cin >> mierDISP;
			cout << "\n ASCENDING(1) DESCENDING(2) : ";
			cin >> ascDesc;
			cita->zoradKrajePodlaKriterii(pocRok, muzZena, mierDISP, ascDesc);
			break;




		}
		case 7: {
			cout << "\n1. Najvacsi a najmensi priemerny pocet ekon.akt obyvatelstva";
			cout << "\n2. Najvacsi pokles miery evidovanej nezamestnanosti pre muzov a zeny";
			cout << "\n3. Najlepsi pomer medzi disp.poctom uchadzacov a poctom uchadzacov absolventov \n";
			cout << "Volba:  ";
			cin >> volba3;
			cout << "\nZadaj pociatocny rok : ";
			cin >> pocRok;
			cout << "\nZadaj konecny rok :";
			cin >> konRok;
			cita->vypisNajlepsiNajhorsiKRAJ(volba3, pocRok, konRok);


			break;
		}
		case 8:
		
			return;
		default:
			break;
		}




	}







}

void vstup::vypisMenu()
{
	printf("\n\n*************************************************\n\n1. (Zadanie 1.) Vyhladaj okres podla nazvu \n"
		"2.Miera nezamestnanosti \n"
		"3. (Zadanie 2.) Zoradenie okresov v danom roku ( Miera evid.nezamenstn / disp.pocet uchadzacov, Muzi/Zeny ) \n"
		"4. (Zadanie 3.) Vyhladanie okresov s najvacsim/najmensim udajom \n"
		"5. (Zadanie 4.) Vyhladanie kraja + sumarne statistiky \n"
		"6. (Zadanie 5.) Zoradenie krajov v danom roku (SUM miera evid.nezamestn / sum disp.pocet uchadzacov, Muzi/Zeny \n"
		"7. (Zadanie 6.) Vyhladanie kraja s najvacsim/najmensim udajom \n"
		"8.Ukonci\n"
	);

}
