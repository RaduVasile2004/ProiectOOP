#ifndef OOP_exercitiu_H
#define OOP_exercitiu_H
#include "entitate.h"
#include "iostream"
class [[maybe_unused]] exercitiu : public entitate {
private:
    float caloriiArse;

public:
    exercitiu() : entitate(), caloriiArse(0) {}
    [[maybe_unused]] exercitiu(const std::string& nume, float cal) : entitate(nume), caloriiArse(cal) {}
    exercitiu(const exercitiu& other) : entitate(other.nume) , caloriiArse(other.caloriiArse){}
    exercitiu& operator=(const exercitiu& other) {
        if (this != &other) {
            nume = other.nume;
            caloriiArse = other.caloriiArse;
        }
        return *this;
    }

    [[maybe_unused]] [[maybe_unused]] [[nodiscard]] float getCaloriiArse() const;
    [[maybe_unused]] [[nodiscard]] const std::string &getNume() const override;

    [[maybe_unused]] void setNume(const std::string &n) override;

    friend std::ostream &operator<<(std::ostream &os, const exercitiu &exercitiu);
    friend std::istream &operator>>(std :: istream& in, exercitiu &exercitiu) {
        std :: cout << "nume= ";
        in >> exercitiu.nume;
        std :: cout << "calorii arse= ";
        in >> exercitiu.caloriiArse;

        return in;
    }

    void afisareDetalii() const override;

    ~exercitiu() override = default;
};
#endif //OOP_exercitiu_H
