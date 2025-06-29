#pragma once
#include <SFML/Graphics.hpp>
#include "Maps.h"
#include "Object.h"

// 0 - ничего
// 1 - трава
// 2 - земля

class MapDrawer {
private:
	int currentPositionX;
	int currentPositionY;

	int move;

	std::string pathToMapTexture;
public:
    MapDrawer(std::string _pathToMapTexture, int _currentPositionX, int _currentPositionY, int _move);

	void Draw(int map[][35], int map_height, int map_width, RenderWindow& window,
		int block_height, int block_width);
};