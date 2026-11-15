//
// Created by domin on 05/11/2026.
//

#include "Praktinis3.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//APSIBREZIMAI

//KONST
const int MAXP = 100;
const int KATSK = 3;
const string KATEGORIJOS[KATSK] = {"Dviraciai","Dalys", "Aksesuarai"}; // Kategorijos
const int NuolaidaK = 10; //Nuo kiek perkant nuolaida
const double NuolaidaD = 0.1; // 10 % nuolaida
const string Duomenys = "Uzsakymas.txt";
const string Failas = "Ataskaita.txt";



//APSIBREZIMAI


int main() {

ifstream praktinis3("Uzsakymas.txt");
    if (!praktinis3.is_open()) {
        cout<<"Neatsidare failas";
        return 1;
    }













return 0;
}
