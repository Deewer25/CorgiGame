#ifndef MAP_H
#define MAP_H
#include<SFML/Graphics.hpp>

class Map
{
private:

public:
	sf::Image map_image;//объект изображения для карты
	sf::Texture map;//текстура карты
	sf::Sprite sprite_map;//создаём спрайт для карты
	static const int HEIGHT_MAP = 25;//высота карты
	const int WIDTH_MAP = 60;//ширина карты
	sf::String TileMap[HEIGHT_MAP]={

        "                                                                                             ",
        "                                                                                             ",
        "                                                                                             ",
        "                                                                                             ",
        "        12223                                                                                ",
        "             123                     12223                                                   ",
        "                123              1223                                                        ",
        "                   422225     123                                                            ",
        "               42226000072225                  42225                                         ",
        "           4222600000000000072225          4222600072225                                     ",
        "222222222226000000000000000000007222222222260000000000072222222222222222222222222222222222222",

};	
public:
	Map();
	~Map();
	void draw(sf::RenderWindow &window);
};






#endif
