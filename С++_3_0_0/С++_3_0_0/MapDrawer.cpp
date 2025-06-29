#include "MapDrawer.h"

MapDrawer::MapDrawer(std::string _pathToMapTexture, int _currentPositionX, int _currentPositionY, int _move) {
	pathToMapTexture = _pathToMapTexture;
	currentPositionX = _currentPositionX;
	currentPositionY = _currentPositionY;
	move = _move;
}

void MapDrawer::Draw(int map[][35], int map_height, int map_width, RenderWindow& window,
	int block_height, int block_width) {
    for (int i = 0; i < map_height; ++i) {
        for (int j = 0; j < map_width; ++j) {

            int title = map[i][j];

            if (title == 1) {

                Object grass(pathToMapTexture, currentPositionX, currentPositionY, 1, 1, block_width, block_height);
                grass.setTextureRect(6 * block_width, 13 * block_height, block_width, block_height);
                window.draw(grass.getSprite());
            }
            else if (title == 2) {
                Object dirt(pathToMapTexture, currentPositionX, currentPositionY, 1, 1, block_width, block_height);
                dirt.setTextureRect(5 * block_width, 13 * block_height, block_width, block_height);
                window.draw(dirt.getSprite());
            }
            else if (title == 3) {
                // Новый блок
            }
            currentPositionX += block_width;
        }
        currentPositionX = 0;
        currentPositionY += block_height;
    }
}