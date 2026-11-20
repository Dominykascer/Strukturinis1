//
// Created by domin on 05/11/2026.
//

#include "Praktinis3.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;




//APSIBREZIMAI

//------------------KONST--------------------//
const int MAXP = 100;  //Max produktai
const int KATSK = 3;  //MAX kategoriju
const string KATEGORIJOS[KATSK] = {"Dviraciai","Dalys", "Aksesuarai"}; // Kategorijos
const int NuolaidaK = 10; //Nuo kiek perkant nuolaida
const double NuolaidaD = 0.1; // 10 % nuolaida
const string Duomenys = "uzsakymas.txt";
const string Failas = "ataskaita.txt";
//------------------KONST--------------------//

//------------------Masyvai--------------------//
string kategorijos[MAXP];
string pavadinimai[MAXP];

double kainos[MAXP];
int kiekiai [MAXP];


//------------------Masyvai--------------------//


int meniu;
//APSIBREZIMAI

// -------------FUCNKCIJOS------------------//

double eilutessum(double kaina, int kiekis) { //Eilutes suma

    return kaina * kiekis;
}

void stars() {
    for ( int i=0; i<50; i++)
        cout<<"*";

}


// -----------------------------------------//

int main() {

    cout << fixed << setprecision(2);
    int n = 0;



    ifstream praktinis3(Duomenys);
    if (!praktinis3.is_open()) {
        cout<<"Neatsidare failas";
        return 1;

}
    else {

    praktinis3>>n;
    praktinis3.ignore(1000, '\n');

    string e;


    // ------------Visos prekes-------------------//
    for (int i = 0; i < n; i++) {

        getline(praktinis3, e);

        stringstream ss(e);
        string kategorija;
        string pavadinimas;
        string kainaTekstas;
        string kiekisTekstas;

        getline(ss, kategorija, ';' );
        getline(ss, pavadinimas, ';' );
        getline(ss, kainaTekstas, ';' );
        getline(ss, kiekisTekstas, ';' );


        pavadinimai[i] = pavadinimas;
        kategorijos[i] = kategorija;
        kainos[i] = stod(kainaTekstas);
        kiekiai[i] = stoi(kiekisTekstas);
    }
}

do{
    // --------------MENIU---------------//
stars();
    cout<<""<<endl;
    cout<<"--------------MENIU-------------"<<endl;
    cout<<"1. Perziureti visas uzsakymo prekes"<<endl;
    cout<<"2. Perziureti pasirinktos kategorijos prekes"<<endl;
    cout<<"3. Perziureti viso uzsakymo sumas"<<endl;
    cout<<"4. Perziureti sumas pagal kategorijas"<<endl;
    cout<<"5. Parodyti visa uzsakymo ataskaita"<<endl;
    cout<<"6. Issaugoti visa ataskaita i failas"<<endl;
    cout<<"7. Iseiti"<<endl;
cout<<"***************************************************"<<endl;
cin>>meniu;
    // -----------------------------------------//


switch (meniu) {

    case 1:
         // ------------Prekiu kiekis-----------------//
    {

        cout << "\n--- VISOS PREKES ---\n";

        for (int i = 0; i < n; i++) {

            cout << "Kategorija: " << kategorijos[i] << endl;
            cout << "Pavadinimas: " << pavadinimai[i] << endl;
            cout << "Kaina: " << kainos[i] << endl;
            cout << "Kiekis: " << kiekiai[i] << endl;

            cout << "-------------------" << endl;
        }
    }
    // -----------------------------------------//
       break;

        case 2:
        cout<<"2"<<endl;
        break;

        case 3: {

            for (int i = 0; i < n; i++)
            {
                double suma = eilutessum(kainos[i], kiekiai[i]);

                cout << pavadinimai[i] << ": " << suma << " EUR" << endl;
            }
            }
        break;
        }

} while (meniu != 7);
return 0;
}




