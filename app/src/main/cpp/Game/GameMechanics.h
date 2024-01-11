#pragma once

#include "GameBoard.h"
#include "Utils.h"
#include "Snake.h"
//#include "GameRenderer.h"

class GameMechanics
{
private:
	GameBoard* m_gameBoard;
	bool m_gameIsOver = false;
	Snake* m_snake;
	//GameRenderer m_renderer;
	direction m_lastDir = direction::UP;

	//direction getDirection(GLFWwindow* window, direction previousDir);

public:
	GameMechanics() = default;
	GameMechanics(GameBoard* gameBoard);

	void onUpdate();
	//void onRender(GLFWwindow* window);
	
	void initGame();
	void checkGameCase();
	void generateNewFruit();
	bool isGameOver() const { return m_gameIsOver; }
};

