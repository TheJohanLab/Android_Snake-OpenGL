#include "GameMechanics.h"
//#include "GLFW/glfw3.h"



GameMechanics::GameMechanics(GameBoard* gameBoard)
{
	m_gameBoard = gameBoard;
	m_snake = gameBoard->getSnake();
	initGame();
	//m_renderer = GameRenderer(800.0f, 800.0f);

}


/*void GameMechanics::onUpdate(GLFWwindow* window)
{
	m_lastDir = getDirection(window, m_lastDir);
	m_snake->move(m_lastDir, *m_gameBoard);
	checkGameCase();
}*/

/*void GameMechanics::onRender(GLFWwindow* window)
{
	m_renderer.updateVertices(*m_gameBoard);
	m_renderer.draw(window);
}*/



void GameMechanics::initGame()
{
	//vec2 initSnakeCoords = { GameBoard::getBoardHeight() / (uint8_t)2 , GameBoard::getBoardWidth() / (uint8_t)2 };
	//m_gameBoard->updateCaseSnake({ initSnakeCoords.posX, initSnakeCoords.posY });
	//m_gameBoard->getSnake()->addSnakeCase(&m_gameBoard->getGrid()[initSnakeCoords.posX][initSnakeCoords.posY]);

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

/*
direction GameMechanics::getDirection(GLFWwindow* window, direction previousDir)
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