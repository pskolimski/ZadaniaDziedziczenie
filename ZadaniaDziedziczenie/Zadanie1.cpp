#include <iostream>

using namespace std;

// Lista uprawnień dla pracowników technicznych
enum Uprawnienia {
    GLOWNY_ADMINISTRATOR,
    ADMNISTRATOR,
    INSTRUKTOR,
    PRACOWNIK_TECHNICZNY
};

// Klasa główna pracownika
class Pracownik {
protected:
    string imie;
    string nazwisko;
    int pensja;

public:
    void DisplayInfo() {
        cout << "Imie: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Pensja: " << pensja << endl;
    }
};

// Klasa reprezentująca pracownika biura
class PracownikBiura : Pracownik {
protected:
    int gabinet; // Numer gabinetu pracownika.
public:
    PracownikBiura(string imiePracownika, string nazwiskoPracownika, int pensjaPracownika, int numerGabinetu) {
        imie = imiePracownika;
        nazwisko = nazwiskoPracownika;
        pensja = pensjaPracownika;
        gabinet = numerGabinetu;
    }

    // Nadpisanie metody wyświetlającej informacje o pracowniku
    void DisplayInfo() {
        cout << "Imie: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Pensja: " << pensja << endl;
        cout << "Gabinet: " << gabinet << endl;
    }

    // Metoda umożliwiająca zmianę gabinetu pracownika.
    void ZmienGabinet(int nowyGabinet) {
        gabinet = nowyGabinet;

        cout << "Zmieniono gabinet na " << gabinet << endl;
    }
};

// Klasa reprezentująca pracownika technicznego.
class PracownikTechniczny : Pracownik {
protected:
    string specjalizacja;
    Uprawnienia uprawnienia;
public:
    PracownikTechniczny(string imiePracownika, string nazwiskoPracownika, int pensjaPracownika, string specjalizacjaPracownika, Uprawnienia uprawnieniaPracownika) {
        imie = imiePracownika;
        nazwisko = nazwiskoPracownika;
        pensja = pensjaPracownika;
        specjalizacja = specjalizacjaPracownika;
        uprawnienia = uprawnieniaPracownika;
    }

    // Nadpisanie metody wyświetlającej informacje o pracowniku
    void DisplayInfo() {
        cout << "Imie: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Pensja: " << pensja << endl;
        cout << "Specjalizacja: " << specjalizacja << endl;
        cout << "Uprawnienia: " << uprawnienia << endl;
    }

    // Metoda sprawdzająca, czy pracownik posiada dane uprawnienia
    void SprawdzUprawnienia(Uprawnienia oczekiwaneUprawnienia) {
        if (oczekiwaneUprawnienia >= uprawnienia) {
            cout << "Pracownik posiada wymagane uprawnienia!" << endl;
        }
        else {
            cout << "Pracownik nie posiada takich uprawnien" << endl;
        }
    }
};


int main() {
    Pracownik pracownik;
    PracownikBiura pracownikBiura = *new PracownikBiura("Jan", "Kowalski", 5000, 5);
    PracownikTechniczny pracownikTechniczny = *new PracownikTechniczny("Jan", "Kowalski", 5000, "IT", ADMNISTRATOR);

    pracownikBiura.ZmienGabinet(50);
    pracownikBiura.DisplayInfo();

    pracownikTechniczny.SprawdzUprawnienia(PRACOWNIK_TECHNICZNY);
    pracownikTechniczny.DisplayInfo();

    return 0;
}
