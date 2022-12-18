#include "Client.h"

int  Client::idGenerator = 1;

Client& Client::operator=(const Client& c) {
	if (&c != this) {
		if (c.numeClient != nullptr)
		{
			if (this->numeClient != nullptr)
				delete[]this->numeClient;
			this->numeClient = new char[strlen(c.numeClient) + 1];
			strcpy_s(this->numeClient, strlen(c.numeClient) + 1, c.numeClient);
		}
		



		if (c.prenumeClient != nullptr)
		{
			if (this->prenumeClient != nullptr)
				delete[]this->prenumeClient;
			this->prenumeClient = new char[strlen(c.prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(c.prenumeClient) + 1, c.prenumeClient);
		}


		if (email != nullptr)
		{
			if (this->email != nullptr)
				delete[]this->email;
			this->email = new char[strlen(c.email) + 1];
			strcpy_s(this->email, strlen(c.email) + 1, c.email);
		}

		if (c.nrBilete > 0 && c.bilete != nullptr)
		{
			if (this->bilete != nullptr)
				delete[]this->bilete;
			this->bilete = new Bilet[c.nrBilete];
			this->nrBilete = c.nrBilete;
			for (int i = 0; i < c.nrBilete; i++)
			{
				this->bilete[i] = c.bilete[i];
			}
		}
	}
	return *this;
}
bool Client::operator!() {
	return (nrBilete <= 0);
}
Bilet& Client::operator[](int index)
{
	if (index >= 0 && index < nrBilete && bilete != nullptr)
	{
		return bilete[index];
	}
	throw exception("Invalid index");

}

ostream& operator<<(ostream& out, Client c) {
	
	cout << endl << "ID client: ";
	out << c.idClient;
	if (c.numeClient != nullptr) {
		cout << endl << "Nume client: ";
		out << c.numeClient;
	}
	else {
		cout << endl << "Clientul nu are nume";

	}
	if (c.prenumeClient != nullptr) {
		cout << endl << "Prenume client: ";
		out << c.prenumeClient;
	}else cout << endl << "Clientul nu are prenume ";
	if (c.email != nullptr) {
		cout << endl << "Email client: ";
		out << c.email;
	}
	else cout <<endl<< "Clientul nu are email";
	if (c.nrBilete > 0 && c.bilete != nullptr) {
		cout << endl << "Numarul de bilete: ";
		out << c.nrBilete;
		cout << endl << "Biletele sunt: " << endl;
		for (int i = 0; i < c.nrBilete; i++) {
			out << c.bilete[i] << " ";
		}
	}
	else {
		cout << endl << "Nu exista bilete." << endl;
	}
	return out;
}
istream& operator>>(istream& in, Client& c) {
	
	
	string nume;
		cout << endl << "Nume client: ";
		cin>>nume;
		if (nume.length() > 0)
		{
			if (c.numeClient != nullptr)
			{
				delete[] c.numeClient;

			}
			c.numeClient = new char[nume.length() + 1];
			strcpy_s(c.numeClient, nume.length() + 1, nume.c_str());

		}
		else {
			cout << "Nume invalid" << endl;
		}

		
		cout << endl << "Prenume client: ";
		cin>> nume;
		if (nume.length() > 0)
		{
			if (c.prenumeClient != nullptr)
			{
				delete[] c.prenumeClient;

			}
			c.prenumeClient = new char[nume.length() + 1];
			strcpy_s(c.prenumeClient, nume.length() + 1, nume.c_str());

		}
		else {
			cout << "Prenume invalid" << endl;
		}

		cout << "Email client: ";
		cin >> nume;
		cout << endl;
		if (nume.length() > 0)
		{
			if (c.email != nullptr)
			{
				delete[] c.email;

			}
			c.email = new char[nume.length() + 1];
			strcpy_s(c.email, nume.length() + 1, nume.c_str());

		}
		else {
			cout << "Email invalid" << endl;
		}
	
	if (c.nrBilete > 0 || c.bilete != nullptr) {
		cout << endl << "Numarul de bilete: ";
		in>> c.nrBilete;
		if (c.bilete != nullptr)
		{
			delete[] c.bilete;
		}
		c.bilete = new Bilet[c.nrBilete];
		cout << endl << "Biletele sunt: " << endl;
		for (int i = 0; i < c.nrBilete; i++) {
			in >> c.bilete[i];
				cout<< " ";
		}
	}
	else {
		cout << endl << "Date invalide" << endl;
	}
	return in;
}

int Client::getIdClient() {
	return idClient;
}
const char* Client::getNumeClient() {
	if (numeClient != nullptr) {
		char* copy = new char[strlen(numeClient) + 1];
		strcpy_s(copy, strlen(numeClient) + 1, numeClient);
		return copy;

	}
	else {
		string eroare;
		eroare = "Clientul nu are nume";
		char* er = new char[eroare.length()];
		strcpy_s(er, eroare.length() + 1, eroare.c_str());
		return er;
	}
}
const char* Client::getPrenumeClient() {
	if (prenumeClient != nullptr) {
		char* copy = new char[strlen(prenumeClient) + 1];
		strcpy_s(copy, strlen(prenumeClient) + 1, prenumeClient);
		return copy;

	}
	else {
		string eroare;
		eroare = "Clientul nu are prenume";
		char* er = new char[eroare.length()];
		strcpy_s(er, eroare.length() + 1, eroare.c_str());
		return er;
	}
}
const char* Client::getEmail() {
	if (email != nullptr) {
		char* copy = new char[strlen(email) + 1];
		strcpy_s(copy, strlen(email) + 1, email);
		return copy;

	}
	else {
		string eroare;
		eroare = "Clientul nu are email";
		char* er = new char[eroare.length()];
		strcpy_s(er, eroare.length() + 1, eroare.c_str());
		return er;
	}
}
Bilet* Client::getBilete() {

	Bilet* copy = new Bilet[nrBilete];
	for (int i = 0; i < nrBilete; i++)
	{
		copy[i] = bilete[i];
	}
	return copy;
}
int Client::getNrBilete() {
	return nrBilete;
}


void Client::setNumeClient(char* numeClient) {
	if (numeClient != nullptr) {
		if (this->numeClient != nullptr) {
			delete[]this->numeClient;
		}
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
		
	}else cout << "Date invalide." << endl;
}
void Client::setPreumeClient(char* prenumeClient) {
	if (prenumeClient != nullptr) {
		if (this->prenumeClient != nullptr) {
			delete[]this->prenumeClient;
		}
		this->prenumeClient = new char[strlen(prenumeClient) + 1];
		strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
	}
	else cout << "Date invalide." << endl;
}
void Client::setEmail(char* email) {
	if (email != nullptr) {
		if (this->email != nullptr) {
			delete[]this->email;
		}
		this->email = new char[strlen(email) + 1];
		strcpy_s(this->email, strlen(email) + 1, email);
	}
	else cout << "Date invalide." << endl;
}
void Client::setBilete(Bilet* b, int nr) {
	if (b != nullptr && nr > 0) {
		if (this->bilete != nullptr) {
			delete[]this->bilete;
		}
		this->bilete = new Bilet[nr];
		this->nrBilete = nr;
		for (int i = 0; i < nr; i++) {
			this->bilete[i] = b[i];
		}

	}
	else cout << "Date invalide." << endl;
}


float Client :: pretTotalClient()
{
	float suma = 0;
	if (bilete != nullptr && nrBilete > 0)
	{
		for (int i = 0; i < nrBilete; i++)
		{
			suma += bilete[i].pretTotalBilet();
		}
	}
	return suma;
}



void Client::anulareBilete()
{
	delete[] bilete;
	bilete = nullptr;
	nrBilete = 0;
}


 Client Client:: clientValoareMax(Client* c, int nr)
{
	if (c != nullptr && nr > 0)
	{
		Client cMax;
		for (int i = 0; i < nr; i++)
		{
			if (c[i].pretTotalClient() > cMax.pretTotalClient())
			{
				cMax = c[i];
			}
		}
		return cMax;
	}
	else throw exception("Nu exista un maxim");
}