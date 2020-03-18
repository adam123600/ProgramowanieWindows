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

void CoordinateSystem::paintCoordinateSystemWithLines(CDC* pDC, const unsigned int& maxSortTime) // uklad + linie
{
	// uklad wspolrzednych
	pDC->MoveTo(this->leftTopPoint.first, this->leftTopPoint.second);
	pDC->LineTo(this->midPoint.first, this->midPoint.second);
	pDC->LineTo(this->bottomRightPoint.first, this->bottomRightPoint.second);

	int temp = maxSortTime;
	
	//temp = 1250;

	// kreski okreslajace skale
	CString s;


	for (int i = 0, j = temp; i < lines2.size(); i++, j -= temp/20)
	{
		//pDC->MoveTo(lines2[i].first.first - 20, lines2[i].first.second);
		s.Format(L"%d", static_cast<int>(j*(-1)/10) * 10);
		pDC->TextOutW(lines2[i].first.first - 60, lines2[i].first.second - 8, s);

		pDC->MoveTo(lines2[i].first.first, lines2[i].first.second);
		pDC->LineTo(lines2[i].second.first, lines2[i].second.second);
	}
}

void CoordinateSystem::drawObject(CDC* pDC)
{
	// uklad wspolrzednych
	pDC->MoveTo(this->leftTopPoint.first, this->leftTopPoint.second);
	pDC->LineTo(this->midPoint.first, this->midPoint.second);
	pDC->LineTo(this->bottomRightPoint.first, this->bottomRightPoint.second);

	// kreski okreslajace skale
	for (int i = 0, j = lines2.size()-1; i < lines2.size(); i++, j--)
	{
		//pDC->MoveTo(lines2[i].first.first - 20, lines2[i].first.second);
		CString s;
		s.Format(L"%d", j * 200);
		pDC->TextOutW(lines2[i].first.first - 60, lines2[i].first.second - 8, s);
		

		pDC->MoveTo(lines2[i].first.first, lines2[i].first.second);
		pDC->LineTo(lines2[i].second.first, lines2[i].second.second);
	}

}