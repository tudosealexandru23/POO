#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Examen {

private:

	char* disciplina;
	int data;
	int nota;
	static int contor;
	const int idExamen;

public:

	Examen() : idExamen(Examen::contor++)
	{
		this->disciplina = nullptr;
		this->nota = 0;
		this->data = 0;

	}

	Examen(char* disciplina, int data, int nota) : idExamen(Examen::contor++)
	{
		if (disciplina != nullptr)
		{
			this->disciplina = new char[strlen(disciplina) + 1];
			this->disciplina = disciplina;

		}
		else
		{
			this->disciplina = nullptr;
		}
		this->nota = nota;
		this->data = data;
	}

	Examen(const Examen& c) : idExamen(Examen::contor++)
	{
		if (c.disciplina != nullptr)
		{
			this->disciplina = new char[strlen(c.disciplina) + 1];
			this->disciplina = c.disciplina;

		}
		else
		{
			this->disciplina = nullptr;
		}
		this->nota = c.nota;
		this->data = c.data;
	}

	~Examen()
	{
		if (this->disciplina != nullptr)
		{
			delete[] this->disciplina;
			this->disciplina = nullptr;
		}
	}


	friend ostream& operator<<(ostream& out, const Examen& a);



	Examen& operator=(const Examen& c)
	{
		if (this != &c)
		{
			if (this->disciplina != nullptr)
			{
				delete[] this->disciplina;
				this->disciplina = nullptr;
			}

			if (c.disciplina != nullptr)
			{
				this->disciplina = new char[strlen(c.disciplina) + 1];
				this->disciplina = c.disciplina;

			}
			else
			{
				this->disciplina = nullptr;
			}
			this->nota = c.nota;
			this->data = c.data;
		}

		return *this;
	}

	bool operator>(const Examen& c)
	{
		return this->data > c.data;
	}

	operator int()
	{
		return this->nota;
	}

	Examen operator+(const Examen& c)
	{
		Examen copie = *this;
		copie.nota += c.nota;
		return copie;
	}

	int getnota()
	{
		return this->nota;
	}

	int getdata()
	{
		return this->data;
	}

	bool EsteNotaMaiMare(int x)
	{
		return this->nota > x;
	}

	bool EsteDataMaiMare(int x)
	{
		return this->data > x;
	}


};

int Examen::contor = 0;

ostream& operator<<(ostream& out, const Examen& a)
{
	cout << "IdExamen:" << a.idExamen << endl;
	cout << "data:" << a.data << endl;
	cout << "nota:" << a.nota << endl;
	if (a.disciplina != nullptr)
	{
		cout << "disciplina:" << a.disciplina << endl;
	}
	else
	{
		cout << "Nespecificat" << endl;
	}
	cout << endl << endl;

	return out;


}





int main()
{

}