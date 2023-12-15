#ifndef MINESWEEPER_MSBOARDTEXTVIEW_H
#define MINESWEEPER_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"


class MSBoardTextView
{
    MinesweeperBoard & board;
public:
    MSBoardTextView(MinesweeperBoard &);
    void display();
};


#endif //MINESWEEPER_MSBOARDTEXTVIEW_H
