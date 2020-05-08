#include "game.h"

Game::Game() :
 window(sf::VideoMode(1280, 720), "GO"),
               time_game(0.0),
               Background(sf::Texture()),
               sprite_background(sf::Sprite()),
               event_game(sf::Event()),
               clock_game(sf::Clock())
{
    Background.loadFromFile("background1.png");
    sprite_background.setTexture(Background);
}

void Game::run()
{
	Hero hero("Corgi.png", SIZE_PICT$ * 551.0, SIZE_PICT$ * 509.0, 0, GROUND$);
	//Skeleton skelet("idle.png", 125, 210, 600, GROUND$);
	//Slime slime("117687.png", 130, 130, 800, GROUND$+105);

	//view.reset(sf::FloatRect(0, 0, 1280, 720));
	Map map;

	while (window.isOpen())
	{
		this->time_game = clock_game.getElapsedTime().asMicroseconds();
		this->clock_game.restart();

		this->time_game = this->time_game / 1000;

		if (this->time_game > 20)
			this->time_game = 20;

		window.clear();
		window.pollEvent(event_game);

		//if (event_game.type == sf::Event::Closed)
		//window.close();
		// The escape key was pressed
		//if ((event_game.type == sf::Event::KeyPressed) && (event_game.key.code == sf::Keyboard::Escape))
		//window.close();


		hero.motion();
		//slime.motion();


		hero.update(time_game);
		//slime.update(time_game);
		//skelet.update(time_game, window, hero.pos_obj);

		window.draw(sprite_background);
		//skelet.draw(window);   //Порядок важен!
		//slime.draw(window);
		
		map.draw(window);
		
		hero.draw(window);

		window.display();
	}
}
