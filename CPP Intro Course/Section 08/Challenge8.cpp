#include <iostream>

using namespace std;

int main(){

    cout << "Enter an amount in cents: ";
    int cents {0};
    cin >> cents;
    cout << "\nYou can provide change for this as follows:" << endl;
    int dollars = cents/100;
    cout << "dollars  : " << dollars << endl;
    cents %= 100;

    int quarters = cents/25;
    cout << "quarters : " << quarters << endl;
    cents %= 25;

    int dimes = cents/10;
    cout << "dimes    : " << dimes << endl;
    cents %= 10;

    int nickels = cents/5;
    cout << "nickels  : " << nickels << endl;
    cents %= 5;
 
    int pennies = cents;
    cout << "pennies  : " << pennies << endl;

    return 0;
}