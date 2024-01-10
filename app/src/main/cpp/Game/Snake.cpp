#include "Snake.h"
#include "GameBoard.h"



Snake::Snake()
{
	m_snake = std::vector<Case*>();

}

void Snake::move(direction dir, GameBoard& gameboard)
{

	uint8_t snakeLen = m_snake.size();

	if (!addFruitElement())
		m_snake.back()->emptyCase();

	if (snakeLen > 1)
	{
		for (uint8_t snakeIdx = snakeLen - 1; snakeIdx > 0; snakeIdx--)
		{
			m_snake[snakeIdx] = m_snake[snakeIdx-1];
			m_snake[snakeIdx]->setSnake();
		}
	}

	vec2 currHeadPos = m_snake.front()->getCoords();
	switch(dir) 
	{
		case direction::UP: 
			(currHeadPos.posY == 0) ? currHeadPos.posY = GameBoard::getBoardHeight() - 1 : currHeadPos.posY--;
			break;
		case direction::DOWN:
			(currHeadPos.posY == GameBoard::getBoardHeight() - 1) ? currHeadPos.posY = 0 : currHeadPos.posY++;
			break;
		case direction::LEFT:
			(currHeadPos.posX == 0) ? currHeadPos.posX = GameBoard::getBoardWidth() - 1 : currHeadPos.posX--;
			break;
		case direction::RIGHT:
			(currHeadPos.posX == GameBoard::getBoardWidth() - 1) ? currHeadPos.posX = 0 : currHeadPos.posX++;
			break;
	}

	
	//m_snake.front() = &grid[currHeadPos.posX][currHeadPos.posY];
	m_snake.front() = &gameboard.getGrid()[currHeadPos.posX][currHeadPos.posY];
	//m_snake.front()->setSnake();

}


void Snake::eat(Case* fruit)
{
	m_snake.front()->setSnake();
	m_eatingFruitCoords = fruit;

}

void Snake::addSnakeCase(Case* boardCase)
{
	m_snake.push_back(boardCase);
}

std::vector<vec2> Snake::getSnakeCoords() const
{
	std::vector<vec2> snakeCoords = std::vector<vec2>();
	for (Case* coord : m_snake)
	{
		vec2 currCoord = coord->getCoords();
		snakeCoords.push_back(currCoord);

	}
	return snakeCoords;
}

vec2 Snake::getSnakeHeadCoord() const
{
	return m_snake.front()->getCoords();
}

Case* Snake::getSnakeHead() const
{
	return m_snake.front();
}

bool Snake::addFruitElement()
{
	if (m_eatingFruitCoords != nullptr && (m_snake.back()->getCoords() == m_eatingFruitCoords->getCoords()))
	{
		addSnakeCase(m_eatingFruitCoords);
		m_eatingFruitCoords = nullptr;
		return true;
	}
	
	return false;
}