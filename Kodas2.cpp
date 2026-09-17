
#include "Kodas2.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
    string pav, arena, sav;
    int metai ;

    cout<<"Labas!\n";
    cout<<"Susikurk savo komanda!\n";
    cout<<"Koks bus tavo komandos pavadinimas?";
    cin>>pav;
    cout<<"Kelintais metais ikurta?";
    cin>>metai;
    cout<<"Kas yra sios komandos savininkas?";
    cin>>sav;
    cout<<"Kokia arena priklauso siai komandai?";
    cin>>arena;

    cout<<"Pavadinimas: "<<pav<<endl;
    cout<<"Ikurimo metai: "<<metai<<endl;
    cout<<"Savinikas: "<<sav<<endl;
    cout<<"Arena: "<<arena<<endl;

    return 0;
}
