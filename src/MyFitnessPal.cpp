#include <iostream>
#include <string>
#include "MyFitnessPal.h"
#include "utilizator.h"
#include "aliment.h"
#include "exercitiu.h"
#include "stdexcept"
using namespace std;

MyFitnessPal :: ~MyFitnessPal(){
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

void MyFitnessPal::introducereUtilizator() {
    cin >> user;
}

void MyFitnessPal::afisareUtilizator() {
    cout << user;
}

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


void MyFitnessPal::introducereAliment() {
    try {
        aliment a;
        cout << "Introduceti numele alimentului consumat si numarul sau de calorii\n";
        cin >> a;

        if (a.getNume().empty()) {
            throw invalid_argument("Numele alimentului nu poate fi gol!");
        }
        if (a.getCalorii() < 0) {
            throw invalid_argument("Numarul de calorii nu poate fi negativ!");
        }

        bool sanatos = a.sanatateAliment();
        if (sanatos)
            std::cout << "Felicitari pentru alegere!\n";
        else
            std::cout << "Aveti grija, alimentul e cam nesanatos!\n";
        V.push(a);
        nrAlimente++;
    } catch (const invalid_argument &e) {
        std::cout << "Eroare: " << e.what() << endl;
    }
}

void MyFitnessPal::nrCaloriiRamase() {
    float calMancate = 0;
    float calArse = 0;
//    for (int i = 0; i < nrAlimente; i++)
//        calMancate += V[i].getCalorii();
    std::stack<aliment> tempStack = V;

    // Iterăm prin copia temporară a stivei
    while (!tempStack.empty()) {
        // Obținem elementul din vârful stivei temporare
        aliment a = tempStack.top();
        // Adăugăm numărul de calorii al alimentului la totalul caloriilor mâncate
        calMancate += a.getCalorii();
        // Eliminăm elementul din vârful stivei temporare
        tempStack.pop();
    }
    std::queue<exercitiu> tempQueue = E;

    // Iterăm prin copia temporară a cozii
    while (!tempQueue.empty()) {
        // Obținem exercițiul din fața cozii temporare
        exercitiu ex = tempQueue.front();
        // Adăugăm numărul de calorii arse de exercițiu la totalul caloriilor arse
        calArse += ex.getCaloriiArse();
        // Eliminăm exercițiul din fața cozii temporare
        tempQueue.pop();
    }
    caloriiRamaseDeMancat = caloriiZilnice - calMancate + calArse;
    cout << "Mai trebuie sa mancati " << caloriiRamaseDeMancat << " calorii azi\n";
}

void MyFitnessPal::introducereExercitiu() {
    try {
        exercitiu e;
        cout << "Introduceti numele exercitiului efectuat si numarul de calorii arse\n";
        cin >> e;

        if (e.getNume().empty()) {
            throw invalid_argument("Numele exercitiului nu poate fi gol!");
        }
        if (e.getCaloriiArse() < 0) {
            throw invalid_argument("Numarul de calorii arse nu poate fi negativ!");
        }

        E.push(e);
        nrExercitii++;
    } catch (const invalid_argument &t) {
        std::cout << "Eroare: " << t.what() << endl;
    }
}


void MyFitnessPal::afisareDetaliiEntitati() const {
    cout << "Detalii utilizator:\n";
    const entitate* entitateUtilizator = &user;
    entitateUtilizator->afisareDetalii();

    cout << "Alimente consumate:\n";
    // Creăm o copie temporară a stivei V pentru a nu o modifica
    std::stack<aliment> tempStack = V;

    // Iterăm prin copia temporară a stivei
    while (!tempStack.empty()) {
        // Obținem elementul din vârful stivei temporare
        const aliment& aliment = tempStack.top();
        const entitate* entitateAliment = &aliment;
        entitateAliment->afisareDetalii();
        // Eliminăm elementul din vârful stivei temporare
        tempStack.pop();
    }

    cout << "Exercitii efectuate:\n";
    std::queue<exercitiu> tempQueue = E;

    // Iterăm prin coada temporară
    while (!tempQueue.empty()) {
        const exercitiu& ex = tempQueue.front(); // Obținem exercițiul din fața cozii temporare
        const entitate* entitateExercitiu = &ex;
        entitateExercitiu->afisareDetalii(); // Afișăm detaliile exercițiului
        tempQueue.pop(); // Eliminăm exercițiul din fața cozii temporare pentru a avansa la următorul
    }
}


