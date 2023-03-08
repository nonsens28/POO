#include <iostream>
using namespace std;

class Persoana{
	int id;
	string nume;

public:

	void SetNume(string n) {
		nume = n;
	}
	string GetNume() {
		return nume;
	}
	void SetId(int x) {
		id = x;
	}
	int GetId() {
		return id;
	}

	Persoana(int id=0 , string nume="") {
		this->id = id;
		this->nume = nume;
	}

	Persoana(Persoana& p) {
		this->nume = p.nume;
		this->id = p.id;
	}

	~Persoana() {}

	int operator=(Persoana& s) {
		this->id = s.id;
		this->nume = s.nume;
		return 0;
	}

	friend istream& operator>>(istream& in, Persoana* a) {
		cout << "Nume : ";
		in >> a->nume;
		cout << "ID : ";
		in >> a->id;
		return in;
	}

	friend ostream& operator<<(ostream& out, Persoana* a) {
		cout << "Nume : ";
		out << a->nume << endl;
		cout << "ID : ";
		out << a->id << endl;
		return out;
	}
};

class Abonat : public Persoana {
	string nr_telefon;
protected:
	string tip_abonat;

public:
	void SetNrTelefon(string n) {
		nr_telefon = n;
	}
	string GetNrTelefon() {
		return nr_telefon;
	}
	static string TellTipAbonat(Abonat* a) {
		return a->tip_abonat;
	}

	virtual string GetIdSkype(){ return ""; };
	virtual string GetTara(){ return ""; };
	virtual string GetAdresaMail() { return ""; };

	Abonat(int id=0 , string nume="", string nr_telefon="", string tip_abonat="") : Persoana(id, nume) {
		this->nr_telefon = nr_telefon;
		this->tip_abonat ="Abonat Standard";
	}

	Abonat(Abonat& a) : Persoana((Persoana&)a) {
		this->nr_telefon = a.nr_telefon;
	}

	~Abonat(){}

	int operator=(Abonat& s) {
		(Persoana&)s;
		this->nr_telefon = s.nr_telefon;
		this->tip_abonat = s.tip_abonat;
		return 0;
	}

	friend istream& operator>>(istream& in, Abonat* a) {
		in >> (Persoana*)a;
		cout << "Numar telefon : ";
		in >> a->nr_telefon;
		return in;
	}

	friend ostream& operator<<(ostream& out, Abonat* a) {
		cout << "Tip abonat : ";
		out << a->tip_abonat << endl;
		out << (Persoana*)a;
		cout << "Numar telefon : ";
		out << a->nr_telefon << endl;
		return out;
	}
};

class Abonat_Skype : public Abonat {
	string id_skype;

public:
	void SetIdSkype(string n) {
		id_skype = n;
	}
	string GetIdSkype() {
		return id_skype;
	}

	Abonat_Skype(int id=0 , string nume="", string nr_telefon="", string id_skype="", string tip_abonat ="Abonat Skype") : Abonat(id, nume, nr_telefon) {
		this->id_skype = id_skype;
		this->tip_abonat="Abonat Skype";
	}

	Abonat_Skype(Abonat_Skype& a) : Abonat((Abonat&)a) {
		this->id_skype = a.id_skype;
	}

	~Abonat_Skype() {}

	int operator=(Abonat_Skype& s) {
		(Abonat&)s;
		this->id_skype = s.id_skype;
		return 0;
	}

	friend istream& operator>>(istream& in, Abonat_Skype* a) {
		in >> (Abonat*)a;
		cout << "ID Skype : ";
		in >> a->id_skype;
		return in;
	}

	friend ostream& operator<<(ostream& out, Abonat_Skype* a) {
		out << (Abonat*)a;
		cout << "ID Skype : ";
		out << a->id_skype << endl;
		return out;
	}
};

class Abonat_Skype_Romania : public Abonat_Skype {
	string adresa_mail;

public:
	void SetAdresaMail(string n) {
		adresa_mail = n;
	}
	string GetAdresaMail() {
		return adresa_mail;
	}

	Abonat_Skype_Romania(int id=0, string nume="", string id_skype="", string nr_telefon="", string adresa_mail="", string tip_abonat ="Abonat Skype Romania") : Abonat_Skype(id, nume, nr_telefon, id_skype) {
		this->adresa_mail = adresa_mail;
		this->tip_abonat = "Abonat Skype Romania";
	}

	Abonat_Skype_Romania(Abonat_Skype_Romania& a) : Abonat_Skype((Abonat_Skype &)a) {
		this->adresa_mail = a.adresa_mail;
	}

	~Abonat_Skype_Romania() {}

	int operator=(Abonat_Skype_Romania& s) {
		(Abonat_Skype&)s;
		this->adresa_mail = s.adresa_mail;
		return 0;
	}

	friend istream& operator>>(istream& in, Abonat_Skype_Romania* a) {
		in >> (Abonat_Skype*)a;
		cout << "Adresa mail : ";
		in >> a->adresa_mail;
		return in;
	}

	friend ostream& operator<<(ostream& out, Abonat_Skype_Romania* a) {
		out << (Abonat_Skype*)a;
		cout << "Adresa mail : ";
		out << a->adresa_mail << endl;
		return out;
	}
};

class Abonat_Skype_Extern : public Abonat_Skype {
	string tara;

public:
	void SetTara(string n) {
		tara = n;
	}
	string GetTara() {
		return tara;
	}

	Abonat_Skype_Extern(int id=0, string nume="", string id_skype="", string nr_telefon="", string tara="", string tip_abonat ="Abonat Skype Extern") : Abonat_Skype(id, nume, nr_telefon, id_skype) {
		this->tara = tara;
		this->tip_abonat = "Abonat Skype Extern";
	}

	Abonat_Skype_Extern(Abonat_Skype_Extern& a) : Abonat_Skype((Abonat_Skype&)a) {
		this->tara = a.tara;
	}

	~Abonat_Skype_Extern() {}

	int operator=(Abonat_Skype_Extern& s) {
		(Abonat_Skype&)s;
		this->tara = s.tara;
		return 0;
	}

	friend istream& operator>>(istream& in, Abonat_Skype_Extern* a) {
		in >> (Abonat_Skype*)a;
		cout << "Tara : ";
		in >> a->tara;
		return in;
	}

	friend ostream& operator<<(ostream& out, Abonat_Skype_Extern* a) {
		out << (Abonat_Skype*)a;
		cout << "Tara : ";
		out << a->tara << endl;
		return out;
	}
};

class Agenda {
	Abonat** list;
	int size;

public:
	int GetSize() {
		return size;
	}
	void SetSize(int x) {
		size = x;
	}

	Agenda(Abonat* list = nullptr , int size = 0) {
		this->list = (Abonat**)malloc(size * sizeof(Abonat*));
		this->size = size;
	}

	Agenda(Agenda& a) {
		this->list = a.list;
		this->size = a.size;
	}

	~Agenda() {
		free(list);
		size = 0;
	}

	int operator=(Agenda& a) {
		this->list = a.list;
		this->size = a.size;
		return 0;
	}

	friend ostream& operator<<(ostream& out, Agenda* a) {
		for (int i = 0;i < a->size;i++) {
			if (Abonat::TellTipAbonat(a->list[i]) == "Abonat Standard") {
				cout << (Abonat*)a->list[i];
			}
			if (Abonat::TellTipAbonat(a->list[i]) == "Abonat Skype") {
				cout << (Abonat_Skype*)a->list[i];
			}
			if (Abonat::TellTipAbonat(a->list[i]) == "Abonat Skype Romania") {
				cout << (Abonat_Skype_Romania*)a->list[i];
			}
			if (Abonat::TellTipAbonat(a->list[i]) == "Abonat Skype Extern") {
				cout << (Abonat_Skype_Extern*)a->list[i];
			}
			cout << endl;
		}
		return out;
	}

	Abonat* operator[](string nume) {
		for ( int i=0;i<size;i++)
			if (nume == list[i]->GetNume()) {
				return list[i];
			}
	}

	void adaugare (Abonat* a) {
		size++;
		list = (Abonat**)realloc(list, size * sizeof(Abonat*));
		list[size - 1] = a;
	}
};

void menu() {
	int x = 0;
	Agenda a;
	while (x != 4) {
		if (x == 1 || x == 3)
			cout << endl;
		cout << "1 - Adaugare abonat" << endl << "2 - Afisare agenda" << endl << "3 - Afisare informatii abonat dupa nume " << endl << "4 - EXIT" << endl;
		cout << "Input : ";
		cin >> x;
		cout << endl;
		if (x == 1) {
			cout << "1 - Abonat Standard" << endl << "2 - Abonat Skype" << endl << "3 - Abonat Skype Romania" << endl << "4 - Abonat Skype Extern" << endl;
			cout << "Selectati tipul abonatului : ";
			int k;
			cin >> k;
			if (k == 1) {
				Abonat* abonat = new Abonat;
				cin >> abonat;
				a.adaugare(abonat);
			}
			if (k == 2) {
				Abonat_Skype* abonat = new Abonat_Skype;
				cin >> abonat;
				a.adaugare(abonat);
			}
			if (k == 3) {
				Abonat_Skype_Romania* abonat = new Abonat_Skype_Romania;
				cin >> abonat;
				a.adaugare(abonat);
			}
			if (k == 4) {
				Abonat_Skype_Extern* abonat = new Abonat_Skype_Extern;
				cin >> abonat;
				a.adaugare(abonat);
			}
		}
		if (x == 2) {
			cout << &a;
		}
		if (x == 3) {
			string nume;
			cout << "Numele abonatului : ";
			cin >> nume;
			if (Abonat::TellTipAbonat(a[nume]) == "Abonat Standard") {
				cout << (Abonat*)a[nume];
			}
			if (Abonat::TellTipAbonat(a[nume]) == "Abonat Skype") {
				cout << (Abonat_Skype*)a[nume];
			}
			if (Abonat::TellTipAbonat(a[nume]) == "Abonat Skype Romania") {
				cout << (Abonat_Skype_Romania*)a[nume];
			}
			if (Abonat::TellTipAbonat(a[nume]) == "Abonat Skype Extern") {
				cout << (Abonat_Skype_Extern*)a[nume];
			}
		}
	}
}

int main()
{
	menu();
	return 0;
}


//-Clasa Persoana(int id, string nume) 
//- Clasa Abonat : Persoana(string nr_telefon) 
//- Clasa Abonat_Skype : Abonat(string id_skype) 
//- Clasa Abonat_Skype_Romania(string adresa_mail) : Abonat_Skype 
//- Clasa Abonat_Skype_Extern(string tara) : Abonat_Skype
//Sa se construiasca clasa Agenda ce contine o lista de abonati si sa se supraincarce operatorul [] (indexare) care 
//returneaza abonatul cu numele precizat.

//Cerințe comune tuturor temelor(barem) :
//    1 - Toate clasele vor conține obligatoriu constructori de inițializare (0.25p), parametrizați (0.25p) și de copiere (0.25p); destructor (0.25p); 
//operatorii„ = ”(0.5p), „ >> ”(0.5p), „ << ”(0.5p)   supraîncărcați   corespunzător, moșteniri & encapsulare(0.5p) 
//    2 - Clasele derivate trebuie sa contina constructori parametrizati(prin care sa se evidentieze transmiterea parametrilor catre constructorul 
//din clasa de baza) si destructori. (1p)
//    3 - În fiecare proiect vor fi ilustrate conceptele de upcasting, downcasting, funcții virtuale (pure – unde se consideră mai natural) – 1.5p (0.5p / cerință)
//    4 - Utilizarea de variabile și de funcții statice – 1p
//    5 - Citirea informațiilor complete a n obiecte, memorarea și afișarea acestora – 0.5p
//    6 - Meniu interactiv – 0.5p
//    7 - Rezolvarea corectă a cerințelor suplimentare corespunzatoare fiecarei teme – 1.5p.
// 
//    Se acordă punctaje parțiale corespunzător și 1p oficiu. - Dacă sursa nu compilează, se acorda nota 1 (punctul din oficiu). 
//    - După expirarea termenului limită se mai pot trimite teme pe mail pentru operioadă de grație de 2 zile(48 de ore).
//    Pentru fiecare zi parțială de întârziere sevor scădea 2 puncte.După expirarea termenului de grație, proiectele nu vor fiacceptate și vor 
//    fi notate cu 0. Punctul din oficiu este primit doar dacă a fosttrimis proiectul în perioada limită + perioada de grație.