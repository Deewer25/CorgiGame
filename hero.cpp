#include "hero.h"

Hero::Hero(const std::string name_file,
           const float obj_size_x,
           const float obj_size_y,
           int pos_x, int pos_y) :

                                   Object(name_file, obj_size_x, obj_size_y, pos_x, pos_y),
                                   currentFrame(0.0),
                                   previous_direction(RIGHT),
                                   ON_GROUND(true),
                                   COOLDOWN_INVINCIBLE(sf::seconds(3.0))
{}

void Hero::motion()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->velocity_obj.x = -0.1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->velocity_obj.x = 0.1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (this->ON_GROUND)
        {
            this->velocity_obj.y = -0.35;
            this->ON_GROUND = false;
            //hero.current_direction = Hero::JUMP_UP;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        this->ON_INVINCIBLE = true;
        if (this->previous_direction_2 > 7)
        {
            this->current_direction = INVINCIBLE_RIGHT;
            this->velocity_obj.x = 1.0;
        }
        else
        {
            this->current_direction = INVINCIBLE_LEFT;
            this->velocity_obj.x = -1.0;
        }
    }
}

void Hero::draw(sf::RenderWindow &window)
{
    switch (this->current_direction)
    {
    case JUMP_DOWN_LEFT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (551 * int(currentFrame) + 551), SIZE_PICT$ * (509 + 530), -SIZE_PICT$ * 551, SIZE_PICT$ * 502));
        break;
    case LEFT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (551 * int(currentFrame) + 551), 0, -SIZE_PICT$ * 551, SIZE_PICT$ * 509));
        break;
    case JUMP_UP_LEFT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (551 * int(currentFrame) + 551), SIZE_PICT$ * 509, -SIZE_PICT$ * 551, SIZE_PICT$ * 530));
        break;
    case STAY_LEFT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (551 * int(currentFrame) + 551), SIZE_PICT$ * (509 + 530 + 502), -SIZE_PICT$ * 551, SIZE_PICT$ * 509));
        break;
    case GOT_HIT_LEFT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (615 * int(currentFrame) + 615), SIZE_PICT$ * 3397, -SIZE_PICT$ * 615, SIZE_PICT$ * 481));
        break;
    case DIZZY_LEFT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (551 * int(currentFrame) + 551), SIZE_PICT$ * 2902, -SIZE_PICT$ * 551, SIZE_PICT$ * 492));
        break;
    case INVINCIBLE_LEFT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (1460 * int(currentFrame) + 1460), SIZE_PICT$ * 2053, -SIZE_PICT$ * 1460, SIZE_PICT$ * 2053));
        break;
    case JUMP_DOWN_RIGHT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * 551 * int(currentFrame), SIZE_PICT$ *(509 + 530), SIZE_PICT$ * 551, SIZE_PICT$ * 502));
        break;
    case RIGHT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * 551 * int(currentFrame), 0, SIZE_PICT$ * 551, SIZE_PICT$ * 509));
        break;
    case JUMP_UP_RIGHT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (551 * int(currentFrame)), SIZE_PICT$ * 509, SIZE_PICT$ * 551, SIZE_PICT$ * 530));
        break;
    case STAY_RIGHT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * 551 * int(currentFrame), SIZE_PICT$ *(509 + 530 + 502), SIZE_PICT$ * 551, SIZE_PICT$ * 509));
        break;
    case GOT_HIT_RIGHT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (615 * int(currentFrame) + 615), SIZE_PICT$ * 3397, SIZE_PICT$ * 615, SIZE_PICT$ * 481));
        break;
    case DIZZY_RIGHT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (551 * int(currentFrame) + 551), SIZE_PICT$ * 2902, SIZE_PICT$ * 551, SIZE_PICT$ * 492));
        break;
    case INVINCIBLE_RIGHT:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (1460 * int(currentFrame)), SIZE_PICT$ * 2053, SIZE_PICT$ * 1460, SIZE_PICT$ * 2053));
        break;
    case GAME_OVER:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (551 * int(currentFrame) + 551), 0, -SIZE_PICT$ * 551, SIZE_PICT$ * 509));
        break;
    default:
        break;
    }
    window.draw(this->obj_sprite);
}

void Hero::update(float time)
{

    this->pos_obj.x += this->velocity_obj.x * time;

    if (!this->ON_GROUND)
        this->velocity_obj.y = this->velocity_obj.y + 0.0005 * time;

    this->pos_obj.y += this->velocity_obj.y * time;
    this->ON_GROUND = false;

    if (this->pos_obj.y > GROUND$)
    {
        this->pos_obj.y = GROUND$;
        this->velocity_obj.y = 0;
        this->ON_GROUND = true;
    }

    currentFrame += 0.005 * time;

    if (currentFrame > 8) //TODO: fix this + spritesheet
        currentFrame -= 8;

    this->obj_sprite.setPosition(this->pos_obj.x, this->pos_obj.y);

    this->previous_direction_2 = this->current_direction;

    if (this->current_direction == LEFT || this->current_direction == RIGHT)
    {
        this->previous_direction = this->current_direction;
    }

    if (this->ON_INVINCIBLE)
    {
        this->velocity_obj.x = 0;
        this->ON_INVINCIBLE = false;
        if (this->current_direction == INVINCIBLE_RIGHT)
            this->obj_sprite.setPosition(this->pos_obj.x - 363, this->pos_obj.y);
        return;
    }

    if (this->velocity_obj.x > 0 && this->velocity_obj.y > 0)
    {
        this->current_direction = JUMP_UP_RIGHT;
    }
    else if (this->velocity_obj.x > 0 && this->velocity_obj.y < 0)
    {
        this->current_direction = JUMP_DOWN_RIGHT;
    }
    else if (this->velocity_obj.x < 0 && this->velocity_obj.y > 0)
    {
        this->current_direction = JUMP_UP_LEFT;
    }
    else if (this->velocity_obj.x < 0 && this->velocity_obj.y < 0)
    {
        this->current_direction = JUMP_DOWN_LEFT;
    }
    else if (this->velocity_obj.x > 0 && this->velocity_obj.y == 0)
    {
        this->current_direction = RIGHT;
    }
    else if (this->velocity_obj.x < 0 && this->velocity_obj.y == 0)
    {
        this->current_direction = LEFT;
    }
    else if (this->velocity_obj.x == 0 && this->velocity_obj.y < 0)
    {
        if (this->previous_direction_2 < 8)
        {
            this->current_direction = JUMP_DOWN_LEFT;
        }
        else
        {
            this->current_direction = JUMP_DOWN_RIGHT;
        }
    }
    else if (this->velocity_obj.x == 0 && this->velocity_obj.y > 0)
    {
        if (this->previous_direction_2 < 8)
        {
            this->current_direction = JUMP_UP_LEFT;
        }
        else
        {
            this->current_direction = JUMP_UP_RIGHT;
        }
    }
    else
    {
        if (this->previous_direction_2 < 8)
        {
            this->current_direction = STAY_LEFT;
        }
        else
        {
            this->current_direction = STAY_RIGHT;
        }
    }

    this->velocity_obj.x = 0;
}