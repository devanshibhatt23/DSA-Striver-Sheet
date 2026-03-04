#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int maxi = piles[0];
    for(int &i : piles) {
        maxi = max(maxi,i);
    }

    int low = 1, high = max(h,maxi);
    int ans;

    while(low <= high) {
        int mid = (low + high) / 2;

        long long ct = 0;
        for(int &i : piles) {
            ct += i/mid;
            if(i % mid) ct++; 
        }

        if(ct <= h) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main() {
    vector<int> piles = {9,7,3,7,8};
    int h = 8;

    cout << minEatingSpeed(piles,h);
}