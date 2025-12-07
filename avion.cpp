#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class BiletAvion
{
private:

	static int tipHartie;
    int numarBilet;
    char* numePasager;
    int durataZbor;
	double* distante;
	int numarSegmente;

public:

	BiletAvion(const char* numePasager,int durataZbor)
	{

		this->numarBilet = 0;
		this->distante = nullptr;
		this->numarSegmente = 0;
		if (numePasager != nullptr)
		{
			this->numePasager = new char[strlen(numePasager) + 1];
			strcpy(this->numePasager, numePasager);
		}
		else
		{
			this->numePasager = nullptr;
		}

		if (durataZbor > 0)
		{
			this->durataZbor = durataZbor;
		}
		else
		{
			this->durataZbor = 0;
		}
	}

	~BiletAvion()
	{
		if (this->numePasager != nullptr)
		{
			delete[] this->numePasager;
			this->numePasager = nullptr;
		}
		if (this->distante != nullptr) {
			delete[] this->distante;
			this->distante = nullptr;
		}
	}


	BiletAvion(const BiletAvion& a)
	{
		numarBilet = a.numarBilet;
		numarSegmente = a.numarSegmente;
		this->distante = new double[a.numarSegmente];
		for (int i = 0; i < this->numarSegmente; i++) {
			this->distante[i] = a.distante[i];
		}
		
		if (a.numePasager != nullptr)
		{
			this->numePasager = new char[strlen(a.numePasager) + 1];
			strcpy(this->numePasager, a.numePasager);
		}
		else
		{
			this->numePasager = nullptr;
		}

		if (a.durataZbor > 0)
		{
			this->durataZbor = a.durataZbor;
		}
		else
		{
			this->durataZbor = 0;
		}
	}


	void setDistante(double* distante, int numarSegmente)
	{
		if (distante != nullptr)
		{
			delete[] this->distante;
			this->numarSegmente = numarSegmente;
			this -> distante = new double[this->numarSegmente];
			for (int i = 0; i < numarSegmente; i++)
			{
				this->distante[i] = distante[i];
			}
		}

	}

	void setnumarSegmente(int numarSegmente)
	{
		if (numarSegmente > 0)
		{
			this->numarSegmente = numarSegmente;
		}
	}
	
	BiletAvion& operator=(const BiletAvion& a)
	{
		if (this != &a)
		{
			if (this->numePasager != nullptr)
			{
				delete[] this->numePasager;
				this->numePasager = nullptr;
			}

			if (this->distante != nullptr) {
				delete[] this->distante;
				this->distante = nullptr;
			}

			numarBilet = a.numarBilet;
			numarSegmente = a.numarSegmente;
			this->distante = new double[a.numarSegmente];
			for (int i = 0; i < this->numarSegmente; i++) {
				this->distante[i] = a.distante[i];
			}
			
			if (a.numePasager != nullptr)
			{
				this->numePasager = new char[strlen(a.numePasager) + 1];
				strcpy(this->numePasager, a.numePasager);
			}
			else
			{
				this->numePasager = nullptr;
			}

			if (a.durataZbor > 0)
			{
				this->durataZbor = a.durataZbor;
			}
			else
			{
				this->durataZbor = 0;
			}
		}
		return *this;
	}
};

int BiletAvion::tipHartie = 0;


int main()
{
	BiletAvion a("bucuresti-cluj", 8); //constr cu param

	BiletAvion b(a); //constr de copiere

	BiletAvion c("cluj-bucuresti", 10); // constr cu param

	b = c; //op de atribuire

	double vector[] = { 1,2,3 };

	a.setnumarSegmente(2); //set numar seg 
	b.setDistante(vector, 3); // set dist
}