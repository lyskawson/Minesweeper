#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard & board, MSBoardTextView & view)
        :board(board),view(view)
{

}

void MSTextController::play()
{
    using namespace std;
    while(board.getGameState() == RUNNING)
    {
        view.display();
        int row, col;
        char choice;
        cout << "Press [R] to reveal field" << endl;
        cout << "Press [F] to toggle flag" << endl;
        cin >> choice;
        if (choice == 'R')
        {
            cout << "Enter row and column of field you want to reveal: " << endl;
            cin >> row;
            cin >> col;
            board.revealField(row, col);
        }
        if (choice == 'F')
        {
            cout << "Enter row and column to toggle flag: " << endl;
            cin >> row;
            cin >> col;
            board.toggleFlag(row, col);
        }
        if (board.getGameState() == FINISHED_LOSS)
        {
            cout << "BOOM! YOU LOST " << endl;
            view.display();
        }
        if (board.getGameState() == FINISHED_WIN)
        {
            cout << "YOU WIN!" << endl;
            view.display();
        }
    }
}
