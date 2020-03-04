#include "stdafx.h"
#include "CoordinateSystem.h"


CoordinateSystem::CoordinateSystem()
{
}


CoordinateSystem::~CoordinateSystem()
{
}


CoordinateSystem::CoordinateSystem(std::pair<int, int> cLeftTopPoint, std::pair<int, int> cMidPoint,
	std::pair<int, int> cBottomRightPoint)
{
	this->leftTopPoint.first = cLeftTopPoint.first;
	this->leftTopPoint.second = cLeftTopPoint.second;

	this->midPoint.first = cMidPoint.first;
	this->midPoint.second = cMidPoint.second;

	this->bottomRightPoint.first = cBottomRightPoint.first;
	this->bottomRightPoint.second = cBottomRightPoint.second;
}


void CoordinateSystem::paintCoordinateSystem(CDC* pDC) // funkcja rysujaca uklad
{
	pDC->MoveTo(this->leftTopPoint.first, this->leftTopPoint.second);
	pDC->LineTo(this->midPoint.first, this->midPoint.second);
	pDC->LineTo(this->bottomRightPoint.first, this->bottomRightPoint.second);
}