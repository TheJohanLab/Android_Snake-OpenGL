#include "Case.h"

Case::Case()
{
}

Case::Case(vec2 coord) : m_coord(coord), m_status(caseStatus::EMPTY)
{

}

bool Case::isEmpty() const
{
	return m_status == caseStatus::EMPTY;
}

bool Case::isSnake() const
{
	return m_status == caseStatus::SNAKE;
}

bool Case::isFruit() const
{
	return m_status == caseStatus::FRUIT;
}

caseStatus Case::getCaseStatus() const
{
	return m_status;
}

void Case::setCaseStatus(caseStatus status)
{
	m_status = status;
}
