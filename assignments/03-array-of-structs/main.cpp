#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

struct sPerson {
    char name[20];
    int alter;
};

void auflisten(int cnt, sPerson *p);
int getFileContent(sPerson *p);
void savePersons(sPerson *p, int cnt);

int main() {
    FILE *f;
    int cnt = 0;
    char weiter = 'z';
    sPerson *p;

    cnt = getFileContent(p);

    do {
        cout << endl
             << endl
             << "n ... neuer Datensatz" << endl
             << "e ... Ende" << endl
             << "l ... vorhandene Personen auflisten" << endl;

        weiter = getc(stdin);

        if (weiter == 'n') {
            cout << endl
                 << cnt + 1 << ".ter Name: ";
            cin >> p[cnt].name;
            cout << "Alter: ";
            cin >> p[cnt].alter;
            cnt++;
            if (cnt % 5 == 0) {
                p = (sPerson *)realloc(p, (cnt + 5) * sizeof(sPerson));
            }
        }
        if (weiter == 'l') {
            auflisten(cnt, p);
        }
        fflush(stdin);
    } while (weiter != 'e');
    savePersons(p, cnt);  // Implementieren
    return 0;
}

void auflisten(int cnt, sPerson *p) {
    cout << endl
         << endl;
    for (int i = 0; i < cnt; i++) {
        cout << p[i].name << " " << p[i].alter << endl;
    }
    cout << endl
         << endl;
}