#include <iostream>

int main(){

    int FavNumber;

    std::cout << "What is your favorite number between 1 and 100?" << std::endl;
    std::cin >> FavNumber;

    if (0 < FavNumber && FavNumber <= 100){
        std::cout << "Amazing! That's my favorite number too!" << std::endl;
        std::cout << "No really, " << FavNumber << " is my favorite number!" << std::endl;

    }
    else{
        std::cout << "that's not a number between 1 and 100!" << std::endl;
    }

    return 0;
}