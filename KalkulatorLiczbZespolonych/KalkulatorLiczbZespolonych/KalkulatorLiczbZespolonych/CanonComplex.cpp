#include "stdafx.h"
#include "CanonComplex.h"



CCanonComplex::CCanonComplex(const CComplex & complex) : complex(complex)
{

}

CCanonComplex::~CCanonComplex()
{
}

std::ostream & operator<<(std::ostream stdOut, CCanonComplex & canonComplex)
{
	// TODO: insert return statement here
	stdOut << canonComplex.getRe() << " + " << "i*(" << canonComplex.getIm() << ")";
	return stdOut;
}

std::istream & operator >> (std::istream stdIn, CCanonComplex & canonComplex)
{
	// TODO: insert return statement here
	double tempRe;
	double tempIm;

	stdIn >> tempRe >> tempIm;

	canonComplex.setRe(tempRe);
	canonComplex.setIm(tempIm);

	return stdIn;
}
