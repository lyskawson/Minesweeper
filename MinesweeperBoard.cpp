#include "MinesweeperBoard.h"
#include "Array2D.h"
#include <iomanip>
#include <time.h>
#include <cmath>



MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode)
{
    width = w;
    height = h;
    board.resize(height, width);

    if(mode==DEBUG)
        set_to_DEBUG();
    if(mode==EASY)
        set_difficulty(0.1);
    if(mode==NORMAL)
        set_difficulty(0.2);
    if(mode==HARD)
        set_difficulty(0.3);
}

void MinesweeperBoard::set_to_DEBUG()
{
    set_to_zero();
    for(int i=0; i<width;i++)
        board[0][i].hasMine = true;
    for(int a=0; a< height;a=a+2)
    {
        for(int b=0; b<width;b++)
            board[a][0].hasMine=true;
    }
    for(int x=0;x<height;x++)
        for(int y=0;y<width;y++)
        {
            if(x==y)
                board[x][y].hasMine = true;
        }
}

void MinesweeperBoard::set_difficulty(float num)
{
    set_to_zero();
    int a,b;
    srand(time(NULL));
    int area = ceil((width*height)*num);
    while(area > 0)
    {
        a = rand()%height;
        b = rand()%width;
        if(not board[a][b].hasMine)
        {
            board[a][b].hasMine = true;
            area --;
        }
    }
}
void MinesweeperBoard::debug_display() const
{
    using namespace std;
    {
        cout << " ";
        for(int k = 0; k<width;k++)
            cout << "  " << setw(2) << k << " ";
        cout << endl;

        for (int i=0;i<height;i++)
        {
            cout << setw(2) <<i;
            for (int j=0;j<width;j++)
            {
                cout << "[";
                if (board[i][j].hasMine) cout << "M";
                else cout << ".";
                if (board[i][j].isRevealed) cout << "o";
                else cout << ".";
                if (board[i][j].hasFlag) cout << "f";
                else cout << ".";
                cout << "]";
            }
            cout << endl;
        }
    }

}

void MinesweeperBoard::set_to_zero() {
    for(int i = 0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            board[i][j] = {false,false,false};
        }
    }
}


int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
    int mineCount = 0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(board[i][j].hasMine)
                mineCount++;
        }
    }
    return mineCount;
}

bool MinesweeperBoard::isValid(int row, int col) const
{
    return row>=0 && row<height && col>=0 && col < width;

}

int MinesweeperBoard::countMines(int row, int col) const
{
    int count = 0;
    for (int r = row - 1; r <= row + 1; r++)
    {
        for (int c = col - 1; c <= col + 1; c++)
        {
            if (isValid(r, c) && board[r][c].hasMine)
                count++;
        }
    }
    if(board[row][col].hasMine)
        count --;

    return count;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(board[row][col].isRevealed)
        return false;
    else if(not board[row][col].hasFlag)
            return false;
    return true;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if(!board[row][col].isRevealed && getGameState() == RUNNING )
    {
        board[row][col].hasFlag = 1 - board[row][col].hasFlag;

    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    return board[row][col].isRevealed;
}

GameState MinesweeperBoard::getGameState() const
{
    int revealed_count = 0;
    int area = width * height;
    for(int i = 0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(board[i][j].isRevealed && !board[i][j].hasMine)
                revealed_count++;
            if (board[i][j].hasMine && board[i][j].isRevealed)
                return FINISHED_LOSS;
        }
    }
    if(getMineCount() == (area - revealed_count))
        return FINISHED_WIN;

    return RUNNING;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    using namespace std;
    if(!isValid(row, col))
        return '#';
    if(!board[row][col].isRevealed && board[row][col].hasFlag)
        return 'F';
    if(!board[row][col].isRevealed && !board[row][col].hasFlag)
        return '_';
    if(board[row][col].isRevealed && board[row][col].hasMine)
        return 'X';
    if(board[row][col].isRevealed && countMines(row, col) == 0)
        return ' ';
    if(board[row][col].isRevealed && countMines(row, col)>0 && !board[row][col].hasMine)
        return (countMines(row, col)+48);
    else
        return '?';

}

bool MinesweeperBoard::isFirstMove() const
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(isRevealed(i, j))
                return false;
        }

    }
    return true;
}

void MinesweeperBoard::revealField(int row, int col)
{
    if(board[row][col].isRevealed || board[row][col].hasFlag || (getGameState() == FINISHED_LOSS || getGameState() == FINISHED_WIN))
        return;
    if(!board[row][col].hasMine)
    {
        board[row][col].isRevealed = true;
        //tu zeby usuwalo pola dookola
        if(countMines(row, col)==0)
            revealFieldsAround(row, col);
    }
    else if(board[row][col].hasMine)
    {
        if(isFirstMove())
        {
            srand(time(NULL));
            int a = rand()%height;
            int b = rand()%width;
            int c = 1;
            while(c>0)
            {
                if(!board[a][b].hasMine)
                {
                    board[a][b].hasMine = true;
                    c --;
                }
            }
            board[row][col].hasMine = false;
            board[row][col].isRevealed = true;
        }
        else
            board[row][col].isRevealed = true;
    }
}

void MinesweeperBoard::revealFieldsAround(int row,int col)
{
    for (int r = row - 1; r <= row + 1; r++)
        {
            for (int c = col - 1; c <= col + 1; c++)
            {
                if (isValid(r, c) )
                    revealField(r, c);
            }
        }
}

int MinesweeperBoard::getFlagCount() const {
    {
        int flagCount = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j].hasFlag)
                    flagCount++;
            }
        }
        return flagCount;
    }
}




