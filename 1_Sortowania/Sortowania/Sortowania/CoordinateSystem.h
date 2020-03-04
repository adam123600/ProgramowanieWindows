#pragma once
//klasa odpowiedzialna za siatke, uklad wspolrzednych

#include <utility>
#include <iostream>

class CoordinateSystem
{


public:
	CoordinateSystem();
	CoordinateSystem(std::pair<int, int> cLeftTopPoint, std::pair<int, int> cMidPoint,
		std::pair<int, int> cBottomRightPoint);
	
	~CoordinateSystem();

public:
	void paintCoordinateSystem(CDC* pDC); // funkcja rysujaca uklad


private:
	std::pair<int, int> leftTopPoint; // lewy gorny rog
	std::pair<int, int> midPoint; // lewy dolny rog ( poczatek ukladu )
	std::pair<int, int> bottomRightPoint; // prawy dolny rog 
};

