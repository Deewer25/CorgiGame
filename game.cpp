#include "game.h"
#include "slime.h"
#include "skeleton.h"
#include "bulet.h"

Game::Game() :
 window(sf::VideoMode(1920, 1080), "GO"),
               time_game(0.0),
               Background(sf::Texture()),
               sprite_background(sf::Sprite()),
               event_game(sf::Event()),
               clock_game(sf::Clock())
{
	Background.loadFromFile("imgonline-com-ua-Resize-PYauMusAo9I.png");
	sprite_background.setTexture(Background);
	slimes_pos = {{2660, 2030}, {2100, 420}, {11970, 420}, {8820, 1260}, {7070, 910}};
	skel_pos = {{900, GROUND$}, {3570, 420}, {3150, 560}, {13230, 1610}};
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
	this->sprite_background.setPosition(pos_camera.x - 950, pos_camera.y - 550);
}



void Game::InitEnemy()
{
	for(int i = 0; i < 4; i++)
	{
		Slime* slime_supp = new Slime("117687.png", 83, 80, slimes_pos[i].x, slimes_pos[i].y);
		Slimes.push_back(slime_supp);
	}

	for (int i = 0; i < 3; i++)
	{
		Skeleton* skeleton_supp = new Skeleton("idle.png", 125, 200, skel_pos[i].x, skel_pos[i].y);
		Skeletons.push_back(skeleton_supp);
	}
}


void Game::KillEnemy(){
	/* for(auto i : Slimes){
		delete i;
	} */
}





void Game::run()
{
	//Menu MENU;

	//MENU.menu(window);
	
	//InitEnemy();

	Hero hero("Corgi.png", SIZE_PICT$ * 551.0, SIZE_PICT$ * 509.0, 0, GROUND$);
	//Skeleton skelet("idle.png", 125, 200, 900, GROUND$);
	//Slime slime1("117687.png", 83, 80, 2660, 2030);
	//Slime slime2("117687.png", 83, 80, 1000, GROUND$);
	

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

		for(auto i : Slimes){
			i->update(time_game, window, hero, map);
		}  


		
		for(auto i : Skeletons){
			i->update(time_game, window, hero, map);
		}


		//slime1.update(time_game, window, hero, map);
		//slime2.update(time_game, window, hero, map);
		//skelet.update(time_game, window, hero, map);
		
		map.draw(window);
		
		
		
		hero.draw(window);

		window.display();
	}
	//KillEnemy();

}
