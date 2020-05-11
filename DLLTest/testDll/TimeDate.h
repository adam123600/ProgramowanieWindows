#pragma once
class ZDLL_API TimeDate
{
public:
	TimeDate(int m_nHour = 0, int m_nMin = 0, int m_nSec = 0, int m_nDay = 1, int m_nMonth = 1, int m_nYear = 1990);
	TimeDate(Time const &time, Date const &date);
	TimeDate(const TimeDate &timeDate);
	~TimeDate();

private:
	Time time;
	Date date;

public:
	void SetTimeDate(int m_nHour, int m_nMin, int m_nSec,
		int m_nDay, int m_nMonth, int m_nYear);

	friend ZDLL_API std::ostream &operator << (std::ostream &stdOut, TimeDate &timeDate);
	friend ZDLL_API std::istream &operator >> (std::istream &stdIn, TimeDate &timeDate);
};

