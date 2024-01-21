#include "GameMechanics.h"
#include "../AndroidOut.h"
//#include "GLFW/glfw3.h"



GameMechanics::GameMechanics(GameBoard* gameBoard)
{
	m_gameBoard = gameBoard;
	m_snake = gameBoard->getSnake();
	initGame();
	//m_renderer = GameRenderer(800.0f, 800.0f);

}


void GameMechanics::onUpdate()
{
	//m_lastDir = getDirection(m_lastDir);
	//m_lastDir = direction::UP;
	m_snake->move(m_dir, *m_gameBoard);
	checkGameCase();
}

/*void GameMechanics::onRender(GLFWwindow* window)
{
	m_renderer.updateVertices(*m_gameBoard);
	m_renderer.draw(window);
}*/



void GameMechanics::initGame()
{
	vec2 initSnakeCoords = { static_cast<uint8_t>(GameBoard::getBoardHeight() / (uint8_t)2) , static_cast<uint8_t>(GameBoard::getBoardWidth() / (uint8_t)2) };
	m_gameBoard->updateCaseSnake({ initSnakeCoords.posX, initSnakeCoords.posY });
	m_gameBoard->getSnake()->addSnakeCase(&m_gameBoard->getGrid()[initSnakeCoords.posX][initSnakeCoords.posY]);

	generateNewFruit();

}


void GameMechanics::checkGameCase()
{
	Case* snakeHead = m_snake->getSnakeHead();
	if (snakeHead->isEmpty())
		snakeHead->setSnake();
	else if (snakeHead->isFruit())
	{
		m_snake->eat(snakeHead);
		generateNewFruit();
	}
	else
		m_gameIsOver = true;
}


void GameMechanics::generateNewFruit()
{
	auto snakeCoords = m_snake->getSnakeCoords();

	vec2 fruitCoords = generateRandomCoords(0, GameBoard::getBoardWidth() - 1, snakeCoords);
	m_gameBoard->updateCaseFruit(fruitCoords);


}

void GameMechanics::setInputSrcPos(int x, int y) {
    aout << "x : " << x << ", y : " << y << "\n";
    this->inputSrcPos.posX = x;
    this->inputSrcPos.posY = y;
}

void GameMechanics::setInputDstPos(int x, int y) {
    aout << "x : " << x << ", y : " << y << "\n";
    this->inputDstPos.posX = x;
    this->inputDstPos.posY = y;

}


direction GameMechanics::handleDirection(direction previousDir) {

    aout<< " handleDir\n";
    if (inputSrcPos.isEmpty() || inputDstPos.isEmpty())
        return direction::UP;

    int deltaX = inputDstPos.posX - inputSrcPos.posX;
    int deltaY = inputDstPos.posY - inputSrcPos.posY;

    aout << "inputDst X = " << static_cast<unsigned>(inputDstPos.posX) << ",Src X = " << static_cast<unsigned>(inputSrcPos.posX) << ", deltax = " << deltaX << "\n";
    aout << "inputDst Y = " << static_cast<unsigned>(inputDstPos.posY) << ",Src Y = " << static_cast<unsigned>(inputSrcPos.posY) << ", deltaY = " << deltaY << "\n";

    float absDeltaX = std::abs(deltaX);
    float absDeltaY = std::abs(deltaY);
    float swipeThreshold = 50;

    if (absDeltaX > absDeltaY && absDeltaX > swipeThreshold) {
        // Swipe horizontal
        if (deltaX > 0 && m_dir != direction::LEFT)
        {
            m_dir = direction::RIGHT;
            aout << "right\n";
        }
        else if (deltaX < 0 && m_dir != direction::RIGHT)
        {
            m_dir = direction::LEFT;
            aout << "left\n";
        }
        //m_dir = (deltaX > 0) ? direction::RIGHT : direction::LEFT;
    } else if (absDeltaY > absDeltaX && absDeltaY > swipeThreshold) {
        // Swipe vertical
        if (deltaY > 0 && m_dir != direction::UP)
        {
            m_dir = direction::DOWN;
            aout << "down\n";
        }
        else if (deltaY < 0 && m_dir != direction::DOWN)
        {
            m_dir = direction::UP;
            aout<< "up\n";
        }
        //m_dir = (deltaY > 0) ? direction::DOWN : direction::UP;
    }

    return direction::UP;
}

/*
direction GameMechanics::getDirection(direction previousDir)
{

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && previousDir != direction::DOWN)
		return direction::UP;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS && previousDir != direction::UP)
		return direction::DOWN;
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && previousDir != direction::RIGHT)
		return direction::LEFT;
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && previousDir != direction::LEFT)
		return direction::RIGHT;

	return previousDir;

}
*/