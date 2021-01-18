#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty, int MaxDifficulty){

    if (Difficulty == 1){
    //art by TomekK from ascii.uk
    std::cout << "*******************************************************************************\n";
    std::cout << "          |                   |                  |                     |       \n";
    std::cout << " _________|________________.=\"\"_;=.______________|_____________________|_______\n";
    std::cout << "|                   |  ,-\"_,=\"\"     `\"=.|                  |                   \n";
    std::cout << "|___________________|__\"=._o`\"-._        `\"=.______________|___________________\n";
    std::cout << "          |                `\"=._o`\"=._      _`\"=._                     |       \n";
    std::cout << " _________|_____________________:=._o \"=._.\"_.-=\"'\"=.__________________|_______\n";
    std::cout << "|                   |    __.--\" , ; `\"=._o.\" ,-\"\"\"-._ \".   |                   \n";
    std::cout << "|___________________|_._\"  ,. .` ` `` ,  `\"-._\"-._   \". '__|___________________\n";
    std::cout << "          |           |o`\"=._` , \"` `; .\". ,  \"-._\"-._; ;              |       \n";
    std::cout << " _________|___________| ;`-.o`\"=._; .\" ` '`.\"\\` . \"-._ /_______________|_______\n";
    std::cout << "|                   | |o;    `\"-.o`\"=._``  '` \" ,__.--o;   |                   \n";
    std::cout << "|___________________|_| ;     (#) `-.o `\"=.`_.--\"_o.-; ;___|___________________\n";
    std::cout << "____/______/______/___|o;._    \"      `\".o|o_.--\"    ;o;____/______/______/____\n";
    std::cout << "/______/______/______/_\"=._o--._        ; | ;        ; ;/______/______/______/_\n";
    std::cout << "____/______/______/______/__\"=._o--._   ;o|o;     _._;o;____/______/______/____\n";
    std::cout << "/______/______/______/______/____\"=._o._; | ;_.--\"o.--\"_/______/______/______/_\n";
    std::cout << "____/______/______/______/______/_____\"=.o|o_.--\"\"___/______/______/______/____\n";
    std::cout << "/______/______/______/______/______/______/______/______/______/______/[TomekK]\n";
    std::cout << "You encounter a chest with an enchanted lock. ";
    }

    Difficulty = MaxDifficulty - Difficulty + 1; //list remaining instead of "level"
    std::cout << "The lock has " << Difficulty << " sealing runes.\n";
    std::cout << "Enter the correct three numbers to break each seal.\n\n";

}

bool PlayGame (int Difficulty, int MaxDifficulty){

    PrintIntroduction(Difficulty, MaxDifficulty);

    //Declare three number code variables
    int CodeA = rand() % Difficulty + 2;
    int CodeB = rand() % Difficulty + 2;
    int CodeC = rand() % Difficulty + 2;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //Output the sum and product

    std::cout << "* There are 3 numbers in each code\n";
    std::cout << "* The numbers add up to: " << CodeSum << std::endl;
    std::cout << "* Multiplying the numbers gives: " << CodeProduct << std::endl;

    //Store the guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct){

        std::cout << "\n**A sealing rune is broken!**\n\n";
        return true;

    }
    else {
        std::cout << "\n**You set off a trap and the chest explodes!**\n";
        return false;
    }

}

int main(){
    
    srand(time(NULL)); //seeding new random number based on time

    int GameDifficulty = 1;
    int const MaximumDifficulty = 5;

    while (GameDifficulty <= MaximumDifficulty){ //loop until all levels are done
        
        bool bLevelComplete = PlayGame(GameDifficulty, MaximumDifficulty);
        std::cin.clear(); //Clear any errors from bad characters
        std::cin.ignore(); //Discard the buffer

        if (bLevelComplete) {
            GameDifficulty++;
        }
        else {
            GameDifficulty = 1;
        }

        
    }

    std::cout << "***The final seals breaks and the chest opens!***";

    return 0;
}