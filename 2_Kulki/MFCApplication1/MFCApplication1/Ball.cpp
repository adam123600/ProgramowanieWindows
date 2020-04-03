#include "stdafx.h"
#include "Ball.h"



CBall::CBall(int xLeftTop, int yLeftTop, int xRightBottom, int yRightBottom, COLORREF color) 
	: CRect(xLeftTop, yLeftTop, xRightBottom, yRightBottom)
{


	m_pBallPen = std::make_unique<CPen>(  ); // w nawiasie parametry
}

CBall::CBall(const CRect & pRect, COLORREF color)
{
}

CBall::CBall(const CPoint & LeftTop, const CSize & size, COLORREF color)
{
}

CBall::~CBall()
{

}

inline void CBall::SetColor(COLORREF color)
{
}

inline void CBall::SetBallSize(const CRect & pRect)
{
}

void CBall::PaintBall(CDC * pDC)
{
}

inline void CBall::CreateObjects(COLORREF BallColor)
{
}

inline void CBall::DeleteObjects()
{
}

void CBall::InitObjects(COLORREF BallColor)
{
}
