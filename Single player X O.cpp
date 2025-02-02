#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to draw the board
void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}


int getValidIntegerInput(const string& prompt, int min, int max) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (cin.fail() || input < min || input > max) {
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume any extra input
            return input;
        }
    }
}

void computerMove(char board[3][3]) {
    vector<pair<int, int>> availableSpots;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                availableSpots.push_back({i, j});
            }
        }
    }

    if (!availableSpots.empty()) {
        srand(time(0));
        int randomIndex = rand() % availableSpots.size();
        int row = availableSpots[randomIndex].first;
        int col = availableSpots[randomIndex].second;
        board[row][col] = 'O';
        cout << "Computer plays at row " << row + 1 << ", column " << col + 1 << endl;
    }
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; // Correct declaration
    char player = 'X';

    cout << "Welcome to X O Game!\n";

    for (int turn = 0; turn < 9; turn++) {
        drawBoard(board);

        if (player == 'X') {
            cout << "Your (X) turn.\n";
            while (true) {
                int row = getValidIntegerInput("Enter row (1-3): ", 1, 3) - 1;
                int col = getValidIntegerInput("Enter column (1-3): ", 1, 3) - 1;

                if (board[row][col] == ' ') {
                    board[row][col] = player;
                    break;
                } else {
                    cout << "That spot is already taken. Try again.\n";
                }
            }
        } else {
            computerMove(board);
        }

        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    drawBoard(board);
    cout << "It's a draw!\n";
    return 0;
}
