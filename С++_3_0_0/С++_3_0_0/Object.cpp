#include "Object.h"

Object::Object(std::string _filename, float _x, float _y, float _scaleX, float _scaleY, float _width, float _height) {

    x = _x;
    y = _y;
    scaleX = _scaleX;
    scaleY = _scaleY;
    width = _width;
    height = _height;

    path = _filename;
    image.loadFromFile(_filename);
    texture.loadFromImage(image);

    sprite.setTexture(texture);

    sprite.setPosition(x, y);
    sprite.setScale(scaleX, scaleY);
}

void Object::setTextureRect(int left, int top, int width, int height) {
    sprite.setTextureRect(IntRect(left, top, width, height));
}

Sprite Object::getSprite() {
    return sprite;
}

float Object::getScaleX() {
    return scaleX;
}

float Object::getScaleY() {
    return scaleY;
}