#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Object{

protected:
    std::string path;
    Image image;
    Texture texture;

    float x, y;
    float scaleX, scaleY;

public:
    float width;
    float height;
    Sprite sprite;

    Object(std::string _filename, float _x, float _y, float _scaleX, float _scaleY, float _width, float _height);

    void setTextureRect(int left, int top, int width, int height);

    Sprite getSprite();
    float getScaleX();
    float getScaleY();
};