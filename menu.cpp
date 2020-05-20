#include "menu.h"


//Menu::Menu():
//{};



void Menu::menu(sf::RenderWindow &window)
{
    texture_button1.loadFromFile("xstart.png");
    texture_button2.loadFromFile("xinfo1.png");
    texture_button3.loadFromFile("xexit.png");
    texture_bckgrund.loadFromFile("s1200.jpeg");
    button1.setTexture(texture_button1);
    button2.setTexture(texture_button2);
    button3.setTexture(texture_button3);
    sp_bckgrund.setTexture(texture_bckgrund);
    is_menu = true;
    button1.setPosition(640-58, 260);
    button1.scale(2.0, 2.0);
    //button1.setTextureRect(sf::IntRect(0, 0, 100, 150));
    button2.setPosition(640-58, 360);
    button2.scale(2.0, 2.0);
    //button2.setTextureRect(sf::IntRect(0, 0, 100, 150));
    button3.setPosition(640-58, 460);
    button3.scale(2.0, 2.0);
    //button3.setTextureRect(sf::IntRect(0, 0, 100, 200));
    sp_bckgrund.setPosition(50, 0);
    
    while (is_menu)
    {

        //window.clear();

        if (sf::IntRect(640 - 58, 260, 150, 50).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            is_menu = false;
        }
        if (sf::IntRect(640 - 58, 360, 150, 50).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            printf("haha\n");
        }
        if (sf::IntRect(640 - 58, 460, 150, 50).contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            printf("bye!\n");
            window.close();
        }


        window.draw(sp_bckgrund);
        window.draw(button1);
        window.draw(button2);
        window.draw(button3);

        window.display();
    }
}