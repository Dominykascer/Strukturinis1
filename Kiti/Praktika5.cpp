#include <iostream>
#include "Praktika5.h"
#include <string>
#include <iomanip>

using namespace std;
int main() {
    int sum = 0;
    int studentGradesNum=5, grade;
    int highestGrade = 0;
    for (int i = 1; i<= studentGradesNum; i++) {
        cout <<"Iveskite" <<i<<" Studento pazymi"<<endl;
        cin>>grade;
        sum += grade;
        highestGrade = (grade > highestGrade) ? grade : highestGrade;
    }

    double average = static_cast<double>(sum) / studentGradesNum;
    cout<<fixed<<setprecision(2);
    cout<<"Pazymiu vidurkis: "<<average<<endl;
    cout<<"Didziausias pazymis: "<<highestGrade<<endl;



    return 0;
}