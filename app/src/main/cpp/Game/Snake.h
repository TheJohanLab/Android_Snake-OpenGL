#pragma once

#include <vector>
#include <array>
#include "Case.h"
#include "Utils.h"
//#include "GameBoard.h"

class GameBoard;

class Snake
{
private:
	
	bool m_eating = false;
	Case* m_eatingFruitCoords = nullptr;

	bool addFruitElement();
	std::vector<Case*> m_snake;

public:
	Snake();
	
	//void move(direction dir, std::array<std::array<Case, 20>,20>& gameBoard);
	void move(direction dir, GameBoard& gameboard);
	void eat(Case* fruit);
	void addSnakeCase(Case* boardCase);

	std::vector<vec2> getSnakeCoords() const;
	vec2 getSnakeHeadCoord() const;
	Case* getSnakeHead() const;
};

