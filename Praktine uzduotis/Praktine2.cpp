//
// Created by domin on 15/10/2026.
//

#include "Praktine2.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //APSIBREZIMAI
    const int MaxM = 100;   // daugiausiai mokiniu
    const int Maxpaz= 10;    // daugiausiai pazymiu vienam mokiniui
    int pazsk, num, esami, paznr, pasirinkimas, naujaspaz, mok;
   int suma = 0;
    esami = num - 1;
    //APSIBREZIMAI

    //MASYVAS
    string vardai[MaxM];
    int pazymiai[MaxM][Maxpaz];
    int pazymiuSk[MaxM] = {0}; // Kiekvieno mokinio turimų pažymių kiekis
    int mokSk = 0; // Esamas mokinių skaičius sąraše
    //MASYVAS


    do {
        cout << "--- MOKINIU PAZYMIU SISTEMA ---\n";
        cout << "1. ivesti mokini ir jo pazymius.\n";
        cout << "2. Perziureti visu mokiniu pazymius.\n";
        cout << "3. Perziureti konkretaus mokinio pažymius.\n";
        cout << "4. Atnaujinti pazymi.\n";
        cout << "5. Apskaiciuoti mokinio vidurki.\n";
        cout << "6. Pasalinti mokini.\n";
        cout << "7. Iseiti.\n";
        cout << "Pasirinkite veiksma (1-7): ";
        cin >> pasirinkimas;
        if (cin.fail()) {
            cout << " Klaida! Prasome ivesti skaiciu, o ne raide. \n" << endl;
            cin.clear(); // Išvalo klaidos būseną
            cin.ignore(10000, '\n'); // Išvalo buferį
            continue;
        }
        if (pasirinkimas<=0) {
            cout<<"Klaida! Tokios funkcijos nera. Bandykite dar karta"<<endl;
        }

        if (pasirinkimas==1) {
            if (mokSk>=MaxM) {
                cout<<"Mokiniu limitas pasiektas("<<MaxM<<")! "<<endl;
            } else {
                cout<<"Ivesk mokinio varda:"<<endl;
                cin.ignore();
                cin>>vardai[mokSk];

                cout<<"Ivesk kiek jis tures pazymiu:"<<endl;
                cin>>pazsk;
                while (pazsk<1 || mokSk>=MaxM) {
                    cout<<"Neteisingas pazymiu skaicius. Iveskite is naujo nuo 1" <<Maxpaz<<endl;
                    cin>>pazsk;
                }
                pazymiuSk[mokSk]=pazsk;
                cout<<"Iveskite"<<pazsk<<"pazymius (Nuo 1 iki 10)"<<endl;

                for (int i=0;i<pazsk;i++) {
                    int pazym;
                    cout<<" Pazymys "<<i+1<<" : "<<endl;
                    cin>>pazym;
                    while (pazym < 1 || pazym > 10) {
                        cout << "  Neteisingas pazymys! Pazymys turi buti nuo 1 iki 10. Iveskite is naujo: "<<endl;
                        cin >> pazym;
                    }
                    pazymiai[mokSk][i]=pazym;
                }
                mokSk++;
                cout<<"Mokinys pridetas"<<endl;
            }
        }
        else if (pasirinkimas==2) {
            if (mokSk == 0) {
                cout<<"Sarase nera mokiniu\n";
            } else {
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

                    cout <<"\n";
                }
            }
        }
        else if (pasirinkimas==3) {
            if (mokSk == 0) {
                cout<<"Sarase nera mokiniu\n";
            } else {
                cout<<"Ivesk mokinio numeri (nuo 1 iki "<<mokSk<<endl;
                if (num < 1 || num > mokSk) {
                    cout<<"Neteisingas mokinio sakicius. Bandykite dar karta"<<endl;
                }else{

                    cout<<"Mokinys: "<<vardai[esami]<<"\nPazymiai: "<<endl;
                    if (pazymiuSk[esami] == 0) {
                        cout << "(nera pazymiu)";
                    } else {
                        for (int j = 0; j < pazymiuSk[esami]; j++) {
                            cout << pazymiai[esami][j] << " ";
                        }
                    }
                    cout<<"\n";

                } else if (pasirinkimas==4) {
                    if (mokSk == 0) {
                        cout<<"Sarase nera mokiniu\n";
                    }else {
                        cout << "Įveskite mokinio numerį (nuo 1 iki " << mokSk << "): ";
                        cin>>mok;

                        if (mok < 1 || mok > mokSk) {
                            cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokSk <<endl;

                        } else {
                            if (pazymiuSk[mok] == 0) {
                                cout << "Šis mokinys neturi jokių pažymių, kuriuos būtų galima atnaujinti"<<endl;
                            } else {
                                cout<<"Iveskite pazymio numeri, kuri norite atnaujinti (Nuo 1 iki "<<pazymiuSk[mok]<<"): "<<endl;
                                cin>>paznr;
                                if (paznr <1 || paznr > pazymiuSk[mok]) {
                                    cout<<"Neteisingas pazymio numeris. Bandykite dar karta"<<endl;
                                } else {
                                    cout<<"Iveskite nauja pazymi (Nuo 1 iki 10"<<endl;
                                    cin>>naujaspaz;
                                    while (naujaspaz < 1 || naujaspaz > 10) {
                                        cout<<"Neteisingas pazymys! Badykite dar karta"<<endl;
                                        cin>>naujaspaz;
                                    }
                                    pazymiai[mok][paznr - 1] = naujaspaz;
                                    cout<<"Pazymys atnaujintas"<<endl;
                                }
                            }
                        }
                    }
                }else if (pasirinkimas==5) {
    if (mokSk == 0) {
        cout<<"Sarase nera mokiniu\n";
    } else {
cout<<"Iveskite mokinio numeri nuo 1 iki"<<mokSk<<": "<<endl;
        cin>>mok;
        if (mok < 1 || mok > mokSk) {
            cout<<"Neteisingas mokinio numeris. Bandykite dar karta"<<endl;
        } else {
if (pazymiuSk[esami] == 0) {
    cout<<"Mokinys"<<vardai[esami]<<" neturi pazymiu. Vidurkis neapskaiciuotas."<<endl;
} else {
    for (int j = 0; j < pazymiuSk[esami]; j++) {
        suma += pazymiai[esami][j];
    }
    double vidurkis = suma / pazymiuSk[esami];
    cout<<fixed<<setprecision(2);
    cout<<"Mokinio" << vardai[esami]<<" pazymiu vidurkis: "<<vidurkis<<endl;

        }
     }
    }
}
        } while (pasirinkimas !=7);
        return 0;
    }