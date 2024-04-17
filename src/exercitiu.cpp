#include "exercitiu.h"
#include "iostream"

[[maybe_unused]] float exercitiu::getCaloriiArse() const {
    return caloriiArse;
}

const std::string &exercitiu::getNume() const {
    return entitate::getNume();
}

[[maybe_unused]] void exercitiu::setCaloriiArse(float cal) {
    caloriiArse = cal;
}

void exercitiu::setNume(const std::string &nume) {
    entitate::setNume(nume);
}

std::ostream &operator<<(std::ostream &os, const exercitiu &exercitiu) {
    os << static_cast<const entitate&>(exercitiu) << "calorii arse= " << exercitiu.caloriiArse;
    return os;
}

