#include <iostream>

#define TABLE_SIDE 3

using namespace std;

class ticTacToe
{
    private:
        int winner = 0;
        int current_player;
        int table[3][3] = {0};

        void switch_active_player()
        {
            current_player = current_player == 1 ? 2 : 1;
        }
        void print_table()
        {
            for(int i = 0; i < TABLE_SIDE; i++)
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

    public:
        bool someone_has_won()
        {
            return winner == 0 ? false : true;
        }
        void run_turn()
        {
            // Woo
        }
    
};

int main()
{
    ticTacToe game0;
    while(!game0.someone_has_won())
    {
        game0.run_turn();
    }
}