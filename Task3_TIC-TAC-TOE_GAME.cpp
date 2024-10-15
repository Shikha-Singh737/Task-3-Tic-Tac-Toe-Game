#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard() {
    system("clear"); // Use "system("CLS")" for Windows
    cout << "Player 1 (X)  -  Player 2 (O)" << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    // Rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    // Columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return currentPlayer;

    return 0;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void game() {
    currentPlayer = 1;
    currentMarker = 'X';
    int winner = 0;
    int slot;

    drawBoard();
    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << ", enter your slot: ";
        cin >> slot;
        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move. Try again." << endl;
            i--;
            continue;
        }
        drawBoard();
        winner = checkWinner();
        if (winner) {
            cout << "Player " << winner << " wins!" << endl;
            break;
        }
        switchPlayer();
    }

    if (winner == 0) {
        cout << "It's a draw!" << endl;
    }
}

int main() {
    char playAgain;
    do {
        for (int i = 0; i < 3; i++) // Reset the board
            for (int j = 0; j < 3; j++)
                board[i][j] = '1' + (i * 3 + j);
        game();
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}
