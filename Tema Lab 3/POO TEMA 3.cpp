#include <iostream>
#include <vector>
using namespace std;

class Persoana {
	int id;
	string nume;

public:

	void SetNume(const string n) {				//variabila constanta
		nume = n;
	}
	string GetNume() const {					//functie constanta
		return nume;
	}
	void SetId(const int x) {
		id = x;
	}
	int GetId() const {
		return id;
	}

	Persoana(int id = 0, string nume = "") {
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

	virtual void print() {								//afisare virtuala
		cout << "Nume : ";
		cout << GetNume() << endl;
		cout << "ID : ";
		cout << GetId() << endl;
	}

	virtual void read() {								//citire virtuala
		cout << "Nume : ";
		cin >> nume;
		SetNume(nume);
		cout << "ID : ";
		cin >> id;
		SetId(id);
	}
};

class Abonat : public Persoana {
	string nr_telefon;
protected :
	string tip_abonat;
	const static string AbonatStandard;							//variabila statica

public:
	void SetNrTelefon(const string n) {
		nr_telefon = n;
	}
	string GetNrTelefon() const {
		return nr_telefon;
	}
	static string TellTipAbonat(Abonat* a) {					//functie statica
		return a->tip_abonat;
	}
	string GetTipAbonat() const {
		return tip_abonat;
	}

	virtual string GetIdSkype() { return ""; };
	virtual string GetTara() { return ""; };
	virtual string GetAdresaMail() { return ""; };

	Abonat(int id = 0, string nume = "", string nr_telefon = "") : Persoana(id, nume) {
		this->nr_telefon = nr_telefon;
		this->tip_abonat = Abonat::AbonatStandard;
	}

	Abonat(Abonat& a) : Persoana((Persoana&)a) {
		this->nr_telefon = a.nr_telefon;
	}

	~Abonat() {}

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

	virtual void print() {
		cout << "Tip abonat : ";
		cout << GetTipAbonat() << endl;
		cout << "Nume : ";
		cout << GetNume() << endl;
		cout << "ID : ";
		cout << GetId() << endl;
		cout << "Numar telefon : ";
		cout << GetNrTelefon() << endl;
	}

	virtual void read() {
		string nume,nr_telefon;
		int id;
		cout << "Nume : ";
		cin >> nume;
		SetNume(nume);
		cout << "ID : ";
		cin >> id;
		SetId(id);
		cout << "Numar telefon : ";
		cin >> nr_telefon;
		SetNrTelefon(nr_telefon);
	}
};

const string Abonat::AbonatStandard = "Abonat Standard";					//pt variabila statica

class Abonat_Skype : public Abonat {
	string id_skype;

public:
	void SetIdSkype(const string n) {
		id_skype = n;
	}
	string GetIdSkype() const {
		return id_skype;
	}

	Abonat_Skype(int id = 0, string nume = "", string nr_telefon = "", string id_skype = "", string tip_abonat = "Abonat Skype") : Abonat(id, nume, nr_telefon) {
		this->id_skype = id_skype;
		this->tip_abonat = "Abonat Skype";
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

	virtual void print() {
		cout << "Tip abonat : ";
		cout << GetTipAbonat() << endl;
		cout << "Nume : ";
		cout << GetNume() << endl;
		cout << "ID : ";
		cout << GetId() << endl;
		cout << "Numar telefon : ";
		cout << GetNrTelefon() << endl;
		cout << "ID Skype : ";
		cout << GetIdSkype() << endl;
	}

	virtual void read() {
		string nume, nr_telefon,id_skype;
		int id;
		cout << "Nume : ";
		cin >> nume;
		SetNume(nume);
		cout << "ID : ";
		cin >> id;
		SetId(id);
		cout << "Numar telefon : ";
		cin >> nr_telefon;
		SetNrTelefon(nr_telefon);
		cout << "ID Skype : ";
		cin >> id_skype;
		SetIdSkype(id_skype);
	}
};

class Abonat_Skype_Romania : public Abonat_Skype {
	string adresa_mail;

public:
	void SetAdresaMail(const string n) {
		adresa_mail = n;
	}
	string GetAdresaMail() const {
		return adresa_mail;
	}

	Abonat_Skype_Romania(int id = 0, string nume = "", string id_skype = "", string nr_telefon = "", string adresa_mail = "", string tip_abonat = "Abonat Skype Romania") : Abonat_Skype(id, nume, nr_telefon, id_skype) {
		this->adresa_mail = adresa_mail;
		this->tip_abonat = "Abonat Skype Romania";
	}

	Abonat_Skype_Romania(Abonat_Skype_Romania& a) : Abonat_Skype((Abonat_Skype&)a) {
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

	virtual void print() {
		cout << "Tip abonat : ";
		cout << GetTipAbonat() << endl;
		cout << "Nume : ";
		cout << GetNume() << endl;
		cout << "ID : ";
		cout << GetId();
		cout << "Numar telefon : ";
		cout << GetNrTelefon() << endl;
		cout << "ID Skype : ";
		cout << GetIdSkype() << endl;
		cout << "Adresa mail : ";
		cout << GetAdresaMail() << endl;
	}

	virtual void read() {
		string nume, nr_telefon, id_skype,adresa_mail;
		int id;
		cout << "Nume : ";
		cin >> nume;
		SetNume(nume);
		cout << "ID : ";
		cin >> id;
		SetId(id);
		cout << "Numar telefon : ";
		cin >> nr_telefon;
		SetNrTelefon(nr_telefon);
		cout << "ID Skype : ";
		cin >> id_skype;
		SetIdSkype(id_skype);
		cout << "Adresa mail : ";
		cin >> adresa_mail;
		SetAdresaMail(adresa_mail);
	}
};

class Abonat_Skype_Extern : public Abonat_Skype {
	string tara;

public:
	void SetTara(const string n) {
		tara = n;
	}
	string GetTara() const {
		return tara;
	}

	Abonat_Skype_Extern(int id = 0, string nume = "", string id_skype = "", string nr_telefon = "", string tara = "", string tip_abonat = "Abonat Skype Extern") : Abonat_Skype(id, nume, nr_telefon, id_skype) {
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

	virtual void print() {
		cout << "Tip abonat : ";
		cout << GetTipAbonat() << endl;
		cout << "Nume : ";
		cout << GetNume() << endl;
		cout << "ID : ";
		cout << GetId() << endl;
		cout << "Numar telefon : ";
		cout << GetNrTelefon() << endl;
		cout << "ID Skype : ";
		cout << GetIdSkype() << endl;
		cout << "Tara : ";
		cout << GetTara() << endl;
	}

	virtual void read() {
		string nume, nr_telefon, id_skype, tara;
		int id;
		cout << "Nume : ";
		cin >> nume;
		SetNume(nume);
		cout << "ID : ";
		cin >> id;
		SetId(id);
		cout << "Numar telefon : ";
		cin >> nr_telefon;
		SetNrTelefon(nr_telefon);
		cout << "ID Skype : ";
		cin >> id_skype;
		SetIdSkype(id_skype);
		cout << "Tara : ";
		cin >> tara;
		SetTara(tara);
	}
};

class Agenda {
	vector<Abonat*> list;						//STL VECTOR
	int nr_abonati_standard, nr_abonati_skype, nr_abonati_skype_romania, nr_abonati_skype_extern;

public:

	Agenda() {
	}

	Agenda(Agenda& a) {
		this->list = a.list;
	}

	~Agenda() {
		list.clear();
	}

	int operator=(Agenda& a) {
		this->list = a.list;
		return 0;
	}

	friend ostream& operator<<(ostream& out, Agenda* a) {
		for (int i = 0;i < a->list.size();i++) {
			if (Abonat::TellTipAbonat(a->list[i]) == "Abonat Standard") {
				a->list[i]->print();
			}
			if (Abonat::TellTipAbonat(a->list[i]) == "Abonat Skype") {
				a->list[i]->print();
			}
			if (Abonat::TellTipAbonat(a->list[i]) == "Abonat Skype Romania") {
				a->list[i]->print();
			}
			if (Abonat::TellTipAbonat(a->list[i]) == "Abonat Skype Extern") {
				a->list[i]->print();
			}

			cout << endl;
		}
		return out;
	}

	Abonat* operator[](string nume) {
		for (int i = 0;i < list.size();i++)
			if (nume == list[i]->GetNume()) {
				return list[i];
			}
	}

	void adaugare(Abonat* a) {;
		list.push_back(a);
	}
};

template <class T> void afisare(T a) {								//template(sablon)
	cout << a;
}

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
			try {																//tratarea exceptiilor
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
				else if (x == 2) {
					cout << "////////// AGENDA ////////////////////////////////////////////////////////////////" << endl << endl;
					cout << &a;
				}
				else if (x == 3) {
					string nume;
					cout << "Numele abonatului : ";
					cin >> nume;
					if (typeid(*a[nume]) == typeid(Abonat)) {				//rtti typeid
						afisare<Abonat*>(a[nume]);
					}
					if (typeid(*a[nume]) == typeid(Abonat_Skype)) {
						afisare<Abonat_Skype*>(dynamic_cast <Abonat_Skype*> (a[nume]));
					}
					if (typeid(*a[nume]) == typeid(Abonat_Skype_Romania)) {
						afisare<Abonat_Skype_Romania*>(dynamic_cast <Abonat_Skype_Romania*> (a[nume]));
					}
					if (typeid(*a[nume]) == typeid(Abonat_Skype_Extern)) {
						afisare<Abonat_Skype_Extern*>(dynamic_cast <Abonat_Skype_Extern*> (a[nume]));			//dynamic cast in template
					}
				}
				else if (x == 4)
					return ;
			else if (x != 4 || x != 1 || x != 2 || x != 3 ) {
				throw x;
			}
		}
		catch (...) {
			cout << "Wrong input" << endl << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');				//solutie gasita pe net incat fara liniile astea 2 imi dadea skip la cin
		}
	}
}

int main()
{
	menu();
	return 0;
}


//utilizarea sabloanelor
// 
//utilizarea conceptelor de RTTI raportat la templat - uri(ex: upcast & dynamic_cast)
//
//clasa de baza sa conțină funcție virtuala de afisare si citire, rescrisa în clasele derivate
// 
//utilizarea variabilelor, funcțiilor statice
// 
//, constantelor și a unei functii const , iar operatorul de citire si afisare să fie 
//implementat ca funcție prieten(în clasele derivate să se facă referire la implementarea acestuia în clasa de baza).
// 
//utilizarea STL
//
//citirea informațiilor complete a n obiecte, memorarea și afișarea acestora
// 
//-să se identifice și să se implementeze ierarhia de clase;
// 
//-clasele să conțină constructori, destructori, =, supraincarcare pe >> si << pentru citire si afisare;
// 
//tratarea excepțiilor
// 
