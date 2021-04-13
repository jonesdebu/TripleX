#include <iostream>
#include <vector>
#include <ctime>


void PrintIntroduction(int Difficulty)
{
    //Print welcome message 

    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room..." << std::endl;
    std::cout << "Enter the correct code to continue...\n\n";

}
bool PlayGame(int Difficulty)
{
   
    PrintIntroduction(Difficulty);
    
    int CodeA = rand() % Difficulty + Difficulty, 
    CodeB = rand() % Difficulty + Difficulty, 
    CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product of Codes
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n\n";

    std::vector<int> PlayerGuess = {};

    //Can enter all three at same time becasue second and third numebrs will be in the cin buffer
    //Store player guesses
    for(int i = 0; i < 3; i++)
    {
        int Guess;
        std::cin >> Guess;
        PlayerGuess.push_back(Guess);
    }
    
    std::cout << '\n';

    //Calculate the Sum of Guesses and Product of the Guesses
    int GuessSum = 0, GuessProduct = 1;
    for(auto x : PlayerGuess)
    {
        GuessSum += x;
        GuessProduct *= x;
    }

    //Calculate the outcome of the game
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Correct Code!\nKeep Going!\n";
        return true;
    }

    else
    {
        std::cout << "You Lose!\nTry again....\n";
        return false;
    }
}

int main()
{ 
        std::cout << R"(
 _       __________    __________  __  _________   __  _____   ________ __ __________ 
| |     / / ____/ /   / ____/ __ \/  |/  / ____/  / / / /   | / ____/ //_// ____/ __ \
| | /| / / __/ / /   / /   / / / / /|_/ / __/    / /_/ / /| |/ /   / ,<  / __/ / /_/ /
| |/ |/ / /___/ /___/ /___/ /_/ / /  / / /___   / __  / ___ / /___/ /| |/ /___/ _, _/ 
|__/|__/_____/_____/\____/\____/_/  /_/_____/  /_/ /_/_/  |_\____/_/ |_/_____/_/ |_|)";

    srand(time(NULL)); // create new random sequence based on the time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while(LevelDifficulty <= MaxLevel)// Loop until all levels are completed
    {
       bool bLevelComplete = PlayGame(LevelDifficulty);
       std::cin.clear(); 
       std::cin.ignore();

       if (bLevelComplete)
       {
           ++LevelDifficulty;
       }
        
    }
    
    std::cout << "YOU HAVE COMPLETED ALL LEVELS MISSION ACCOMPLISHED!\n";
    return 0;
}

