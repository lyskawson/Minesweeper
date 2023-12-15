#include "MSSFMLController.h"
#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"

MSSFMLController::MSSFMLController(MinesweeperBoard & board, MSSFMLView & view)
        : board(board), view(view)
{

}

void MSSFMLController::Play (sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.key.code == sf::Mouse::Left) {
            int row = (event.mouseButton.y - 192) / 66;
            int col = (event.mouseButton.x) / 66;
            board.revealField(row, col);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.key.code == sf::Mouse::Right) {
            int row = (event.mouseButton.y-192) / 66;
            int col = (event.mouseButton.x) / 66;
            board.toggleFlag(row, col);
        }
    }
}
