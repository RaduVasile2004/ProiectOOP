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
    MyFitnessPal(): user(), nivelActivitate(0), caloriiZilnice(0), caloriiRamaseDeMancat(0), nrAlimente(0), nrExercitii(0){}//{V = new aliment[nrAlimente];}


public:
    friend class utilizator;

    static MyFitnessPal& getInstance() {
        static MyFitnessPal instance;
        return instance;
    }

    MyFitnessPal(const MyFitnessPal &a) = delete;

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

    MyFitnessPal& operator=(const MyFitnessPal &a) = delete;

    void introducereExercitiu();

    void afisareDetaliiEntitati();

    void sortAlimente();

    void sortExercitii();

    //destructor
    ~MyFitnessPal();
};


#endif //OOP_MYFITNESSPAL_H
