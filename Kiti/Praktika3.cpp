#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int balance = 100;
    int choice;
    int amount;
    do {
        cout<<"\n - - - SASKAITOS MENIU\n"
        <<"1.Perziureti saskaitos likuti\n"
        <<"2.Papildyti saskaita\n"
        <<"3.Atlikti apmokejima\n"
        <<"0.Baigti programos darba\n";
        cout<<"Pasirinkite funkcija"<<endl;
        cin>>choice;
        switch(choice) {
            case 1:
            cout<<"Saskaitos likutis "<<balance<<endl;
            break;
            default:
                cout<<"Tokios funkcijos nera";
            case 0:
                cout<<"Programas baige darba"<<endl;
                break;
                case 2:
                cout<<"Papildimo suma";
                cin>>amount;
                if (amount>0) {
                    balance += amount;
                    cout<<"Saskaita papildyta";
                }else {
                    cout<<"Neteisinga suma, iveskite teigiama"<<endl;
                    break;}

                    case 3: {
                    cout<<"Apmokejimo suma";
                        cin>>amount;
                        if (amount>0) {
                            balance += amount;
                            cout<<"Apmoketa";
                            }  else {
                                balance -= amount;
                                
                            }


                    }




        }
    }while (choice != 0);



    return 0;
}
