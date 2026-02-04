#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    if(bills[0] != 5) return false;

    int count_five = 0, count_ten = 0;
    for(int &i : bills) {
        if(i == 5) count_five++;
        else if(i == 10) {
            if(count_five == 0) return false;
            count_ten++;
            count_five--;
        }
        else {
            if(count_five >= 1 && count_ten >= 1) {
                count_five--;
                count_ten--;
                continue;
            }
            else if(count_five >= 3) {
                count_five -= 3;
                continue;
            }
            else return false;
        }
    }

    return true;
}

int main() {
    vector<int> v = {5,5,5,10,20};
    cout << lemonadeChange(v);
}