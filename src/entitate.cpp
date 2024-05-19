#include "entitate.h"
#include "iostream"
std::ostream &operator<<(std::ostream &os, const entitate &entitate) {
    os << "nume" << entitate.nume;
    return os;
}
