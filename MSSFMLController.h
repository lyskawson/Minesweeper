#ifndef MINESWEEPER_MSSFMLCONTROLLER_H
#define MINESWEEPER_MSSFMLCONTROLLER_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"

class MSSFMLController
{
    MinesweeperBoard &board;
    MSSFMLView &view;

public:
    MSSFMLController(MinesweeperBoard &, MSSFMLView &);
    void Play(sf::Event &);

};


#endif //MINESWEEPER_MSSFMLCONTROLLER_H
