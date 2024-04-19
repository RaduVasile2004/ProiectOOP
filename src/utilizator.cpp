#include "utilizator.h"
#include "ostream"
using namespace std;

//constructor prin copiere
//[[maybe_unused]] utilizator::utilizator(const utilizator &u)  : entitate(u) {
//    varsta = u.varsta;
//    inaltime = u.inaltime;
//    greutate = u.greutate;
//    sex = u.sex;
//    nume = u.nume;
//}



//settere
//[[maybe_unused]] void utilizator::setVarsta(int v) {
//    utilizator::varsta = v;
//}
//
//[[maybe_unused]] void utilizator::setInaltime(int i) {
//    utilizator::inaltime = i;
//}

[[maybe_unused]] void utilizator::setNume(const std::string &n) {
    utilizator::nume = n;
}
//
//[[maybe_unused]] void utilizator::setSex(const std::string &s) {
//    utilizator::sex = s;
//}
//
////gettere
//[[maybe_unused]] int utilizator::getVarsta() const {
//    return varsta;
//}
//
//[[maybe_unused]] int utilizator::getInaltime() const {
//    return inaltime;
//}

[[maybe_unused]] const std::string &utilizator::getNume() const {
    return nume;
}

//[[maybe_unused]] const std::string &utilizator::getSex() const {
//    return sex;
//}

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

//[[maybe_unused]] int utilizator::getGreutate() const {
//    return greutate;
//}
//
//[[maybe_unused]] void utilizator::setGreutate(int g) {
//    utilizator::greutate = g;
//}

void utilizator::afisareDetalii() const {
    std::cout << "Nume: " << nume << "\n";
    std::cout << "Varsta: " << varsta << "\n";
    std::cout << "Inaltime: " << inaltime << "\n";
    std::cout << "Greutate: " << greutate << "\n";
    std::cout << "Sex: " << sex << "\n";
}