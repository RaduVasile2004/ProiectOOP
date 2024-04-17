#ifndef OOP_ENTITATE_H
#define OOP_ENTITATE_H
#include <utility>

#include "string"
class entitate {
protected:
    std::string nume;

public:
    // Constructor implicit
    entitate() : nume() {}

    // Constructor cu parametri
    explicit entitate(std::string  nume) : nume(std::move(nume)) {}

    // Getter pentru nume
    [[maybe_unused]] [[nodiscard]] virtual const std::string& getNume() const {
        return nume;
    }

    // Setter pentru nume
    [[maybe_unused]] virtual void setNume(const std::string& n) {
        this->nume = n;
    }

    friend std::ostream &operator<<(std::ostream &os, const entitate &entitate);

    [[maybe_unused]] virtual void afisareDetalii() const = 0;

    // Destructor virtual
    virtual ~entitate() = default;
};
#endif //OOP_ENTITATE_H
