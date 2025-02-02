#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";

    auto start = high_resolution_clock::now();

    do {
        auto now = high_resolution_clock::now();
        auto elapsed = duration_cast<seconds>(now - start);
        cout << "\rElapsed time: " << elapsed.count() << " seconds" << flush;

        cout << "\nGuess a number between 1 and 100: ";
        cin >> guess;
        attempts++;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        int diff = abs(secretNumber - guess);

        if (guess < secretNumber) {
            if (diff <= 5) {
                cout << "Very close! Try a little higher.\n";
            } else if (diff <= 10) {
                cout << "Close, but still a bit low. Try higher.\n";
            } else {
                cout << "Too low! You're quite far off.\n";
            }
        } else if (guess > secretNumber) {
            if (diff <= 5) {
                cout << "Very close! Try a little lower.\n";
            } else if (diff <= 10) {
                cout << "Close, but still a bit high. Try lower.\n";
            } else {
                cout << "Too high! You're quite far off.\n";
            }
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            cout << "Time taken to guess: " << duration.count() << " seconds.\n";
            break;
        }

        if (attempts >= 5) {
            if (diff <= 5) {
                cout << "You're super close, just a little more!\n";
            } else if (diff <= 10) {
                cout << "You're getting there, not far now!\n";
            }
        }

        if (attempts >= 10) {
            cout << "Sorry, you've reached the maximum number of attempts. The secret number was: " << secretNumber << ".\n";
            break;
        }

    } while (guess != secretNumber);

    return 0;
}
