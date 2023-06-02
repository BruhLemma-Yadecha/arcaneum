#include <iostream>

#define TABLE_SIDE 3
#define IGNORED_AMOUNT 1024

using std::cout;
using std::cin;
using std::endl;

class ticTacToe
{
    private:
        const int CONVERSION_CHART[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}; // Used to convert coords
        int winner = 0;
        int current_player = 1;
        int table[TABLE_SIDE][TABLE_SIDE] = {0};

        void switch_active_player();
        void print_table();
        void check_for_a_winner();
        void win_check();

    public:
        bool someone_has_won();
        void run_turn();
        void print_win_screen();
};

void ticTacToe::switch_active_player()
{
    current_player = current_player == 1 ? 4 : 1;
}

void ticTacToe::print_table()
{
    for (int i = 0; i < TABLE_SIDE; i++)
    {
            cout << "|";
            for (int j = 0; j < TABLE_SIDE; j++)
            {
                cout << (table[i][j] != 0 ? table[i][j] == 1 ? " X" : " O" : "  ");
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
    int display_player = current_player == 1 ? 1 : 2;
    cout << "Player " << display_player << " won!" << endl;
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
    win_check();
    if (winner == 0)
    {
            switch_active_player(); // Continues the game if no winner has been found.
    }
}

void ticTacToe::win_check()
{
    int row_sum[TABLE_SIDE] = {0};
    int column_sum[TABLE_SIDE] = {0};

    for (int row_index = 0; row_index < TABLE_SIDE; row_index++)
    {
            for (int column_index = 0; column_index < TABLE_SIDE; column_index++)
            {
                row_sum[column_index] += table[row_index][column_index];
                column_sum[row_index] += table[row_index][column_index];
            }
    }

    for(int i = 0; i < TABLE_SIDE; i++)
    {
        if (row_sum[i] == 3 || column_sum[i] == 3)
        {
            winner = 1;
            return;
        }
        if (row_sum[i] == 12 || column_sum[i] == 12)
        {
            winner = 2;
            return;
        }
    }

    // Diagonal check
    int left_diagonal_sum = 0;
    for (int i = 0; i < TABLE_SIDE; i++)
    {
        left_diagonal_sum += table[i][i];
    }

    int right_diagonal_sum = 0;
    for (int i = TABLE_SIDE - 1; i >= 0; i--)
    {
        right_diagonal_sum += table[i][TABLE_SIDE - 1 - i];
    }

    if (left_diagonal_sum == 3 || right_diagonal_sum == 3)
    {
        winner = 1;
        return;
    }
    else if (left_diagonal_sum == 12 || right_diagonal_sum == 12)
    {
        winner = 2;
        return;
    }
}

int main()
{
    ticTacToe game0;
    while(true)
    {
        if (!game0.someone_has_won())
        {
            game0.run_turn();
        }
        else
        {
            game0.print_win_screen();
            break;
        }
    }
}