#include <SFML/Graphics.hpp>

#include "Object.h"

using namespace sf;

class MainCharacter : public Object {

private:
    Image images[1]; // Кадры для анимации
    
    float weight;
    float accelertion_free_fall = 9.81;

    float strength;

    int health;

public:

    int currentFrame;

    float dx;
    float dy;

    float speed;
    int dir;

    MainCharacter(std::string _filename, float _x, float _y, float _scaleX, float _scaleY, float _width, float _height,
        int _health, float _strength, float _weight) :
        Object(_filename, _x, _y, _scaleX, _scaleY, _width, _height) {

        currentFrame = 0;

        x = _x;
        y = _y;
        scaleX = _scaleX;
        scaleY = _scaleY;
        width = _width;
        height = _height;
        health = _health;
        strength = _strength;
        weight = _weight;

        path = _filename;
        image.loadFromFile(_filename);
        texture.loadFromImage(image);

        sprite.setTexture(texture);
      
        sprite.setTextureRect(IntRect(188, 96, width, height)); // !!!!!

        dx = 0;
        dy = 0;
        speed = 0;
        dir = 0;

        sprite.setPosition(x, y);
        sprite.setScale(scaleX, scaleY);
    }


    void update(float time) {
        switch (dir)
        {
            case 0: dx = speed; dy = 0; break;
            case 1: dx = -speed; dy = 0; break;
            case 2: dx = 0; dy = speed; break;
            case 3: dx = 0; dy = -speed; break;
        }
        x += dx * time;
        y += dy * time;

        speed = 0;
        sprite.setPosition(x, y);
    }
};

int main()
{
    RenderWindow window(VideoMode(800, 800), L"Новый проект", Style::Default);
    window.setVerticalSyncEnabled(true);

    // 0 - ничего
    // 1 - трава
    // 2 - земля

    int map[24][35]{
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,2,1,1,1,1,1,1},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2.2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2.2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2.2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2.2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2.2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2.2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
    };



    Object object("Img/sky.jpeg", 0, 0, 5, 4, 474*5, 331*4);
    MainCharacter hero("Img/ghost_textures.png", 300, 300, 2, 2, 47, 48, 100, 25, 20);

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
           /* hero.currentFrame += 0.005 * time;
            if (hero.currentFrame > 8) {
                hero.currentFrame -= 2;
            }*/
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
        window.draw(object.getSprite());

        //==========Карта==========

        int currentPositionX = 0;
        int currentPositionY = 0;

        int move = 64;

        std::string pathToMapTexture = "Img/map_textures.png";

        //for (int i = 0; i < 24; i++) {
        //    for (int j = 0; j < 35; j++) {
        //        if (map[i][j] == 1) {

        //            Object grass(pathToMapTexture, currentPositionX, currentPositionY, 1, 1);
        //            grass.setTextureRect(6 * 64, 13 * 64, 64, 64);
        //            window.draw(grass.getSprite());
        //        }
        //        else if (map[i][j] == 2) {
        //            Object dirt(pathToMapTexture, currentPositionX, currentPositionY, 1, 1);
        //            dirt.setTextureRect(5 * 64, 13 * 64, 64, 64);
        //            ..window.draw(dirt.getSprite());
        //        }
        //        else if (map[i][j] == 2) {
        //            // Новый блок
        //        }
        //        currentPositionX += 64;
        //    }
        //    currentPositionX = 0;
        //    currentPositionY += 64;
        //}

        //=========================


        window.draw(hero.getSprite());

        window.display();
    }
    return 0;
}