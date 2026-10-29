//
// Created by domin on 15/10/2026.
//

#include "Praktine2.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
void stars() {
    for ( int i=0; i<50; i++)
        cout<<"*";
}

int main() {

    // APSIBREZIMAI
    const int MaxM = 100;   // daugiausiai mokiniu
    const int Maxpaz = 10;   // daugiausiai pazymiu vienam mokiniui
    int pazsk, paznr, pasirinkimas, naujaspaz, mok;
    // APSIBREZIMAI

    // MASYVAS
    string vardai[MaxM];
    int pazymiai[MaxM][Maxpaz];
    int pazymiuSk[MaxM] = {0}; // Kiekvieno mokinio turimu pazymiu kiekis
    int mokSk = 0; // Esamas mokiniu skaicius sarase
    // MASYVAS

    do {
        stars();
        cout << "\n--- MOKINIU PAZYMIU SISTEMA ---\n";
        cout << "1. Ivesti mokini ir jo pazymius.\n";
        cout << "2. Perziureti visu mokiniu pazymius.\n";
        cout << "3. Perziureti konkretaus mokinio pazymius.\n";
        cout << "4. Atnaujinti pazymi.\n";
        cout << "5. Apskaiciuoti mokinio vidurki.\n";
        cout << "6. Pasalinti mokini.\n";
        cout << "7. Iseiti.\n";
        stars();
        cout<<""<<endl;
        cout << "Pasirinkite veiksma (1-7): ";
        cin >> pasirinkimas;

        if (cin.fail()) {
            cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n";
            cin.clear(); // Išvalo klaidos būseną
            cin.ignore(10000, '\n'); // Išvalo buferį
            continue;
        }
//IVEDIMAS I SISTEMA
        if (pasirinkimas == 1) {
            if (mokSk >= MaxM) { //PATIKRA
                cout << "Mokiniu limitas pasiektas (" << MaxM << ")! \n";
            } else {
                cout << "Ivesk mokinio varda: ";
                cin.ignore();
               cin>>vardai[mokSk];

                cout << "Ivesk kiek jis tures pazymiu (nuo 1 iki " << Maxpaz << "): ";
                cin >> pazsk;
                while (pazsk < 1 || pazsk > Maxpaz) {
                    cout << "Neteisingas pazymiu skaicius. Iveskite is naujo nuo 1 iki " << Maxpaz << ": ";
                    cin >> pazsk;
                    if (cin.fail()) {
                        cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n";
                        cin.clear(); // Išvalo klaidos būseną
                        cin.ignore(10000, '\n'); // Išvalo buferį
                        continue;
                    }
                }
                pazymiuSk[mokSk] = pazsk;
                cout << "Iveskite " << pazsk << " pazymius (Nuo 1 iki 10):\n";

                for (int i = 0; i < pazsk; i++) {
                    int pazym;
                    cout << "  Pazymys " << (i + 1) << " : ";
                    cin >> pazym;
                    while (pazym < 1 || pazym > 10) {
                        cout << "  Neteisingas pazymys! Pazymys turi buti nuo 1 iki 10. Iveskite is naujo: ";
                        cin >> pazym;
                        if (cin.fail()) {
                            cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n";
                            cin.clear(); // Išvalo klaidos būseną
                            cin.ignore(10000, '\n'); // Išvalo buferį
                            continue;
                        }
                    }
                    pazymiai[mokSk][i] = pazym;
                }
                mokSk++;
                cout << "Mokinys pridetas!\n";
            }
        }
        //IVEDIMAS I SISTEMA

        //MOKINIU SARASAS SU PAZYMIAIS
        else if (pasirinkimas == 2) {
            if (mokSk == 0) {
                cout << "Sarase nera mokiniu\n";
            } else {
                stars();
                cout << "\n--- VISU MOKINIU SARASAS IR JU PAZYMIAI ---\n";
                for (int i = 0; i < mokSk; i++) {
                    cout << (i + 1) << ". " << vardai[i] << " - Pazymiai: ";
                    if (pazymiuSk[i] == 0) {
                        cout << "(nera pazymiu)";
                    } else {
                        for (int j = 0; j < pazymiuSk[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << "\n";
                }
            }
        }
        //MOKINIU SARASAS SU PAZYMIAIS

        //MOKINIO PAZYMAI
        else if (pasirinkimas == 3) {
            if (mokSk == 0) {
                cout << "Sarase nera mokiniu\n";
            } else {
                cout << "Ivesk mokinio numeri (nuo 1 iki " << mokSk << "): ";
                cin >> mok;
                   if (cin.fail()) {
                        cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n";
                        cin.clear(); // Išvalo klaidos būseną
                        cin.ignore(10000, '\n'); // Išvalo buferį
                        continue;
                    }

                if (mok < 1 || mok > mokSk) {
                    cout << "Neteisingas mokinio numeris. Bandykite dar karta\n";
                } else {
                    int ind = mok - 1;
                    stars();
                    cout<<""<<endl;
                    cout << "Mokinys: " << vardai[ind] << "\nPazymiai: ";
                    if (pazymiuSk[ind] == 0) {
                        cout << "(nera pazymiu)";
                    } else {
                        for (int j = 0; j < pazymiuSk[ind]; j++) {
                            cout << pazymiai[ind][j] << " ";
                        }
                    }
                    cout << "\n";
                }
            }
        }
        //MOKINIO PAZYMAI

        //PAZYMIO ATNAUJINIMAS
        else if (pasirinkimas == 4) {
            if (mokSk == 0) {
                cout << "Sarase nera mokiniu\n";
            } else {
                cout << "Iveskite mokinio numeri (nuo 1 iki " << mokSk << "): ";
                cin >> mok;
                if (cin.fail()) {
                    cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n";
                    cin.clear(); // Išvalo klaidos būseną
                    cin.ignore(10000, '\n'); // Išvalo buferį
                    continue;
                }



                if (mok < 1 || mok > mokSk) {
                    cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << mokSk << "\n";
                } else {
                    int ind = mok - 1;
                    if (pazymiuSk[ind] == 0) {
                        cout << "Sis mokinys neturi jokiu pazymiu, kuriuos butu galima atnaujinti\n";
                    } else {
                        cout << "Iveskite pazymio numeri, kuri norite atnaujinti (Nuo 1 iki " << pazymiuSk[ind] << "): ";
                        cin >> paznr;
                        if (paznr < 1 || paznr > pazymiuSk[ind]) {
                            cout << "Neteisingas pazymio numeris. Bandykite dar karta\n";
                        } else {
                            cout << "Iveskite nauja pazymi (Nuo 1 iki 10): ";
                            cin >> naujaspaz;
                            while (naujaspaz < 1 || naujaspaz > 10) {
                                cout << "Neteisingas pazymys! Bandykite dar karta: ";
                                cin >> naujaspaz;
                                if (cin.fail()) {
                                    cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n";
                                    cin.clear(); // Išvalo klaidos būseną
                                    cin.ignore(10000, '\n'); // Išvalo buferį
                                    continue;
                                }
                            }
                            pazymiai[ind][paznr - 1] = naujaspaz;
                            cout << "Pazymys atnaujintas!\n";
                        }
                    }
                }
            }
        }
        //PAZYMIO ATNAUJINIMAS

        //VIDURKIS
        else if (pasirinkimas == 5) {
            if (mokSk == 0) {
                cout << "Sarase nera mokiniu\n";
            } else {
                cout << "Iveskite mokinio numeri nuo 1 iki " << mokSk << ": ";
                cin >> mok;
                if (cin.fail()) {
                    cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n";
                    cin.clear(); // Išvalo klaidos būseną
                    cin.ignore(10000, '\n'); // Išvalo buferį
                    continue;
                }
                if (mok < 1 || mok > mokSk) {
                    cout << "Neteisingas mokinio numeris. Bandykite dar karta\n";
                } else {
                    int ind = mok - 1;
                    if (pazymiuSk[ind] == 0) {
                        cout << "Mokinys " << vardai[ind] << " neturi pazymiu. Vidurkis neapskaiciuotas.\n";
                    } else {
                        double suma = 0;
                        for (int j = 0; j < pazymiuSk[ind]; j++) {
                            suma += pazymiai[ind][j];
                        }
                        double vidurkis = suma / pazymiuSk[ind];
                        cout << fixed << setprecision(2);
                        cout << "Mokinio " << vardai[ind] << " pazymiu vidurkis: " << vidurkis << "\n";
                    }
                }
            }
        }
        //VIDURKIS


        //PASALINIMAS
        else if (pasirinkimas == 6) {
            if (mokSk == 0) {
                cout << "Sarase nera mokiniu\n";
            } else {
                cout << "Iveskite mokinio numeri, kuri norite pasalinti (Nuo 1 iki " << mokSk << "): ";
                cin >> mok;
                if (cin.fail()) {
                    cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n";
                    cin.clear(); // Išvalo klaidos būseną
                    cin.ignore(10000, '\n'); // Išvalo buferį
                    continue;
                }
                if (mok < 1 || mok > mokSk) {
                    cout << "Neteisingas mokinio numeris. Bandykite dar karta.\n";
                } else {
                    int mokn = mok - 1;
                    cout << "Mokinys " << vardai[mokn] << " sekmingai pasalintas is saraso\n";

                    // Perstumiame elementus, kad neliktu tusciu tarpu
                    for (int i = mokn; i < mokSk - 1; i++) {
                        vardai[i] = vardai[i + 1];
                        pazymiuSk[i] = pazymiuSk[i + 1];
                        for (int j = 0; j < Maxpaz; j++) {
                            pazymiai[i][j] = pazymiai[i + 1][j];
                        }
                    }
                    mokSk--;
                }
            }
        }
        //PASALINIMAS
        else if (pasirinkimas == 7) {
            cout << "Programa uzsidaro. Viso gero!\n";
        }
        else {
            cout << "Neteisingas pasirinkimas. Pasirinkite skaiciu nuo 1 iki 7\n";
        }

    } while (pasirinkimas != 7);

    return 0;
}