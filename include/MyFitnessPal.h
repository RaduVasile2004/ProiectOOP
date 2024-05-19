#ifndef OOP_MYFITNESSPAL_H
#define OOP_MYFITNESSPAL_H
#include <string>
#include <ostream>
#include <vector>
#include "stack"
#include "queue"
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
    std::stack<aliment> V;
    std::queue<exercitiu> E;

    [[maybe_unused]] static const int DEFAULT_SIZE = 0;


public:
    friend class utilizator;

    //constructor
    MyFitnessPal(): user(), nivelActivitate(0), caloriiZilnice(0), caloriiRamaseDeMancat(0), nrAlimente(0), nrExercitii(0){}//{V = new aliment[nrAlimente];}

    //constructor prin copiere
    MyFitnessPal(const MyFitnessPal &a) = default;

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
    MyFitnessPal& operator=(const MyFitnessPal &a){
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
