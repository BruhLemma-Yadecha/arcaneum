#include <iostream>

#define TABLE_SIDE 3
#define IGNORED_AMOUNT 1024

using std::cout;
using std::cin;
using std::endl;

class ticTacToe
{
    private:
        const int CONVERSION_CHART[9][2] = { {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} }; // Used to convert coords
        int winner = 0;
        int current_player = 1;
        int table[TABLE_SIDE][TABLE_SIDE] = {0};

        void switch_active_player();
        void print_table();
        void check_for_a_winner();

    public:
        bool someone_has_won();
        void run_turn();
        void print_win_screen();
};

void ticTacToe::switch_active_player()
{
    current_player = current_player == 1 ? 2 : 1;
}

void ticTacToe::print_table()
{
    for (int i = 0; i < TABLE_SIDE; i++)
    {
            cout << "| ";
            for (int j = 0; j < TABLE_SIDE; j++)
            {
                cout << (table[i][j] != 0 ? table[i][j] == 1 ? "X" : "O" : " ");
                cout << " |";
            }
            cout << endl;
    }
}

bool ticTacToe::someone_has_won ()
{
    return winner == 0 ? false : true;
}

void ticTacToe::print_win_screen()
{
    print_table();
    cout << "Player " << current_player << " won!" << endl;
}

void ticTacToe::run_turn()
{
    print_table();

    int picked_tile, picked_row, picked_column;
    while (true) // This helps run checks
    {
            // Input the picked tile and check if it's within bounds.
            cout << "Player " << current_player << ": ";
            cin >> picked_tile;
            if (picked_tile < 1 || picked_tile > 9)
            {
                cout << "Invalid tile! Try again" << endl;
                cin.ignore();
                continue;
            }

            picked_row = CONVERSION_CHART[picked_tile - 1][0];
            picked_column = CONVERSION_CHART[picked_tile - 1][1];

            if (table[picked_row][picked_column] != 0)
            {
                cout << "That tile is already occupied! Try again" << endl;
                cin.ignore();
                continue;
            }
            break;
    }

    table[picked_row][picked_column] = current_player; // Reserving the tile
    check_for_a_winner();
    if (winner == 0)
    {
            switch_active_player(); // Continues the game if no winner has been found.
    }
}

void ticTacToe::check_for_a_winner()
{
    int row_product[TABLE_SIDE] = {1};
    int column_product[TABLE_SIDE] = {1};

    for (int row_index = 0; row_index < TABLE_SIDE; row_index++)
    {
            for (int column_index = 0; column_index < TABLE_SIDE; column_index++)
            {
                row_product[column_index] *= table[row_index][column_index];
                column_product[row_index] *= table[row_index][column_index];
            }
    }

    for (int row_checked = 0; row_checked < TABLE_SIDE; row_checked++)
    {
            if (row_product[row_checked] == 1)
            {
                winner = 1;
                return;
            }
            else if (row_product[row_checked] == 8)
            {
                winner = 2;
                return;
            }
    }

    for (int column_checked = 0; column_checked < TABLE_SIDE; column_checked++)
    {
            if (column_product[column_checked] == 1)
            {
                winner = 1;
                return;
            }
            else if (column_product[column_checked] == 8)
            {
                winner = 2;
                return;
            }
    }

    // Diagonal check
    int left_diagonal_product = 1;
    for (int i = 0; i < TABLE_SIDE; i++)
    {
            left_diagonal_product *= table[i][i];
    }

    int right_diagonal_product = 1;
    for (int i = TABLE_SIDE - 1; i >= 0; i--)
    {
            right_diagonal_product *= table[i][TABLE_SIDE - 1 - i];
    }

    if (left_diagonal_product == 1 || right_diagonal_product == 1)
    {
            winner = 1;
            return;
    }
    else if (left_diagonal_product == 8 || right_diagonal_product == 8)
    {
            winner = 2;
            return;
    }
}

int main()
{
    ticTacToe game0;
    while(!game0.someone_has_won())
    {
        game0.run_turn();
    }
    game0.print_win_screen();
}