#include "GameBoard.h"


GameBoard::GameBoard()
{

	m_snake = Snake();

	for (uint8_t i = 0; i <= GRID_HEIGHT - 1; i++)
	{
		for (uint8_t j = 0; j <= GRID_WIDTH - 1; j++)
		{
			m_Grid[i][j] = Case({ i, j });
		}
	}


}

void GameBoard::updateCase(vec2 coords, caseStatus status)
{
	m_Grid[coords.posX][coords.posY].setCaseStatus(status);
}

void GameBoard::updateCaseSnake(vec2 coords)
{
	m_Grid[coords.posX][coords.posY].setCaseStatus(caseStatus::SNAKE);
}

void GameBoard::updateCaseFruit(vec2 coords)
{
	m_Grid[coords.posX][coords.posY].setCaseStatus(caseStatus::FRUIT);
	m_fruit = &m_Grid[coords.posX][coords.posY];
}






