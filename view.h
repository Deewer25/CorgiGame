#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

using namespace sf;
sf::View view;

void ChangeView(float x,float y)  { //функция для считывания координат игрока
    float X, Y;
    X = x;
    Y = y;

	if (x < 640) X = 640;
    if (x > 5400) X = 5400;
	if (y < 100) Y = 100;//верхнюю сторону
	if (y >= 500) Y = 500;//нижнюю сторону	
    
	view.setCenter(X, Y); //следим за игроком, передавая его координаты камере. +100 - сместили камеру по иксу вправо. эксперементируйте
 
	
}

#endif
