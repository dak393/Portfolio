#include <iostream>
#include <vector>

using namespace std;

int main(){

vector <int> vec {1,2,3,5,10,-99,23,42};
int count {0};
int index {0};

while(index < vec.size() && vec.at(index) != -99 ){
    cout << "number: " << vec.at(index) << " index: " << index <<endl;
    count++;
    index++;
    
}

cout << "Count: " << count << endl;

return 0;
}