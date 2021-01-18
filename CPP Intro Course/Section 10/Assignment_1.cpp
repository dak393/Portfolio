//Dakota G.
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main(){
    string UserInput {};

    cout << "Enter a string to create a pyramid:" << endl;
    getline(cin, UserInput);
    const size_t InputLength  {UserInput.length()};

    for(int i {0}; i < InputLength; i++){ //loop each row
        for (int j{1}, count {0}; j <= InputLength + i; j++){ //loop through ever character on a line
            if(j < InputLength - i){ //preceding white space
                cout << " ";
            } else if (j < InputLength){ //print string counting up
                cout << UserInput.at(count);
                count ++;
            } else { //print string counting down
                cout << UserInput.at(count);
                count--;
            }
        }
        cout << endl; //new line for next row
    }
}