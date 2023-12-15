#ifndef MINESWEEPER_MINESWEEPERBOARD_H
#define MINESWEEPER_MINESWEEPERBOARD_H
#include "Array2D.h"


struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };


class MinesweeperBoard
{
    //Field board[100][100];
    Array2D<Field> board{1,1};
    int width;
    int height;

public:
    MinesweeperBoard(int, int, GameMode);
    void debug_display() const;
    void set_to_zero();
    void set_to_DEBUG();
    void set_difficulty(float num);
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
    bool isValid(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    bool isRevealed(int row, int col) const;
    GameState getGameState() const;
    char getFieldInfo(int row, int col) const;
    void revealField(int row, int col);
    bool isFirstMove() const;
    void revealFieldsAround(int row,int col);
    int getFlagCount() const;

};
#endif //MINESWEEPER_MINESWEEPERBOARD_H
