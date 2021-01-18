#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


string encode_message(string temp_message, int shift){
    string encoded_message {};
    for(size_t i {0}; i < temp_message.length(); i++){
        char c = temp_message.at(i);
        if(isalpha(c)){ //ignore if not a letter
            for(size_t j = 0; j < shift; j++){ //increment characters 'shift' places
                (c == 'z' || c == 'Z') ? c-= 25 : c += 1; //if character is 'z' or 'Z' change it to it's 'a' or 'A' value, otherwise increment 1
            }
        }
        encoded_message += c; //assign encoded character to message
    }
    return encoded_message;
}

string decode_message(string temp_message, int shift){
    string decoded_message {};
    for(size_t i {0}; i < temp_message.length(); i++){
        char c = temp_message.at(i);
        if(isalpha(c)){ //ignore if not a letter
            for(size_t j = 0; j < shift; j++){ //increment characters 'shift' places
                (c == 'a' || c == 'A') ? c+= 25 : c -= 1; //if character is 'a' or 'A' change it to it's 'z' or 'Z' value, otherwise increment 1
            }
        }
        decoded_message += c; //assign encoded character to message
    }
    return decoded_message;
}

int main(){
    string message {};
    int shift {};

    cout << "Enter text to encode: ";
    getline(cin, message);
    cout << "Number to shift cipher: ";
    cin >> shift;

    cout << "Encrypting message..." << endl;
    message.assign(encode_message(message, shift));
    cout << "Encrypted message: " << message << endl;
    cout << "Decrytping message..." << endl; 
    message.assign(decode_message(message, shift));
    cout << "Decrypted message: " << message << endl;
}