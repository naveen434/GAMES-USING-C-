#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits> // Required for numeric_limits

using namespace std;

// ... (drawBoard and checkWin functions remain the same)

// Function to get valid integer input from the user (improved)
int getValidIntegerInput(const string& prompt, int min, int max) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (input >= min && input <= max) {
            break;
        } else {
            cout << "Input must be between " << min << " and " << max << ".\n";
        }
    }
    return input;
}


// Function for the computer's move (Improved AI - blocking/winning)
void computerMove(char board[3][3]) {
    // 1. Check if computer can win in this turn
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O'; // Temporarily make the move
                if (checkWin(board, 'O')) {
                    cout << "Computer played at row " << i << ", column " << j << endl;
                    return; // Win found, move made
                }
                board[i][j] = ' '; // Undo the move
            }
        }
    }

    // 2. Check if player can win in this turn, block if possible
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X'; // Temporarily make the move for player
                if (checkWin(board, 'X')) {
                    board[i][j] = 'O'; // Block the player
                    cout << "Computer played at row " << i << ", column " << j << endl;
                    return; // Block made
                }
                board[i][j] = ' '; // Undo the move
            }
        }
    }


    // 3. If no winning or blocking move, make a random move (less important now)
    vector<pair<int, int>> availableSpots;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                availableSpots.push_back({i, j});
            }
        }
    }

    if (!availableSpots.empty()) {
        srand(time(0)); // Seed the random number generator
        int randomIndex = rand() % availableSpots.size();
        int row = availableSpots[randomIndex].first;
        int col = availableSpots[randomIndex].second;
        board[row][col] = 'O';
        cout << "Computer played at row " << row << ", column " << col << endl;
    }
}

int main() {
    // ... (rest of the main function remains the same)
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int row, col;
    int turn;

    cout << "Welcome to X O Game Best OfLuck!\n";

    for (turn = 0; turn < 9; turn++) {
        drawBoard(board);

        if (player == 'X') { // Human player's turn
            while (true) {
                row = getValidIntegerInput("Player " + string(1, player) + ", enter row (0-2): ", 0, 2);
                col = getValidIntegerInput("Player " + string(1, player) + ", enter column (0-2): ", 0, 2);

                if (board[row][col] != ' ') {
                    cout << "Invalid move. Try again.\n";
                } else {
                    break;
                }
            }
            board[row][col] = player;
        } else { // Computer's turn
            computerMove(board);
        }



        if (checkWin(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " wins!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X'; // Switch players
    }

    drawBoard(board);
    if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) {
        cout << "It's a draw!\n";
    }

    return 0;
}
