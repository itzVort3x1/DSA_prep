#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Player {
    private: 
        string color;
        string name;
    public:
        Player(string color, string name);
        string getName();
        string getColor();
        pair<int, int> makeMove();
};

class Board {
    private:
        vector<vector<string>> board;
    public:
        Board();

        void resetBoard();
        void printBoard();
        void isEmpty(int row, int col);
        void placeMove(int row, int col, string symbol);
        void isWinner(int row, int col, string symbol);
};

class Game {
private:
    Player player1;
    Player player2;
    Player currentPlayer;
    Board board;

public:
    Game(Player p1, Player p2);

    void start();
    void switchTurns();
    bool checkDraw();
};

int main() {
    Player player1 = Player("Blue", "L");
    Player player2 = Player("Red", "H"); 

    Game game(player1, player2);

    game.start();

    return 0;
}