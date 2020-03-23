#include "stdafx.h"
#include "ColorRect.h"

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
	/*pDC->SelectObject(this->m_pBrush);
	pDC->Rectangle(this);*/

	CPen* pOldPen = pDC->SelectObject(m_pPen);
	CBrush* pOldBrush = pDC->SelectObject(m_pBrush);

	pDC->SelectObject(m_pBrush);
	pDC->Rectangle(this);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CColorRect::setAttr(int penWidth, COLORREF penColor, COLORREF bkgColor) // ustawienie parametrow pedzla
{
	m_pPen->DeleteObject();
	m_pBrush->DeleteObject();
	createAttr(penWidth, penColor, bkgColor);
}

CPen* CColorRect::getRectPen() const
{
	return this->m_pPen;
}

CBrush* CColorRect::getRectBrush() const
{
	return this->m_pBrush;
}

void CColorRect::createAttr(int penWidth, COLORREF penColor, COLORREF bkgColor)
{
	m_pPen->CreatePen(PS_SOLID, penWidth, penColor);
	m_pBrush->CreateSolidBrush(bkgColor);
}
