#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class FirmaD{ 
private:	
	char* numeC;
	string produs;
	int cantitate;
	float pret;
	static int nrFirme;
	
public:
	//constructor fara parametri
	FirmaD() {
	 	this->numeC = nullptr;
		this->produs = "";
		this->cantitate = 0;
		this->pret = 0.0;

	}
	//constructor cu parametri
	FirmaD(const char* numeC = nullptr, string produs = "", int cantitate = 0, float pret = 0.0) {
		if (numeC != nullptr) {
			this->numeC = new char[strlen(numeC) + 1];
			strcpy_s(this->numeC, strlen(numeC) + 1, numeC);
		
		}
		else {
			this->numeC = nullptr;
		}
		this->produs = produs;
		this->cantitate = cantitate;
		this->pret = pret;
	}
	//constructor de copiere
	FirmaD(const FirmaD& f) {
		if (f.numeC != nullptr) {
			this->numeC = new char[strlen(f.numeC) + 1];
			strcpy_s(this->numeC, strlen(f.numeC) + 1, f.numeC);

		}
		else {
			this->numeC = nullptr;
		}
		this->produs = f.produs;
		this->cantitate = f.cantitate;
		this->pret = f.pret;
	}
	//destructor
	~FirmaD(){
	 if (this->numeC != nullptr) {
		 delete[] this->numeC;
	 }

	}
	//operator atribuire
	FirmaD& operator=(const FirmaD& f) {
		if (this->numeC != nullptr) {
			delete[] this->numeC;
		}

		if (f.numeC != nullptr) {
			this->numeC = new char[strlen(f.numeC) + 1];
			strcpy_s(this->numeC, strlen(f.numeC) + 1, f.numeC);

		}
		else {
			this->numeC = nullptr;
		}
		this->produs = f.produs;
		this->cantitate = f.cantitate;
		this->pret = f.pret;

		return *this;

	 }
	//geteri

	char* getNumeC() {
		return this->numeC;
	}
	string getProdus() {
		return this->produs;
	}
	int getCantitate() {
		return this->cantitate;
	}
	float getPret() {
		return this->pret;
	}


	//metoda pentru afisare	
	  friend ostream& operator<<(ostream& out, const FirmaD& f)
	{
		out << f.numeC << " " << f.produs << " " << f.cantitate << " " << f.pret << " ";
		if(f.numeC!=nullptr){
			out << f.numeC;
		}
		return out;

	}
	//operatorul de incrementare
	FirmaD operator++(int i) {
		FirmaD copiere = *this;
		this->pret++;
		return copiere;
	}

	// operatorul +=
	FirmaD operator+=(const FirmaD&f)
	{ 
		if (f.numeC != nullptr) {
			this->numeC = new char[strlen(f.numeC) + 1];
			strcpy_s(this->numeC, strlen(f.numeC) + 1, f.numeC);

		}
		else {
			this->numeC = nullptr;
		}
		this->produs += f.produs;
		this->cantitate += f.cantitate;
		this->pret += f.pret;
	}
};
int FirmaD::nrFirme = 0;



int main() {
	FirmaD f1("Ionescu", "Telefon", 20, 500.5);
	cout << "Nume: " << f1.getNumeC() << endl;
	cout << "Produs: " << f1.getProdus() << endl;
	cout << "Cantitate: " << f1.getCantitate() << endl;
	cout << "Pret: " << f1.getPret() << endl;
	cout << endl;

	FirmaD f2("Popescu", "Laptop", 30, 205.3);
	cout << "Nume: " << f2.getNumeC() << endl;
	cout << "Produs: " << f2.getProdus() << endl;
	cout << "Cantitate: " << f2.getCantitate() << endl;
	cout  << "Pret: " << f2.getPret() << endl;
	cout << endl;

	//ne arata ca incrementarea merge
	cout << "Pretul este: " << f1.getPret() << endl;
	f1++;
	cout << "Pretul este: " << f1.getPret() << endl;
	f1++;
	cout << "Pretul este: " << f1.getPret() << endl;
	f1++;
	

	int cantitate = 30;
	cantitate += 10;
	cout << "Cantitatea este: " << cantitate << endl; 


	//operator comparatie
	int cantitate1 = 30;
	int cantitate2 = 20;
	if (cantitate1 <= cantitate2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}