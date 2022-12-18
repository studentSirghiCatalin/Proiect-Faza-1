#pragma once
#include<iostream>
#include<string>
using namespace std;

class Eveniment
{
private:
	string numeEveniment;
	string locatieEveniment;
	char dataEveniment[11];
	char oraEveniment[6];
	float pretEveniment;
	int nrRanduri;
	int nrLocuriRand;
	int** locuri;

public:
	Eveniment() {
		numeEveniment = "-";
		locatieEveniment = "-";
		strcpy_s(dataEveniment, 11, "00.00.0000");
		strcpy_s(oraEveniment, 6, "99:99");
		pretEveniment = 0;
		nrRanduri = 0;
		nrLocuriRand = 0;
		locuri = nullptr;
	}

	Eveniment(string numeEveniment, string locatieEveniment, const char dataEveniment[11], const char oraEveniment[6], float pret, int nrRanduri, int nrLocuriRand, int** locuri) :Eveniment() {
		this->numeEveniment = numeEveniment;
		this->locatieEveniment = locatieEveniment;
		if (dataEveniment != nullptr&&strlen(dataEveniment)==10) {
			strcpy_s(this->dataEveniment, 11, dataEveniment);
		}
		if (oraEveniment != nullptr&&strlen(oraEveniment)==5) {
			strcpy_s(this->oraEveniment, 6, oraEveniment);
		}
		this->pretEveniment = pret;
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

	Eveniment(const Eveniment& Eveniment) {
		this->numeEveniment = Eveniment.numeEveniment;
		this->locatieEveniment = Eveniment.locatieEveniment;
		strcpy_s(this->dataEveniment, 11, Eveniment.dataEveniment);
		strcpy_s(this->oraEveniment, 6, Eveniment.oraEveniment);
		this->pretEveniment = Eveniment.pretEveniment;
		this->nrRanduri = Eveniment.nrRanduri;
		this->nrLocuriRand = Eveniment.nrLocuriRand;
		if (Eveniment.locuri != nullptr) {

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

	~Eveniment() {

		if (locuri != nullptr) {
			if (nrRanduri > 0) {
				for (int i = 0; i < this->nrRanduri; i++)
				{
					delete[] this->locuri[i];

				}
				delete[] this->locuri;
			}

		}
	}




	Eveniment& operator=(const Eveniment&);


	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);


	explicit operator string ();
	bool operator<(Eveniment e);
	bool operator>(Eveniment e);


	string getNumeEveniment();
	string getLocatieEveniment();
	const char* getDataEveniment();
	const char* getOraEveniment();
	float getPretEveniment();
	int getNrRanduri();
	int getNrLocuriRand();
	int** getLocuri();

	void setNumeEveniment(string);
	void setLocatieEveniment(string);
	void setDataEveniment(const char*);
	void setOraEveniment(const char*);
	void setPretEveniment(float);
	void setLocuri(int**,int,int);

	int capacitateMaxima();
	int nrLocuriOcupate();
};

