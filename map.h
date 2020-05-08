#ifndef MAP_H
#define MAP_H
#include<SFML/Graphics.hpp>

class Map
{
private:
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
	"        eooof                                                                                ",
	"             eof                       eoof                                                  ",
	"                eof              eoof                                                        ",
	"                   cooool     eof                                                            ",
	"               cooodqqqqkoool                  coool                                         ",
	"           cooodqqqqqqqqqqqqkoool          cooodqqqkoool                                     ",
	"ooooooooooodqqqqqqqqqqqqqqqqqqqqkoooooooooodqqqqqqqqqqqkooooooooooooooooooooooooooooooooooooo",

};	
public:
	Map();
	~Map();
	void draw(sf::RenderWindow &window);


};






#endif
