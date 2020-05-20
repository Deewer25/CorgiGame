#ifndef BULET_H
#define BULET_H
#include "objects.h"
#include <SFML/Graphics.hpp>
#include "hero.h";

//Для правильности работы этого объекта противник, который его использует должен задать начальные скорости и направление.
class Bulet : public Object
{

private:



public:
    bool life;


    enum Direction
    {
        UP = 1,
        DOWN,
        LEFT,
        RIGHT,
        STAY,
    };

    short int previous_direction;
    short int previous_direction_2;
    short int current_direction;
    int NUMBER_SLIDE;
    double currentFrame;
    bool ON_GROUND;

    virtual void draw(sf::RenderWindow &window);

    bool CheckWall(Map& map);

    void motion();

    void CheckHero(Hero& hero);

    Bulet(const std::string name_file,
         const float obj_size_x,
         const float obj_size_y,
         int pos_x, int pos_y);

    //Bulet(const Bulet& that);

    void update(float time, sf::RenderWindow &window, Map& map);
};

#endif