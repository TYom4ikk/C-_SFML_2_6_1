#pragma once
#include "Object.h"
#include <vector>
#include "Coordinate.h"
#include "SFML/Graphics.hpp"
class Mob : public Object
{
private:
    Image images[1]; // Кадры для анимации

    // массив анимации бега направо
    // массив анимации бега налево
    // массив анимации прыжка
    // массив анимации падения
    // массив анимации бездействия
    std::vector<Image> inactionFrames;

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

    int defaultTextureLeft;
    int defaultTextureTop;

    Mob(std::string _filename, float _x, float _y, float _scaleX, float _scaleY,
        float _width, float _height, int _health, float _strength, float _weight,
        int _defaultTextureLeft, int _defaultTextureTop);

    void InitilizeInactionFramesArray(int inactionFramesCount, std::vector<Coordinate> coordinates) {
        for (int i = 0; i < coordinates.size(); i++) {
            inactionFrames.push_back();
        }
    }



    void update(float time);

};

