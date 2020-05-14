#include "skeleton.h"
#include <cmath>






//ЗАДАЧА:
//Придумать как передать координаты и по ним вычислять начальную скорость.






Skeleton::Skeleton(const std::string name_file,
            const float obj_size_x,
            const float obj_size_y,
            int pos_x, int pos_y) :

        Object(name_file, obj_size_x, obj_size_y, pos_x, pos_y),
        currentFrame(0.0),
        previous_direction(RIGHT),
        ON_GROUND(true)
        {
            current_direction = RIGHT;
        }



void Skeleton::draw(sf::RenderWindow &window){

    if (this->current_direction == RIGHT)
        this->obj_sprite.setTextureRect(sf::IntRect(125, 0, -125, 210));
    
    if (this->current_direction == LEFT)
        this->obj_sprite.setTextureRect(sf::IntRect(0, 0, 125, 210));
        

    window.draw(this->obj_sprite);
}





void Skeleton::motion(){   

}

void Skeleton::update(float time, sf::RenderWindow &window, const sf::Vector2f& hero_pos){
    current_direction = IsHeroNear(hero_pos);
    draw(window);
    fire(hero_pos);

    if(bullets.size() != 0){
        bullets.front().update(time, window);
    }


    //this->pos_obj.x += this->velocity_obj.x * time;

    //currentFrame += 0.005 * time;

    /* if (currentFrame > 4)  //fix this + spritesheet @TODO 
        currentFrame -= 4;

    this->obj_sprite.setPosition(this->pos_obj.x, this->pos_obj.y); */

    //this->velocity_obj.x = 0;
}

int Skeleton::IsHeroNear(const sf::Vector2f& hero_pos){
    float dist = hero_pos.x - pos_obj.x;

    if (abs(dist) < 1000){
        if (dist > 0){
            return RIGHT;
        }
        else{
            return LEFT;
        }
    }

    return 0;
}



//ПРОВЕРИТЬ FIRE, А ТАК ЖЕ РАЗОБРАТЬСЯ С КОМЕНТАРИЕМ ПУЛИ
void Skeleton::fire(const sf::Vector2f& hero_pos){
    
    if (bullets.size() == 0 && IsHeroNear(hero_pos)){
        float y_0, x_0;
        x_0 = hero_pos.x - pos_obj.x;
        y_0 = pos_obj.y - hero_pos.y;

        Bulet my_bulet("bullet.png", 95, 87, 0, GROUND$ - 1);

        my_bulet.current_direction = this->current_direction;
        if(x_0 < 0){
            my_bulet.velocity_obj.x = -0.2;
        } else{
            my_bulet.velocity_obj.x = 0.2;
        }
        my_bulet.velocity_obj.y = -0.3;
        //ТУТ ФИЗИКА
        //my_bulet.velocity_obj.y = - (((x_0 * my_bulet.acceleration_obj.y)/my_bulet.velocity_obj.x) - (my_bulet.velocity_obj.x * y_0)/x_0);

       
        bullets.push_back(my_bulet); //Пулю надо убрать в проверке касания со стенами?

        
    }

    if(bullets.size() != 0){
        
        if(!bullets.front().life){
            bullets.erase(bullets.begin());
            
        } 
    }
    

}

bool Skeleton::CheckWall(){
    
}