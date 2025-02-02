#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

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
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to get valid integer input
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
            return input;
        }
    }
}

void computerMove(char board[3][3]) {
    srand(time(0)); // Seed the random number generator

    while (true) {
        int row = rand() % 3;
        int col = rand() % 3;
        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            break;
        }
    }
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int row, col;

    cout << "Welcome to X O Game Best OfLuck!\n";

    for (int turn = 0; turn < 9; turn++) {
        drawBoard(board);

        if (player == 'X') {
            while (true) {
                row = getValidIntegerInput("Enter row (1-3): ", 1, 3) - 1;
                col = getValidIntegerInput("Enter column (1-3): ", 1, 3) - 1;

                if (board[row][col] == ' ') {
                    board[row][col] = 'X';
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

    // Check for a draw *only after* all moves are made
    drawBoard(board);
    cout << "It's a draw!\n";
    return 0;
}

