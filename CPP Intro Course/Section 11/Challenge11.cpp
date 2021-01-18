#include <iostream>
#include <vector> 

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void display_menu();
char get_selection();
void print_list(const vector <int> &list_in);
void add_list(vector <int> &list_in);
void mean_list(const vector <int> &list_in);
void smallest_list(const vector <int> &list_in);
void largest_list(const vector <int> &list_in);

int main(){
    char selection {};
    vector <int> list {};   
    do{        
        display_menu();
        selection = get_selection();
        switch (selection){
            case 'P': print_list(list);
                break;
            case 'A': add_list(list);
                break;
            case 'M': mean_list(list);
                break;
            case 'S': smallest_list(list);
                break;
            case 'L': largest_list(list);               
                break;
            case 'Q': cout << "Quiting, goodbye.";
                break;
            default: cout << "Unknown command, try again" << endl;
        }
    } while (selection != 'Q');
}

void display_menu(){
    cout << "----------------------" << endl;
            cout << "P - Print numbers" << endl;
            cout << "A - Add a number" << endl;
            cout << "M - Display mean of the numbers" << endl;
            cout << "S - Display the smallest number" << endl;
            cout << "L - Display the largest number" << endl;
            cout << "Q - Quit" << endl;
            
            cout << "\nEnter your choice: ";
}

char get_selection(){
    char select{};
    cin >> select;
    return toupper(select);
}

void print_list(const vector <int> &list_in){
    if (list_in.size() !=0){
        cout << "[ ";
        for(int i {}; i < list_in.size(); i++){
            cout << list_in.at(i) << " ";
            }
        cout << "]" << endl;
    } else {
    cout << "[] - list is empty" << endl;
    }
}

void add_list(vector <int> &list_in){
    int store {};
    cout << "Enter a new number to add: ";
    cin >> store;
    list_in.push_back(store);
    cout << store << " added" <<endl;
}

void mean_list(const vector <int> &list_in){
    int store {};
    if (list_in.size()!=0){
        for(int i {0}; i<list_in.size();i++){
            store+=list_in.at(i);
        }
        store /= list_in.size();
        cout << "Mean: " << store << endl;
    } else {
        cout << "Unable to calculate the mean - no data" << endl;
    }
}

void smallest_list(const vector <int> &list_in){
    int store {};
    if (list_in.size() != 0){
        store = list_in.at(0);
        for(int i{1};i<list_in.size();i++){
            if(list_in.at(i) < store){
                store = list_in.at(i);
            }
        }
        cout << "The smallest number is " << store << endl;
    } else {
        cout << "Unable to determine the smallest number - list is empty" << endl;
    }
}

void largest_list(const vector <int> &list_in){
    int store {};
    if (list_in.size() != 0){
        store = list_in.at(0); 
        for(int i{1};i<list_in.size();i++){
            if(list_in.at(i) > store){
                store = list_in.at(i);
            }
        }
        cout << "The largest number is " << store << endl;
    } else {
        cout << "Unable to determine the largest number - list is empty" << endl;
    }
}