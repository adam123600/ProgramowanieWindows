#include "stdafx.h"
#include "ColorRect.h"

#define RED RGB(255, 0, 0);

CColorRect::CColorRect(CRect* pRect, int penWidth, COLORREF penColor, COLORREF bkgColor) : CRect(pRect)
{
	this->m_pPen = new CPen(PS_SOLID, penWidth, penColor);
	this->m_pBrush = new CBrush(bkgColor);
}

CColorRect::CColorRect(const CRect& pRect, int penWidth, COLORREF penColor, COLORREF bkgColor) : CRect(pRect)
{
	this->m_pPen = new CPen(PS_SOLID, penWidth, penColor);
	this->m_pBrush = new CBrush(bkgColor);
}

CColorRect::CColorRect(const CPoint& LeftTop, const CPoint& RightBottom, int penWidth, COLORREF penColor, COLORREF bkgColor) : CRect(LeftTop, RightBottom)
{
	this->m_pPen = new CPen(PS_SOLID, penWidth, penColor);
	this->m_pBrush = new CBrush(bkgColor);
}

CColorRect::CColorRect(const CPoint& LeftTop, const CSize& size, int penWidth, COLORREF penColor, COLORREF bkgColor) : CRect(LeftTop, size)
{
	this->m_pPen = new CPen(PS_SOLID, penWidth, penColor);
	this->m_pBrush = new CBrush(bkgColor);
}

CColorRect::~CColorRect()
{
	delete m_pPen;
	delete m_pBrush;
}

void CColorRect::PaintColorRect(CDC* pDC) // funkcja rysujaca
{
	/*pDC->SelectObject(this->m_pPen);
	pDC->MoveTo(50, 50);
	pDC->LineTo(200, 200);*/
	// rysowanie prostokata pDC->Rectangle( &CRect)

	// narysowac prostokat


	pDC->SelectObject(this->m_pBrush);
	
	pDC->Rectangle(this);
}

void CColorRect::setAttr(int penWidth, COLORREF penColor, COLORREF bkgColor) // ustawienie parametrow pedzla
{

}

CPen* CColorRect::getRectPen() const
{
	return this->m_pPen;
}

CBrush* CColorRect::getRectBrush() const
{
	return this->m_pBrush;
}

void CColorRect::drawObject(CDC* pDC)
{
	pDC->SelectObject(this->m_pBrush);

	pDC->Rectangle(this);
}