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
    if (x > 12500) X =12500;
	if (y < 100) Y = 100;//верхнюю сторону
	if (y >= 2190) Y = 2190;//нижнюю сторону	
    
	view.setCenter(X, Y); //следим за игроком, передавая его координаты камере. +100 - сместили камеру по иксу вправо. эксперементируйте
 
	
}

#endif
