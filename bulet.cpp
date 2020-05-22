#include "bulet.h"


 
Bulet::Bulet(const std::string name_file,
            const float obj_size_x,
            const float obj_size_y,
            int pos_x, int pos_y) :

        Object(name_file, obj_size_x, obj_size_y, pos_x, pos_y),
        currentFrame(0.0),
        previous_direction(RIGHT),
        ON_GROUND(true)
        {
                                    
            life = true;
            current_direction = RIGHT;
            acceleration_obj = {0, 0.0005};
            //velocity_obj = {0.3, -0.3};
            //velocity_obj.x = 0;
            //velocity_obj.y = 0;
        }

/* Bulet::Bulet(const Bulet& that)
{
    pos_obj = that.pos_obj;
    velocity_obj = that.velocity_obj;
    obj_sprite = that.obj_sprite;
} */


void Bulet::draw(sf::RenderWindow &window)
{
    if(life){
        if(current_direction == LEFT){
            
            this->obj_sprite.setTextureRect(sf::IntRect(0, 0, 95, 87));
        }
        if(current_direction == RIGHT){
            this->obj_sprite.setTextureRect(sf::IntRect(95, 0, -95, 87));
        }
        window.draw(this->obj_sprite);
    }
    
}


void Bulet::motion()
{   
    

}


void Bulet::update(float time, sf::RenderWindow &window, Hero& hero, Map& map){
    this->pos_obj.x += this->velocity_obj.x * time;

    if (!this->ON_GROUND)
        this->velocity_obj.y = this->velocity_obj.y + acceleration_obj.y * time;

    if(velocity_obj.y != 0){
        this->pos_obj.y += this->velocity_obj.y * time;
        this->ON_GROUND = false;
    }
    

    /* if (this->pos_obj.y > GROUND$)
    {
        this->pos_obj.y = GROUND$;
        this->velocity_obj.y = 0;
        this->ON_GROUND = true;
    } */
    CheckWall(map);
    CheckHero(hero);
    currentFrame += 0.005 * time;

    if (currentFrame > 4)  //fix this + spritesheet @TODO 
        currentFrame -= 4;

    this->obj_sprite.setPosition(this->pos_obj.x, this->pos_obj.y);

    draw(window);
    

    //this->velocity_obj.x = 0;
}


bool Bulet::CheckWall(Map& map){
        float w = this->size_obj.x;
        float h = this->size_obj.y;

        float x = this->pos_obj.x;
        float y = this->pos_obj.y;




		for (int i = y / 70; i < (y + h) / 70; i++){//проходимся по элементам карты
            if(i < 0){
                life = false;
                break;
            }
		    for (int j = x / 70; j < (x + w) / 70; j++)
		    {
			    if (map.TileMap[i][j] != ' '|| map.TileMap[i][j] == 'G')
			    {
                    life = false;
                }

            }
        }
///asasd


    /* if (pos_obj.y > GROUND$){
        velocity_obj = {0, 0};
        pos_obj.y = GROUND$;
        this->ON_GROUND = true;
        life = false;   
        life = false;   
        return 1;
    } */
    return 0;
}





void Bulet::CheckHero(Hero& hero){
    if(this->getRect().intersects(hero.getRect())){
        this->life = false;
        hero.hit_points--;
        hero.velocity_obj.y = -0.35; //подумать чтобы отбрасывало в сторону а не только вверх;
    }
}
