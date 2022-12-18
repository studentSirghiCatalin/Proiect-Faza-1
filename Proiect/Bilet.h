#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include"Eveniment.h"
using namespace std;

class Bilet
{
private:
	const int idBilet;
	float pretFinal;
	int* randAles;
	int* locRandAles;
	int nrLocuriBilet;
	Eveniment eveniment;

public:

	Bilet():idBilet(rand())
	{
		pretFinal = 0;
		randAles = nullptr;
		locRandAles = nullptr;
		nrLocuriBilet = 0;
	
	}

	Bilet(float pretFinal, int* randAles, int* locRandAles, int nrLocuriBilet,Eveniment eveniment) :idBilet(rand()) {
		
		this->pretFinal = pretFinal;
		this->eveniment = eveniment;
		if (randAles != nullptr&&locRandAles!=nullptr&&nrLocuriBilet>0) {
			bool verif = true;

			for (int i = 0; i < nrLocuriBilet; i++) {
				if (randAles[i] < 0 || locRandAles[i] < 0) {
					verif = false;
				}
				
			}
			if (verif == true) {
				this->randAles = new int[nrLocuriBilet];
				this->locRandAles = new int[nrLocuriBilet];
				this->nrLocuriBilet = nrLocuriBilet;
				for (int i = 0; i < nrLocuriBilet; i++) {
					this->randAles[i] = randAles[i];
					this->locRandAles[i] = locRandAles[i];
				}
			}
			else {
				this->randAles = nullptr;
				this->locRandAles = nullptr;
				this->nrLocuriBilet = 0;
			}
		}
		else {
			this->randAles = nullptr;
			this->locRandAles = nullptr;
			this->nrLocuriBilet = 0;
		}
	}

	Bilet(const Bilet& b):idBilet(rand()) {
		
		this->pretFinal = b.pretFinal;
		this->eveniment = b.eveniment;
		if (b.randAles != nullptr && b.locRandAles != nullptr && b.nrLocuriBilet > 0) {
			bool verif = true;

			for (int i = 0; i < b.nrLocuriBilet; i++) {
				if (b.randAles[i] < 0 || b.locRandAles[i] < 0) {
					verif = false;
				}

			}
			if (verif == true) {
				this->randAles = new int[b.nrLocuriBilet];
				this->locRandAles = new int[b.nrLocuriBilet];
				this->nrLocuriBilet = b.nrLocuriBilet;
				for (int i = 0; i < b.nrLocuriBilet; i++) {
					this->randAles[i] = b.randAles[i];
					this->locRandAles[i] = b.locRandAles[i];
				}
			}
			else {
				this->randAles = nullptr;
				this->locRandAles = nullptr;
				this->nrLocuriBilet = 0;
			}
		}
		else {
			this->randAles = nullptr;
			this->locRandAles = nullptr;
			this->nrLocuriBilet = 0;
		}

	}

	~Bilet() {

		if (randAles != nullptr) {
			delete[]randAles;
		}
		if (locRandAles != nullptr) {
			delete[]locRandAles;
		}
	}

	Bilet& operator=(const Bilet&);


	Bilet& operator++();
	Bilet operator++(int x);

	Bilet& operator--();
	Bilet operator--(int x);
	

	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
	
	int getIdBilet();
	float getPretFinal();
	int* getRandAles();
	int* getLocRandAles();
	int getLocuriBilet();
	Eveniment getEveniment();

	void setPretFinal(float);
	void setLocuri(int*,int*,int );
	void setEveniment(Eveniment);
	
	void reducere(int procent);
	float pretTotalBilet();
	
};

