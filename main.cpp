#include <iostream>
#include <random>
//using namespace std;
// I'm doing it without the namespace since it visually shows me where all the outputs are.

// Build your solution starting from this code.
//Most of the code I originally did is commented out, but it's still there.
//Extra things added:
//Try inputting an 'o' after the game ends
//Try beating the game in one single turn.
//Added a way to adjust the score you have to reach (hopefully)

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
    char ee;
};

class Die {
private: //learning, not needed in a class
    int m_value;
    int m_numOfSides;

public:

    Die() {
        m_numOfSides = 6;
        setValue();
    }

    //conditional changing of variable
    void set_numOfSides(int numOfSides) {
        switch (numOfSides) {
            case 4:
                m_numOfSides = 4;
                break;
            case 6:
                m_numOfSides = 6;
                break;
            case 8:
                m_numOfSides = 8;
                break;
            default:
                m_numOfSides = 6;
        }

    }
    int getNumOfSides() {
        return m_numOfSides;
    }

    //Set private thing
    void setValue() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, m_numOfSides);
        m_value = dis(gen);
    }

    //Get private thing
    int getValue() {
        return m_value;
        //put rules for accessing data here, not in setting
    }
};

void roll(GameState &gs);
void hold(GameState &gs);
void takeTurn(GameState &gs);
void play_game(GameState &gs);
void display_rules();


int main() {
    GameState my_game; // instantiate a GameState object

    display_rules();

    play_game(my_game);
    return 0;
}


void display_rules() {
    std::cout << "Rules of Pig Dice:" << std::endl;
    std::cout << "1. Roll a dice, and try to get to 20 score in the fewest amount of Turns." << std::endl;
    std::cout << "2. Your turn ends when you Hold, or if you roll a 1." << std::endl;
    std::cout << "3. If you roll a 1, you lose all points for the current turn." << std::endl;
    std::cout << "4. Holding will save all the points you've gathered, but end the turn." << std::endl;
    std::cout << std::endl;
}

void roll(GameState &gs) {
    /*int dicenumber = 0;
    dicenumber = rand() % 6 + 1;
    std::cout << "Rolled a " << dicenumber << std::endl;
    //why the hell does this programming language do rand like this
    if (dicenumber != 1) {
        gs.score_this_turn += dicenumber;
    } else {
        gs.score_this_turn = 0;
        gs.turn_over = true;
        std::cout << "Turn over. Score has been lost." << std::endl;
    }*/

    /*srand(time(0));
    int die = rand() % 6 + 1;*/

    Die myDie; // calls default values
    //myDie.setValue();
    std::cout << "Die: " << myDie.getValue();
    if (myDie.getValue() == 1) {
        std::cout << std::endl << "Rolled a 1. Lost turn score." << std::endl;
        gs.score_this_turn = 0;
        gs.turn_over = true;
    } else {
        gs.score_this_turn += myDie.getValue();
        std::cout << " - Current turn score: " << gs.score_this_turn << std::endl;
    }
    
}

void hold(GameState &gs) {
    gs.turn_over = true;
}

void takeTurn(GameState &gs) {
    /*
    std::cout << "Turn " << gs.turn_count << " - Current Score: " << gs.score_this_turn << std::endl;
    std::cout << "Would you like to Roll or Hold? (r/h)" << std::endl;
    std::cin >> gs.choice;

    if (gs.choice == 'r') {
        roll(gs);
    }else if (gs.choice == 'h') {
        hold(gs);
    }else {
        std::cout << "Invalid character. Defaulted to Hold." << std::endl;
        hold(gs);
    }
    */
    gs.turn_count++;
    std::cout << std::endl << "Turn " << gs.turn_count << " - Current Score: " << gs.game_score << std::endl;

    while (gs.turn_over == false) {
        std::cout << "Would you like to Roll or Hold? (r/h):  ";
        std::cin >> gs.choice;
        if (gs.choice == 'r') {
            roll(gs);
        }else if (gs.choice == 'h') {
            hold(gs);
        }else {
            std::cout << "Invalid character. Defaulted to Hold." << std::endl;
            hold(gs);
        }
    }
    std::cout << "Score gathered: " << gs.score_this_turn << std::endl;
}

void play_game(GameState &gs) {
    while (!gs.game_over) {
        takeTurn(gs);
        gs.game_score += gs.score_this_turn;
        if (gs.game_score >= 20) {
            gs.game_over = true;
        }
        else {
            gs.turn_over = false;
            gs.score_this_turn = 0;
        }
    }
    std::cout << std::endl << "You won!" << std::endl;
    std::cout << "You finished with " << gs.game_score << " in " << gs.turn_count << " turns." << std::endl;
    std::cin >> gs.ee;
    if (gs.ee == 'o') {
        std::cout << "My thanks to Yusuke Ohmura!";
        //inside joke
    }
}