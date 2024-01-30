a#include <iostream>
#include <cstdlib> // For clearing the screen

using namespace std;

void printBoard(); // Function declaration
int checkWin();    // Function declaration

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    char playAgain;

    do
    {
        int player = 1, input, status = -1;
        char mark;
        printBoard(); // Display the initial game board.

        while (status == -1)
        {
            player = (player % 2 == 0) ? 2 : 1; // Alternate between players 1 and 2.
            mark = (player == 1) ? 'X' : 'O';    // Set the mark ('X' or 'O') based on the current player.

            cout << "Please Enter Number for player " << player << ": ";
            cin >> input; // Get the player's move input.

            if (input < 1 || input > 9)
            {
                cout << "Invalid Input!" << endl; // Display an error message for invalid input.
            }

            board[input] = mark; // Update the game board with the player's move.
            clearScreen();       // Display the updated game board.

            int result = checkWin(); // Check if there is a winner or a draw.
            if (result == 1)
            {
                cout << "Player " << player << " is the Winner" << endl; // Display the winner.
                break; // Exit the loop if there is a winner.
            }
            else if (result == 0)
            {
                cout << "Match Draw" << endl; // Display a draw message.
                break; // Exit the loop if it's a draw.
            }

            player++; // Switch to the next player for the next turn.
        }

        cout << "Do you want to play another game? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y')
        {
            // Reset the board for a new game.
            for (int i = 1; i <= 9; ++i)
            {
                board[i] = '0' + i;
            }
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

void printBoard()
{
    clearScreen(); // Clear the console screen.
    cout << "\n\n";
    cout << "=== TIC TAC TOE === \n\n";
    cout << "    |    |      \n";
    cout << " " << board[1] << "  | " << board[2] << "  | " << board[3] << "   \n";
    cout << "____|____|____  \n";
    cout << "    |    |      \n";
    cout << " " << board[4] << "  | " << board[5] << "  | " << board[6] << endl;
    cout << "____|____|____  \n";
    cout << "    |    |      \n";
    cout << " " << board[7] << "  | " << board[8] << "  | " << board[9] << "   \n";
    cout << "\n\n";
}

int checkWin()
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1; // Return 1 if there is a winner in the first row.
    }
    if (board[4] == board[5] && board[5] == board[6])
    {
        return 1; // Return 1 if there is a winner in the second row.
    }
    if (board[7] == board[8] && board[8] == board[9])
    {
        return 1; // Return 1 if there is a winner in the third row.
    }
    if (board[1] == board[4] && board[4] == board[7])
    {
        return 1; // Return 1 if there is a winner in the first column.
    }
    if (board[2] == board[5] && board[5] == board[8])
    {
        return 1; // Return 1 if there is a winner in the second column.
    }
    if (board[3] == board[6] && board[6] == board[9])
    {
        return 1; // Return 1 if there is a winner in the third column.
    }
    if (board[1] == board[5] && board[5] == board[9])
    {
        return 1; // Return 1 if there is a winner in the diagonal from top-left to bottom-right.
    }
    if (board[3] == board[5] && board[5] == board[7])
    {
        return 1; // Return 1 if there is a winner in the diagonal from top-right to bottom-left.
    }

    int count = 0;

    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            count++;
        }
    }

    if (count == 9)
    {
        return 0; // Return 0 if the game is a draw.
    }

    return -1; // Return -1 if the game is still ongoing.
}
