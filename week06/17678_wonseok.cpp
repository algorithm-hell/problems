#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// "hh:mm" 형식의 시간에 대해 사칙연산 및 비교 연산을 제공하는 클래스
class Time {
public:
    Time() {};
    Time(int minutes): minutes(minutes) {}
    Time(string time) {
        int mid = time.find(":");
        
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(mid+1, 2));
        
        this->minutes = hours * 60 + minutes;
    }

    bool operator<(const Time& other) { return this->minutes < other.minutes; }
    bool operator==(const Time& other) { return this->minutes == other.minutes; }
    bool operator<=(const Time& other) { return *this < other || *this == other; }
    Time operator+(const int minute) { return Time(this->minutes+minute); }
    Time operator-(const int minute) {return Time(this->minutes-minute); }

    string toString() {
        int hours = (this->minutes / 60) % 24;
        int minutes = this->minutes % 60;
        string strHours = to_string(hours);
        string strMinutes = to_string(minutes);
        if (hours < 10) strHours = "0" + strHours;
        if (minutes < 10) strMinutes = "0" + strMinutes;

        return strHours + ":" + strMinutes;
    }
    
    int minutes;
};

class LazyWorker {
public:
    // 버스 도착 시간을 구성한다.
    void setBuses(int nums, int interval, int capacity) {
        Time bus = Time("09:00");
        for (int i=0; i<nums; i++) {
            buses.push_back(bus);
            bus = bus + interval;
        }

        busCapacity = capacity;
    }

    // 승객의 대기 시작 시간을 구성한다.
    void setPassengers(vector<string>& timetable) {
        for (string time : timetable) 
            passengers.push_back(Time(time));
        sort(passengers.begin(), passengers.end());
    }

    // 1. 승객을 한 명씩 버스에 탑승시킨다.
    // 2. 마지막 승객까지 탑승시킨다.
    //   - 버스에 정원이 남은 경우 -> 막차 버스 탑승
    //   - 버스에 정원이 없는 경우 -> 마지막 탑승자보다 1분 빠르게 대기
    string goToWork() {
        int onBoard = operateBuses();

        if (onBoard < busCapacity) 
            return buses.back().toString();
        if (pPassenger < passengers.size())
            return (passengers[pPassenger]-1).toString();

        return (passengers.back()-1).toString();
    }

private:
    // 승객들을 버스에 탑승시키고, 마지막 버스의 탑승 인원을 반환한다.
    // 이때 pPassenger는 마지막에 탄 승객을 가리킨다.
    int operateBuses() {
        int onBoard;
        while (pBus < buses.size()) {
            onBoard = 0;
            while (pPassenger < passengers.size()) {
                if (!isItMyBus()) break;
                if (isBusFull(onBoard)) break;

                onBoard++;
                pPassenger++;
            }

            pBus++;
        }
        pPassenger--;

        return onBoard;
    }
    
    bool isItMyBus() { return passengers[pPassenger] <= buses[pBus]; }
    bool isBusFull(int onBoard) { return onBoard == busCapacity; }

    vector<Time> passengers;
    vector<Time> buses;

    int pPassenger=0, pBus=0;
    int busCapacity;
};

string solution(int n, int t, int m, vector<string> timetable) {
    LazyWorker worker;
    worker.setBuses(n, t, m);
    worker.setPassengers(timetable);

    return worker.goToWork();
};

void testSortingTimesShouldBeAscendingByDefault() {
    Time t1("02:11"), t2("04:50"), t3("00:05");
    vector<Time> times = {t1, t2, t3};
    sort(times.begin(), times.end());

    // assert
}

void testEarlierTimeIsLesserThanLateTime() {
    Time t1("02:11"), t2("04:50");
    // assert(t1 < t2, true);
    // assert(t2 < t1, false);
}