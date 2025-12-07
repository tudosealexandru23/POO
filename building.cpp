#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cladire
{      
private:

	const int CODUnic;
	char* locatie;
	int nrMateriale;
	float* preturiMateriale;
	static int contor;

public:

	Cladire() : CODUnic(Cladire::contor++)
	{
		this->locatie = nullptr;
		this->nrMateriale = 0;
		this->preturiMateriale = nullptr;
	}

	Cladire(char* locatie, int nrMateriale, float* preturiMateriale) : CODUnic(Cladire::contor++)
	{
		if (locatie != nullptr)
		{
			this->locatie = new char[strlen(locatie) + 1];
			strcpy(this->locatie, locatie);
		}
		else
		{
			this->locatie = nullptr;
		}
		if (preturiMateriale != nullptr)
		{
			this->preturiMateriale = new float[nrMateriale];
			for (int i = 0; i<nrMateriale; i++)
			{
				this->preturiMateriale[i] = preturiMateriale[i];
			}
		}
		else
		{
			this->preturiMateriale = nullptr;
		}
		if (nrMateriale > 0)
		{
			this->nrMateriale = nrMateriale;
		}
		else
		{
			this->nrMateriale = 0;
		}


		

	}
	~Cladire()
	{
		if (this->locatie != nullptr)
			delete[] this->locatie;
		if (this->preturiMateriale != nullptr)
			delete[] this->preturiMateriale;

	}


        const char* get_locatie()
		{
			return this->locatie;
		}



			void set_locatie(char* locatie)
		{
			if (locatie != nullptr)
			{
				this->locatie = new char[strlen(locatie) + 1];
				strcpy(this->locatie, locatie);
			}
		}


		int get_nrMateriale()
		{
			return this->nrMateriale;
		}
		

		int get_CODUnic()
		{
			return this->CODUnic;
		}

		Cladire(const Cladire &a):CODUnic(Cladire::contor++)
		{
			if (a.locatie != nullptr)
			{
				this->locatie = new char[strlen(a.locatie) + 1];
				strcpy(this->locatie, a.locatie);
			}
			else
			{
				this->locatie = nullptr;
			}
			if (a,preturiMateriale != nullptr)
			{
				this->preturiMateriale = new float[a.nrMateriale];
				for (int i = 0; i < a.nrMateriale; i++)
				{
					this->preturiMateriale[i] = a.preturiMateriale[i];
				}
			}
			else
			{
				this->preturiMateriale = nullptr;
			}
			if (a.nrMateriale > 0)
			{
				this->nrMateriale = a.nrMateriale;
			}
			else
			{
				this->nrMateriale = 0;
			}


		}


		Cladire& operator=(const Cladire& a)
		{
			if (this->locatie != nullptr)
			delete[] this->locatie;
		    if (this->preturiMateriale != nullptr)
			delete[] this->preturiMateriale;



			if (a.locatie != nullptr)
			{
				this->locatie = new char[strlen(a.locatie) + 1];
				strcpy(this->locatie, a.locatie);
			}
			else
			{
				this->locatie = nullptr;
			}
			if (a, preturiMateriale != nullptr)
			{
				this->preturiMateriale = new float[a.nrMateriale];
				for (int i = 0; i < a.nrMateriale; i++)
				{
					this->preturiMateriale[i] = a.preturiMateriale[i];
				}
			}
			else
			{
				this->preturiMateriale = nullptr;
			}
			if (a.nrMateriale > 0)
			{
				this->nrMateriale = a.nrMateriale;
			}
			else
			{
				this->nrMateriale = 0;
			}

		}


			int getNrMaterialeIeftine(float valoare)
		{
			int contor = 0;
			for (int i = 0; i < this->nrMateriale; i++)
			{
				if (this->preturiMateriale[i] < valoare)
				{
					contor++;
				}
			}
			return contor;
		}
};
int Cladire::contor = 0;

int main()
{

}