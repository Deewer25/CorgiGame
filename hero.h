#ifndef HERO_H
#define HERO_H

#include "objects.h"


class Hero : public Object
{
public:
    enum Direction
    {
        LEFT = 1,
        JUMP_UP_LEFT,
        JUMP_DOWN_LEFT,
        GOT_HIT_LEFT,
        DIZZY_LEFT,
        INVINCIBLE_LEFT,
        STAY_LEFT,
        RIGHT,
        JUMP_UP_RIGHT,
        JUMP_DOWN_RIGHT,
        GOT_HIT_RIGHT,
        DIZZY_RIGHT,
        INVINCIBLE_RIGHT,
        STAY_RIGHT,
        GAME_OVER
    };

    short int previous_direction;
    short int previous_direction_2;
    short int current_direction;
    int NUMBER_SLIDE;
    double currentFrame;

    bool ON_GROUND;
    bool ON_INVINCIBLE;

    const sf::Time COOLDOWN_INVINCIBLE;
    sf::Time recent_click;
    sf::Time first_click;
    sf::Time current_summary_time;
    const sf::Time permissible_summary_time;
    sf::Clock clock;

    virtual void draw(sf::RenderWindow &window);

    void motion();

    Hero(const std::string name_file,
         const float obj_size_x,
         const float obj_size_y,
         int pos_x, int pos_y);

    void CheckMap(Map &map, float Dx, float Dy); //ф-ция взаимодействия с картой

    Hero(const Hero&) = delete;

    void update(float time, Map& map);
};


#endif
