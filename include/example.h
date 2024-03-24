#ifndef OOP_EXAMPLE_H
#define OOP_EXAMPLE_H
#include <string>
#include <ostream>
#include <vector>

struct aliment{
    std::string nume;
    float calorii = 0;
};

class utilizator{
private:
    int varsta;
    int inaltime;
    int greutate;
    std :: string nume;
    std :: string sex;

public:
    friend class MyFitnessPal;
    //constructori
    [[maybe_unused]] utilizator(const int &varsta, const int &inaltime, const int &greutate, const std :: string &nume, const std :: string &sex);

    utilizator(): varsta(0), inaltime(0), greutate(0){};

    [[maybe_unused]] utilizator(const utilizator &u);

    //gettere
    [[maybe_unused]] [[nodiscard]] int getVarsta() const;

    [[maybe_unused]] [[nodiscard]] int getInaltime() const;

    [[maybe_unused]] [[nodiscard]] const std::string &getNume() const;

    [[maybe_unused]] [[nodiscard]] const std::string &getSex() const;

    [[maybe_unused]] [[nodiscard]] int getGreutate() const;

    //settere
    [[maybe_unused]] void setVarsta(int varsta);

    [[maybe_unused]] void setInaltime(int inaltime);

    [[maybe_unused]] void setNume(const std::string &nume);

    [[maybe_unused]] void setSex(const std::string &sex);

    [[maybe_unused]] void setGreutate(int g);

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

    //destructor
    ~utilizator();

};

class MyFitnessPal{
private:
    utilizator user;
    int nivelActivitate;
    double caloriiZilnice;
    double caloriiRamaseDeMancat;
    int nrAlimente;
    aliment *V;

    [[maybe_unused]] void allocateMemory(int newSize) {
        auto *newV = new aliment[newSize];
        for (int i = 0; i < nrAlimente; ++i) {
            newV[i] = V[i];
        }
        delete[] V;
        V = newV;
    }

public:
    friend class utilizator;

    //constructor
    MyFitnessPal(): user(), nivelActivitate(0), caloriiZilnice(0), caloriiRamaseDeMancat(0), nrAlimente(0){V = new aliment[nrAlimente];};

    //constructor prin copiere
    MyFitnessPal(const MyFitnessPal &a) : user(a.user), nivelActivitate(a.nivelActivitate), caloriiZilnice(a.caloriiZilnice), caloriiRamaseDeMancat(a.caloriiRamaseDeMancat), nrAlimente(a.nrAlimente), V(new aliment[a.nrAlimente]){
        for (int i = 0; i < a.nrAlimente; ++i) {
            V[i] = a.V[i];
        }
    }

    //gettere
    [[maybe_unused]] [[nodiscard]] int getNivelActivitate() const;

    [[maybe_unused]] [[nodiscard]] double getCaloriiZilnice() const;

    [[maybe_unused]] [[nodiscard]] const utilizator &getUser() const;

    [[maybe_unused]] [[nodiscard]] double getCaloriiRamaseDeMancat() const;

    //settere
    [[maybe_unused]] void setNivelActivitate(int n);

    [[maybe_unused]] void setCaloriiZilnice(float c);

    [[maybe_unused]] void setUser(const utilizator &user);

    [[maybe_unused]] void setCaloriiRamaseDeMancat(float cal);

    //introducere utilizator
    void introducereUtilizator();

    //afisare utilizaror
    void afisareUtilizator();

    //ecran principal
    void ecranPrincipal();

    //calculator calorii
    void calcCaloriiZilnice();

    //introducere aliment
    void introducereAliment();

    //nr calorii ramase de mancat
    void nrCaloriiRamase();

    //supraincarcare =
    MyFitnessPal& operator=(const MyFitnessPal &a) {
        if(this != &a)
        {
            nivelActivitate = a.nivelActivitate;
            caloriiZilnice = a.caloriiZilnice;
            caloriiRamaseDeMancat = a.caloriiRamaseDeMancat;
            nrAlimente = a.nrAlimente;
            V = a.V;
            user = a.user;
        }
        return *this;
    }

    //destructor
    ~MyFitnessPal();
};


#endif //OOP_EXAMPLE_H
