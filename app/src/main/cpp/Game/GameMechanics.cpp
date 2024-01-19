#include "GameMechanics.h"
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

void GameMechanics::setInputSrcPos(vec2 pos) {
    this->inputSrcPos = pos;
}

void GameMechanics::setInputDstPos(vec2 pos) {
    this->inputDstPos = pos;
}


direction GameMechanics::handleDirection(direction previousDir) {

    float deltaX = inputDstPos.posX - inputSrcPos.posX;
    float deltaY = inputDstPos.posY - inputSrcPos.posY;

    float absDeltaX = std::abs(deltaX);
    float absDeltaY = std::abs(deltaY);
    float swipeThreshold = 10;

    if (absDeltaX > absDeltaY && absDeltaX > swipeThreshold) {
        // Swipe horizontal
        if (deltaX > 0 && m_dir != direction::LEFT)
            m_dir = direction::RIGHT;
        else if (deltaX < 0 && m_dir != direction::RIGHT)
            m_dir = direction::LEFT;
        //m_dir = (deltaX > 0) ? direction::RIGHT : direction::LEFT;
    } else if (absDeltaY > absDeltaX && absDeltaY > swipeThreshold) {
        // Swipe vertical
        if (deltaY > 0 && m_dir != direction::UP)
            m_dir = direction::DOWN;
        else if (deltaY < 0 && m_dir != direction::DOWN)
            m_dir = direction::UP;
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