#ifndef OOP_MYFITNESSPAL_H
#define OOP_MYFITNESSPAL_H
#include <string>
#include <ostream>
#include <vector>
#include "utilizator.h"
#include "aliment.h"
#include "exercitiu.h"

class MyFitnessPal{
private:
    utilizator user;
    int nivelActivitate;
    double caloriiZilnice;
    double caloriiRamaseDeMancat;
    int nrAlimente;
    int nrExercitii;
    std::vector<aliment> V;
    std::vector<exercitiu> E;

    static const int DEFAULT_SIZE = 0;

public:
    friend class utilizator;

    //constructor
    MyFitnessPal(): user(), nivelActivitate(0), caloriiZilnice(0), caloriiRamaseDeMancat(0), nrAlimente(0), nrExercitii(0), V(DEFAULT_SIZE), E(DEFAULT_SIZE){}//{V = new aliment[nrAlimente];}

    //constructor prin copiere
    MyFitnessPal(const MyFitnessPal &a) : user(a.user), nivelActivitate(a.nivelActivitate), caloriiZilnice(a.caloriiZilnice), caloriiRamaseDeMancat(a.caloriiRamaseDeMancat), nrAlimente(a.nrAlimente), nrExercitii(a.nrExercitii), V(a.V.size()), E(a.E.size()){
        for (int i = 0; i < a.nrAlimente; ++i) {
            V[i] = a.V[i];
        }
        for (int i = 0; i < a.nrExercitii; ++i){
            E[i] = a.E[i];
        }
    }

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
            nrExercitii = a.nrExercitii;
            E = a.E;
        }
        return *this;
    }

    void introducereExercitiu();

    void afisareDetaliiEntitati() const;

    //destructor
    ~MyFitnessPal();
};


#endif //OOP_MYFITNESSPAL_H
