#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";

    auto start = high_resolution_clock::now();

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

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<minutes>(stop - start); // Calculate in minutes

            // Check if the duration is less than 1 minute, if so print seconds
            if (duration.count() < 1) {
                auto duration_seconds = duration_cast<seconds>(stop - start);
                cout << "Time taken to guess: " << duration_seconds.count() << " seconds.\n";
            }
            else {
                cout << "Time taken to guess: " << duration.count() << " minutes.\n";
            }


        }
    } while (guess != secretNumber);

    return 0;
}
