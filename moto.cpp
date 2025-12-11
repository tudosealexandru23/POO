#include<iostream>
#include<string>

using namespace std;

class Motocicleta {
private:
	const int ID;
	static int nrMotociclete;
	string marca;
	int nrPiese;
	float* pret;
public:
	Motocicleta() :ID(++nrMotociclete) {
		this->marca = "Necunoscuta";
		this->nrPiese = 0;
		this->pret = nullptr;
	}

	Motocicleta(string _marca, int nrPiese, float* pret) :ID(++nrMotociclete) {
		marca = _marca;
		this->nrPiese = nrPiese;
		//shallow copy
		//this->pret = pret;

		//deep copy
		this->pret = new float[nrPiese];
		for (int i = 0; i < nrPiese; i++) {
			this->pret[i] = pret[i];
		}
		delete[] pret;
	}

	Motocicleta(const Motocicleta& m) :ID(++nrMotociclete) {
		this->marca = m.marca;
		this->nrPiese = m.nrPiese;
		this->pret = new float[m.nrPiese];
		for (int i = 0; i < m.nrPiese; i++) {
			this->pret[i] = m.pret[i];
		}
	}

	const Motocicleta& operator=(const Motocicleta& m) {
		if (this == &m) {
			return *this;
		}
		this->marca = m.marca;
		this->nrPiese = m.nrPiese;
		if (this->pret != nullptr) {
			delete[]this->pret;
		}
		this->pret = new float[m.nrPiese];
		for (int i = 0; i < m.nrPiese; i++) {
			this->pret[i] = m.pret[i];
		}
		return *this;
	}

	
	Motocicleta operator+=(float pret) {
		this->nrPiese++;
		float* aux = new float[this->nrPiese];
		for (int i = 0; i < this->nrPiese - 1; i++) {
			aux[i] = this->pret[i];
		}
		aux[this->nrPiese - 1] = pret;
		if (this->pret != nullptr) {
			delete[]this->pret;
		}
		this->pret = aux;
		return *this;
	}

	Motocicleta operator+(float pret) const {
		Motocicleta temp = *this;
		float* aux = new float[temp.nrPiese + 1];
		for (int i = 0; i < temp.nrPiese; i++) {
			aux[i] = this->pret[i];
		}
		aux[temp.nrPiese] = pret;
		if (temp.pret != nullptr) {
			delete[]temp.pret;
		}
		temp.pret = aux;
		temp.nrPiese++;
		return temp;
	}
	



	int getNrPiese() {
		return this->nrPiese;
	}



	void setNrPiese(int nrPiese) {
		if (nrPiese > 0) {
			this->nrPiese = nrPiese;
		}
		else {
			throw new exception();
		}
	}

	
	float* getPreturi() const {
		//return this->pret;
		float* vectorPreturi = new float[this->nrPiese];
		for (int i = 0; i < this->nrPiese; i++) {
			vectorPreturi[i] = this->pret[i];
		}
		return vectorPreturi;
	}

	void setPreturi(float* noulVectorPreturi, int nouaDimensiune) {
		setNrPiese(nouaDimensiune);
		if (this->pret != nullptr) {
			delete[] this->pret;
		}
		this->pret = new float[nouaDimensiune];
		for (int i = 0; i < nouaDimensiune; i++) {
			this->pret[i] = noulVectorPreturi[i];
		}
		delete[] noulVectorPreturi;
	}

	const int getID()const {
		return this->ID;
	}
	friend Motocicleta operator+(float pret, Motocicleta m);

	~Motocicleta() {
	
		if (this->pret != nullptr)
			delete[] this->pret;
	}

	void afisareMotocicleta() {
		cout << this->ID << ". Motocicleta cu marca " << this->marca;
		if (this->nrPiese > 0) {
			cout << " are " << this->nrPiese << " componente cu urmatoarele pret:";
			if (this->pret != nullptr) {
				for (int i = 0; i < this->nrPiese; i++) {
					cout << " " << this->pret[i];
				}
			}
		}
		cout << endl;
	}

	static int getNrMotociclete() {
		return nrMotociclete;
	}
	static void setNrMotociclete(int _nrMotociclete) {
		nrMotociclete = _nrMotociclete;
	}

};
int Motocicleta::nrMotociclete = 0;


Motocicleta operator+(float pret, Motocicleta m) {
	Motocicleta temp = m + pret;
	return temp;
}


int main() {

	Motocicleta motocicleta1("Kawasaki", 3, new float[3] {1, 2, 3});

	Motocicleta motocicleta2 = motocicleta1;
	Motocicleta motocicleta3("Suzuki", 3, new float[3] {661, 635, 62});
	

	motocicleta3 += 1000;
	motocicleta2 = motocicleta3 + 2000;

	motocicleta2 = 3000 + motocicleta3;

	motocicleta2.afisareMotocicleta();
}

