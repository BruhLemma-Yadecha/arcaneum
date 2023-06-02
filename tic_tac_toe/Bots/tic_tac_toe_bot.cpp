#include <iostream>

#define TABLE_SIDE 3

class tic_tac_toe_bot
{
    private:
        const int CONVERSION_CHART[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}; // Used to convert coords
        int *table;
        int row_sum[TABLE_SIDE] = {0};
        int column_sum[TABLE_SIDE] = {0};

        int blank_tile_spotter_row(int particular_row);
    public : tic_tac_toe_bot(int *target_table)
        {
            table = target_table;
        }
        void update_sums()
        {
            for (int i = 0; i < TABLE_SIDE; i++)
            {
                for (int j = 0; j < TABLE_SIDE; j++)
                {
                    this->row_sum[i] += this->table[i][j];
                }
            }
        }
        int take_turn()
        {
            update_sums();
            // Check first condition
            for(int i = 0; i < TABLE_SIDE; i++)
            {
                if (row_sum[i] == 2)
                {
                    return blank_tile_spotter_row(i);
                }
            }
        }
};

int tic_tac_toe_bot::blank_tile_spotter_row(int particular_row)
{
    for (int i = 0; i < TABLE_SIDE; i++)
    {
        if (table[particular_row][i] == 0)
        {
            return this->CONVERSION_CHART;
        }
    }
}



// Should receive an input then output the ideal move.
int main()
{

}