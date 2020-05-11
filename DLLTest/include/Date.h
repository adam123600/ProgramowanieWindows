#pragma once

#include <iostream>

class ZDLL_API Date
{
public:
	
	Date(int m_nDay = 1, int m_nMonth = 1, int m_nYear = 1990);
	Date(const Date &date);
	~Date();

private:
	int m_nDay;
	int m_nMonth;
	int m_nYear;

public:
	inline const int getDay() { return this->m_nDay; }
	inline const int getMonth() { return this->m_nMonth; }
	inline const int getYear() { return this->m_nYear; }
	inline void setDay(int Day) { this->m_nDay = Day; }
	inline void setMonth(int Month) { this->m_nMonth = Month; }
	inline void setYear(int Year) { this->m_nYear = Year; }

	void setDate(int Day, int Month, int Year);

	friend ZDLL_API std::ostream &operator<<(std::ostream &stdOut, Date &date);
	friend ZDLL_API std::istream &operator>>(std::istream &stdIn, Date &date);
};

