#include <iostream>
#include "Praktika5.h"
#include <string>
#include <iomanip>

using namespace std;
int main() {
    const int studentGradesNum = 5;
    int grade;
    int sum = 0;
    int highestGrade = 0;

    for (int i = 1; i <= studentGradesNum; i++) {
        cout << "Iveskite "<<i<<" studento pazymi"<<endl;
        cin >> grade;
        sum += grade;

        highestGrade = (grade > highestGrade) ? grade : highestGrade;

    }

    double averageGrade = static_cast<double>(sum) / studentGradesNum;

    cout <<fixed << setprecision(2)
        <<"Pazymius vidurkis: "<< averageGrade << endl;
    cout <<"Didziausias pazymys: "<< highestGrade << endl;


    return 0;
}