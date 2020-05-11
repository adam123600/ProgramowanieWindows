//#include "Time.h"

#include "testDll.h"

//Time::Time()
//{
//}

Time::Time(int m_nHour, int m_nMin, int m_nSec)
{
	this->m_nHour = m_nHour;
	this->m_nMin = m_nMin;
	this->m_nSec = m_nSec;
}


Time::Time(const Time &time)
{
	this->m_nHour = time.m_nHour;
	this->m_nMin = time.m_nMin;
	this->m_nSec = time.m_nSec;
}

Time::~Time()
{
}

void Time::setTime(int Hour, int Min, int Sec) {
	this->setHour(Hour);
	this->setMin(Min);
	this->setSec(Sec);
}

ZDLL_API std::ostream & operator<<(std::ostream &stdOut, Time & time)
{
	// TODO: insert return statement here
	stdOut << time.m_nHour << ":" << time.m_nMin << ":" << time.m_nSec;
	return stdOut;
}

ZDLL_API std::istream & operator >> (std::istream & stdIn, Time & time)
{
	// TODO: insert return statement here
	stdIn >> time.m_nHour >> time.m_nMin >> time.m_nSec;
	return stdIn;
}
