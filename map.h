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
	static const int HEIGHT_MAP = 37;//высота карты
	//const int WIDTH_MAP = 200;//ширина карты
	sf::String TileMap[HEIGHT_MAP]={
 
        "                                                                                                                                                                                                ",
        "                                                                                                                                                     k                                          ",
        "                                                                                                                                                    G G     GG                                  ",
        "                                                                                                                          H                    G G G   G G G  G                                 ",
        "                   GGGG       k                                            H                                                                  42222222222225  G                                 ",
        "                  G    G G G G G                                          G G                                           GG GG                                 G                                 ",
        "                 G     4222222225                                        G   G                                          42225                                 G          4225                   ",
        "             GG  G                                                 G G G G   G                                                                                G                                 ",
        "            G 4225                         4225                    42222222225                                                                                425                               ",
        "            G                                                 G                               $ $ $ $ $ $         GGGG                                                                          ",
        "            G                                                425                                                  4225                                  GG   GGG                                ",
        "            G                                           G                                                                                              G  G G   G                               ",
        "          4225                                         425                                                                                             G  425    G                              ",
        "                                                  G                                          42222222222225     GG                           G G G G G G          G                             ",
        " $$$                                             425                                                         425  G  GGG                    422222222225           G   GGG                      ",
        "                G G G G G           G G G G G                                                                     G G   G                 G                         G G   G                     ",
        "          G    42222222225         42222222225                                                                    425    G               425                        425    G                    ",
        "         425                                                                 GG      GG                                  G G G G G G                                        G                   ",
        "                           GG                                               G  G    G  G  G                              422222222225                                        G  GG   $ $ $ $ $  ",
        "222225                    G  G                                              G  422225  G G G                                                                                 G G  G             ",
        "00000i             GGGG   G  425                                        GG  G          425 G                                          GG                                     425   G            ",
        "                  G    G  G                                             G G G              G                                         G  G                                          G            ",
        "             GG  G      G G                                             G 425              G                                         G  4225                                       G            ",
        "            G  GHG      G G                                             G                  GGG                                       G                                             422222222222 ",
        "            G  425      425                                             G                  425                                  GG   G                                                          ",
        "            G                                                        GG G                                              GGG     G  G  G                                                          ",
        "        GG  G                                                       G 425                                      GGG    G   G   G   4225                 H                                        ",
        "       G  G G                                                       G                                         G   G  G     G  G                       G G                                       ",
        "       G  425                      G G G G                          G                           GGGG          G   4225     G  G                      G   G                                      ",
        "       G            GGG           422222225                         G                           4225          G            G  G                     G     G                                     ",
        "       G            425           r0000000i                      4225                           r00i          G            4225                    422222225                                    ",
        "       G                          r0000000i      G G G           r00i                           r00i          G                                    r0000000i                                    ",
        "     425                          r0000000i      42225           r00i                           r00i       4225                                 422600000007225                             d   ",
        "                               42260000000i      r000i           r007225                     422600i                                            r0000000000000i                             D   ",
        "                               r0000000000i   42260007225wwwww422600000i                     r00000i                                         422600000000000007225                          D   ",
        "                               r0000000000i   r000000000iwwwwwr00000000i    ~~~~~ k ~~~~~    r00000i                                         r0000000000000000000i                          D   ",
        "22222222222222222222222222222226000000000072226000000000iwwwwwr00000000722228888822288888222260000072222222lllllllllllllllllllllllllllll22222600000000000000000007222222222222222222222222222222",

};	
public:
	Map();
	~Map();
	void draw(sf::RenderWindow &window);
};






#endif
