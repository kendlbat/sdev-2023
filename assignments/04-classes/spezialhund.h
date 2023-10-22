#include "hund.h"

class Spezialhund: public Hund {
    private:
        string ausbildung;
    public:
        string getAusbildung();
        void setAusbildung(string ausbildung);

        Spezialhund(string rasse): Hund(rasse) {
            cout << "Spezialhund erzeugt!" << endl;
        }
};
