#ifndef GAME_H
#define GAME_H


#include "hero.h"
//#include "view.h"
#include "slime.h"
#include "skeleton.h"
#include "menu.h"

class Game
{
private:

//std::vector<sf::Vector2f> slimes_pos = {{2660, 2030}, {2100, 420}};
//std::vector<sf::Vector2f> skel_pos = {{900, GROUND$}};
struct xy{
    int x;
    int y;
};

void InitEnemy();
void KillEnemy();

    


public:
    sf::RenderWindow window;
    sf::Texture Background;
    sf::Sprite sprite_background;
    sf::Event event_game;
    sf::Clock clock_game;
    float time_game;

    Game();
    void background_motion(sf::Vector2f pos_camera);
    void run();
    void pause();

    std::vector<struct xy> skel_pos;
    std::vector<struct xy> slimes_pos;
    

    std::list<Slime*> Slimes;
    std::vector<Skeleton*> Skeletons;


    Game(const Game &) = delete;
};

#endif
