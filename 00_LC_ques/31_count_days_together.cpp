#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateDay(vector<int> &mon, string time) {
        int month = stoi(time.substr(0,2));
        int date = stoi(time.substr(3,2));

        if(month == 1) {
            return date;
        }

        return mon[month-2] + date;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};

        for(int i=1; i<12; i++) {
            daysInMonth[i] += daysInMonth[i-1];
        }

        int arrA = calculateDay(daysInMonth, arriveAlice);
        int leaveA = calculateDay(daysInMonth, leaveAlice);
        int arrB = calculateDay(daysInMonth, arriveBob);
        int leaveB = calculateDay(daysInMonth, leaveBob);

        return max(0, min(leaveA, leaveB) - max(arrA, arrB) + 1);
    }
};