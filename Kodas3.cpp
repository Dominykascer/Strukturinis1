
#include "Kodas3.h"
#include <iostream>
#include<string>
using namespace std;
int main() {

    string golf1, golf2, golf3, golf4, g1;
    golf1 = "Volkswagen Golf 1. Pagaminimo metai:1977. Motoro litrazas nuo 1.1 iki 1.8L   ";
    golf2 = "Volkswagen Golf 2. Pagaminimo metai 1983. Motoro litrazas nuo 1 iki 2.0L";
    golf3 = "Volkswagen Golf 3. Pagaminimo metai 1991. Motoro litrazas nuo 1.4 iki 2.9L ";
    golf4 = "Volkswagen Gold 4. Pagaminimo metai 1997. Motoro litrazas 1.4 iki 3.2L ";

    cout<<"Labas!\n";
    cout<<"Irasyk apie kuri golfa nori suzinoti (golf1,golf2,golf3,golf4)";
cin>>g1;
    if(g1=="golf1") {
        cout<<golf1;
    }
    else if(g1=="golf2") {
        cout<<golf2;
    }
    else if(g1=="golf3") {
        cout<<golf3;
    }
    else if(g1=="golf4") {
        cout<<golf4;
    }



    return 0;
}

