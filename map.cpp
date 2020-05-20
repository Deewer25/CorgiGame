#include "map.h"
using namespace sf;

Map::Map()
{
	
	map_image.loadFromFile("tilemap1.png");//загружаем файл для карты
	
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	
	sprite_map.setTexture(map);//заливаем текстуру спрайтом

}

void Map::draw(sf::RenderWindow &window){
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
            if(TileMap[i][j] ==' ') sprite_map.setTextureRect(IntRect(350,70,70,70));
			                      if(TileMap[i][j] ==' ') sprite_map.setTextureRect(IntRect(0,0,70,70));
                        if(TileMap[i][j] =='0') sprite_map.setTextureRect(IntRect(0,70,70,70));
                        if(TileMap[i][j] =='1') sprite_map.setTextureRect(IntRect(70,0,70,70));
                        if(TileMap[i][j] =='2') sprite_map.setTextureRect(IntRect(140,0,70,70));
                        if(TileMap[i][j] =='3') sprite_map.setTextureRect(IntRect(210,0,70,70));
                        if(TileMap[i][j] =='4') sprite_map.setTextureRect(IntRect(70,70,70,70));
                        if(TileMap[i][j] =='5') sprite_map.setTextureRect(IntRect(140,70,70,70));
                        if(TileMap[i][j] =='6') sprite_map.setTextureRect(IntRect(70,140,70,70));
                        if(TileMap[i][j] =='7') sprite_map.setTextureRect(IntRect(140,140,70,70));
                        if(TileMap[i][j] =='8') sprite_map.setTextureRect(IntRect(210,140,70,70));
                        if(TileMap[i][j] =='~') sprite_map.setTextureRect(IntRect(210,70,70,70));
                        if(TileMap[i][j] =='9') sprite_map.setTextureRect(IntRect(0,140,70,70));
                        if(TileMap[i][j] =='r') sprite_map.setTextureRect(IntRect(210,280,70,70));
                        if(TileMap[i][j] =='i') sprite_map.setTextureRect(IntRect(280,280,70,70));
                        if(TileMap[i][j] =='*') sprite_map.setTextureRect(IntRect(280,70,70,70));
                        if(TileMap[i][j] =='$') sprite_map.setTextureRect(IntRect(280,0,70,70));
                        if(TileMap[i][j] =='h') sprite_map.setTextureRect(IntRect(420,0,70,70));
                        if(TileMap[i][j] =='^') sprite_map.setTextureRect(IntRect(350,0,70,70));
                        if(TileMap[i][j] =='W') sprite_map.setTextureRect(IntRect(0,210,70,70));
                        if(TileMap[i][j] =='w') sprite_map.setTextureRect(IntRect(140,210,70,70));
                        if(TileMap[i][j] =='L') sprite_map.setTextureRect(IntRect(0,280,70,70));
                        if(TileMap[i][j] =='l') sprite_map.setTextureRect(IntRect(140,280,70,70));
                        if(TileMap[i][j] =='G') sprite_map.setTextureRect(IntRect(490,210,70,70));
                        if(TileMap[i][j] =='S') sprite_map.setTextureRect(IntRect(560,210,70,70));
                        if(TileMap[i][j] =='B') sprite_map.setTextureRect(IntRect(630,210,70,70));

	    		sprite_map.setPosition(j*70,i*70);
			window.draw(sprite_map);
		}
}


Map::~Map(){

}
