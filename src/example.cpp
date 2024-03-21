#include <iostream>
#include <string>
#include "example.h"
using namespace std;

//constructor cu parametri
[[maybe_unused]] utilizator ::utilizator(const int &varsta, const int &inaltime, const int &greutate, const std::string &nume, const std::string &sex) {
    this -> varsta = varsta;
    this -> inaltime = inaltime;
    this -> greutate = greutate;
    this -> nume = nume;
    this -> sex = sex;
}

//constructor prin copiere
[[maybe_unused]] utilizator::utilizator(utilizator &u) {
    varsta = u.varsta;
    inaltime = u.inaltime;
    greutate = u.greutate;
    sex = u.sex;
    nume = u.nume;
}

//destructor
utilizator ::~utilizator() {
    varsta = 0;
    inaltime = 0;
    greutate = 0;
    nume.clear();
    sex.clear();
}

//settere
[[maybe_unused]] void utilizator::setVarsta(int v) {
    utilizator::varsta = v;
}

[[maybe_unused]] void utilizator::setInaltime(int i) {
    utilizator::inaltime = i;
}

[[maybe_unused]] void utilizator::setNume(const std::string &n) {
    utilizator::nume = n;
}

[[maybe_unused]] void utilizator::setSex(const std::string &s) {
    utilizator::sex = s;
}

//gettere
[[maybe_unused]] int utilizator::getVarsta() const {
    return varsta;
}

[[maybe_unused]] int utilizator::getInaltime() const {
    return inaltime;
}

[[maybe_unused]] const std::string &utilizator::getNume() const {
    return nume;
}

[[maybe_unused]] const std::string &utilizator::getSex() const {
    return sex;
}

ostream &operator<<(ostream &os, const utilizator &utilizator) {
    os << "varsta: " << utilizator.varsta << " inaltime: " << utilizator.inaltime << " greutate: " << utilizator.greutate << " nume: " << utilizator.nume
       << " sex: " << utilizator.sex;
    return os;
}

bool utilizator::operator==(const utilizator &rhs) const {
    return varsta == rhs.varsta &&
           inaltime == rhs.inaltime &&
           greutate == rhs.greutate &&
           nume == rhs.nume &&
           sex == rhs.sex;
}

void operator--(utilizator &u) {
    u.varsta = 0;
    u.inaltime = 0;
    u.greutate = 0;
    u.nume.clear();
    u.sex.clear();
}

bool operator!=(const utilizator &lhs, const utilizator &rhs) {
    return !(rhs == lhs);
}

//supraincarcare =
utilizator& utilizator::operator=(const utilizator &rhs) {
    if(this != &rhs)
    {
        varsta = rhs.varsta;
        inaltime = rhs.varsta;
        greutate = rhs.greutate;
        sex = rhs.sex;
        nume = rhs.nume;
    }
    return *this;
}

[[maybe_unused]] int utilizator::getGreutate() const {
    return greutate;
}

[[maybe_unused]] void utilizator::setGreutate(int g) {
    utilizator::greutate = g;
}











//istream &operator>>(istream &in, const utilizator &utilizator) {
//    cout << "varsta= ";
//    in >> utilizator.varsta;
//    cout << "inaltime= ";
//    in >> (utilizator.inaltime);
//    cout << "nume= ";
//    in >> (utilizator.nume);
//    cout << "sex= ";
//    in >> (utilizator.sex);
//    return in;
//}





MyFitnessPal :: ~MyFitnessPal()= default;

[[maybe_unused]] int MyFitnessPal::getNivelActivitate() const {
    return nivelActivitate;
}

[[maybe_unused]] float MyFitnessPal::getCaloriiZilnice() const {
    return caloriiZilnice;
}

[[maybe_unused]] void MyFitnessPal::setNivelActivitate(int n) {
    MyFitnessPal::nivelActivitate = n;
}

[[maybe_unused]] void MyFitnessPal::setCaloriiZilnice(float c) {
    MyFitnessPal::caloriiZilnice = c;
}

void MyFitnessPal::introducereUtilizator() {
    //utilizator u;
    cin >> user;
    //user = u;
}

void MyFitnessPal::afisareUtilizator() {
    cout << user;
}

[[maybe_unused]] const utilizator &MyFitnessPal::getUser() const {
    return user;
}

[[maybe_unused]] void MyFitnessPal::setUser(const utilizator &u) {
    MyFitnessPal::user = u;
}

void MyFitnessPal::ecranPrincipal() {
    int optiune;
    //cout << "My Fitness Pal\nde Radu-Mihai Vasile\nAlegeti o optiune:\n";
    cout << "[1] Introducere utilizator\n";
    cout << "[2] Afisare utilizator\n";
    cout << "[3] Calculator calorii zilnice\n";
    cout << "[4] Introducere aliment consumat\n";
    cout << "[5] Numar de calorii ramase de mancat pentru azi\n";
    cout << "[6] Iesire\n";
    cin >> optiune;
    switch (optiune) {
        case 1:
            introducereUtilizator();
            cout << string(50, '\n');
            ecranPrincipal();
            break;
        case 2:
            if (user.varsta == 0)
            {
                cout << "Nu ati introdus un utilizator!\n";
                ecranPrincipal();
                break;
            }

            afisareUtilizator();
            cout << "\n";
            ecranPrincipal();
            break;
        case 3:
            if (user.varsta == 0)
            {
                cout << "Nu ati introdus un utilizator!\n";
                ecranPrincipal();
                break;
            }

            calcCaloriiZilnice();
            ecranPrincipal();
            break;
        case 4:
            if (user.varsta == 0)
            {
                cout << "Nu ati introdus un utilizator!\n";
                ecranPrincipal();
                break;
            }

            introducereAliment();
            ecranPrincipal();
            break;
        case 5:
            if (user.varsta == 0)
            {
                cout << "Nu ati introdus un utilizator!\n";
                ecranPrincipal();
                break;
            }

            nrCaloriiRamase();
            ecranPrincipal();
            break;
        case 6:
            cout << string(50, '\n');
            break;
        default:
            cout << "Optiune invalida" << endl;
            break;
    }
}

void MyFitnessPal::calcCaloriiZilnice() {
    int optiune;
    double BMR;

    if(nivelActivitate == 0)
    {
        cout << "Estimati-va nivelul de activitate pe o scara de la 1 la 10\n";
        cin >> nivelActivitate;
    }


    if (user.sex == "M" || user.sex == "m")
        BMR = 66.50 + (13.75 * user.greutate) + (5.003 * user.inaltime) - (6.75 * user.varsta);
    else
        BMR = 655.10 + (9.563 * user.greutate) + (1.850 * user.inaltime) - (4.676 * user.varsta);

    if (nivelActivitate < 2)
    {
        BMR = BMR * 1.2;
    } // sedentar

    else if (nivelActivitate >= 2 && nivelActivitate < 4) // putin activ
    {
        BMR = BMR * 1.375;
    }
    else if (nivelActivitate >= 4 && nivelActivitate < 7) // activ
    {
        BMR = BMR * 1.55;
    }
    else if (nivelActivitate >= 7 && nivelActivitate < 9) // foarte activ
    {
        BMR = BMR * 1.725;
    }
    else
    {
        BMR = BMR * 1.9;
    }

    cout << "Selectati scopul pe care il aveti:\n[1]Bulk\n[2]Cut\n[3]Maintain\n";
    cin >> optiune;
    switch (optiune) {
        case 1:
            caloriiZilnice = BMR * 1.2;
            break;
        case 2:
            caloriiZilnice = BMR * 0.8;
            break;
        case 3:
            caloriiZilnice = BMR;
        default :
            cout << "Optiune invalida" << endl;
            break;
    }
    cout << "Trebuie sa mancati " << caloriiZilnice << " calorii zilnic\n";
}

[[maybe_unused]] float MyFitnessPal::getCaloriiRamaseDeMancat() const {
    return caloriiRamaseDeMancat;
}

[[maybe_unused]] void MyFitnessPal::setCaloriiRamaseDeMancat(float cal) {
    MyFitnessPal::caloriiRamaseDeMancat = cal;
}

void MyFitnessPal::introducereAliment() {
    aliment a;

    cout << "Introduceti numele alimentului consumat si numarul sau de calorii\n";
    cin >> a.nume;
    cin >> a.calorii;
    aliment *aux;
    aux = new aliment[nrAlimente + 1];
    for (int i = 0; i < nrAlimente; i++) {
        aux[i] = V[i];
    }
    aux[nrAlimente] = a;
    delete[] V;
    V = aux;
    nrAlimente++;
}

void MyFitnessPal::nrCaloriiRamase() {
    float calMancate = 0;
    for (int i = 0; i < nrAlimente; i++)
        calMancate += V[i].calorii;
    caloriiRamaseDeMancat = caloriiZilnice - calMancate;
    cout << "Mai trebuie sa mancati " << caloriiRamaseDeMancat << " calorii azi\n";
}


