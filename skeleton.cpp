#include "skeleton.h"
#include <cmath>






//ЗАДАЧА:
//Придумать как передать координаты и по ним вычислять начальную скорость.


//Bulet my_bulet("bullet.png", 95, 87, 500, GROUND$ - 100);



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
            acceleration_obj.y = 0.0005;
            velocity_obj.y = 0.1;
        }




void Skeleton::draw(sf::RenderWindow &window){

    if (this->current_direction == RIGHT)
        this->obj_sprite.setTextureRect(sf::IntRect(125, 0, -125, 200));
    
    if (this->current_direction == LEFT)
        this->obj_sprite.setTextureRect(sf::IntRect(0, 0, 125, 200));
        

    window.draw(this->obj_sprite);
}





void Skeleton::motion(){   

}

void Skeleton::update(float time, sf::RenderWindow &window, const sf::Vector2f& hero_pos, Map& map){
    this->pos_obj.x += this->velocity_obj.x * time;
    CheckWall(map, this->velocity_obj.x, 0);
    
    if (!this->ON_GROUND){
        this->velocity_obj.y = this->velocity_obj.y + acceleration_obj.y * time;
    }
    this->pos_obj.y += this->velocity_obj.y * time;
    this->ON_GROUND = false;
    CheckWall(map, 0, this->velocity_obj.y);
    current_direction = IsHeroNear(hero_pos);
    draw(window);
    fire(hero_pos);

    if(bullets.size() != 0){
        bullets.front().update(time, window, map);
    }

    this->obj_sprite.setPosition(this->pos_obj.x, this->pos_obj.y);
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
    Bulet* my_bulet = new Bulet("bullet.png", 95, 87, pos_obj.x, pos_obj.y);

    if (bullets.size() == 0 && IsHeroNear(hero_pos)){
        float y_0, x_0;
        x_0 = hero_pos.x - pos_obj.x;
        y_0 = hero_pos.y - pos_obj.y;

        
        
        
        my_bulet->current_direction = this->current_direction;
        if(x_0 < 0){
            my_bulet->velocity_obj.x = -0.4;
        } else{
            my_bulet->velocity_obj.x = 0.4;
        }
        my_bulet->velocity_obj.y = -0.3;
       
       
        //ТУТ ФИЗИКА
        /* if(x_0 == 0){
            my_bulet->velocity_obj.y = 0;
        } else{
            my_bulet->velocity_obj.y = -(((y_0 * my_bulet->velocity_obj.x)/x_0) + ((my_bulet->acceleration_obj.y * x_0)/my_bulet->velocity_obj.x));
            
        } */
        //my_bulet.velocity_obj.y = ((y_0 * my_bulet.velocity_obj.x)/x_0) + ((my_bulet.acceleration_obj.y * x_0)/my_bulet.velocity_obj.x);

       
        bullets.emplace_back(*my_bulet); //Пулю надо убрать в проверке касания со стенами?

        
    }

    if(bullets.size() != 0){
        
        if(!bullets.front().life){
            bullets.erase(bullets.begin());
            
        } 
    }
    

}

bool Skeleton::CheckWall(Map& map, float Dx, float Dy){
        float w = this->size_obj.x;
        float h = this->size_obj.y;

        float x = this->pos_obj.x;
        float y = this->pos_obj.y;




		for (int i = y / 70; i < (y + h) / 70; i++)//проходимся по элементам карты
		for (int j = x / 70; j < (x + w) / 70; j++)
		{
			if (map.TileMap[i][j] == '1' || map.TileMap[i][j] == '2' || map.TileMap[i][j] == '3' || map.TileMap[i][j] == '4' || map.TileMap[i][j] == '5')
			{
				if (Dy > 0){
                    this->pos_obj.y = i * 70 - h;  
                    velocity_obj.y = 0; 
                    ON_GROUND = true; 
                }
                if (Dy < 0)
                {
                    this->pos_obj.y = i * 70 + 70;
                    velocity_obj.y = 0;
                }

			    
				if (Dx > 0){
                    this->pos_obj.x = j * 70 - w;
                }//с правым краем карты
				if (Dx < 0){
                    this->pos_obj.x = j * 70 + 70;
                }// с левым краем карты
			} //else {ON_GROUND = false;}
		}
 

	return 0;
        
	
}