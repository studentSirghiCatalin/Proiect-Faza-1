#pragma once
#include<iostream>
#include<string>
#include"Bilet.h"
using namespace std;

class Client
{private:
	const int idClient;
	static int idGenerator;
	char* numeClient;
	char* prenumeClient;
	char* email;
	Bilet* bilete;
	int nrBilete;

public:

	Client():idClient(idGenerator) {
		idGenerator++;
		numeClient = nullptr;
		prenumeClient = nullptr;
		email = nullptr;
		nrBilete = 0;
		bilete = nullptr;
	}

	Client(const char* numeClient,const char* prenumeClient,const char* email,Bilet* bilete,int nrBilete) :idClient(idGenerator) {
		idGenerator++;
		if (numeClient != nullptr)
		{
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
		}
		
			
		else {
			this->numeClient = nullptr;
			}
		
		
		if (prenumeClient != nullptr)
		{
			this->prenumeClient = new char[strlen(prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(prenumeClient) + 1, prenumeClient);
		}
		else this->prenumeClient = nullptr;
		

		if (email != nullptr)
		{
			this->email = new char[strlen(email) + 1];
			strcpy_s(this->email, strlen(email) + 1, email);
		}
		else this->email = nullptr;
		
		if (nrBilete > 0 && bilete != nullptr)
		{
			this->nrBilete = nrBilete;
			this->bilete=new Bilet[nrBilete];

			for (int i = 0; i < nrBilete; i++)
			{
				this->bilete[i] = bilete[i];
			}
		}
		else {
			this->bilete = nullptr;
			this->nrBilete = 0;
		}
		
	}

	Client(const Client& c) :idClient(idGenerator)
	{
		idGenerator++;
		if (c.numeClient != nullptr)
		{
			this->numeClient = new char[strlen(c.numeClient) + 1];
			strcpy_s(this->numeClient, strlen(c.numeClient) + 1, c.numeClient);
		}
		else {
		this->numeClient = nullptr;

		}
		if (c.prenumeClient != nullptr)
		{
			this->prenumeClient = new char[strlen(c.prenumeClient) + 1];
			strcpy_s(this->prenumeClient, strlen(c.prenumeClient) + 1, c.prenumeClient);
		}
		else {
			this->prenumeClient = nullptr;
		}

		if (c.email != nullptr)
		{
			this->email = new char[strlen(c.email)+1];
			strcpy_s(this->email, strlen(c.email) + 1, c.email);
		}
		else {
			this->email = nullptr;
		}
		if (c.nrBilete > 0 && c.bilete != nullptr)
		{
			
			this->bilete = new Bilet[c.nrBilete];
			this->nrBilete = c.nrBilete;
			for (int i = 0; i < c.nrBilete; i++)
			{
				this->bilete[i] = c.bilete[i];
			}
		}
		else
		{
			this->nrBilete = 0;
			this->bilete = nullptr;
		}

	}

	Client& operator=(const Client&);
	bool operator!();
	Bilet& operator[](int index);

	friend ostream& operator<<(ostream&, Client);
	friend istream& operator>>(istream&, Client&);

	int getIdClient();
	const char* getNumeClient();
	const char* getPrenumeClient();
	const char* getEmail();
	Bilet* getBilete();
	int getNrBilete();


	void setNumeClient(char*);
	void setPreumeClient(char*);
	void setEmail(char*);
	void setBilete(Bilet*,int);
	
	float pretTotalClient();
	void anulareBilete();
	static Client clientValoareMax(Client* c,int nr);
};

