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
	static const int HEIGHT_MAP = 11;//высота карты
	const int WIDTH_MAP = 1000;//ширина карты
	sf::String TileMap[HEIGHT_MAP]={
 
        "                                                                                                                ^                                  $*$    425                                     ",
        "             GG                                                                                              GG              GG                                                                   ",
        "            G  G GG                                                                                         G  G GG         G  G GG                            425                                ",
        "        GG  G  425 G              425www425                                                     425        G   425 G    GG  G  425 G                                  425                         ",
        "       G  G G       G             r0iwwwr0i                      4225                           r0i        G        G  G  G G       G             42225                                           ",
        "       G  425       G             r0iwwwr0i                      r00i                           r0i        G         G G  425       G             r000i                                           ",
        "       G            GGG           r0iwwwr0i      42225           r00i                           r0i       GGG        G G            GGG        42260007225        425                             ",
        "     425            425        42260iwwwr0i      r000i           r007225                     42260i       425        425            425     G  r000000000i                                        ",
        "                 2             r0000iwwwr0i   42260007225wwwww422600000i                     r0000i                                         42260000000007225                                     ",
        "                 2             r0000iwwwr0i   r000000000iwwwwwr00000000i   ~~~~~   ~~~~~     r0000i                                         r000000000000000i                                     ",
        "222222222222222222222222222222260000iwwwr072226000000000iwwwwwr00000000722288888222888882222260000722222222222222222222222222222222222222222600000000000000072222222222222222222222222222222222222",

};	
public:
	Map();
	~Map();
	void draw(sf::RenderWindow &window);
};






#endif
