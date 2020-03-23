#pragma once
#include "atltypes.h"
#include "Constants.h"

class CColorRect : public CRect
{
public:
	CColorRect(CRect* pRect = NULL, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bkgColor = BLACK);
	CColorRect(const CRect& pRect, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bkgColor = BLACK);
	CColorRect(const CPoint& LeftTop, const CPoint& RightBottom, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bkgColor = BLACK);
	CColorRect(const CPoint& LeftTop, const CSize& size, int penWidth = 0, COLORREF penColor = BLACK, COLORREF bkgColor = BLACK);
	
	virtual ~CColorRect();

public:
	void PaintColorRect(CDC* pDC); // funkcja rysujaca
	void setAttr(int penWidth = 0, COLORREF penColor = BLACK, COLORREF bkgColor = BLACK); // ustawia atrybuty
	CPen* getRectPen() const; // zwraca pioro
	CBrush* getRectBrush() const; // zwraca pedzel

private:
	void createAttr(int penWidth, COLORREF penColor, COLORREF bkgColor);

private:
	CPen* m_pPen;
	CBrush* m_pBrush;
};

