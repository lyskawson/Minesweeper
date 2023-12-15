#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "MSSFMLController.h"

int main()
{
    MinesweeperBoard board (10,10,EASY);
    sf::RenderWindow window(sf::VideoMode(board.getBoardWidth()*66, board.getBoardHeight()*66 + 192) , "MINESWEEPER");

    MSSFMLView view(board);
    MSSFMLController ctrl(board,view);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ctrl.Play(event);

        window.clear();
        view.draw(window);
        window.display();
    }
    return 0;
}




