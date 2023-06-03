#include <iostream>
#include <stdio.h>

#define TABLE_SIDE 3

class tic_tac_toe_bot
{
    private:
        const int CONVERSION_CHART[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Used to convert tuple coords to regular dial coords
        int (*table)[TABLE_SIDE];
        int *row_sum;
        int *column_sum;
        int left_diagonal_sum = 0;
        int right_diagonal_sum = 0;

        void update_sums();
        int blank_tile_spotter_row(int particular_row);
        int blank_tile_spotter_column(int particular_column);

    public:
        tic_tac_toe_bot(int (*target_table)[TABLE_SIDE])
        {
            table = target_table;
        }

        int take_turn();
};

int tic_tac_toe_bot::blank_tile_spotter_row(int particular_row)
{
    for (int i = 0; i < TABLE_SIDE; i++)
    {
        if (table[particular_row][i] == 0)
        {
            return CONVERSION_CHART[particular_row][i];
        }
    }
}

int tic_tac_toe_bot::blank_tile_spotter_column(int particular_column)
{
    for (int i = 0; i < TABLE_SIDE; i++)
    {
        if (table[i][particular_column] == 0)
        {
            return CONVERSION_CHART[i][particular_column];
        }
    }
}

void tic_tac_toe_bot::update_sums()
{
    int local_row_sum[TABLE_SIDE] = {0};
    int local_column_sum[TABLE_SIDE] = {0};
    int local_left_diagonal_sum = 0;
    int local_right_diagonal_sum = 0;

    for (int i = 0; i < TABLE_SIDE; i++)
    {
        for (int j = 0; j < TABLE_SIDE; j++)
        {
            local_row_sum[i] += table[i][j];
            local_column_sum[j] += table[i][j];
        }
    }

    for (int i = 0; i < TABLE_SIDE; i++)
    {
        local_left_diagonal_sum += table[i][i];
    }

    for (int i = TABLE_SIDE - 1; i >= 0; i--)
    {
        local_right_diagonal_sum += table[i][TABLE_SIDE - 1 - i];
    }

    row_sum = local_row_sum;
    column_sum = local_column_sum;
    left_diagonal_sum = local_left_diagonal_sum;
    right_diagonal_sum = local_right_diagonal_sum;

    for (int i = 0; i < TABLE_SIDE; i++)
    {
        printf("Row %d: %d | ", i, row_sum[i]);
        printf("Column %d: %d\n", i, column_sum[i]);
    }
    printf("Diagonal (Left): %d |", left_diagonal_sum);
    printf("Diagonal (Right): %d\n", right_diagonal_sum);
}

int tic_tac_toe_bot::take_turn()
{
    update_sums();

    // First condition - check for two in a row
    for (int i = 0; i < TABLE_SIDE; i++)
    {
        if (row_sum[i] == 2)
        {
            return blank_tile_spotter_row(i);
        }
        if (column_sum[i] == 2)
        {
            return blank_tile_spotter_column(i);
        }
        if (left_diagonal_sum == 2)
        {
            return table[0][0] == 0 ? 1 : TABLE_SIDE *TABLE_SIDE; // Checks the top left or bottom right.
        }
        if (right_diagonal_sum == 2)
        {
            return table[0][TABLE_SIDE - 1] == 0 ? TABLE_SIDE : ((TABLE_SIDE - 1) * TABLE_SIDE) + 1; // Checks the top right and bottom left.
        }
    }

    // Second condition - block a two in a row
    for (int i = 0; i < TABLE_SIDE; i++)
    {
        if (row_sum[i] == 8)
        {
            return blank_tile_spotter_row(i);
        }
        if (column_sum[i] == 8)
        {
            return blank_tile_spotter_column(i);
        }
        if (left_diagonal_sum == 8)
        {
            return table[0][0] == 0 ? 1 : TABLE_SIDE * TABLE_SIDE; // Checks the top left or bottom right.
        }
        if (right_diagonal_sum == 8)
        {
            printf("Replacing %d\n", table[0][TABLE_SIDE]);
            return table[0][TABLE_SIDE - 1] == 0 ? TABLE_SIDE : ((TABLE_SIDE - 1) * TABLE_SIDE) + 1; // Checks the top right and bottom left.
            
        }
    }
    // Third - 

    // Fourth

    // Fifth
    int centre_coordinate = (TABLE_SIDE - 1) / 2
    if (table[centre_coordinate][centre_coordinate] == 0)
    {
        return CONVERSION_CHART[centre_coordinate][centre_coordinate];
    }

    // Sixth - Corners - play an opposing corner
    if (table[0][0] == 4) {return CONVERSION_CHART[TABLE_SIDE - 1][TABLE_SIDE - 1];}
    if (table[0][TABLE_SIDE - 1] == 4) {return CONVERSION_CHART[TABLE_SIDE - 1][0];}
    if (table[TABLE_SIDE - 1][0] == 4) {return CONVERSION_CHART[0][TABLE_SIDE - 1];}
    if (table[TABLE_SIDE - 1][TABLE_SIDE - 1] == 4) {return CONVERSION_CHART[0][0];}

    // Seven - play an open corner
    if (table[0][0] == 0) {return CONVERSION_CHART[0][0];}
    if (table[0][TABLE_SIDE - 1] == 0) {return CONVERSION_CHART[0][TABLE_SIDE - 1];}
    if (table[TABLE_SIDE - 1][0] == 0) {return CONVERSION_CHART[TABLE_SIDE - 1][0];}
    if (table[TABLE_SIDE - 1][TABLE_SIDE - 1] == 0) {return CONVERSION_CHART[TABLE_SIDE - 1][TABLE_SIDE - 1];}

    // Eight - fill an edge
    /// THIS IS RESTRICTED FOR 3x3
    if (table[0][1] == 0) {return CONVERSION_CHART[0][1];}
    if (table[1][0] == 0) {return CONVERSION_CHART[1][0];}
    if (table[1][2] == 0) {return CONVERSION_CHART[1][2];}
    if (table[2][1] == 0) {return CONVERSION_CHART[2][1];}

}

void print_table(int (table)[3][3])
{
    for (int i = 0; i < TABLE_SIDE; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < TABLE_SIDE; j++)
        {
            std::cout << (table[i][j] != 0 ? table[i][j] == 1 ? "X" : "O" : " ");
            std::cout << " |";
        }
        std::cout << std::endl;
    }
}

// Should receive an input then output the ideal move.
int main()
{
    const int CONVERSION_CHART[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}; // Used to convert coords
    int table[3][3] = {
    {0,0,0},
    {4,4,0},
    {0,0,0}};
    print_table(table);
    tic_tac_toe_bot bot0(table);
    int picked_tile = bot0.take_turn();
    std::cout << "Bot picks " << picked_tile << std::endl;
    int picked_row = CONVERSION_CHART[picked_tile - 1][0];
    int picked_column = CONVERSION_CHART[picked_tile - 1][1];
    table[picked_row][picked_column] = 1;
    print_table(table);
}