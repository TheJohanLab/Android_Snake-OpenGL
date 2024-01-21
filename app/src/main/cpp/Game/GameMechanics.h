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
	direction m_dir = direction::UP;
    vec2 inputSrcPos {0, 0};
    vec2 inputDstPos {0, 0};
    bool isDirectionReady = false;

public:
	GameMechanics() = default;
	GameMechanics(GameBoard* gameBoard);

	void onUpdate();
	//void onRender(GLFWwindow* window);

	void initGame();
	void checkGameCase();
	void generateNewFruit();
	bool isGameOver() const { return m_gameIsOver; }
	direction handleDirection(direction previousDir);
    void setInputSrcPos(int x, int y);
    void setInputDstPos(int x, int y);

    void setInputReady(bool isReady) { isDirectionReady = isReady; }

};

