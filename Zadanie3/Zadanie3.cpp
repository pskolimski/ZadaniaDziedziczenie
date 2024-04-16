#include <iostream>
#include <vector>

using namespace std;

class Kontakt {
public:
    string imie;
    string nazwisko;
    string telefon;
    string email;

    Kontakt(string imie1, string nazwisko1, string telefon1, string email1) {
        imie = imie1;
        nazwisko = nazwisko1;
        telefon = telefon1;
        email = email1;
    }
};

class KsiazkaAdresowa {
private:
    vector<Kontakt> kontakty = vector<Kontakt>();

    Kontakt szukajKontakt(string szukaneImie, string szukaneNazwisko) {
        int iloscKontaktow = kontakty.size();

        for (int i = 0; i < iloscKontaktow; i++) {
            Kontakt aktywnyKontakt = kontakty[i];

            if (aktywnyKontakt.imie == szukaneImie && aktywnyKontakt.nazwisko == szukaneNazwisko) {
                return aktywnyKontakt;
            }
        }
    }

    int szukajIndexKontaktu(string szukaneImie, string szukaneNazwisko) {
        int iloscKontaktow = kontakty.size();

        for (int i = 0; i < iloscKontaktow; i++) {
            Kontakt aktywnyKontakt = kontakty[i];
            cout << "Pętla działa!" << endl;

            if (aktywnyKontakt.imie == szukaneImie && aktywnyKontakt.nazwisko == szukaneNazwisko) {
                cout << aktywnyKontakt.imie << aktywnyKontakt.nazwisko << endl;
                return i;
            }
        }
    }

public:
    void dodajKontakt(Kontakt kontakt) {
        kontakty.push_back(kontakt);
    }

    void wypiszKontakty() {
        int iloscKontaktow = kontakty.size();

        for (int i = 0; i < iloscKontaktow; i++) {
            Kontakt aktywnyKontakt = kontakty[i];

            cout << "---------------------------------" << endl;
            cout << "Imię: " << aktywnyKontakt.imie << endl;
            cout << "Nazwisko: " << aktywnyKontakt.nazwisko << endl;
            cout << "Telefon: " << aktywnyKontakt.telefon << endl;
            cout << "Email: " << aktywnyKontakt.email << endl;
            cout << "---------------------------------" << endl;
        }
    }

    void usunKontakt(string imie1, string nazwisko1) {
        int kontaktDoUsuniecia = szukajIndexKontaktu(imie1, nazwisko1);

        if (kontaktDoUsuniecia) {
            kontakty.erase(kontakty.begin() + kontaktDoUsuniecia);
            cout << "Usunięto kontakt!" << endl;
        }
        else {
            cout << "Nie znaleziono kontaktu o podanych danych!" << endl;
        }
    }
};

int main()
{
    KsiazkaAdresowa ksiazka;

    Kontakt kontakt = *new Kontakt("Patryk", "Skolimski", "23232323232", "patryk@skolimski.com");

    ksiazka.dodajKontakt(kontakt);
    ksiazka.usunKontakt("Patryk", "Skolimski");
    ksiazka.wypiszKontakty();
}
