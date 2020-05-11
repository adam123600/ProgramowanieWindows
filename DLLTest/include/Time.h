#pragma once

#include <iostream>

class ZDLL_API Time
{
public:
	Time(int m_nHour = 0, int m_nMin = 0, int m_nSec = 0);
	Time(const Time &time);
	~Time();


private:
	int m_nHour;
	int m_nMin;
	int m_nSec;

public:
	inline const int getHour()	 { return this->m_nHour; }
	inline const int getMin()		 { return this->m_nMin; }
	inline const int getSec()		 { return this->m_nSec; }
	inline void setHour(int Hour)   { this->m_nHour = Hour; }
	inline void setMin(int Min)	 { this->m_nMin = Min; }
	inline void setSec(int Sec)	 { this->m_nSec = Sec; }

	void setTime(int Hour, int Min, int Sec);

	friend ZDLL_API std::ostream &operator<<(std::ostream &stdOut, Time &time);
	friend ZDLL_API std::istream &operator>>(std::istream &stdIn, Time &time);
};
