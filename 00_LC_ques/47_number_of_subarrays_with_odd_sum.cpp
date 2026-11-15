#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> pref(n+1,0);
        pref[1] = arr[0];

        for(int i=1; i<n; i++) {
            pref[i+1] = pref[i] + arr[i];
        }

        int curr_even_ct = 0, curr_odd_ct = 0;
        long long total_even_before_odd = 0, total_odd_before_even = 0;

        for(int i=0; i<n+1; i++) {
            if(pref[i] & 1) {
                total_even_before_odd += curr_even_ct;
                curr_odd_ct++;
            }
            else {
                total_odd_before_even += curr_odd_ct;
                curr_even_ct++;
            }
        }

        return ((total_even_before_odd % MOD) + (total_odd_before_even % MOD) % MOD);
    }
};