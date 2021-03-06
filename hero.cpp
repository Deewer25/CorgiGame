#include "hero.h"
#include "view.h"

Hero::Hero(const std::string name_file,
           const float obj_size_x,
           const float obj_size_y,
           int pos_x, int pos_y) :
    Object(name_file, obj_size_x, obj_size_y, pos_x, pos_y),
    currentFrame(0.0),
    previous_direction(RIGHT),
    ON_GROUND(true),
    COOLDOWN_INVINCIBLE(sf::seconds(3.0)),
    COOLDOWN_GOTHIT(sf::seconds(2.0)),
    hit_points(3),
    FIRST_GOTHIT(false),
    hearts_sprite(sf::Sprite()),
    texture_hearts(sf::Texture())
{
    acceleration_obj.y = 0.0005;
    texture_hearts.loadFromFile("tilemap1.png");
    hearts_sprite.setTexture(texture_hearts);
    hearts_sprite.setTextureRect(sf::IntRect(490, 490, 70, 70));
    hearts_sprite.setPosition(640-70, 0);
    view.reset(sf::FloatRect(0, 0, 1920, 1080));
}

void Hero::motion()
{   
    if(this->hit_points <= 0)
    {
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->velocity_obj.x = -0.4;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->velocity_obj.x = 0.4;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (this->ON_GROUND)
        {
            this->velocity_obj.y = -0.55;
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
            this->velocity_obj.x = 2.0;
        }
        else
        {
            this->current_direction = INVINCIBLE_LEFT;
            this->velocity_obj.x = -2.0;
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
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (1460 * int(currentFrame)), SIZE_PICT$ * 2053, -SIZE_PICT$ * 1460, SIZE_PICT$ * 849));
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
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (1460 * int(currentFrame)), SIZE_PICT$ * 2053, SIZE_PICT$ * 1460, SIZE_PICT$ * 849));
        break;
    case GAME_OVER:
        this->obj_sprite.setTextureRect(sf::IntRect(SIZE_PICT$ * (615 * int(currentFrame) + 615), SIZE_PICT$ * 3878, SIZE_PICT$ * 615, SIZE_PICT$ * 530));
        break;
    default:
        break;
    }
    ChangeView(this->pos_obj.x, this->pos_obj.y);
    window.setView(view);

    switch(this->hit_points)
    {
    case 0:
        break;
    case 1:
        hearts_sprite.setPosition(view.getCenter().x - 950 , view.getCenter().y - 530);
        window.draw(hearts_sprite);
        break;
    case 2:
        hearts_sprite.setPosition(view.getCenter().x - 950, view.getCenter().y - 530);
        window.draw(hearts_sprite);
        hearts_sprite.setPosition(view.getCenter().x - 950 + 70, view.getCenter().y - 530);
        window.draw(hearts_sprite);
        break;
    case 3:
        hearts_sprite.setPosition(view.getCenter().x - 950, view.getCenter().y - 530);
        window.draw(hearts_sprite);
        hearts_sprite.setPosition(view.getCenter().x - 950 + 70, view.getCenter().y - 530);
        window.draw(hearts_sprite);
        hearts_sprite.setPosition(view.getCenter().x - 950 + 70 + 70, view.getCenter().y - 530);
        window.draw(hearts_sprite);
        break;
    }
    window.draw(this->obj_sprite);
}

void Hero::update(float time, Map& map)
{
    if (this->hit_points < 0)
    {
        currentFrame += 0.002 * time;

        if (currentFrame > 8) //TODO: fix this + spritesheet
            currentFrame -= 8;

        this->current_direction = GAME_OVER;
        return;
    }

    this->pos_obj.x += this->velocity_obj.x * time;
    CheckMap(map, velocity_obj.x, 0);

    if (!this->ON_GROUND)
        this->velocity_obj.y = this->velocity_obj.y + acceleration_obj.y * time;

    this->pos_obj.y += this->velocity_obj.y * time;
    this->ON_GROUND = false;

    CheckMap(map, 0, velocity_obj.y);

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
    if (this->hit_points < this->hit_points_previous || 
        ((this->previous_direction_2 == GOT_HIT_RIGHT) || 
        (this->previous_direction_2 == GOT_HIT_LEFT)))
    {
        if (this->hit_points < this->hit_points_previous)
        {
            //printf("ELAPSED: %lld, COOLD: %lld\n", this->clock.getElapsedTime().asMicroseconds(), this->COOLDOWN_GOTHIT.asMicroseconds());
            if ((this->clock.getElapsedTime().asMicroseconds() < this->COOLDOWN_GOTHIT.asMicroseconds()))
            {
                this->hit_points = this->hit_points_previous;
                //printf("FALSE\n");
            }
            else
            {
                //printf("RESET\n");
                this->clock.restart();
                //this->FIRST_GOTHIT = true;
            }
        }
        //printf("CUR HIT %d PREV HIT %d\n", hit_points,  hit_points_previous);

        if ((this->clock.getElapsedTime().asMicroseconds() < this->COOLDOWN_GOTHIT.asMicroseconds()))
        {
            if (this->current_direction < 8)
            {
                this->current_direction = GOT_HIT_LEFT;
            }
            else
            {
                this->current_direction = GOT_HIT_RIGHT;
            }
        }
    }
    this->hit_points_previous = this->hit_points;

    // ДОБАВИТЬ ПРОВЕРКУ ХП + ИЗМЕНИТЬ СПРАЙТ ЛЯ ЭТГО

    this->velocity_obj.x = 0;
}

void Hero::CheckMap(Map &map, float Dx, float Dy) //ф-ция взаимодействия с картой
{
    float w = this->size_obj.x;
    float h = this->size_obj.y;

    float x = this->pos_obj.x;
    float y = this->pos_obj.y;

    for (int i = y / 70; i < (y + h) / 70; i++) //проходимся по элементам карты
    {
        for (int j = x / 70; j < (x + w) / 70; j++)
        {
            if (map.TileMap[i][j] == '1' || map.TileMap[i][j] == '2' || map.TileMap[i][j] == '3' || map.TileMap[i][j] == '4' || map.TileMap[i][j] == '5' || map.TileMap[i][j] == '$' || map.TileMap[i][j] =='*' || map.TileMap[i][j] == 'r' || map.TileMap[i][j] == 'i')
            {
                if (Dy > 0)
                {
                    this->pos_obj.y = i * 70 - h;
                    velocity_obj.y = 0;
                    ON_GROUND = true;
                }
                if (Dy < 0)
                {
                    this->pos_obj.y = i * 70 + 70;
                    velocity_obj.y = 0;
                }
                if (Dx > 0)
                {
                    this->pos_obj.x = j * 70 - w;
                } //с правым краем карты
                if (Dx < 0)
                {
                    this->pos_obj.x = j * 70 + 70;
                } // с левым краем карты
            } //else {ON_GROUND = false;}
	    
	    //собираем монеты
	    if (map.TileMap[i][j] == 'G')
	    {
            gold++;
		    map.TileMap[i][j] = ' ';
	    }
        //ПОБЕЕЕЕЕЕЕЕЕЕДА
        if ((map.TileMap[i][j] == 'D' || map.TileMap[i][j] == 'd') && keys == 3)
	    {
            hit_points = 0;
            //ГЕЙМ ОВЕР
	    }
        

        if (map.TileMap[i][j] == 'k')
	    {
            keys++;
		    map.TileMap[i][j] = ' ';
	    }

	    //дополнительные хп
	    if (map.TileMap[i][j] == 'H')
	    {
		    if(this->hit_points < 3)
		    {
			    this->hit_points++;
		    	map.TileMap[i][j] = ' ';
		    }
	    }
	    
	    //бонусные ячейки
	    if (map.TileMap[i][j] == '$')
	    {
		    map.TileMap[i][j] = 'M';
	    }
	    if (map.TileMap[i][j] == '*')
	    {
		    map.TileMap[i][j] = '!';
	    }
            //попадает на осколки
            if (map.TileMap[i][j] == '~')
            {
                this->hit_points--;
        		this->velocity_obj.y = -0.35; 
            }
	    
	    //попадает в лаву
	    if (map.TileMap[i][j] == 'l')
            {
                this->hit_points--;
            }

        }
    }
}

sf::Vector2f Hero::get_pos_camera()
{
    return view.getCenter();
}
