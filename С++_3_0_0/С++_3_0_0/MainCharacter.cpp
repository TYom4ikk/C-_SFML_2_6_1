#include "MainCharacter.h"

MainCharacter::MainCharacter(std::string _filename, float _x, float _y, float _scaleX, float _scaleY, float _width, float _height,
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


void MainCharacter::update(float time) {
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

// 