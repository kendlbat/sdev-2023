#include <iostream>
using namespace std;

class Hund {
    private:
        static int initialized;
    
    protected:
        string rasse;
        int geburtsjahr;
        string steuernummer;

    public:
        string getRasse() {
            return rasse;
        }

        void setRasse(string rasse) {
            this->rasse = rasse;
        }

        int getGeburtsJahr() {
            return geburtsjahr;
        }

        void setGeburtsJahr(int geburtsjahr) {
            this->geburtsjahr = geburtsjahr;
        }

        string getSteuernummer() {
            return steuernummer;
        }

        void setSteuernummer(string steuernummer) {
            this->steuernummer = steuernummer;
        }

        static int getInitialized() {
            return initialized;
        }

        Hund(string rasse) {
            initialized++;
            this->rasse = rasse;
            cout << "Hund wurde erzeugt!" << endl;
        }

        virtual ~Hund() {
            initialized--;
        }
};
