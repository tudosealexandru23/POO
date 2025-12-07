#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Autobuz {
private:
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:
    // Constructoul fără parametrii
    Autobuz() : idAutobuz(++nrAutobuze) {
        capacitate = 0;
        nrPersoaneImbarcate = 0;
        producator = nullptr;
    }

    // Constructorul cu parametrii
    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(++nrAutobuze) {
        if (capacitate < 0) capacitate = 0;
        if (nrPersoaneImbarcate < 0) nrPersoaneImbarcate = 0;
        if (nrPersoaneImbarcate > capacitate) nrPersoaneImbarcate = capacitate;

        this->capacitate = capacitate;
        this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        this->producator = new char[strlen(producator) + 1];
        strcpy(this->producator, producator);
    }

    // Constructorul de copiere
    Autobuz(const Autobuz& whatever) : idAutobuz(++nrAutobuze) {
        capacitate = whatever.capacitate;
        nrPersoaneImbarcate = whatever.nrPersoaneImbarcate;
        producator = new char[strlen(whatever.producator) + 1];
        strcpy(producator, whatever.producator);
    }

    // Destructorul
    ~Autobuz() {
        delete[] producator;
    }

    // getter pentru capacitate
    int getCapacitate() const {
        return capacitate;
    }

	//setter pentru capacitate
    void setCapacitate(int capacitate) {
        if (capacitate >= 0) {
            this->capacitate = capacitate;
            if (nrPersoaneImbarcate > capacitate) {
                nrPersoaneImbarcate = capacitate;
            }
        }
    }

	// getter pentru producator
    const char* getProducator() const {
        return producator;
    }

	//setter pentru producator
    void setProducator(const char* producator) {
        delete[] this->producator;
        this->producator = new char[strlen(producator) + 1];
        strcpy(this->producator, producator);
    }

    // Operatorul de atribuire
    Autobuz& operator=(const Autobuz& whatever) {
        if (this != &whatever) {
            capacitate = whatever.capacitate;
            nrPersoaneImbarcate = whatever.nrPersoaneImbarcate;
            delete[] producator;
            producator = new char[strlen(whatever.producator) + 1];
            strcpy(producator, whatever.producator);
        }
        return *this;
    }

    // Operatorul de afișare
    friend ostream& operator<<(ostream& os, const Autobuz& autobuz) {
        os << "ID: " << autobuz.idAutobuz << "; Capacitate: " << autobuz.capacitate << "; Nr. Persoane Imbarcate: " << autobuz.nrPersoaneImbarcate << "; Producator: " << autobuz.producator;
        return os;
		// de ce nu merge cu std::cout?

    }

    // Metoda pentru numar locuri libere
    int getNumarLocuriLibere() const {
        return capacitate - nrPersoaneImbarcate;
    }

    // Operatorul de cast la int
    operator int() const {
        return nrPersoaneImbarcate;
    }

    // Operatorul de comparare
    bool operator>(const Autobuz& whatever) const {
        return capacitate > whatever.capacitate;
    }
};

// Inițializare variabilei statice
int Autobuz::nrAutobuze = 0;

int main() {
    // Testare constructori
    Autobuz a1;
    Autobuz a2(50, 30, "Mercedes");
    Autobuz a3(a2);

    // Testare operator "=" 
    a1 = a2;

    // Testare operator "<<"
    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;

    // Testare metode accesor
    a1.setCapacitate(60);
    a1.setProducator("Volvo");
    cout << "Capacitate: " << a1.getCapacitate() << ", Producator: " << a1.getProducator() << endl;

    // Testare pentru numar locuri libere
    cout << "Numar locuri libere: " << a1.getNumarLocuriLibere() << endl;

    // Testarea operatorului de cast la int
    int nrPersoane = a1;
    cout << "Numar persoane imbarcate: " << nrPersoane << endl;

    // Testare operator ">"
    if (a1 > a2) {
        cout << "Autobuzul a1 are o capacitate mai mare decat a2." << endl;
    }
    else {
        cout << "Autobuzul a2 are o capacitate mai mare sau egala cu a1." << endl;
    }

    return 0;
}
