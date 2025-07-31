#include<iostream>
#include<vector>
using namespace std;

enum class Color {
    WHITE,
    BLACK
};

enum class GameStatus {
    IN_PROGRESS,
    WHITE_WIN,
    BLACK_WIN,
    STALEMATE,
    DRAW
};

class Player {
private:
    std::string name;
    Color color;

public:
    Player(const std::string& name, Color color);
    Color getColor() const;
};

class Piece; // forward declaration

class Square {
    private:
        int row;
        int col;
        Piece* piece;

    public:
        Square(int row, int col);
        bool isOccupied() const;
        Piece* getPiece() const;
        void setPiece(Piece* piece);
        int getRow() const;
        int getCol() const;
};
    

class Board {
    private:
        Square* grid[8][8];

    public:
        Board();
        void initialize();
        Square* getSquare(int row, int col) const;
};

class Move {
    private:
        Square* from;
        Square* to;
        Piece* movedPiece;
        Piece* capturedPiece;
        bool isCastlingMove;
        bool isEnPassant;
        bool isPromotion;

    public:
        Move(Square* from, Square* to, Piece* moved);
};

class Piece {
    protected:
        Color color;
        Square* currentSquare;

    public:
        Piece(Color color);
        virtual std::vector<Move> getValidMoves(Board* board) = 0;
        Color getColor() const;
        void setSquare(Square* square);
        Square* getSquare() const;
};

class King : public Piece {
    public:
        King(Color color);
        std::vector<Move> getValidMoves(Board* board) override;
};

class MoveValidator {
    public:
        static bool isValidMove(Board* board, Move* move, Player* player);
};

class Game {
    private:
        Board* board;
        Player* whitePlayer;
        Player* blackPlayer;
        Player* currentTurn;
        GameStatus status;
        std::vector<Move*> moveHistory;

    public:
        Game(Player* white, Player* black);
        void start();
        bool makeMove(Move* move);
        void switchTurn();
        GameStatus getStatus() const;
};
