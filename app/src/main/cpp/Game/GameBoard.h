#pragma once

#include <array>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include "Case.h"
#include "Snake.h"

//class Snake;

class GameBoard
{
private:
	static const uint8_t GRID_WIDTH = 20;
	static const uint8_t GRID_HEIGHT = 20;


	std::array<std::array<Case, GRID_WIDTH>, GRID_HEIGHT> m_Grid;
	Snake m_snake;
	Case* m_fruit;
	
public:

	GameBoard();
	~GameBoard() = default;

	void updateCase(vec2 coords, caseStatus status);
	void updateCaseSnake(vec2 coords);
	void updateCaseFruit(vec2 coords);

	static uint8_t getBoardWidth() { return GRID_WIDTH;  }
	static uint8_t getBoardHeight() { return GRID_HEIGHT;  }

	std::array<std::array<Case, GRID_WIDTH>, GRID_HEIGHT>& getGrid() { return m_Grid; }

	Snake* getSnake() { return &m_snake; }
	Case* getFruitCoords() const { return m_fruit; }

};

