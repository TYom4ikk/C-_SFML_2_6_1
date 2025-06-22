#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

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

    MainCharacter(std::string _filename, float _x, float _y, float _scaleX, float _scaleY,
        float _width, float _height, int _health, float _strength, float _weight);

    void update(float time);
};