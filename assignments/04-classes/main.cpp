#include "spezialhund.cpp"

void ausgabe(Hund* hund) {
    cout << "---" << endl;
    cout << "Rasse: " << hund->getRasse() << endl;
    cout << "Geburtsjahr: " << hund->getGeburtsJahr() << endl;
    cout << "Steuernummer: " << hund->getSteuernummer() << endl;
    Spezialhund* sHund = dynamic_cast<Spezialhund*>(hund);
    if (sHund != NULL) cout << "Ausbildung: " << sHund->getAusbildung() << endl;
    cout << "---" << endl;
}

//Alloziiert den Speicher im RAM für die static variable
int Hund::initialized = 0;

int main() {
    Hund hund1("Dackel");
    hund1.setGeburtsJahr(2015);
    hund1.setSteuernummer("S1");

    Hund hund2("Schaefer");
    hund2.setGeburtsJahr(2016);
    hund2.setSteuernummer("S2");

    Spezialhund hund3("Deutsche Dogge");
    hund3.setGeburtsJahr(2017);
    hund3.setSteuernummer("S3");
    hund3.setAusbildung("Sp\x81rhund");

    Spezialhund hund4("Pudel");
    hund4.setGeburtsJahr(2018);
    hund4.setSteuernummer("S4");
    hund4.setAusbildung("Herumgetragen werden");

    ausgabe(&hund1);
    ausgabe(&hund2);
    ausgabe(&hund3);
    ausgabe(&hund4);

    cout << "Es gibt " <<Hund::getInitialized() <<" Hunde" << endl;
    return 0;
}