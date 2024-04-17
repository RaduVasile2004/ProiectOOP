#include <iostream>
#include <string>
#include "MyFitnessPal.h"
#include "utilizator.h"
#include "aliment.h"
using namespace std;

MyFitnessPal :: ~MyFitnessPal(){
    delete[] V;
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

[[maybe_unused]] int MyFitnessPal::getNivelActivitate() const {
    return nivelActivitate;
}

[[maybe_unused]] double MyFitnessPal::getCaloriiZilnice() const {
    return caloriiZilnice;
}

[[maybe_unused]] void MyFitnessPal::setNivelActivitate(int n) {
    MyFitnessPal::nivelActivitate = n;
}

[[maybe_unused]] void MyFitnessPal::setCaloriiZilnice(float c) {
    MyFitnessPal::caloriiZilnice = c;
}

void MyFitnessPal::introducereUtilizator() {
    cin >> user;
}

void MyFitnessPal::afisareUtilizator() {
    cout << user;
}

[[maybe_unused]] const utilizator &MyFitnessPal::getUser() const {
    return user;
}

[[maybe_unused]] void MyFitnessPal::setUser(const utilizator &u) {
    MyFitnessPal::user = u;
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
        cout << "[6] Iesire\n";
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

    else if (nivelActivitate >= 2 && nivelActivitate < 4) // putin activ
    {
        BMR = BMR * 1.375;
    }
    else if (nivelActivitate >= 4 && nivelActivitate < 7) // activ
    {
        BMR = BMR * 1.55;
    }
    else if (nivelActivitate >= 7 && nivelActivitate < 9) // foarte activ
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

[[maybe_unused]] double MyFitnessPal::getCaloriiRamaseDeMancat() const {
    return caloriiRamaseDeMancat;
}

[[maybe_unused]] void MyFitnessPal::setCaloriiRamaseDeMancat(float cal) {
    MyFitnessPal::caloriiRamaseDeMancat = cal;
}

void MyFitnessPal::introducereAliment() {
    aliment a;
    cout << "Introduceti numele alimentului consumat si numarul sau de calorii\n";
    cin >> a;

    allocateMemory(nrAlimente + 1);

    V[nrAlimente] = a;
    nrAlimente++;
}

void MyFitnessPal::nrCaloriiRamase() {
    float calMancate = 0;
    for (int i = 0; i < nrAlimente; i++)
        calMancate += V[i].getCalorii();
    caloriiRamaseDeMancat = caloriiZilnice - calMancate;
    cout << "Mai trebuie sa mancati " << caloriiRamaseDeMancat << " calorii azi\n";
}


