#pragma once

#include <iostream>
#include <time.h>
#include "GameBoard.h"
#include "GameMechanics.h"
#include "Snake.h"
//#include "GLFW/glfw3.h"

class GameLoop
{
private:
	uint8_t FPS;
	GameBoard m_gameBoard;
	GameMechanics m_gameMechanics;

	bool m_isRunning;
	uint8_t m_frameCnt;

public:
	GameLoop();
	GameLoop(uint8_t FPS);
	~GameLoop() = default;

	//void startGame(GLFWwindow* window);
	void stopGame();
	direction getKeyboardInput(direction previousDir);
};

