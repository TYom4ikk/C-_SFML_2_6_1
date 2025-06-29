#pragma once
#include <SFML/Graphics.hpp>
#include "Mob.h"

class MainCharacter : public Mob {
public:
	MainCharacter(std::string _filename, float _x, float _y, float _scaleX, float _scaleY,
		float _width, float _height, int _health, float _strength, float _weight, int _defaultTextureLeft, int _defaultTextureTop);

};