#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string password;

    do {
        cout << "Sukurkite slaptazodi (bent 8 simbolius): " << endl;
        cin >> password;

        if (password.length() < 8) {
            cout << "Slaptazodis per trumpas. Bandykite dar karta." << endl;
        }
    } while (password.length() > 8);

    cout << "Slaptazodis priimtas!" << endl;

    return 0;
}
