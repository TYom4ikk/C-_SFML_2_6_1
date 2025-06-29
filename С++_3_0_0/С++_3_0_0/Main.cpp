#include <SFML/Graphics.hpp>
#include "Object.h"
#include "MainCharacter.h"
#include "Maps.h"
#include "MapDrawer.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000, 1000), L"Новый проект", Style::Default);
    window.setVerticalSyncEnabled(true);

    Object sky("Img/sky.jpeg", 0, 0, 5, 4, 474*5, 331*4);
    MainCharacter hero("Img/ghost_textures.png", 300, 300, 2, 2, 47, 48, 100, 25, 20, 188, 96);

    Mob john1("Img/john_doe.png", 350, 350, 1, 1, 141, 160, 100, 10, 60, 0, 0);

    Mob john2("Img/john_doe.png", 400, 350, 1, 1, 141, 160, 100, 10, 60, 0, 0);

    Mob john3("Img/john_doe.png", 450, 350, 1, 1, 141, 160, 100, 10, 60, 0, 0);

    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::A)) {
            hero.dir = 1; hero.speed = 0.1;
            hero.currentFrame = 6;

            hero.currentFrame += 0.005 * time;
            if (hero.currentFrame > 8) {
                hero.currentFrame -= 2;
            }

            hero.setTextureRect(hero.width * int(hero.currentFrame), 0, hero.width, hero.height);


            sf::FloatRect bounds = hero.sprite.getLocalBounds();
            hero.sprite.setOrigin(0.f, 0.f);
            hero.sprite.setScale(hero.getScaleX(), hero.getScaleY());

        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            hero.dir = 0; hero.speed = 0.1;

            hero.currentFrame = 6;
            hero.setTextureRect(hero.width*int(hero.currentFrame), 0, hero.width, hero.height);

            sf::FloatRect bounds = hero.sprite.getLocalBounds();
            hero.sprite.setOrigin(bounds.width, 0.f);
            hero.sprite.setScale(-hero.getScaleX(), hero.getScaleY());

        }
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            hero.dir = 3; hero.speed = 0.1;
            hero.currentFrame = 4;
            hero.setTextureRect(hero.width * int(hero.currentFrame), 0, hero.width, hero.height);
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            hero.dir = 2; hero.speed = 0.1;

            hero.currentFrame = 0;
            hero.setTextureRect(hero.width * int(hero.currentFrame), 0, hero.width, hero.height);
        }

        hero.update(time);
        window.clear(Color::White);
        window.draw(sky.getSprite());

        window.draw(john1.getSprite());

        window.draw(john2.getSprite());

        window.draw(john3.getSprite());

        MapDrawer drawer("Img/map_textures.png", 0, 0, 64);
        //drawer.Draw(MAP_2, MAP_2_HEIGHT, MAP_2_WIDTH, window, 64, 64);

        window.draw(hero.getSprite());

        window.display();
    }
    return 0;
}