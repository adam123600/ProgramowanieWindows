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

CoordinateSystem::CoordinateSystem(std::pair<int, int> cLeftTopPoint, std::pair<int, int> cMidPoint,
	std::pair<int, int> cBottomRightPoint, std::vector<std::pair<int, int>> cLines)
{
	this->leftTopPoint.first = cLeftTopPoint.first;
	this->leftTopPoint.second = cLeftTopPoint.second;

	this->midPoint.first = cMidPoint.first;
	this->midPoint.second = cMidPoint.second;

	this->bottomRightPoint.first = cBottomRightPoint.first;
	this->bottomRightPoint.second = cBottomRightPoint.second;

	for (int i = 0; i < cLines.size(); i++)
	{
		lines[i] = cLines[i];
	}
}

CoordinateSystem::CoordinateSystem(std::pair<int, int> cLeftTopPoint, std::pair<int, int> cMidPoint,
	std::pair<int, int> cBottomRightPoint, std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> cLines2)
{
	this->leftTopPoint.first = cLeftTopPoint.first;
	this->leftTopPoint.second = cLeftTopPoint.second;

	this->midPoint.first = cMidPoint.first;
	this->midPoint.second = cMidPoint.second;

	this->bottomRightPoint.first = cBottomRightPoint.first;
	this->bottomRightPoint.second = cBottomRightPoint.second;

	for (int i = 0; i < cLines2.size(); i++)
	{
		std::pair<std::pair<int, int>, std::pair<int, int>> s;
		s.first.first = cLines2[i].first.first;
		s.first.second = cLines2[i].first.second;
		s.second.first = cLines2[i].second.first;
		s.second.second = cLines2[i].second.second;

		lines2.push_back(s);
	}
}



void CoordinateSystem::paintCoordinateSystem(CDC* pDC) // funkcja rysujaca uklad
{
	pDC->MoveTo(this->leftTopPoint.first, this->leftTopPoint.second);
	pDC->LineTo(this->midPoint.first, this->midPoint.second);
	pDC->LineTo(this->bottomRightPoint.first, this->bottomRightPoint.second);
}

void CoordinateSystem::paintCoordinateSystemWithLines(CDC* pDC) // uklad + linie
{
	// uklad wspolrzednych
	pDC->MoveTo(this->leftTopPoint.first, this->leftTopPoint.second);
	pDC->LineTo(this->midPoint.first, this->midPoint.second);
	pDC->LineTo(this->bottomRightPoint.first, this->bottomRightPoint.second);

	// kreski okreslajace skale
	for (int i = 0; i < lines2.size(); i++)
	{
		pDC->MoveTo(lines2[i].first.first, lines2[i].first.second);
		pDC->LineTo(lines2[i].second.first, lines2[i].second.second);
	}
}