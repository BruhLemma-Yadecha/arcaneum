#include <iostream>

#define TABLE_SIDE 3

class tic_tac_toe_bot
{
    private:
        int *table;
        int row_sum[TABLE_SIDE] = {0};
        int column_sum[TABLE_SIDE] = {0};
    public:
        tic_tac_toe_bot (int *target_table)
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
        }
};



// Should receive an input then output the ideal move.
int main()
{

}