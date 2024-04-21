#include "exercitiu.h"
#include "iostream"

[[maybe_unused]] float exercitiu::getCaloriiArse() const {
    return caloriiArse;
}

const std::string &exercitiu::getNume() const {
    return entitate::getNume();
}

void exercitiu::setNume(const std::string &n) {
    entitate::setNume(n);
}

std::ostream &operator<<(std::ostream &os, const exercitiu &exercitiu) {
    os << static_cast<const entitate&>(exercitiu) << "calorii arse= " << exercitiu.caloriiArse;
    return os;
}

void exercitiu::afisareDetalii() const {
    std::cout << "Nume: " << nume << "\n";
    std::cout << "Calorii arse: " << caloriiArse << "\n";
}
