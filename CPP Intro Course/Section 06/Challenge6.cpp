#include <iostream>

using namespace std;

int main(){

const float SmallRoomCost {25};
const float LargeRoomCost {35};
const float SalesTax {0.06};
const int ValidDays {30}; //estimate valid time in days

cout << "Hello, Welcome to Dak's Carpet Cleaning Service" << endl;

cout << "\nHow Many small rooms would you like cleaned? ";
int SmallRoomNumber {0};
cin >> SmallRoomNumber;
double SmallRoomTotal {SmallRoomCost * SmallRoomNumber};

cout << "How Many large rooms would you like cleaned? ";
int LargeRoomNumber {0};
cin >> LargeRoomNumber;
double LargeRoomTotal {LargeRoomCost * LargeRoomNumber};

cout << "\nEstimate for carpet cleaning service:" << endl;
cout << "Number of small rooms: " << SmallRoomNumber << endl;
cout << "Number of large rooms: " << LargeRoomNumber << endl;
cout << "Price per small room: $" << SmallRoomCost << endl;
cout << "Price per large room: $" << LargeRoomCost << endl;

double CombinedTotal {SmallRoomTotal + LargeRoomTotal}; //of just the large and small rooms
cout << "Cost: $" << CombinedTotal << endl;

double FinalTax {CombinedTotal * SalesTax};
cout << "Tax: $" << FinalTax << endl;
cout << "=================================================" << endl;

double FinalTotal {CombinedTotal + FinalTax};
cout << "Total estimate: $" << FinalTotal << endl;
cout << "This Estimate is valid for " << ValidDays << " days" << endl;

return 0;
}