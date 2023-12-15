#ifndef MINESWEEPER_MSSFMLVIEW_H
#define MINESWEEPER_MSSFMLVIEW_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MinesweeperBoard.h"

class MSSFMLView
{
    MinesweeperBoard & board;
    sf::Font font;
    sf::Text mines_text;
    sf::Texture t1,t2,t3,t4,t5,t6,t7,t8,tFlag,tMine,tBlank, tUnrevealed,tloseFace, twinFace, trunningFace,tFrame;
    sf::Sprite s1,s2,s3,s4,s5,s6,s7,s8,sFlag,sMine,sBlank, sUnrevealed, sloseFace, swinFace, srunningFace, sFrame;

public:

    MSSFMLView(MinesweeperBoard & board);
    void draw(sf::RenderWindow & window );

};

#endif //MINESWEEPER_MSSFMLVIEW_H
