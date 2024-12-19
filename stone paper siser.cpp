#include <iostream>
#include <cstdlib>
#include <ctime>

void playRound(int &userScore, int &computerScore) {
    std::srand(std::time(0));
    std::string choices[3] = {"Stone", "Paper", "Scissors"};
    int computerChoice = std::rand() % 3;

    std::cout << "Choose one: (0) Stone, (1) Paper, (2) Scissors: ";
    int userChoice;
    std::cin >> userChoice;

    std::cout << "You chose: " << choices[userChoice] << std::endl;
    std::cout << "Computer chose: " << choices[computerChoice] << std::endl;

    if (userChoice == computerChoice) {
        std::cout << "It's a tie!" << std::endl;
    } else if ((userChoice == 0 && computerChoice == 2) || 
               (userChoice == 1 && computerChoice == 0) || 
               (userChoice == 2 && computerChoice == 1)) {
        std::cout << "You win this round!" << std::endl;
        userScore++;
    } else {
        std::cout << "Computer wins this round!" << std::endl;
        computerScore++;
    }
}

void playGame() {
    int userScore = 0;
    int computerScore = 0;
    const int winningScore = 5;

    std::cout << "Welcome to STONE, Paper, Scissors!" << std::endl;

    while (userScore < winningScore && computerScore < winningScore) {
        playRound(userScore, computerScore);
        std::cout << "Score - You: " << userScore << " Computer: " << computerScore << std::endl;
    }

    if (userScore == winningScore) {
        std::cout << "Congratulations! You are the overall winner!" << std::endl;
    } else {
        std::cout << "Computer is the overall winner! Better luck next time!" << std::endl;
    }
}

int main() {
    playGame();
    return 0;
}
