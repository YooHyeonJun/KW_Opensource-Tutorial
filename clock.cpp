#include "clock.h"
#include <iostream>
#include <thread>
using namespace std;
Clock::Clock() { //생성자
    hour = minute = second = 0;
}

Clock::~Clock() { //소멸자

}

void Clock::increaseHour() { 
    hour++;   //시간 증가 후 setHour호출하여 값 설정
    setHour(hour);

}

void Clock::increaseMinute() {
    minute++;//시간 증가 후 setMinute호출하여 값 설정
    if (minute > 59) increaseHour(); //59보다 커지면 carry
    setMinute(minute);
}

void Clock::increaseSecond() {
    second++;
    if (second > 59) increaseMinute();//59보다 커지면 carry
    setSecond(second);
}

void Clock::setTime(int second) {
    setHour(second / 3600 % 24); //각 변수에 맞게 나눠서 넣어줌
    setMinute (second / 60 % 60);
    setSecond (second % 60);
}

void Clock::setHour(int hour) {
    this->hour = hour % 24; //23보다 커지면 0으로 초기화
    cout << "Hour:" << this->hour << endl;
}

void Clock::setMinute(int minute) {
    this->minute = minute % 60; //60보다 커지면 0으로 초기화
    cout << "Minute:" << this->minute << endl;
}

void Clock::setSecond(int second) {
    this->second = second % 60; //60보다 커지면 0으로 초기화
    cout << "Second:" << this->second << endl;
}
int main() {
    Clock clock;
    int time = 0;
    cin >> time;
    // while (true) { //시간 증가에 따른 값 측정
    //     clock.increaseSecond();
    // }
    clock.setTime(time);
    return 0;
}