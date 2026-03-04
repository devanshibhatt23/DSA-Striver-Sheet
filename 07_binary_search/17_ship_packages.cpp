#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long calc_days(vector<int>& weights, long long mid) {
    int n = weights.size();
    int day = 1, cap = 0;

    for (int i = 0; i < n; i++) {
        if (cap + weights[i] > mid) {
            day++;
            cap = 0;
        }
        cap += weights[i];
    }
    return day;
}

int shipWithinDays(vector<int>& weights, int days) {
    int ans;
    int n = weights.size();
    int low = weights[0];
    long long high = 0;

    for (int i = 0; i < n; i++) {
        low = max(low, weights[i]);
        high += weights[i];
    }

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long req_days = calc_days(weights, mid);

        if (req_days <= days) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << shipWithinDays(weights,days);
}