#include "Bilet.h"

Bilet& Bilet::operator=(const Bilet& b) {
	if (&b != this) {

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
				if (this->randAles != nullptr)
					delete[]this->randAles;
				this->randAles = new int[b.nrLocuriBilet];
				if (this->locRandAles != nullptr)
					delete[]this->locRandAles;
				this->locRandAles = new int[b.nrLocuriBilet];
				this->nrLocuriBilet = b.nrLocuriBilet;
				for (int i = 0; i < b.nrLocuriBilet; i++) {
					this->randAles[i] = b.randAles[i];
					this->locRandAles[i] = b.locRandAles[i];
				}
			}
			
		}

	}

	return *this;
}

Bilet& Bilet::operator++() {

	this->pretFinal++;
	return *this;
}
Bilet Bilet :: operator++(int x)
{
	this->pretFinal++;
	Bilet b = *this;
	return b;

}
Bilet& Bilet::operator--() {
	if (this->pretFinal > 0)
		this->pretFinal--;
	return *this;
}
Bilet Bilet :: operator--(int x)
{
	if (this->pretFinal > 0)
		this->pretFinal--;
	Bilet b = *this;
	return b;

}

ostream& operator<<(ostream& out, Bilet b)
{
	cout << "Id bilet: ";
	out << b.idBilet << endl;
	cout << "Pret bilet: ";
	out << b.pretFinal << endl;
	cout << "Numar persoane: ";
	out << b.nrLocuriBilet << endl;
	if (b.randAles != nullptr && b.locRandAles != nullptr && b.nrLocuriBilet > 0) {
		for (int i = 0; i < b.nrLocuriBilet; i++) {
			cout << i + 1 << "." << endl;
			cout << "Rand: ";
			out << b.randAles[i] << " ";
			cout << "Loc: ";
			out << b.locRandAles[i] << endl;
		}
	}
	out << b.eveniment;
	return out;
}
istream& operator>>(istream& in, Bilet& b) {
	
	cout << "Pret bilet: ";
	in >> b.pretFinal;
	cout<< endl;
	cout << "Numar persoane: ";
	in >> b.nrLocuriBilet;
	cout<< endl;
	if (b.randAles != nullptr && b.locRandAles != nullptr && b.nrLocuriBilet > 0) {
		for (int i = 0; i < b.nrLocuriBilet; i++) {
			cout << i + 1 << "." << endl;
			cout << "Rand: ";
			in >> b.randAles[i];
			cout<< " ";
			cout << "Loc: ";
			in >> b.locRandAles[i];
			cout<< endl;
		}
	}
	in >>b.eveniment;
	return in;
}


int Bilet:: getIdBilet()
{
	return idBilet;
}
float Bilet:: getPretFinal()
{
	return pretFinal;
}
int* Bilet :: getRandAles()
{
	if (randAles != nullptr)
	{
		int* copy = new int[nrLocuriBilet];
		for (int i = 0; i < nrLocuriBilet; i++)
		{
			copy[i] = randAles[i];
		}
		return copy;
	}
	else return nullptr;
}
int* Bilet :: getLocRandAles()
{
	if (locRandAles != nullptr)
	{
		int* copy = new int[nrLocuriBilet];
		for (int i = 0; i < nrLocuriBilet; i++)
		{
			copy[i] = locRandAles[i];
		}
		return copy;
	}
	else return nullptr;


}
int Bilet :: getLocuriBilet()
{
	return nrLocuriBilet;
}
Eveniment Bilet :: getEveniment()
{
	return eveniment;
}


void Bilet::setPretFinal(float p)
{
	if (p > 0)
	{
		pretFinal = p;
	}
	else cout << "Pret invalid"<<endl;
}
void Bilet::setLocuri(int* rand, int* loc, int nr)
{
	if (rand != nullptr && loc != nullptr && nr > 0)
	{
		if (randAles != nullptr)
		{
			delete[] randAles;
		}


		if (locRandAles != nullptr)
		{
			delete[] locRandAles;
		}

		randAles = new int[nr];
		locRandAles = new int[nr];
		nrLocuriBilet = nr;
		for (int i = 0; i < nr; i++)
		{
			randAles[i] = rand[i];
			locRandAles[i] = loc[i];

		}
	}
	else cout << "Date invalide" << endl;
}
void Bilet::setEveniment(Eveniment e) {
	this->eveniment = e;
}


void Bilet :: reducere(int procent)
{
	if (pretFinal == 0&&procent>0&&procent<50)
	{
		pretFinal = eveniment.getPretEveniment() - (eveniment.getPretEveniment() * procent / 100);
		pretFinal = pretFinal * nrLocuriBilet;
	}
	else cout << "Nu se poate acorda reducere" << endl;
}



float Bilet::pretTotalBilet()
{
	if (pretFinal != 0&&nrLocuriBilet>0)
	{
		return pretFinal * nrLocuriBilet;
	}
	else if (nrLocuriBilet > 0&&pretFinal==0)
	{
		return eveniment.getPretEveniment() * nrLocuriBilet;
	}
	else {
		return 0;
	}
}
