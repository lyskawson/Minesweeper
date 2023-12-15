#include "MSSFMLView.h"
#include <iostream>

MSSFMLView::MSSFMLView(MinesweeperBoard & board) : board(board)
{
    //zaladowanie tekstur z pliku
    t1.loadFromFile("../MS_textures.png", sf::IntRect (16,0,16,16));
    t2.loadFromFile("../MS_textures.png", sf::IntRect (32,0,16,16));
    t3.loadFromFile("../MS_textures.png", sf::IntRect (48,0,16,16));
    t4.loadFromFile("../MS_textures.png", sf::IntRect (0, 16,16,16));
    t5.loadFromFile("../MS_textures.png", sf::IntRect (16,16,16,16));
    t6.loadFromFile("../MS_textures.png", sf::IntRect (32,16,16,16));
    t7.loadFromFile("../MS_textures.png", sf::IntRect (48,16,16,16));
    t8.loadFromFile("../MS_textures.png", sf::IntRect (0,32,16,16));
    tFlag.loadFromFile("../MS_textures.png", sf::IntRect (32,32,16,16));
    tMine.loadFromFile("../MS_textures.png", sf::IntRect (16,48,16,16));
    tBlank.loadFromFile("../MS_textures.png", sf::IntRect (0,0,16,16));
    tUnrevealed.loadFromFile("../MS_textures.png", sf::IntRect (16,32,16,16));
    font.loadFromFile("../Pixels.ttf");
    twinFace.loadFromFile("../winFace.png");
    tloseFace.loadFromFile("../loseFace.png");
    trunningFace.loadFromFile("../runningFace.png");
    tFrame.loadFromFile("../Frame.png");

    //ustawienie tekstur na duszki
    s1.setTexture(t1);
    s2.setTexture(t2);
    s3.setTexture(t3);
    s4.setTexture(t4);
    s5.setTexture(t5);
    s6.setTexture(t6);
    s7.setTexture(t7);
    s8.setTexture(t8);
    sMine.setTexture(tMine);
    sFlag.setTexture(tFlag);
    sBlank.setTexture(tBlank);
    sUnrevealed.setTexture(tUnrevealed);
    sFrame.setTexture(tFrame);
    swinFace.setTexture(twinFace);
    sloseFace.setTexture(tloseFace);
    srunningFace.setTexture(trunningFace);

    //skalowanie duszkow
    s1.setScale(sf::Vector2f(4,4));
    s2.setScale(sf::Vector2f(4,4));
    s3.setScale(sf::Vector2f(4,4));
    s4.setScale(sf::Vector2f(4,4));
    s5.setScale(sf::Vector2f(4,4));
    s6.setScale(sf::Vector2f(4,4));
    s7.setScale(sf::Vector2f(4,4));
    s8.setScale(sf::Vector2f(4,4));
    sMine.setScale(sf::Vector2f(4,4));
    sFlag.setScale(sf::Vector2f(4,4));
    sBlank.setScale(sf::Vector2f(4,4));
    sUnrevealed.setScale(sf::Vector2f(4,4));
    sFrame.setScale(sf::Vector2f(((board.getBoardWidth()*66)/1480.0),0.41921));
    swinFace.setScale(sf::Vector2f(0.45,0.45));
    sloseFace.setScale(sf::Vector2f(0.45, 0.45));
    srunningFace.setScale(sf::Vector2f(0.45, 0.45));

    //dodawanie tekstu
    mines_text.setFont(font);
    mines_text.setColor(sf::Color::Black);
    mines_text.setCharacterSize(65);
}

void MSSFMLView::draw (sf::RenderWindow & window)
{
    window.draw(sFrame);
    srunningFace.setPosition(board.getBoardWidth()*66*0.7,46);
    sloseFace.setPosition(board.getBoardWidth()*66-170,46);
    swinFace.setPosition(board.getBoardWidth()*66-170,46);
    mines_text.setPosition(board.getBoardWidth()*6.6,60);
    mines_text.setString("MINES: " + std::to_string(board.getMineCount() - board.getFlagCount()));
    window.draw(mines_text);

    for (int i=0; i<board.getBoardHeight(); ++i)
    {
        for (int j=0; j<board.getBoardWidth(); ++j)
        {
            s1.setPosition(66*j,66*i + 192 );
            s2.setPosition(66*j,66*i + 192);
            s3.setPosition(66*j,66*i + 192);
            s4.setPosition(66*j,66*i + 192);
            s5.setPosition(66*j,66*i + 192);
            s6.setPosition(66*j,66*i + 192);
            s7.setPosition(66*j,66*i + 192);
            s8.setPosition(66*j,66*i + 192);
            sFlag.setPosition(66*j,66*i + 192);
            sMine.setPosition(66*j,66*i + 192);
            sUnrevealed.setPosition(66*j,66*i + 192);
            sBlank.setPosition(66*j,66*i + 192);

            switch (board.getFieldInfo(i,j))
            {
                case '_':
                    window.draw(sUnrevealed);
                    break;
                case ' ':
                    window.draw(sBlank);
                    break;
                case 'F':
                    window.draw(sFlag);
                    break;
                case 'X':
                    window.draw(sMine);
                    break;
                case '1':
                    window.draw(s1);
                    break;
                case '2':
                    window.draw(s2);
                    break;
                case '3':
                    window.draw(s3);
                    break;
                case '4':
                    window.draw(s4);
                    break;
                case '5':
                    window.draw(s5);
                    break;
                case '6':
                    window.draw(s6);
                    break;
                case '7':
                    window.draw(s7);
                    break;
                case '8':
                    window.draw(s8);
                    break;
            }
            if (board.getGameState() == RUNNING)
                window.draw(srunningFace);
            if (board.getGameState() == FINISHED_WIN)
                window.draw(swinFace);
            if (board.getGameState() == FINISHED_LOSS)
                window.draw(sloseFace);
        }
    }

}
