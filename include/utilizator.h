#ifndef OOP_UTILIZATOR_H
#define OOP_UTILIZATOR_H
#include <utility>

#include "string"
#include "ostream"
#include "iostream"
#include "entitate.h"
class utilizator : public entitate{
private:
    int varsta;
    int inaltime;
    int greutate;
    std :: string sex;

public:
    friend class MyFitnessPal;
    //constructori
    [[maybe_unused]] utilizator(const int &varsta, const int &inaltime, const int &greutate, const std :: string &nume, std :: string sex):
    entitate(nume), varsta(varsta), inaltime(inaltime), greutate(greutate), sex(std::move(sex)) {}

    utilizator(): entitate(), varsta(0), inaltime(0), greutate(0), sex() {}

    [[maybe_unused]] utilizator(const utilizator &u) = default;

    //gettere
//    [[maybe_unused]] [[nodiscard]] int getVarsta() const;
//
//    [[maybe_unused]] [[nodiscard]] int getInaltime() const;

    [[maybe_unused]] [[nodiscard]] const std::string &getNume() const override;

//    [[maybe_unused]] [[nodiscard]] const std::string &getSex() const;
//
//    [[maybe_unused]] [[nodiscard]] int getGreutate() const;

    //settere
//    [[maybe_unused]] void setVarsta(int varsta);
//
//    [[maybe_unused]] void setInaltime(int inaltime);

    [[maybe_unused]] void setNume(const std::string &nume) override;

//    [[maybe_unused]] void setSex(const std::string &sex);
//
//    [[maybe_unused]] void setGreutate(int g);

    //supraincarcare <<
    friend std::ostream &operator<<(std::ostream &os, const utilizator &utilizator);

    //supraincarcare >>
    friend std::istream &operator>>(std :: istream& in, utilizator &utilizator){
        std :: cout << "varsta= ";
        in >> utilizator.varsta;
        std :: cout << "inaltime= ";
        in >> utilizator.inaltime;
        std :: cout << "greutate= ";
        in >> utilizator.greutate;
        std :: cout << "nume= ";
        in >> utilizator.nume;
        std :: cout << "sex= ";
        in >> utilizator.sex;
        return in;
    }

    //supraincarcare == ca functie membra
    bool operator==(const utilizator &rhs) const;

    //supraincarcare != ca functie membra
    friend bool operator!=(const utilizator &lhs, const utilizator &rhs);

    //supraincarcare -- (reseteaza datele utilizatorului) ca functie non-membra
    friend void operator--(utilizator &u);

    //supraincarcare = ca operator de copiere
    utilizator& operator=(const utilizator &rhs);

    void afisareDetalii() const override;

    //destructor
    ~utilizator() override = default;

};
#endif //OOP_UTILIZATOR_H
