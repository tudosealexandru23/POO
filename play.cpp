#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


class Consola {
private:
    char* model;
    int storage; // spațiu de stocare în GB
    float price;

public:
    // Constructorul implicit
    Consola() : model(nullptr), storage(0), price(0.0f) {
        this->model = new char[10];
        memcpy(this->model, "NU EXISTA\0", 10);
        //cout << "Constructor implicit apelat\n";
    }

    // Constructor cu parametri
    Consola(const char* model, int storage, float price) : storage(storage), price(price) {
        if (model != nullptr && strlen(model) > 0 && strlen(model) < 15) {
            this->model = new char[strlen(model) + 1];
            strcpy(this->model, model);
        }
        else {
            this->model = nullptr;  // Setăm modelul la nullptr dacă nu respectă condițiile
        }

        if (storage < 0) {
            this->storage = 0;
        }

        if (price < 0.0f) {
            this->price = 0.0f;
        }

        cout << "Constructor cu parametri apelat\n";
    }

    // Constructor de copiere
    Consola(const Consola& other) {
        if (other.model != nullptr) {
            model = new char[strlen(other.model) + 1];
            strcpy(model, other.model);
        }
        else {
            model = nullptr;
        }
        storage = other.storage;
        price = other.price;
        cout << "Constructor de copiere apelat\n";
    }

    // Destructor
    ~Consola() {
        delete[] this->model;
        this->model = nullptr;
        cout << "Destructor apelat pentru consola " << (model ? model : "Necunoscut") << "\n";
    }

    // Getter pentru model
    const char* getModel() {
        return this->model;
    }

    // Setter pentru model
    void setModel(const char* model) {

        if (model != nullptr && strlen(model) > 0 && strlen(model) < 15) {
            this->model = new char[strlen(model) + 1];
            strcpy(this->model, model);
        }
        else {
            this->model = nullptr;  // Setăm modelul la nullptr dacă nu respectă condițiile
        }

    }

    // Getter pentru storage
    int getStorage() {
        return storage;
    }

    // Setter pentru storage
    void setStorage(int storage) {
        this->storage = storage >= 0 ? storage : 0;
    }

    // Getter pentru price
    float getPrice() const {
        return price;
    }

    // Setter pentru price
    void setPrice(float price) {
        this->price = price >= 0 ? price : 0.0f;
    }

    // Suprascrierea operatorului de atribuire (=)
    Consola& operator=(const Consola& other) {
        if (this != &other) {
            delete[] model;
            if (other.model != nullptr) {
                model = new char[strlen(other.model) + 1];
                strcpy(model, other.model);
            }
            else {
                model = nullptr;
            }
            storage = other.storage;
            price = other.price;
        }
        cout << "Operator de atribuire apelat\n";
        return *this;
    }

    // Afișare informații despre consolă
    void afisare() const {
        cout << "Model: " << (model ? model : "Necunoscut") << ", Storage: " << storage << " GB, Price: $" << price << endl;
    }
};

int main() {
    // Crearea unui obiect Consola folosind constructorul cu parametri
    Consola consola1("PlayBox", 500, 299.99);
    consola1.afisare();

    // Folosirea constructorului de copiere
    Consola consola2 = consola1;
    consola2.afisare();

    // Folosirea operatorului de atribuire
    Consola consola3;
    consola3 = consola1;
    consola3.afisare();

    // Folosirea setterilor pentru a modifica valorile
    consola3.setModel("GameStation");
    consola3.setStorage(1000);
    consola3.setPrice(499.99);
    cout << "Detalii dupa modificare:\n";
    consola3.afisare();

    return 0;
}