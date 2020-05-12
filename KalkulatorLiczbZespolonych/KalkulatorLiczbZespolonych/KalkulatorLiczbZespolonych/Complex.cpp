#include "stdafx.h"
#include "Complex.h"



CComplex::CComplex(double m_re, double m_im)
{
	this->m_re = m_re;
	this->m_im = m_im;
}

CComplex::CComplex(const CComplex & complex)
{
	this->m_re = complex.m_re;
	this->m_im = complex.m_im;
}

CComplex::~CComplex()
{
}

CComplex & CComplex::operator=(const CComplex & complex)
{
	// TODO: insert return statement here
	this->m_re = complex.m_re;
	this->m_im = complex.m_im;
	return *this;
}

CComplex & CComplex::operator+=(const CComplex & complex)
{
	// TODO: insert return statement here
	this->m_re += complex.m_re;
	this->m_im += complex.m_im;
	return *this;
}

CComplex & CComplex::operator-=(const CComplex & complex)
{
	// TODO: insert return statement here
	this->m_re -= complex.m_re;
	this->m_im -= complex.m_im;
	return *this;
}

CComplex & CComplex::operator*=(const CComplex & complex)
{
	// TODO: insert return statement here
	double temp = this->m_re;
	this->m_re = this->m_re * complex.m_re - this->m_im * complex.m_im;
	this->m_im = temp * complex.m_im + this->m_im * complex.m_re;
	return *this;
}

CComplex & CComplex::operator/=(const CComplex & complex)
{
	// TODO: insert return statement here
	double temp = this->m_re;
	this->m_re = (this->m_re*complex.m_re + this->m_im*complex.m_im) / (complex.m_re*complex.m_re + complex.m_im*complex.m_im);
	this->m_im = (this->m_im*complex.m_re - temp*complex.m_im) / (complex.m_re*complex.m_re + complex.m_im*complex.m_im);
	return *this;
}

const double CComplex::getRe()
{
	return this->m_re;
}

const double CComplex::getIm()
{
	return this->m_im;
}

void CComplex::setRe(const double &re)
{
	this->m_re = re;
}

void CComplex::setIm(const double &im)
{
	this->m_im = im;
}

void CComplex::setComplex(const CComplex & complex)
{ 
	this->setRe(complex.m_re);
	this->setIm(complex.m_im);
}

CComplex CComplex::Module()
{
	CComplex result;
	result.setRe(sqrt(this->getRe() * this->getRe() + this->getIm() * this->getIm()));
	result.setIm(0);
	return result;
}

CComplex CComplex::Coupled()
{
	CComplex result(this->getRe(), this->getIm() * (-1));
	return result;
}

CComplex operator+(const CComplex & complex1, const CComplex & complex2)
{
	CComplex result(complex1);
	result += complex2;
	return result;
}

CComplex operator-(const CComplex & complex1, const CComplex & complex2)
{
	CComplex result(complex1);
	result -= complex2;
	return result;
}

CComplex operator*(const CComplex & complex1, const CComplex & complex2)
{
	CComplex result(complex1);
	result *= complex2;
	return result;
}

CComplex operator/(const CComplex & complex1, const CComplex & complex2)
{
	CComplex result(complex1);
	result /= complex2;
	return result;
}

bool operator==(const CComplex & complex1, const CComplex & complex2)
{
	if (complex1.m_re == complex2.m_re && complex1.m_im == complex2.m_im)
		return true;
	else
		return false;
}

bool operator!=(const CComplex & complex1, const CComplex & complex2)
{
	return !(complex1 == complex2);
}
