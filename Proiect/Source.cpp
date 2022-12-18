#include<iostream>
#include"Client.h"
#include"Bilet.h"
#include"Eveniment.h"
using namespace std;


int main() {
	
	Eveniment e1;
	int** locuri = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		locuri[i] = new int[3];
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
		
			{
				locuri[i][j] = (i+j)%2;
			}
		}

	Eveniment e2("event", "Buc", "01.01.2023", "16:30", 19, 3, 3, locuri);
	e1 = e2;
	Eveniment e3 = e2;
	cout << e2;
	//cin >> e1;
	cout<<e2.getDataEveniment()<<endl;
	
	try {
		locuri = e2.getLocuri();
			
		
		
	}
	catch (exception e) {
		cout << e.what()<<endl;
	}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
		
			{
				cout << locuri[i][j] << " ";
			}
		cout << endl;
		}

	Eveniment nul;
	nul.setNumeEveniment("nume");
	cout << nul << endl;

	Bilet b1;
	Bilet b2;

	int n[]{ 2,3,4 };
	int m[]{ 1,3,2 };

	Bilet b3( 5,n, m, 3,e2);
	Bilet b4 = b3;

	b4 = b1;
	cout << b4;
	cout << b3;

	int* v = new int[3];
	v = b4.getLocRandAles();
	for (int i = 0; i < b4.getLocuriBilet(); i++)
	{
		cout << v[i] << endl;
	}

	cout << b2<<endl;
	b2.setLocuri(m, n, 3);
	cout << b2<<endl;
	b2.setEveniment(e1);
	cout << b2 << endl;

	
	char* nume = new char[5];
	Bilet* bilete = new Bilet[2];
	bilete[0] = b1;
	bilete[1] = b3;
	strcpy_s(nume, 5, "nume");
	Client c2(nume,nume,nume,bilete,2);
	Client c1 = c2;
	Client c3;
	c3 = c1;
	cout << c3<<endl;
	//cin >> c3;
	cout << c3<<endl;
	Bilet* b = new Bilet[2];
	b=c2.getBilete();
	for (int i = 0; i < 2; i++)
	{
		cout << b[i] << endl;
	}
	cout << b2<<endl;
	b2++;
	cout << b2<<endl;
	b2--;
	cout << b2<<endl;
	Client null;
	cout<<!null<<endl;


	cout << c2 << endl;
	cout << endl;

	try {
		cout << c2[3]<<endl;

	}
	catch (exception e) {
		cout << e.what()<<endl;
	}

	cout<<(string)e1;
	
	cout << (e1 < e2) << endl;
	e2.setPretEveniment(10);
	cout << (e1 > e2) << endl;

	cout << e2.capacitateMaxima()<<endl;
	cout << e2.nrLocuriOcupate() << endl;
	cout << b2.pretTotalBilet() << endl;
	cout << c2.pretTotalClient() << endl;
	/*c2.anulareBilete();*/
	cout << c2<<endl;
	Client* c = new Client[3];
	c[0] = c1;
	c[1] = c2;
	c[2] = c3;

	try
	{
		cout << (Client::clientValoareMax(c, 3)) << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	Bilet b5(13, n, m, 3, e2);
	bilete[0] = b5;
	Client C(nume,nume,nume,bilete,2);
	c[2] = C;
	cout << C.pretTotalClient() << endl;
	cout << c1.pretTotalClient() << endl;
	cout << c2.pretTotalClient() << endl;
	cout << c3.pretTotalClient() << endl;

	try
	{
		cout << (Client::clientValoareMax(c, 3)) << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
	
	cout<<bilete[0].pretTotalBilet();
	
	
}