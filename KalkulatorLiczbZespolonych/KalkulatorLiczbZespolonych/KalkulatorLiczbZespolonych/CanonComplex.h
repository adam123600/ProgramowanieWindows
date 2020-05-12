#pragma once
#include "Complex.h"
class CCanonComplex : public CComplex
{
public:
	CCanonComplex(const CComplex& complex);
	~CCanonComplex();

	friend std::ostream & operator << (std::ostream stdOut, CCanonComplex & canonComplex);
	friend std::istream & operator >> (std::istream stdIn, CCanonComplex & canonComplex);

private:
	CComplex complex;
};

