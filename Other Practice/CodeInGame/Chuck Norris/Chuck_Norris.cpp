#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    string MESSAGE;
    getline(cin, MESSAGE);
    string BINARY{};
    string ANSWER{};
    
    for(auto c: MESSAGE){
        std::bitset<7> bs(c);
        BINARY.append(bs.to_string()); 
    }

    size_t count {0};
    for(size_t i{0}; i < BINARY.length(); i++){
        if (count > 0) { 
            if (BINARY.at(i-1) == BINARY.at(i)){ //increment count if last character is the same
                count++;                   
            } else { //if last character is different, insert '0' equal to count at the end and a ' ' for new block
                ANSWER.insert(ANSWER.end(), count, '0');
                ANSWER.append(" ");
                count = 0;
            }
        }
        if (count == 0){ //start of new block
            if (BINARY.at(i) == '0'){
                ANSWER.append("00 ");
            } else if (BINARY.at(i) == '1'){
                ANSWER.append("0 ");
            }
        count++;
        }
        if (i + 1 == BINARY.length()){ //insert last set if we are at the end
            ANSWER.insert(ANSWER.end(), count, '0');
        }
    }
    cout << ANSWER << endl;       
}