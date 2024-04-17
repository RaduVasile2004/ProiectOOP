#include "aliment.h"

[[maybe_unused]] float aliment::getCalorii() const {
    return calorii;
}

[[maybe_unused]] void aliment::setCalorii(float cal) {
    aliment::calorii = cal;
}

const std::string &aliment::getNume() const {
    return entitate::getNume();
}

void aliment::setNume(const std::string &nume) {
    entitate::setNume(nume);
}

std::ostream &operator<<(std::ostream &os, const aliment &aliment) {
    os << static_cast<const entitate&>(aliment) << "calorii= " << aliment.calorii;
    return os;
}
