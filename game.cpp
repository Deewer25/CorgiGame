#include "game.h"
#include "slime.h"
#include "skeleton.h"
#include "bulet.h"

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


void Game::pause()
{
	while (1)
	{
		window.pollEvent(event_game);
		if((event_game.type == sf::Event::KeyPressed))
			break;
	};
}

void Game::background_motion(sf::Vector2f pos_camera)
{
	this->sprite_background.setPosition(pos_camera.x - 650, pos_camera.y - 350);
}

void Game::run()
{
	//Menu MENU;

	//MENU.menu(window);


	Hero hero("Corgi.png", SIZE_PICT$ * 551.0, SIZE_PICT$ * 509.0, 0, GROUND$);
	Skeleton skelet("idle.png", 125, 200, 900, GROUND$);
	//Bulet slime("bullet.png", 83, 80, 0, GROUND$);


//	View view;
//	view.reset(sf::FloatRect(0, 0, 1280, 720));
	Map map;
	while (window.isOpen())
	{
		this->time_game = clock_game.getElapsedTime().asMicroseconds();
		this->clock_game.restart();

		this->time_game = this->time_game / 1000;

		if (this->time_game > 20)
			this->time_game = 20;

//		window.setView(view);
		window.clear();
		window.pollEvent(event_game);
		window.draw(sprite_background);
		//if (event_game.type == sf::Event::Closed)
		//window.close();
		// The escape key was pressed
		if ((event_game.type == sf::Event::KeyPressed) && (event_game.key.code == sf::Keyboard::Escape))
			pause();


		hero.motion();
		//slime.motion();
		background_motion(hero.get_pos_camera());


		hero.update(time_game, map);
		//slime.update(time_game, map);
		skelet.update(time_game, window, hero, map);
		
		
		
		map.draw(window);
		skelet.draw(window);   //Порядок важен!
		//slime.draw(window);
		
		
		hero.draw(window);

		window.display();
	}
}
