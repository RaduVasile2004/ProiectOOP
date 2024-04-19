#ifndef OOP_ALIMENT_H
#define OOP_ALIMENT_H
#include "string"
#include "entitate.h"
#include "iostream"

class aliment : public entitate{
private:
    float calorii;
public:
    aliment(): entitate(), calorii(0){}
    [[maybe_unused]] aliment(const std::string& nume, float cal): entitate(nume), calorii(cal){}
    aliment(const aliment& other) : entitate(other.nume), calorii(other.calorii) {}
    aliment& operator=(const aliment& other) {
        if (this != &other) {
            nume = other.nume;
            calorii = other.calorii;
        }
        return *this;
    }

    [[maybe_unused]] [[nodiscard]] float getCalorii() const;
    [[maybe_unused]] [[nodiscard]] const std::string &getNume() const override;

//    [[maybe_unused]] void setCalorii(float cal);
    [[maybe_unused]] void setNume(const std::string &n) override;

    [[nodiscard]] bool sanatateAliment() const;

    friend std::istream &operator>>(std :: istream& in, aliment &aliment) {
        std :: cout << "nume= ";
        in >> aliment.nume;
        std :: cout << "calorii= ";
        in >> aliment.calorii;

        return in;
    }
    friend std::ostream &operator<<(std::ostream &os, const aliment &aliment);

    void afisareDetalii() const override;

    ~aliment() override = default;
};

#endif //OOP_ALIMENT_H
