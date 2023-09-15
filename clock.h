#pragma once
class Clock { //Clock Class 선언
public:
	Clock();
	~Clock();

	void increaseHour();
	void increaseMinute();
	void increaseSecond();

	void setTime(int second);
private:
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	int hour;
	int minute;
	int second;
};