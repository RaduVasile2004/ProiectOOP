#include "aliment.h"

[[maybe_unused]] float aliment::getCalorii() const {
    return calorii;
}

//[[maybe_unused]] void aliment::setCalorii(float cal) {
//    aliment::calorii = cal;
//}

const std::string &aliment::getNume() const {
    return entitate::getNume();
}

void aliment::setNume(const std::string &n) {
    entitate::setNume(n);
}

std::ostream &operator<<(std::ostream &os, const aliment &aliment) {
    os << static_cast<const entitate&>(aliment) << "calorii= " << aliment.calorii;
    return os;
}

bool aliment::sanatateAliment() const {
    //daca are mai mult de 500 calorii nu e sanatos
    if(calorii > 500)
        return false;//nesanatos
    else
        return true;
}

void aliment::afisareDetalii() const {
    std::cout << "Nume: " << nume << "\n";
    std::cout << "Calorii: " << calorii << "\n";
}
