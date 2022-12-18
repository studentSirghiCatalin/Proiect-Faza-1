#include "Eveniment.h"


Eveniment& Eveniment::operator=(const Eveniment& Eveniment) {
	if (this != &Eveniment) {

		this->numeEveniment = Eveniment.numeEveniment;
		this->locatieEveniment = Eveniment.locatieEveniment;
		if (strlen(Eveniment.dataEveniment) == 8) {
			strcpy_s(this->dataEveniment, 9, Eveniment.dataEveniment);
		}
		if (strlen(Eveniment.oraEveniment) == 5) {
			strcpy_s(this->oraEveniment, 6, Eveniment.oraEveniment);
		}
		this->pretEveniment = Eveniment.pretEveniment;

		if (Eveniment.nrRanduri > 0 && Eveniment.nrLocuriRand > 0 && Eveniment.locuri != nullptr) {
			if (this->locuri != nullptr) {
				for (int i = 0; i < this->nrRanduri; i++)
				{
					delete[] this->locuri[i];

				}
				delete[] this->locuri;
			}
			this->nrRanduri = Eveniment.nrRanduri;
			this->nrLocuriRand = Eveniment.nrLocuriRand;
			this->locuri = new int* [Eveniment.nrRanduri];
			for (int i = 0; i < Eveniment.nrRanduri; i++) {
				this->locuri[i] = new int[Eveniment.nrLocuriRand];
			}
			for (int i = 0; i < Eveniment.nrRanduri; i++) {
				for (int j = 0; j < Eveniment.nrLocuriRand; j++) {
					this->locuri[i][j] = Eveniment.locuri[i][j];
				}
			}
		}


	}
	return*this;

}
Eveniment::operator string () {

	string detaliiEveniment;
	detaliiEveniment = numeEveniment + "\n" + locatieEveniment + "\n";
	if (dataEveniment != nullptr) {
		detaliiEveniment = detaliiEveniment+dataEveniment + "\n";
	}
	else detaliiEveniment = detaliiEveniment+"Data nu a fost stabilita" + "\n";
	if (oraEveniment != nullptr) {
		detaliiEveniment = detaliiEveniment + oraEveniment + "\n";
	}
	else detaliiEveniment = detaliiEveniment + "Ora nu a fost stabilita" + "\n";
	return detaliiEveniment;
}
bool Eveniment::operator<(Eveniment e) {
	if (this->pretEveniment < e.pretEveniment) return 1;
	return 0;
}
bool Eveniment::operator>(Eveniment e) {
	if (this->pretEveniment > e.pretEveniment) return 1;
	return 0;
}



ostream& operator<<(ostream& out, Eveniment e) {
	cout << endl << "Numele evenimentului: ";
	out << e.numeEveniment;
	cout << endl << "Locatia evenimentului: ";
	out << e.locatieEveniment;
	cout << endl << "Data evenimentului: ";
	out << e.dataEveniment;
	cout << endl << "Ora evenimentului: ";
	out << e.oraEveniment;
	cout << endl << "Pretul evenimentului:";
	out << e.pretEveniment;
	cout << endl << "Numarul de randuri ale evenimentului: ";
	out << e.nrRanduri;
	cout << endl << "Numarul de locuri ale evenimentului: ";
	out << e.nrLocuriRand;
	if (e.locuri != nullptr&&e.nrRanduri>0&&e.nrLocuriRand>0) {
		
		cout << endl << "Locurile sunt: " << endl;
		for (int i = 0; i < e.nrRanduri; i++) {
			for (int j = 0; j < e.nrLocuriRand; j++) {
				out << e.locuri[i][j] << " ";
			}
			cout << endl;
		}
	}
	return out;
}
istream& operator>>(istream& in, Eveniment& e) {
	cout << endl << "Numele evenimentului: ";
	in >> e.numeEveniment;
	cout << endl << "Locatia evenimentului: ";
	in >> e.locatieEveniment;
	cout << endl << "Data evenimentului: ";
	in >> e.dataEveniment;
	cout << endl << "Ora evenimentului: ";
	in >> e.oraEveniment;
	cout << endl << "Pretul evenimentului:";
	in >> e.pretEveniment;
	cout << endl << "Numarul de randuri ale evenimentului: ";
	in >> e.nrRanduri;
	cout << endl << "Numarul de locuri ale evenimentului: ";
	in >> e.nrLocuriRand;
	if (e.nrRanduri > 0 && e.nrLocuriRand > 0) {
		if (e.locuri != nullptr) {
			for (int i = 0; i < e.nrRanduri; i++)
			{
				delete[] e.locuri[i];

			}
			delete[]e.locuri;


		}
		e.locuri = new int* [e.nrRanduri];
		for (int i = 0; i < e.nrRanduri; i++) {
			e.locuri[i] = new int[e.nrLocuriRand];
		}

		for (int i = 0; i < e.nrRanduri; i++) {
			for (int j = 0; j < e.nrLocuriRand; j++) {
				e.locuri[i][j] = 0;

			}

		}
	}
	else if (e.locuri != nullptr)
	{
		for (int i = 0; i < e.nrRanduri; i++)
		{
			delete[] e.locuri[i];

		}
		delete[]e.locuri;
		e.locuri = nullptr;
	}
	return in;
}


string Eveniment::getNumeEveniment() {
	return numeEveniment;
}
string Eveniment::getLocatieEveniment() {
	return locatieEveniment;
}
const char* Eveniment::getDataEveniment() {
	if (dataEveniment!=nullptr) {
		char* copy = new char[11];
		strcpy_s(copy, 11, dataEveniment);
		return copy;
	}
	else
	{
		char* copy = new char[1];
		strcpy_s(copy, 1, "");
		return copy;
	}
	

}
const char* Eveniment::getOraEveniment() {
	if (oraEveniment != nullptr) {
		char* copy = new char[11];
		strcpy_s(copy, 11, oraEveniment);
		return copy;
	}
	else
	{
		char* copy = new char[1];
		strcpy_s(copy, 1, "");
		return copy;
	}
}
float Eveniment::getPretEveniment() {
	return pretEveniment;
}
int Eveniment::getNrRanduri() {
	return nrRanduri;
}
int Eveniment::getNrLocuriRand() {
	return nrLocuriRand;
}
int** Eveniment::getLocuri() {
	if (locuri != nullptr && nrRanduri > 0 && nrLocuriRand > 0) {
		int** copy = new int* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++) {
			copy[i] = new int[nrLocuriRand];
		}

		for (int i = 0; i < nrRanduri; i++) {
			for (int j = 0; j < nrLocuriRand; j++) {
				copy[i][j] = locuri[i][j];
			}
		}
		return copy;
	}

	else
		throw exception("Locurile nu sunt disponibile");
}

void Eveniment::setNumeEveniment(string s)
{
	if (s != "")
	{
		numeEveniment = s;
	}
	else cout << "Nume nevalid" << endl;
}
void Eveniment::setLocatieEveniment(string s){

	if (s != "")
	{
		locatieEveniment = s;
	}
	else cout << "Locatie nevalida" << endl;
}
void Eveniment::setDataEveniment(const char* data) {
	if (data != nullptr && strlen(data) == 10) {
		strcpy_s(this->dataEveniment, strlen(data) + 1, data);
	}
	else cout << "Data invalida" << endl;
}
void Eveniment::setOraEveniment(const char* ora) {
	if (ora != nullptr && strlen(ora) == 10) {
		strcpy_s(this->oraEveniment, strlen(ora) + 1, ora);
	}
	else cout << "Ora invalida" << endl;
}
void Eveniment::setPretEveniment(float pret) {
	if (pret > 0) {
		pretEveniment = pret;
	}
	else cout << "Pret invalid" << endl;
}
void Eveniment::setLocuri(int** locuri,int nrRanduri,int nrLocuriRand) {
	if (locuri != nullptr && nrRanduri > 0 && nrLocuriRand > 0) {
		if (this->locuri != nullptr) {
			for (int i = 0; i < this->nrRanduri; i++)
			{
				delete[] this->locuri[i];

			}
			delete[] this->locuri;
		}
		this->nrRanduri = nrRanduri;
		this->nrLocuriRand = nrLocuriRand;
		this->locuri = new int* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++) {
			this->locuri[i] = new int[nrLocuriRand];
		}
		for (int i = 0; i < nrRanduri; i++) {
			for (int j = 0; j < nrLocuriRand; j++) {
				this->locuri[i][j] = locuri[i][j];
			}
		}
	}
	else cout << "Locuri invalide" << endl;
}

int Eveniment::capacitateMaxima()
{
	if (nrLocuriRand > 0 && nrRanduri > 0)
	{
		return nrLocuriRand * nrRanduri;
	}
	
	return 0;
}

int Eveniment :: nrLocuriOcupate()
{
	int suma = 0;
	if (nrRanduri > 0 && nrLocuriRand > 0 && locuri)
	{
		
		for (int i = 0; i < nrRanduri; i++)
		{
			for (int j = 0; j < nrLocuriRand;j++)
			{
				if (locuri[i][j] != 0)

				{
					suma++;
				}
			}
		}
	}
	return suma;
}
