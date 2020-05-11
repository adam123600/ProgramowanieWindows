

#include "testDll.h"


Date::Date(int m_nDay, int m_nMonth, int m_nYear)
{
	this->m_nDay = m_nDay;
	this->m_nMonth = m_nMonth;
	this->m_nYear = m_nYear;
}

Date::Date(const Date & date)
{
	this->m_nDay = date.m_nDay;
	this->m_nMonth = date.m_nMonth;
	this->m_nYear = date.m_nYear;
}

Date::~Date()
{
}

void Date::setDate(int Day, int Month, int Year)
{
	this->setDay(Day);
	this->setMonth(Month);
	this->setYear(Year);
}

ZDLL_API std::ostream & operator<<(std::ostream & stdOut, Date & date)
{
	// TODO: insert return statement here
	stdOut << date.m_nDay << "/" << date.m_nMonth << "/" << date.m_nYear;
	return stdOut;
}

ZDLL_API std::istream &operator >> (std::istream &stdIn, Date &date) 
{
	stdIn >> date.m_nDay >> date.m_nMonth >> date.m_nYear;
	return stdIn;
}