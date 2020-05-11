#include "testDll.h"
#include "TimeDate.h"


TimeDate::TimeDate(int m_nHour, int m_nMin, int m_nSec, int m_nDay, int m_nMonth, int m_nYear) :
	time(m_nHour, m_nMin, m_nSec), date(m_nDay, m_nMonth, m_nYear)
{

}

TimeDate::TimeDate(Time const & time, Date const & date)
{
	this->time = time;
	this->date = date;
}


TimeDate::TimeDate(const TimeDate & timeDate)
{
	this->time = timeDate.time;
	this->date = timeDate.date;
}

TimeDate::~TimeDate()
{

}

void TimeDate::SetTimeDate(int m_nHour, int m_nMin, int m_nSec, int m_nDay, int m_nMonth, int m_nYear)
{
	this->time.setTime(m_nHour, m_nMin, m_nSec);
	this->date.setDate(m_nDay, m_nMonth, m_nYear);
}

ZDLL_API std::ostream & operator<<(std::ostream & stdOut, TimeDate & timeDate)
{
	// TODO: insert return statement here
	stdOut << timeDate.time.getHour() << ":" << timeDate.time.getMin() << ":" << timeDate.time.getSec() <<
		"\t" << timeDate.date.getDay() << "/" << timeDate.date.getMonth() << "/" << timeDate.date.getYear();
	return stdOut;
}

ZDLL_API std::istream & operator >> (std::istream & stdIn, TimeDate & timeDate)
{
	// TODO: insert return statement here
	// to trzeba zrobic :-)
	return stdIn;
}
