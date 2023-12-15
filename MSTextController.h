
#ifndef MINESWEEPER_MSTEXTCONTROLLER_H
#define MINESWEEPER_MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController
{
    MinesweeperBoard &board;
    MSBoardTextView &view;
public:
    MSTextController(MinesweeperBoard &, MSBoardTextView &);
    void play();


};


#endif //MINESWEEPER_MSTEXTCONTROLLER_H
