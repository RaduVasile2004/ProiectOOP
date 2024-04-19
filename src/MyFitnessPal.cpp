#include <iostream>
#include <string>
#include "MyFitnessPal.h"
#include "utilizator.h"
#include "aliment.h"
#include "exercitiu.h"
#include "stdexcept"
using namespace std;

MyFitnessPal :: ~MyFitnessPal(){
//    delete[] V;
    nrAlimente = 0;
    caloriiZilnice = 0;
    caloriiRamaseDeMancat = 0;
    nivelActivitate = 0;
    user.varsta = 0;
    user.sex.clear();
    user.greutate = 0;
    user.nume.clear();
    user.inaltime = 0;
}
//
//[[maybe_unused]] int MyFitnessPal::getNivelActivitate() const {
//    return nivelActivitate;
//}
//
//[[maybe_unused]] double MyFitnessPal::getCaloriiZilnice() const {
//    return caloriiZilnice;
//}
//
//[[maybe_unused]] void MyFitnessPal::setNivelActivitate(int n) {
//    MyFitnessPal::nivelActivitate = n;
//}
//
//[[maybe_unused]] void MyFitnessPal::setCaloriiZilnice(float c) {
//    MyFitnessPal::caloriiZilnice = c;
//}

void MyFitnessPal::introducereUtilizator() {
    cin >> user;
}

void MyFitnessPal::afisareUtilizator() {
    cout << user;
}
//
//[[maybe_unused]] const utilizator &MyFitnessPal::getUser() const {
//    return user;
//}
//
//[[maybe_unused]] void MyFitnessPal::setUser([[maybe_unused]] const utilizator &u) {
//    MyFitnessPal::user = u;
//}


void MyFitnessPal::ecranPrincipal() {
    bool exitLoop = false;
    while (!exitLoop) {
        int optiune;
        cout << "[1] Introducere utilizator\n";
        cout << "[2] Afisare utilizator\n";
        cout << "[3] Calculator calorii zilnice\n";
        cout << "[4] Introducere aliment consumat\n";
        cout << "[5] Numar de calorii ramase de mancat pentru azi\n";
        cout << "[6] Introducere exercitiu\n";
        cout << "[7] Afisare statistici\n";
        cout << "[8] Iesire\n";
        cin >> optiune;

        switch (optiune) {
            case 1:
                introducereUtilizator();
                cout << string(50, '\n');
                break;
            case 2:
                if (user.varsta == 0) {
                    cout << "Nu ati introdus un utilizator!\n";
                    break;
                }
                afisareUtilizator();
                cout << "\n";
                break;
            case 3:
                if (user.varsta == 0) {
                    cout << "Nu ati introdus un utilizator!\n";
                    break;
                }
                calcCaloriiZilnice();
                break;
            case 4:
                if (user.varsta == 0) {
                    cout << "Nu ati introdus un utilizator!\n";
                    break;
                }
                introducereAliment();
                break;
            case 5:
                if (user.varsta == 0) {
                    cout << "Nu ati introdus un utilizator!\n";
                    break;
                }
                nrCaloriiRamase();
                break;
            case 6:
                introducereExercitiu();
                break;
            case 7:
                afisareDetaliiEntitati();
                break;
            case 8:
                cout << string(50, '\n');
                exitLoop = true; // Set the flag to exit the loop
                break;
            default:
                cout << "Optiune invalida" << endl;
                break;
        }
    }
}


void MyFitnessPal::calcCaloriiZilnice() {
    int optiune;
    double BMR;

    if(nivelActivitate == 0)
    {
        cout << "Estimati-va nivelul de activitate pe o scara de la 1 la 10\n";
        cin >> nivelActivitate;
    }


    if (user.sex == "M" || user.sex == "m")
        BMR = 66.50 + (13.75 * user.greutate) + (5.003 * user.inaltime) - (6.75 * user.varsta);
    else
        BMR = 655.10 + (9.563 * user.greutate) + (1.850 * user.inaltime) - (4.676 * user.varsta);

    if (nivelActivitate < 2)
    {
        BMR = BMR * 1.2;
    } // sedentar

    else if (nivelActivitate < 4) // putin activ
    {
        BMR = BMR * 1.375;
    }
    else if (nivelActivitate < 7) // activ
    {
        BMR = BMR * 1.55;
    }
    else if (nivelActivitate < 9) // foarte activ
    {
        BMR = BMR * 1.725;
    }
    else
    {
        BMR = BMR * 1.9;
    }

    cout << "Selectati scopul pe care il aveti:\n[1]Bulk\n[2]Cut\n[3]Maintain\n";
    cin >> optiune;
    switch (optiune) {
        case 1:
            caloriiZilnice = BMR * 1.2;
            break;
        case 2:
            caloriiZilnice = BMR * 0.8;
            break;
        case 3:
            caloriiZilnice = BMR;
            break;
        default :
            cout << "Optiune invalida" << endl;
            break;
    }
    cout << "Trebuie sa mancati " << caloriiZilnice << " calorii zilnic\n";

}

//[[maybe_unused]] double MyFitnessPal::getCaloriiRamaseDeMancat() const {
//    return caloriiRamaseDeMancat;
//}
//
//[[maybe_unused]] void MyFitnessPal::setCaloriiRamaseDeMancat(float cal) {
//    MyFitnessPal::caloriiRamaseDeMancat = cal;
//}

void MyFitnessPal::introducereAliment() {
//    aliment a;
//    cout << "Introduceti numele alimentului consumat si numarul sau de calorii\n";
//    cin >> a;
//
//    bool sanatos = a.sanatateAliment();
//    if(sanatos)
//        cout << "Felicitari pentru alegere!\n";
//    else
//        cout << "Aveti grija, alimentul e cam nesanatos!\n";
//    V.push_back(a);
//    nrAlimente++;
    try {
        aliment a;
        cout << "Introduceti numele alimentului consumat si numarul sau de calorii\n";
        cin >> a;

        // Verificăm dacă numele alimentului este gol
        if (a.getNume().empty()) {
            throw invalid_argument("Numele alimentului nu poate fi gol!");
        }

        // Verificăm dacă numărul de calorii este negativ
        if (a.getCalorii() < 0) {
            throw invalid_argument("Numarul de calorii nu poate fi negativ!");
        }

        bool sanatos = a.sanatateAliment();
        if (sanatos)
            std::cout << "Felicitari pentru alegere!\n";
        else
            std::cout << "Aveti grija, alimentul e cam nesanatos!\n";
        V.push_back(a);
        nrAlimente++;
    } catch (const invalid_argument &e) {
        // Prindem excepțiile de tip invalid_argument (sau orice alt tip derivat din std::exception)
        // Putem face upcasting la std::exception pentru a afișa mesajul de eroare generic
        std::cout << "Eroare: " << e.what() << endl;
    }
}

void MyFitnessPal::nrCaloriiRamase() {
    float calMancate = 0;
    float calArse = 0;
    for (int i = 0; i < nrAlimente; i++)
        calMancate += V[i].getCalorii();
    for (int i = 0; i < nrExercitii; i++)
        calArse += E[i].getCaloriiArse();
    caloriiRamaseDeMancat = caloriiZilnice - calMancate + calArse;
    cout << "Mai trebuie sa mancati " << caloriiRamaseDeMancat << " calorii azi\n";
}

void MyFitnessPal::introducereExercitiu() {
//    exercitiu e;
//    cin >> e;
//    E.push_back(e);
//    nrExercitii++;
    try {
        exercitiu e;
        cout << "Introduceti numele exercitiul efectuat si numarul de calorii arse\n";
        cin >> e;

        // Verificăm dacă numele alimentului este gol
        if (e.getNume().empty()) {
            throw invalid_argument("Numele exercitiului nu poate fi gol!");
        }

        // Verificăm dacă numărul de calorii este negativ
        if (e.getCaloriiArse() < 0) {
            throw invalid_argument("Numarul de calorii arse nu poate fi negativ!");
        }

        E.push_back(e);
        nrExercitii++;
    } catch (const invalid_argument &t) {
        // Prindem excepțiile de tip invalid_argument (sau orice alt tip derivat din std::exception)
        // Putem face upcasting la std::exception pentru a afișa mesajul de eroare generic
        std::cout << "Eroare: " << t.what() << endl;
    }
}

//[[maybe_unused]] int MyFitnessPal::getNrExercitii() const {
//    return nrExercitii;
//}
//
//[[maybe_unused]] void MyFitnessPal::setNrExercitii(int nr) {
//    MyFitnessPal::nrExercitii = nr;
//}

void MyFitnessPal::afisareDetaliiEntitati() const {
    cout << "Detalii utilizator:\n";
    const entitate* entitateUtilizator = &user;
    entitateUtilizator->afisareDetalii();

    cout << "Alimente consumate:\n";
    for (const auto& aliment : V) {
        const entitate* entitateAliment = &aliment;
        entitateAliment->afisareDetalii();
    }

    cout << "Exercitii efectuate:\n";
    for (const auto& exercitiu : E) {
        const entitate* entitateExercitiu = &exercitiu;
        entitateExercitiu->afisareDetalii();
    }
}


