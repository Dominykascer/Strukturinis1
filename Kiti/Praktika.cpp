#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
int main(){
int savings = 100;
    const int target = 500;
    const int monthlyDeposit = 70;
    int month = 0;
    int year = 0;

    while (savings < target) {
        month++;
        savings += monthlyDeposit;
        cout<<"menuo "<<month<<" santaupos "<<savings<<" EUR"<<endl;
        cout<<"Tikslas pasiektas per "<<month<<" menesius"<<endl;


    }



    return 0;
}
