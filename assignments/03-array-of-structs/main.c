#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPerson {
    char name[20];
    int id;
};

void savePeople(struct sPerson* people, int size);
void outputPeople(struct sPerson* people, int size);
void getUserInput(struct sPerson* people, int* size);
int printMenu();
struct sPerson* initPeople(int* size);

int main() {
    int registered = 0;
    struct sPerson* people = initPeople(&registered);
    int choice = printMenu();
    while (choice != '0') {
        switch (choice) {
            case '1':
                getUserInput(people, &registered);
                break;
            case '2':
                outputPeople(people, registered);
                break;
            case '3':
                savePeople(people, registered);
                break;
            default:
                break;
        }
        choice = printMenu();
    };
    return 0;
}

void savePeople(struct sPerson* people, int size) {
    FILE* f = fopen("people.dat", "wb");
    fwrite(&size, sizeof(int), 1, f);
    fwrite(people, sizeof(struct sPerson), size, f);
    fclose(f);
}

void outputPeople(struct sPerson* people, int size) {
    for (int i = 0; i < size; i++) {
        printf("---\n");
        printf("Person #%d:\n", i + 1);
        printf("Name: %s\n", people[i].name);
        printf("ID: %d\n", people[i].id);
    }
    printf("---\n");
}

void getUserInput(struct sPerson* people, int* size) {
    char name[20];
    char idStr[20];
    int id = 0;
    struct sPerson newPerson;
    do {
        printf("Name eingeben: ");
        fflush(stdin);
        do {
            fgets(name, 20, stdin);
        } while (name[0] == '\n');
    } while (strlen(name) == 0);
    name[strcspn(name, "\n")] = 0;
    printf("ID: ");
    fgets(idStr, 20, stdin);
    id = atoi(idStr);
    while (id <= 0) {
        printf("Falsche eingabe!\n");
        printf("Welche ID soll der Benutzer haben: ");
        fflush(stdin);
        fgets(idStr, 20, stdin);
        id = atoi(idStr);
    }
    strcpy(newPerson.name, name);
    newPerson.id = id;
    people[*size] = newPerson;
    (*size)++;
    if (*size % 5 == 1) {
        int arrSize = *size + 4;
        people = (sPerson*) realloc(people, arrSize * sizeof(struct sPerson));
    }
}

int printMenu() {
    printf("1) Person eintragen\n");
    printf("2) Personen ausgeben\n");
    printf("3) Personen speichern\n");
    printf("0) Programm beenden\n");
    printf("\n");
    printf("Was moechtest du tun?\n");
    int input = 0;
    do {
        fflush(stdin);
        input = getc(stdin);
    } while (input == '\n');
    fflush(stdin);
    return input;
}

struct sPerson* initPeople(int* size) {
    FILE* f = fopen("people.dat", "rb");
    struct sPerson* people;
    if (f == NULL)
        people = (struct sPerson*)malloc(5 * sizeof(struct sPerson));
    else {
        fread(size, sizeof(int), 1, f);
        int sizeArray = *size;
        if (sizeArray % 5 != 0) sizeArray += 5 - sizeArray % 5;
        people = (struct sPerson*)malloc(sizeArray * sizeof(struct sPerson));
        fread(people, sizeof(struct sPerson), *size, f);
        fclose(f);
    }
    return people;
}