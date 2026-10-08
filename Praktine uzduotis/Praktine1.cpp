
#include "Praktine1.h"
#include <iostream>
#include <iomanip>

using namespace std;
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
    int choiceP  ;
    double keitimasG = 0;



    cout<<fixed<<setprecision(2);
    //APSIBREZIMAS

    //VALIUTOS KEITYKLOS VEIKSMAI
    do {
        //MENIU
        cout<<"\n - - - VALIUTOS KEITYKLA - - - \n"
        <<"1.Valiutos kurso palyginimas su EUR\n"
        <<"2.Valiutos Pirkimas (EUR -> Pasirinkta valiuta\n"
        <<"3.Valiutos Pardavimas ( Pasirinkta valiuta -> EUR\n"
        <<"4.Baigti programos darba\n";
        cout<<"Pasirinkite funkcija (1-4): "<<endl;
        cin>>choiceM;
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
        cout<<"\nPasirink norima valiuta (1-3): \n"<<endl;
        cout<<"\n1. GBP\n";
        cout<<"\n2. USD\n";
        cout<<"\n3. INR\n";


        cin>>choiceV;
        if (choiceV<1 || choiceV>3) {
            cout<<"\nKlaida! Si funkcija neegzistuoja. Bandykite dar karta\n";
            continue;
        }
        //VALIUTOS PASIRINKIMAS

        //KURSO PALYGINIMAS
        if (choiceM==1) {
            if (choiceV==1) {
                cout<<"GBP palyginus su EUR: "<<GBP_Bendras<<endl;
                cout<<"GBP pirkimas: "<<GBP_Pirkti<<endl;
                cout<<"GBP pardavimas : "<<GBP_Parduoti<<endl;


            } else if (choiceV==2) {
                cout<<"USD palyginus su EUR: "<<USD_Bendras<<endl;
                cout<<"USD pirkimas: "<<USD_Pirkti<<endl;
                cout<<"USD pardavimas : "<<USD_Parduoti<<endl;
            }else if (choiceV==3) {
                cout<<"INR palyginus su EUR: "<<INR_Bendras<<endl;
                cout<<"INR pirkimas: "<<INR_Pirkti<<endl;
                cout<<"INR pardavimas : "<<INR_Parduoti<<endl;
            }
        }
        //KURSO PALYGINIMAS

        //VALIUTOS PIRKIMAS

        if (choiceM==2)
        if (choiceV==1) {
            cout<<"\n Ivesk kokia suma noretum issikeisti: \n";
            cin>>choiceP;
            keitimasG = choiceP*GBP_Parduoti;
            cout<<"Sekmingai nusipirkai: "<<keitimasG<<" GBP"<<endl;
        } else if (choiceV == 2) {
            keitimasG = choiceP * USD_Parduoti;
            cout << "Sekmingai nusipirkai: " << keitimasG << " USD" << endl;
        } else if (choiceV == 3) {
            keitimasG = choiceP * INR_Parduoti;
            cout << "Sekmingai nusipirkai: " << keitimasG << " INR" << endl;
        }



        //VALIUTOS PIRKIMAS

    }while (choiceM !=4);
    //VALIUTOS KEITYKLOS VEIKSMAI
    return 0;
}



