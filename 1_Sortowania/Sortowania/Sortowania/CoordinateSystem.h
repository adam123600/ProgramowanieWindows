#pragma once
//klasa odpowiedzialna za siatke, uklad wspolrzednych

#include <iostream>
#include <utility>
#include <vector>


class CoordinateSystem
{


public:
	CoordinateSystem();
	CoordinateSystem(std::pair<int, int> cLeftTopPoint, std::pair<int, int> cMidPoint,
		std::pair<int, int> cBottomRightPoint);
	CoordinateSystem(std::pair<int, int> cLeftTopPoint, std::pair<int, int> cMidPoint,
		std::pair<int, int> cBottomRightPoint, std::vector<std::pair<int, int>> cLines);

	CoordinateSystem(std::pair<int, int> cLeftTopPoint, std::pair<int, int> cMidPoint,
		std::pair<int, int> cBottomRightPoint, std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> cLines2);


	~CoordinateSystem();

public:
	void paintCoordinateSystem(CDC* pDC); // funkcja rysujaca uklad
	void paintCoordinateSystemWithLines(CDC* pDC, const unsigned int& maxSortTime); // uklad + linie
	//void drawObject(CDC* pDC) override;


private:
	std::pair<int, int> leftTopPoint; // lewy gorny rog
	std::pair<int, int> midPoint; // lewy dolny rog ( poczatek ukladu )
	std::pair<int, int> bottomRightPoint; // prawy dolny rog 
	std::vector<std::pair<int, int>> lines;
	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines2;
};

