#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n////////////////////////////////////////////////////////////////////\n";
    std::cout << "\n\n~ You have just returned from three weeks of vacation and have forgotten your gym locker combination.\n\n";
    std::cout << "~ Using hints you left for yourself, guess the correct combination to get access to your locker so you can work out...\n\n";
    std::cout << "Hints for locker " << Difficulty << " are below.\n\n";
}

bool PlayGame(int Difficulty, int MaximumDifficulty)
{
    PrintIntroduction(Difficulty);

    const int Digit1 = rand() % Difficulty + Difficulty;
    const int Digit2 = rand() % Difficulty + Difficulty;
    const int Digit3 = rand() % Difficulty + Difficulty;

    const int DigitSum = Digit1 + Digit2 + Digit3;
    const int DigitProduct = Digit1 * Digit2 * Digit3;


    std::cout << "------------------------------------------------\n";
    std::cout << "~ There are three digits in the code.\n";
    std::cout << "~ The digits sum to: " << DigitSum << "\n";
    std::cout << "~ and the product of the digits is: " << DigitProduct << "\n";
    std::cout << "------------------------------------------------\n";    

    int GuessA, GuessB, GuessC;
    std::cout << "Digit 1? >";
    std::cin >> GuessA;
    std::cout << "Digit 2? >";
    std::cin >> GuessB;
    std::cout << "Digit 3? >";
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    if (GuessSum == DigitSum && GuessProduct == DigitProduct)
    {
        if (Difficulty == MaximumDifficulty)
        {
            std::cout << "OPEN! No more lockers.\n";
        } 
        else
        {
            std::cout << "OPEN! Next Locker...";
        }
        return true;
    }
    else
    {
        std::cout << "Wrong combination! Try again.";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int Difficulty = 1;
    const int MaximumDifficulty = 5;

    while(Difficulty <= MaximumDifficulty)
    {
        bool bLevelComplete = PlayGame(Difficulty, MaximumDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++Difficulty;
        }
    }
    std::cout << "Congratulations on opening all the lockers. Get your stuff and go!";
    return 0;
}