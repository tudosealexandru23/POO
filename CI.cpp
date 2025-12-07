#include <iostream>
#include <string>
using namespace std;

class Persoana {
private:
	string nume;
	int varsta;
	int nrNote;
	int* note;

public:
	Persoana() {
		nume = "";
		varsta = 0;
		nrNote = 0;
		note = nullptr;
	}

	Persoana(string nume, int varsta, int nrNote, const int* note) {
		this->nume = nume;
		this->varsta = varsta;
		this->nrNote = nrNote;
		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->note[i] = note[i];
		}
	}

	void getNote() {
		for (int i = 0; i < nrNote; i++) {
			cout << note[i] << " " << endl;
		}
	}

	string getNume() {
		return this->nume;
	}

	int getVarsta() {
		return this->varsta;
	}

	~Persoana() {
		cout << endl << "persoana s-a distrus";
		delete[] note;
		note = nullptr;
		cout << endl << "s-au dezalocat " << nrNote * sizeof(int) << " bytes";	
	}
};


int main() {

	int note[4] = { 10, 9, 8, 5};

	Persoana pers1("Andrei", 20, 4, note);

	cout << endl << pers1.getNume() << endl << pers1.getVarsta() << endl;
	pers1.getNote();
	

	return 0;
}