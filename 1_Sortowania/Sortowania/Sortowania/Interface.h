#pragma once

#include "stdafx.h"
#include "iostream"
class ObjectToDraw
{
public:
	virtual void drawObject(CDC* pDC) = 0;
};
