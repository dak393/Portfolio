// Copyright Dakota G.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay()           // When the game starts
{
    Super::BeginPlay();
    Isogram = GetValidWords(HiddenList);
    SetupGame();

    //PrintLine(TEXT("The number of possible words is: %i"), HiddenList.Num()); //debug word totals
    //PrintLine(TEXT("The number of valid words is: %i"), Isogram.Num()); //debug valid total

}

void UBullCowCartridge::OnInput(const FString& PlayerInput)                 // When the player hits enter
{
    if (bGameOver) {                                                        //game over
        ClearScreen();
        SetupGame();
    }
    else {                                                                  //normal play
        ProcessGuess(PlayerInput);
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = Isogram[FMath::RandRange(0,Isogram.Num()-1)];
    Lives = HiddenWord.Len() * 2;                                          //set difficulty based on word length
    bGameOver = false;

    //PrintLine(TEXT("The Hidden Word is: %s.\nIt is %i characters long."), *HiddenWord, HiddenWord.Len()); //Debug line

    PrintLine(TEXT("Welcome to Bulls and Cows!\nGuess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and hit Enter"));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Game Over\nPress Enter to play again"));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess){
    
    if (Guess == HiddenWord){                                            //correct word, win
                PrintLine(TEXT("You Win!!!"));
                EndGame();
                return;
    }
    else if (Guess.Len() != HiddenWord.Len()){                          //wrong number of letters
        PrintLine(TEXT("The hidden word is %i letters long.\nTry again"), HiddenWord.Len());
        return;
    }
    else if (!IsIsogram(Guess)){
            PrintLine(TEXT("The word you entered has duplicate letters\nTry again"));
            return;
    }  
    
    //PrintLine(TEXT("Wrong!"));  //debug: wrong word
    if (--Lives <= 0) {                                               //life loss + check 
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The Hidden word was: %s"), *HiddenWord);                
        EndGame();
        return;
    } else { 
    //wrong guess, not out of lives
    FBullCowCount Score = GetBullCows(Guess);

    PrintLine(TEXT("You have %i bulls and %i cows"), Score.Bulls, Score.Cows);
    PrintLine(TEXT("%i lives left, try again."), Lives);
    return;
    }
}

bool UBullCowCartridge::IsIsogram(const FString& CheckWord) const{

    for (int32 i {0}; i < CheckWord.Len(); i++){
        for (int32 j=i+1; j < CheckWord.Len(); j++){
            if (CheckWord[i] == CheckWord[j]){
                return false;
            }
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const{

   TArray<FString> ValidWords; 

    for (auto WordToCheck : WordList){
        if (3 < WordToCheck.Len() && WordToCheck.Len() < 9){
            if(IsIsogram(WordToCheck)){
                ValidWords.Emplace(WordToCheck);
            }
        }     
    }   
    return ValidWords;
}

 FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const{

    FBullCowCount Count;

    for(int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++){                    //for every index the same bull++
        if (Guess[GuessIndex] == HiddenWord[GuessIndex]){
            Count.Bulls++;
            continue;
        }

        for(int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++){        //if not, was it a cow, cow++
            if(Guess[GuessIndex] == HiddenWord[HiddenIndex]){
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}