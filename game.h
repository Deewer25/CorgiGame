#ifndef GAME_H
#define GAME_H


#include "hero.h"
#include "slime.h"
#include "skeleton.h"


class Game
{
public:
    sf::RenderWindow window;
    sf::Texture Background;
    sf::Sprite sprite_background;
    sf::Event event_game;
    sf::Clock clock_game;
    float time_game;

    Game();

    void run();

    Game(const Game &) = delete;
};

#endif