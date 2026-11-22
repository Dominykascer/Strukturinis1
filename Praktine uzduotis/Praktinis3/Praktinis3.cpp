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
            //----Sumos----//
double eilutessum(double kaina, int kiekis) { //Eilutes suma

    return kaina * kiekis;
}

//----Nuolaida----//
double nuolaida(double suma, int kiekis) {

    if (kiekis >=NuolaidaK) {
        double nuolaida = suma * NuolaidaD;
 suma -= nuolaida;
    }
    return suma;
}
//----Nuolaida----//
            //----Sumos----//

//----Kategorijos----//

              //----Kategorijos sumos----//
void kategorijusumos( const string kategorijos[],
    const double kainos[],
    const int kiekiai[],
    int n){
    for (int k = 0; k < KATSK; k++) {
        double kategorijossum = 0;

        for ( int i = 0 ; i < n; i++) {
            if ( kategorijos[i] == KATEGORIJOS[k]) {
                double pradineSuma = eilutessum(kainos[i], kiekiai[i]);
                double galutineSuma = nuolaida(pradineSuma, kiekiai[i]);
                kategorijossum += galutineSuma;
            }

        }
        cout << "Kategorija: " << KATEGORIJOS[k] << endl;
        cout << "Galutine suma: " << kategorijossum << " EUR" << endl;


        cout << "----------------------------" << endl;

    }

}
                //----Kategorijos sumos----//
//----Kategorijos----//
            //----zvaigzd----//
void stars() {
    for ( int i=0; i<50; i++)
        cout<<"*";

}
            //----zvaigzd----//

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
    praktinis3.close();
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

    default:
        cout << "Neteisingas pasirinkimas!" << endl;
        break;



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

        case 2: {
            int p;
            void stars();
            cout<<"Pasirink kategorija: "<<endl;
            for (int k = 0; k < KATSK; k++) {
                cout<< k + 1<<". "<<KATEGORIJOS[k]<<endl;
            }
            cin>>p;

            string pasirinkta = KATEGORIJOS[p - 1];
            for (int i = 0; i < n; i++) {
                if (kategorijos[i] == pasirinkta) {
                    cout << "Preke: " << pavadinimai[i] << endl;
                    cout << "Kaina: " << kainos[i] << " EUR" << endl;
                    cout << "Kiekis: " << kiekiai[i] << endl;
                    cout << "-------------------" << endl;

                }
            }
        }




        break;

        case 3: {
            double bendraSuma = 0;
            for (int i = 0; i < n; i++)
            {

                double pradineSuma = eilutessum(kainos[i], kiekiai[i]);
                double galutineSuma = nuolaida(pradineSuma, kiekiai[i]);
                     bendraSuma += galutineSuma;

                cout << "Preke: " << pavadinimai[i] << endl;
                cout << "Pradine suma: " << pradineSuma << " EUR" << endl;
                cout << "Galutine suma: " << galutineSuma << " EUR" << endl;
                cout << "Sutaupyta: " << pradineSuma - galutineSuma << " EUR" << endl;

                cout << "----------------------------" << endl;

            }


            cout << "-------- BENDRA SUMA: " << bendraSuma <<" ---------"<< endl;
            }
        break;

    case 4:
        kategorijusumos(kategorijos, kainos, kiekiai, n);


        break;
        }

} while (meniu != 7);
return 0;
}




