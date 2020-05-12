#pragma once

#include <iostream>
#include <math.h>

class CComplex
{
public:
	CComplex(double m_re = 1, double m_im = 1);
	CComplex(const CComplex &complex);
	~CComplex();

	CComplex & operator = (const CComplex & complex);

	CComplex & operator += (const CComplex & complex);
	CComplex & operator -= (const CComplex & complex);
	CComplex & operator *= (const CComplex & complex);
	CComplex & operator /= (const CComplex & complex);

	friend CComplex operator + (const CComplex & complex1, const CComplex & complex2);
	friend CComplex operator - (const CComplex & complex1, const CComplex & complex2);
	friend CComplex operator * (const CComplex & complex1, const CComplex & complex2);
	friend CComplex operator / (const CComplex & complex1, const CComplex & complex2);

	friend bool operator == (const CComplex & complex1, const CComplex & complex2);
	friend bool operator != (const CComplex & complex1, const CComplex & complex2);

	const double getRe();
	const double getIm();

	void setRe(const double &re);
	void setIm(const double &im);
	void setComplex(const CComplex & complex);

	CComplex Module();
	CComplex Coupled();

private:
	double m_re;
	double m_im;
};

