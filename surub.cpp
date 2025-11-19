include <iostream>
#include <vector>
using namespace std;

// Clasa Surub
class Surub {
private:
    string cod;
    string dimensiune;
    string material;
    double pret;
    int stoc;

public:
    Surub(string c, string d, string m, double p, int s)
        : cod(c), dimensiune(d), material(m), pret(p), stoc(s) {
    }

    string getCod() const { return cod; }
    double getPret() const { return pret; }
    int getStoc() const { return stoc; }

    void afiseaza() const {
        cout << "Cod: " << cod
            << ", Dimensiune: " << dimensiune
            << ", Material: " << material
            << ", Pret: " << pret
            << " lei, Stoc: " << stoc << endl;
    }

    void vinde(int cantitate) {
        if (cantitate <= stoc) {
            stoc -= cantitate;
            cout << "S-au vandut " << cantitate << " bucati din " << cod << endl;
        }
        else {
            cout << "Stoc insuficient pentru " << cod << endl;
        }
    }

    double valoareStoc() const {
        return pret * stoc;
    }
};

// Clasa Magazin
class Magazin {
private:
    vector<Surub> suruburi;

public:
    void adaugaSurub(const Surub& s) {
        suruburi.push_back(s);
    }

    void afiseazaStoc() const {
        cout << "=== Stoc magazin ===" << endl;
        for (const auto& s : suruburi) {
            s.afiseaza();
        }
    }

    void vindeSurub(string cod, int cantitate) {
        for (auto& s : suruburi) {
            if (s.getCod() == cod) {
                s.vinde(cantitate);
                return;
            }
        }
        cout << "Surub cu codul " << cod << " nu exista in stoc." << endl;
    }

    double valoareTotalaStoc() const {
        double total = 0;
        for (const auto& s : suruburi) {
            total += s.valoareStoc();
        }
        return total;
    }
};

// Main
int main() {
    Magazin magazin;

    // Adaugam suruburi
    magazin.adaugaSurub(Surub("S001", "M6x30", "Otel", 0.5, 100));
    magazin.adaugaSurub(Surub("S002", "M8x50", "Inox", 1.2, 50));
    magazin.adaugaSurub(Surub("S003", "M10x70", "Aluminiu", 0.9, 80));

    // Afisam stocul
    magazin.afiseazaStoc();

    // Vindem cateva suruburi
    magazin.vindeSurub("S001", 20);
    magazin.vindeSurub("S002", 60); // va da mesaj de stoc insuficient

    // Afisam stocul dupa vanzari
    magazin.afiseazaStoc();

    // Valoarea totala a stocului
    cout << "Valoarea totala a stocului: "
        << magazin.valoareTotalaStoc() << " lei" << endl;

    return 0;
}