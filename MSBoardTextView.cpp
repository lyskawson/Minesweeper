#include "MSBoardTextView.h"
#include <iomanip>

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board) : board(board)
{

}

void MSBoardTextView::display()
{
    using namespace std;

    cout << " ";
    for(int k = 0; k<board.getBoardWidth();k++)
        cout <<  setw(3) << k ;
    cout << endl;

    for (int i = 0;i<board.getBoardHeight();i++)
    {
        cout <<i<< " ";
        for(int j=0;j<board.getBoardWidth();j++)
        {
            cout << "[" << board.getFieldInfo(i, j)<<"]";
        }
        cout << std::endl;
    }

}