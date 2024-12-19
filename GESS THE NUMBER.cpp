#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator
    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";

    do {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low. Try again.\n";
        } else if (guess > secretNumber) {
            cout << "Too high. Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
    } while (guess != secretNumber);

    return 0;
}