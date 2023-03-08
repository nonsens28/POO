#include <iostream>
#include <string.h>
using namespace std;

class student {
    string nume;
    int an_nastere, nr_credite;
    double med_generala;

public:

    void SetNume(string n) {
        this->nume = n;
    }
    string GetNume() {
        return nume;
    }
    void SetAnNastere(int n) {
        an_nastere = n;
    }
    int GetAnNastere() {
        return an_nastere;
    }
    void SetNrCredite(int n) {
        nr_credite = n;
    }
    int GetNrCredite() {
        return nr_credite;
    }
    void SetMedGenerala(double n) {
        med_generala = n;
    }
    double GetMedGenerala() {
        return med_generala;
    }

    student() {
        an_nastere = 0, nr_credite = 0, med_generala = 0, nume = "";
    }
    ~student() {
    }

    student(student& s) {
        an_nastere = s.an_nastere;
        nr_credite = s.nr_credite;
        med_generala = s.med_generala;
        nume = s.nume;
    }

    friend const istream& operator>>(istream& in, student* s) {
        cout << "Nume : ";
        in >> s->nume;
        cout << "An nastere : ";
        in >> s->an_nastere;
        cout << "Numar credite : ";
        in >> s->nr_credite;
        cout << "Media generala : ";
        in >> s->med_generala;
        return in;
    }
    friend const ostream& operator<<(ostream& out, student* s) {
        out << s->nume << endl;
        out << s->an_nastere << endl;
        out << s->nr_credite << endl;
        out << s->med_generala << endl;

        return out;
    }

    int operator=(const student& s) {
        this->an_nastere = s.an_nastere;
        this->nr_credite = s.nr_credite;
        this->med_generala = s.med_generala;
        this->nume = s.nume;
        return 0;
    }

};

class grupa {
    student** students;
    int size;
    double suma_medii = 0;

public:
    int GetSize() {
        return size;
    }
    double GetMed() {
        return suma_medii / size;
    }

    void DisplayStudent(int i) {
        cout << students[i];
    }

    grupa(int size = 0, student* students = nullptr) {     // daca student nu e specificat atunci ia valoarea null
        this->students = (student**)malloc(size * sizeof(student*));
        this->size = size;
        if (students != nullptr) {
            this->students = (student**)malloc(size * sizeof(student*));
            for (int i = 0; i < size; i++) {
                this->students[i] = new student();
                this->students[i] = &students[i];
            }
        }
        suma_medii = 0;
    }

    ~grupa() {
        free(students);
        size = 0;
    }

    void eliminare(string nume) {
        int i;
        for (i = 0; i < size; i++)
            if (nume == students[i]->GetNume())
                break;
        for (i = i; i < size - 1; i++)
            students[i] = students[i + 1];
        size--;
        students = (student**)realloc(students, size * sizeof(student*));
        cout << "Studentul " << nume << " eliminat";
        cout << endl;
    }

    void adaugare(student* s) {
        size++;
        students = (student**)realloc(students, size * sizeof(student*));
        student* stud = new student();
        students[size - 1] = stud;
        (*students[size - 1]) = *s;
        this->suma_medii += (*s).GetMedGenerala();
    }

    void verificare(string nume) {
        int k = 0;
        for (int i = 0; i < size; i++)
            if (nume == (*students[i]).GetNume()) {
                cout << "Studentul exista";
                cout << endl;
                k = 1;
            }
        if (k == 0)
            cout << "Studentul nu exista";
    }
};

void menu(grupa& g) {
    int x = 0;
    cout << "1 - Adaugare student" << endl << "2 - Informatii student dupa numar" << endl << "3 - Eliminare student dupa nume" << endl
        << "4 - Verificare daca exista student dupa nume" << endl << "5 - Exit" << endl;
    while (x != 5) {
        cout << "Input : ";
        cin >> x;
        if (x == 1) {
            student* s = new student;
            cin >> s;
            g.GetSize();
            g.adaugare(s);
        }
        if (x == 2) {
            int x;
            cout << "Index student : ";
            cin >> x;
            g.DisplayStudent(x);
        }
        if (x == 3) {
            string nume;
            cout << "Nume : ";
            cin >> nume;
            g.eliminare(nume);
        }
        if (x == 4) {
            string nume;
            cout << "Nume : ";
            cin >> nume;
            g.verificare(nume);
        }
    }
}

int main()
{
    student* s = new student;
    grupa g;

    menu(g);

    return 0;
}