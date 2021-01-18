#include <iostream>
#include <vector> 

using namespace std;

int main(){
char selection {};
vector <int> list {};
int store {};

do{
    cout << "----------------------" << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;

    cout << "\nEnter your choice: ";

    cin >> selection;

    switch (selection){
        case 'P':
        case 'p': 
            if (list.size() !=0){
                cout << "[ ";
                for(int i {}; i < list.size(); i++){
                    cout << list.at(i) << " ";
                }
                cout << "]" << endl;
            } else {
                cout << "[] - list is empty" << endl;
            }
            break;

        case 'A':
        case 'a': 
            cout << "Enter a new number to add: ";
            cin >> store;
            list.push_back(store);
            cout << store << " added" <<endl;
            break;

        case 'M':
        case 'm': 
            if (list.size()!=0){
                store = 0;
                for(int i {0}; i<list.size();i++){
                    store+=list.at(i);
                }
                store /= list.size();
                cout << "Mean: " << store << endl;
            } else {
                cout << "Unable to calculate the mean - no data" << endl;
            }
            break;

        case 'S':
        case 's': 
            if (list.size() != 0){
                store = list.at(0);
                for(int i{1};i<list.size();i++){
                    if(list.at(i) < store){
                        store = list.at(i);
                    }
                }
                cout << "The smallest number is " << store << endl;
            } else {
                cout << "Unable to determine the smallest number - list is empty" << endl;
            }
            break;

        case 'L':
        case 'l': 
            if (list.size() != 0){
                store = list.at(0); 
                for(int i{1};i<list.size();i++){
                    if(list.at(i) > store){
                        store = list.at(i);
                    }
                }
                cout << "The largest number is " << store << endl;
                    } else {
                cout << "Unable to determine the largest number - list is empty" << endl;
            }
            break;

        case 'Q':
        case 'q': 
            cout << "Quiting, goodbye.";
            break;

        default: cout << "Unknown command, try again" << endl;
            break;
    }
} while (selection != 'Q' && selection != 'q');

return 0;
}