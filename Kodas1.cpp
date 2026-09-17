//
// Created by domin on 17/09/2026.
//

#include "Kodas1.h"
#include <iostream>
#include<string>
using namespace std;
int main() {
    string vardas, pavarde, kursas, studijos ;
    int amzius, grupe ;
    cout<<"Labas!\n",
   cout<< "Koks tavo vardas?";
    cin >> vardas;
    cout<<"Kokia pavarde?";
    cin >> pavarde;
    cout<<" Kiek tau metu?";
    cin>>amzius;
    cout<<"Ka studijuoji?";
    cin>>studijos;
    cout<<"Kelintame kurse (pirmame ir t.t)";

    cin>>kursas;
    cout<<"Kuri grupe? (1 arba 2)";
    cin>>grupe;

    cout<<"Studento vardas ir pavarde  "<<vardas<<" "<<pavarde<<"\n";
    cout<<"Amzius"<<" "<<amzius<<"\n";
    cout<<"Grupe"<<" "<<grupe<<"\n";
    cout<<"Studijos"<<" "<<studijos<<"\n";
    cout<<"Kelintame kurse"<<" "<<kursas<<endl;


    return 0;
}
