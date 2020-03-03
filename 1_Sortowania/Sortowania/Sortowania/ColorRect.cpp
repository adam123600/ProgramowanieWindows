#include "stdafx.h"
#include "ColorRect.h"

#define RED RGB(255, 0, 0);

CColorRect::CColorRect(CRect* pRect, int penWidth, COLORREF penColor, COLORREF bkgColor)
{
	penWidth = 10;
	penColor = RED;
	bkgColor = RED;
}

CColorRect::CColorRect(const CRect& pRect, int penWidth, COLORREF penColor, COLORREF bkgColor)
{
	penWidth = 10;
	penColor = RED;
	bkgColor = RED;
}

CColorRect::CColorRect(const CPoint& LeftTop, const CPoint& RightBottom, int penWidth, COLORREF penColor, COLORREF bkgColor)
{
	penWidth = 10;
	penColor = RED;
	bkgColor = RED;
}

CColorRect::CColorRect(const CPoint& pRect, const CSize& size, int penWidth, COLORREF penColor, COLORREF bkgColor)
{
	penWidth = 10;
	penColor = RED;
	bkgColor = RED;
}


CColorRect::~CColorRect()
{

}


void CColorRect::PaintColorRect(CDC* pDC)
{

}

void CColorRect::setAttr(int penWidth, COLORREF penColor, COLORREF bkgColor)
{

}

//CPen* CColorRect::getRectPen() const
//{
//
//}
//
//CBrush* CColorRect::getRectBrush() const
//{
//
//}