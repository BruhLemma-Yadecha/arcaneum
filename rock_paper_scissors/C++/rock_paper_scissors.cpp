#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

enum Shapes
{
    Rock,
    Paper,
    Scissors,
};

enum Winner
{
    Draw,
    Player1,
    Player2,
};

class RockPaperScissorsEngine
{
    private:
    // Change rules here.
        unordered_map<Shapes, Shapes> rule_map = {
            {Shapes::Rock, Shapes::Scissors},
            {Shapes::Scissors, Shapes::Paper},
            {Shapes::Paper, Shapes::Rock},
        };
    public:
        Winner round(Shapes player1_move, Shapes player2_move)
        {
            if (player1_move == player2_move)
            {
                return Winner::Draw;
            }

            if (this->rule_map[player1_move] == player2_move)
            {
                return Winner::Player1;
            }
            else
            {
                return Winner::Player2;
            }
        }
};

int main()
{
    RockPaperScissorsEngine game0;
    cout << game0.round(Shapes::Paper, Shapes::Paper) << endl;
}