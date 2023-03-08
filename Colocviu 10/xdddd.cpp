// Rada Paul 141
// Microsoft Visual Studio Community 2022
// Alexandra Murgoci

using namespace std;
#include <iostream>
#include <vector>
#include <math.h>
#include <map>

class Car {
protected:
	int An;
	string Nume;
	string Model;
	int VitMax;
	int Greutate;
	int Autonomie;
public:
	Car();
	Car(const Car&) = default;
	Car& operator=(const Car&) = default;
	virtual ~Car() = default;
	virtual void CalcAutonomie() = 0;
	friend istream& operator>>(istream& in, Car& c) {
		return c.read(in);
	}
	friend ostream& operator<<(ostream& out, Car& c) {
		return c.print(out);
	}
	virtual istream& read(istream& in) = 0;
	virtual ostream& print(ostream& out) = 0;
	string GetModel()const;
	int GetAutonomie()const;
	int GetVitMax();
	void SetVitMax(int x);
};
Car::Car() : An(0), Nume(""), Model(""), VitMax(0), Greutate(0), Autonomie(0) {}
string Car::GetModel() const {
	return Model;
}
int Car::GetAutonomie() const {
	return Autonomie;
}
void Car::SetVitMax(int x) {
	this->VitMax = x;
}
int Car::GetVitMax() {
	return VitMax;
}

class CarStandard : virtual public Car {
protected:
	string TipCombustibil;
	int CapacitateRezervor;
public:
	virtual void CalcAutonomie();
	CarStandard();
	CarStandard(const CarStandard&) = default;
	CarStandard& operator=(const CarStandard&) = default;
	virtual ~CarStandard() = default;
	istream& read(istream& in);
	ostream& print(ostream& out);
};
CarStandard::CarStandard() : Car(), TipCombustibil(""), CapacitateRezervor(0) {}
void CarStandard::CalcAutonomie() {
	Autonomie = CapacitateRezervor / (sqrt(Greutate));
}
istream& CarStandard::read(istream& in) {
	int x;
	cout << "An : ";
	in >> An;
	cout << "Nume : ";
	in >> Nume;
	cout << "Model : ";
	in >> Model;
	cout << "Viteza maxima : ";
	in >> VitMax;
	cout << "Greutate : ";
	in >> Greutate;
	cout << "Tip combustibil ( 1 - Benzina  |  2 - Motorina)  : ";
	in >> x;
	if (x == 1) {
		TipCombustibil = "Benzina";
	}
	else TipCombustibil = "Motorina";
	cout << "Capacitate rezervor : ";
	in >> CapacitateRezervor;
	CalcAutonomie();
	return in;
}

ostream& CarStandard::print(ostream& out) {
	return out;
}


class CarElectric : virtual public Car {
protected:
	int CapacitateBaterie;
public:
	virtual void CalcAutonomie();
	CarElectric();
	CarElectric(const CarElectric&) = default;
	CarElectric& operator=(const CarElectric&) = default;
	virtual ~CarElectric() = default;
	istream& read(istream& in);
	ostream& print(ostream& out);
};
CarElectric::CarElectric() : Car(), CapacitateBaterie(0) {}
void CarElectric::CalcAutonomie() {
	Autonomie = CapacitateBaterie / (Greutate * Greutate);
}
istream& CarElectric::read(istream& in) {
	cout << "An : ";
	in >> An;
	cout << "Nume : ";
	in >> Nume;
	cout << "Model : ";
	in >> Model;
	cout << "Viteza maxima : ";
	in >> VitMax;
	cout << "Greutate : ";
	in >> Greutate;
	cout << "Capacitate baterie : ";
	in >> CapacitateBaterie;
	CalcAutonomie();
	return in;
}

ostream& CarElectric::print(ostream& out) {
	return out;
}


class CarHybrid : public CarElectric, public CarStandard {

public:
	void CalcAutonomie();
	CarHybrid();
	CarHybrid(const CarHybrid&) = default;
	CarHybrid& operator=(const CarHybrid&) = default;
	virtual ~CarHybrid() = default;
	istream& read(istream& in);
	ostream& print(ostream& out);
};
CarHybrid::CarHybrid() : CarStandard(), CarElectric() {}
void CarHybrid::CalcAutonomie() {
	Autonomie = CapacitateRezervor / (sqrt(Greutate)) + CapacitateBaterie / (Greutate * Greutate);
}
istream& CarHybrid::read(istream& in) {
	int x;
	cout << "An : ";
	in >> An;
	cout << "Nume : ";
	in >> Nume;
	cout << "Model : ";
	in >> Model;
	cout << "Viteza maxima : ";
	in >> VitMax;
	cout << "Greutate : ";
	in >> Greutate;
	cout << "Tip combustibil ( 1 - Benzina  |  2 - Motorina)  : ";
	in >> x;
	if (x == 1) {
		TipCombustibil = "Benzina";
	}
	else TipCombustibil = "Motorina";
	cout << "Capacitate rezervor : ";
	in >> CapacitateRezervor;
	cout << "Capacitate baterie : ";
	in >> CapacitateBaterie;
	CalcAutonomie();
	return in;
}

ostream& CarHybrid::print(ostream& out) {
	return out;
}




class Tranzactie {
	string NumeClient;
	int Zi;
	int Luna;
	int An;
	vector<Car*>Modele;
public:
	Tranzactie();
	Tranzactie(const Tranzactie&) = default;
	Tranzactie& operator=(const Tranzactie&) = default;
	~Tranzactie();
	friend istream& operator>>(istream& in, Tranzactie& c);
	friend ostream& operator<<(ostream& out, Tranzactie& c);
};
Tranzactie::Tranzactie() : NumeClient(""), Zi(0), Luna(0), An(0), Modele() {}
Tranzactie::~Tranzactie() {
	for (int i = 0; i < Modele.size(); i++) {
		delete Modele[i];
		Modele.clear();
	}
}


Car* ReadCar() {
	cout << "Tip masina ( 1 - STANDARD  |  2 - ELECTRIC  |  3 - HYBRID : \n";
	int a;
	cin >> a;
	if (a == 1) {
		Car* c = new CarStandard;
		cin >> *c;
		return c;
	}
	else if (a == 2) {
		Car* c = new CarElectric;
		cin >> *c;
		return c;
	}
	else if (a == 3) {
		Car* c = new CarHybrid;
		cin >> *c;
		return c;
	}
}
istream& operator>>(istream& in, Tranzactie& c) {
	cout << "Nume : ";
	in >> c.NumeClient;
	cout << "Zi :";
	in >> c.Zi;
	cout << "Luna :";
	in >> c.Luna;
	cout << "An :";
	in >> c.An;
	cout << "Numar masini achiziotionate : ";
	int nr;
	in >> nr;
	for (int i = 0; i < nr; i++) {
		cout << "Tip masina ( 1 - STANDARD  |  2 - ELECTRIC  |  3 - HYBRID : \n";
		int a;
		cin >> a;
		if (a == 1) {
			Car* v = new CarStandard;
			cin >> *v;
			c.Modele.push_back(v);
			cout << "Masina adaugata\n";
		}
		else if (a == 2) {
			Car* v = new CarElectric;
			cin >> *v;
			c.Modele.push_back(v);
			cout << "Masina adaugata\n";
		}
		else if (a == 3) {
			Car* v = new CarHybrid;
			cin >> *v;
			c.Modele.push_back(v);
			cout << "Masina adaugata\n";
		}
		cout << endl;
	}
	c.Modele.push_back(ReadCar());

	return in;
}
ostream& operator<<(ostream& out, Tranzactie& c) {
	return out;
}


void menu() {
	vector<Tranzactie*>Lista;
	vector<Car*>Masini;
	cout << "1 - Adauga model masina\n" << "2 - Adauga tranzactie\n" << "3 - Afiseaza cel mai vandut model\n"
		<< "4 - Afiseaza modelul cu autonomia cea mai mare\n" << "5 - Optimizare model (Marire viteza max procentual)\n"
		<< "6 - Stop\n";
	bool ok = true;
	int x;
	while (ok == true) {
		cout << "Selectati optiune : ";
		cin >> x;
		if (x == 1) {
			cout << "Tip masina ( 1 - STANDARD  |  2 - ELECTRIC  |  3 - HYBRID : \n";
			int a;
			cin >> a;
			if (a == 1) {
				Car* c = new CarStandard;
				cin >> *c;
				Masini.push_back(c);
				cout << "Masina adaugata\n";
			}
			else if (a == 2) {
				Car* c = new CarElectric;
				cin >> *c;
				Masini.push_back(c);
				cout << "Masina adaugata\n";
			}
			else if (a == 3) {
				Car* c = new CarHybrid;
				cin >> *c;
				Masini.push_back(c);
				cout << "Masina adaugata\n";
			}

		}
		if (x == 2) {
			Tranzactie* t = new Tranzactie;
			cin >> *t;
			Lista.push_back(t);
		}
		if (x == 3) {
			//map<string,int>NumeModele;
			//for (Car* c : Masini) {
			//	ok = 0;
			//	for (auto Nume : NumeModele)
			//		if (c->GetModel() == Nume.first)
			//			ok = 1;
			//	if (ok == 0)
			//		NumeModele.insert(<string,int>c->GetModel(),0);
			//}
		}
		if (x == 4) {
			int max = 0;
			string model;
			for (Car* c : Masini) {
				if (max == 0) {
					max = c->GetAutonomie();
					model = c->GetModel();
				}

				else if (max < c->GetAutonomie()) {
					max = c->GetAutonomie();
					model = c->GetModel();
				}
			}
			cout << "Modelul cu cea mai mare autonomie este : " << model;
		}
		if (x == 5) {
			string Model;
			cout << "Nume model : ";
			cin >> Model;
			cout << "Procent (doar numarul , fara %) : ";
			int procent;
			cin >> procent;
			for (Car* c : Masini) {
				if (c->GetModel() == Model) {
					int viteza = c->GetVitMax();
					viteza += procent / 100 * viteza;
					c->SetVitMax(viteza);
					cout << "Model optimizat cu succes!";
				}

			}
			cout << endl;
		}
		if (x == 6)
			ok = false;
	}
}


int main()
{
	menu();
	return 0;
}
