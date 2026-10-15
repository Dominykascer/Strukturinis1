
#include "Praktine1.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
void stars() {
    for ( int i=0; i<50; i++)
        cout<<"*";
}
int main() {
    //APSIBREZIMAS
    const double Eur = 1;

    const double GBP_Bendras = 0.8729;
    const double GBP_Pirkti = 0.860;
    const double GBP_Parduoti = 0.9220;

    const double  USD_Bendras   = 1.1793;
    const double  USD_Pirkti    = 1.1460;
    const double   USD_Parduoti  = 1.2340;

    const double  INR_Bendras   = 104.6918;
    const double  INR_Pirkti    = 101.3862;
    const double   INR_Parduoti  = 107.8546;

    int choiceM = 0;
    int choiceV  ;
    double choiceP =0 ;
    cout<<fixed<<setprecision(2);



    //APSIBREZIMAS

    //VALIUTOS KEITYKLOS VEIKSMAI
    do {
        //MENIU
        stars();
        cout<<"\n - - - VALIUTOS KEITYKLA - - - \n"
        <<"1.Valiutos kurso palyginimas su EUR\n"
        <<"2.Valiutos Pirkimas (EUR -> Pasirinkta valiuta\n"
        <<"3.Valiutos Pardavimas ( Pasirinkta valiuta -> EUR\n"
        <<"4.Baigti programos darba\n";
        stars();
        cout<<endl;
        cout<<"Pasirinkite funkcija (1-4): "<<endl;
        cin>>choiceM;

        if (cin.fail()) {
            cout << "\nKlaida! Prasome ivesti skaiciu, o ne raide.\n" << endl;
            cin.clear(); // Išvalo klaidos būseną
            cin.ignore(10000, '\n'); // Išvalo buferį
            continue;
        }
        if (choiceM==4) {
            cout<<"\nViso gero!\n";
            break;

        }

        if (choiceM<1 || choiceM>4) {
            cout<<"\nKlaida! Si funkcija neegzistuoja. Bandykite dar karta\n"<<endl;
            continue;
        }
        //MENIU

        //VALIUTOS PASIRINKIMAS
        stars();
        cout<<"\nPasirink norima valiuta (1-3): \n";
        cout<<"1. GBP\n";
        cout<<"\n2. USD\n";
        cout<<"\n3. INR\n";
        stars();
        cout<<endl;
        cin>>choiceV;
        if (cin.fail()) {
            cout << "\nKlaida! Prasome ivesti skaiciu, o ne raide.\n" << endl;
            cin.clear(); // Išvalo klaidos būseną
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalo buferį
            continue;
        }
        if (choiceV<1 || choiceV>3) {
            cout<<"\nKlaida! Si funkcija neegzistuoja. Bandykite dar karta\n";
            continue;
        }
        //VALIUTOS PASIRINKIMAS

        //KURSO PALYGINIMAS
        if (choiceM==1) {
            if (choiceV==1) {
                cout<<"1 EUR = "<<GBP_Bendras<<" GBP"<<endl;
                cout<<"1 GBP = "<<(Eur/GBP_Bendras)<<" EUR"<<endl;



            } else if (choiceV==2) {
                cout<<"1 EUR = "<<USD_Bendras<<" USD"<<endl;
                cout<<"1 USD = "<<(Eur/USD_Bendras)<<" EUR"<<endl;

            }else if (choiceV==3) {
                cout<<"1 EUR = "<<INR_Bendras<<" INR"<<endl;
                cout<<"1 INR = "<<(Eur/INR_Bendras)<<" EUR"<<endl;
            }
        }
        //KURSO PALYGINIMAS

        //VALIUTOS PIRKIMAS
        double keitimasV = 0;

        if (choiceM==2) {
            if (choiceV==1) {
                cout<<"\n Ivesk kokia suma noretum issikeisti: \n";
                if (cin.fail()) {
                    cout << "\nKlaida! Neteisingai ivesta suma.\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                cin>>choiceP;
                keitimasV = choiceP*GBP_Pirkti;
                cout<<"Sekmingai issikeitei "<<choiceP<<" EUR -> "<<keitimasV<<" GBP"<<endl;
            } else if (choiceV == 2){
                cout<<"\n Ivesk kokia suma noretum issikeisti: \n";
                if (cin.fail()) {
                    cout << "\nKlaida! Neteisingai ivesta suma.\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                cin>>choiceP;
                keitimasV = choiceP * USD_Pirkti;
                cout<<"Sekmingai issikeitei "<<choiceP<<" EUR -> "<<keitimasV<<" USD"<<endl;
            } else if (choiceV == 3) {
                cout<<"\n Ivesk kokia suma noretum issikeisti: \n";
                if (cin.fail()) {
                    cout << "\nKlaida! Neteisingai ivesta suma.\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                cin>>choiceP;
                keitimasV = choiceP * INR_Pirkti;
                cout<<"Sekmingai issikeitei "<<choiceP<<" EUR -> "<<keitimasV<<" INR"<<endl;
            }
        }
        //VALIUTOS PIRKIMAS

        //VALIUTOS PARDAVIMAS

        if (choiceM==3) {
            if (choiceV==1) {
                cout<<"Iveskite kokia suma norite parduoti: \n";
                if (cin.fail()) {
                    cout << "\nKlaida! Neteisingai ivesta suma.\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                cin>>choiceP;
                keitimasV=choiceP/GBP_Parduoti;
                cout<<"Isikeitei "<<choiceP<<" GBP -> "<<keitimasV<<" EUR"<<endl;


            }
            else if (choiceV==2) {
                cout<<"Iveskite kokia suma norite parduoti: \n";
                if (cin.fail()) {
                    cout << "\nKlaida! Neteisingai ivesta suma.\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                cin>>choiceP;
                keitimasV=choiceP/USD_Parduoti;
                cout<<"Isikeitei "<<choiceP<<" USD -> "<<keitimasV<<" EUR"<<endl;


            }
            else if (choiceV==3) {
                cout<<"Iveskite kokia suma norite parduoti: \n";
                if (cin.fail()) {
                    cout << "\nKlaida! Neteisingai ivesta suma.\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }
                cin>>choiceP;
                keitimasV=choiceP/INR_Parduoti;
                cout<<"Isikeitei "<<choiceP<<" INR -> "<<keitimasV<<" EUR"<<endl;

            }
        }
        //VALIUTOS PARDAVIMAS
    }while (choiceM !=4);

    return 0;
}




