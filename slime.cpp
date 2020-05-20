#include "slime.h"


Slime::Slime(const std::string name_file,
            const float obj_size_x,
            const float obj_size_y,
            int pos_x, int pos_y) :

        Object(name_file, obj_size_x, obj_size_y, pos_x, pos_y),
        currentFrame(0.0),
        previous_direction(RIGHT),
        ON_GROUND(true)
        {
            current_direction = RIGHT;
            velocity_obj.x = 0.1;
        }



void Slime::draw(sf::RenderWindow &window)
{
    if (this->current_direction == RIGHT)
        this->obj_sprite.setTextureRect(sf::IntRect(0, 0, 125, 210));
    if (this->current_direction == LEFT)
        this->obj_sprite.setTextureRect(sf::IntRect(125, 0, -125, 210));
    window.draw(this->obj_sprite);
}


void Slime::motion(int a)
{   //int a;
    //int a = CheckWallX();
    switch (a)
    {
    case LEFT:
        current_direction = LEFT;
        velocity_obj.x = -0.1;
        break;

    case RIGHT:
        current_direction = RIGHT;
        velocity_obj.x = 0.1;
        break;
    
    }

}

void Slime::update(float time, Map& map){
    this->pos_obj.x += this->velocity_obj.x * time;
    int a = CheckWall(map, 0, this->velocity_obj.y);
    motion(a);
    currentFrame += 0.005 * time;

    if (currentFrame > 4)  //fix this + spritesheet @TODO 
        currentFrame -= 4;

    this->obj_sprite.setPosition(this->pos_obj.x, this->pos_obj.y);

    //this->velocity_obj.x = 0;
}


int Slime::CheckWall(Map& map, float Dx, float Dy){
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
			    
				if (Dx > 0){
                    this->pos_obj.x = j * 70 - w;
                    return LEFT;
                }//с правым краем карты
				if (Dx < 0){
                    this->pos_obj.x = j * 70 + 70;
                    return RIGHT;
                }// с левым краем карты
			} //else {ON_GROUND = false;}
		}
 

			    /* if (TileMap[i][j] == 's') { //если символ равен 's' (камень)
				    x = 300; y = 300;//какое то действие... например телепортация героя
				    TileMap[i][j] = ' ';//убираем камень, типа взяли бонус. можем и не убирать, кстати.
			    } */
	return 0;
        
	
}
