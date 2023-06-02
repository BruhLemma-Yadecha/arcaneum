use std::collections::HashMap;

#[derive(Eq, Hash, PartialEq)]
enum Shapes {
    Rock,
    Paper,
    Scissors,
}

use Shapes::Paper;
use Shapes::Rock;
use Shapes::Scissors;

#[derive(Debug)]
enum Winner {
    Draw,
    Player1,
    Player2,
}

struct RockPaperScissorsEngine {
    rule_map: HashMap<Shapes, Shapes>,
}

impl RockPaperScissorsEngine {
    fn new() -> Self {
        let mut rule_map = HashMap::new();

        // Rules implemented here as (x, y) where x beats y
        rule_map.insert(Rock, Scissors);
        rule_map.insert(Scissors, Paper);
        rule_map.insert(Paper, Rock);

        RockPaperScissorsEngine {
            rule_map,
        }
    }
    fn round(&self, player1_move: Shapes, player2_move: Shapes) -> Winner {
        if player1_move == player2_move {
            return Winner::Draw;
        }

        if self.rule_map[&player1_move] == player2_move {
            return Winner::Player1;
        } else {
            return Winner::Player2;
        }
    }
}

fn main() {
    let game0 = RockPaperScissorsEngine::new();
    println!("{:?}", game0.round(Scissors, Scissors));
}

/*
use core::ops::Rem;

#[derive(Rem)]
#[derive(PartialEq)]
enum Options {
    Rock,
    Paper,
    Scissors,
}

use Options::Paper;
use Options::Rock;
use Options::Scissors;

enum Player {
    Draw,
    Player1,
    Player2,
}

use Player::Draw;
use Player::Player1;
use Player::Player2;

fn main() {
    let answer = match rock_paper_scissors(Rock, Paper) {
        Player1 => "Player 1 Wins!",
        Player2 => "Player 2 Wins!",
        Draw => "Draw!",
    };
    println!("{}", answer);
}

fn rock_paper_scissors(p1: Options, p2: Options) -> Player {
    if p1 == p2 {
        return Draw;
    }

    if p1 % 2 == p2 % 2 {
        return Player2;
    }
    else {
        return Player1;
    }
}
*/
