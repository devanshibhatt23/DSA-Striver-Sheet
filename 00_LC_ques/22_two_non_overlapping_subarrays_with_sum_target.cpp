#include <bits/stdc++.h>
using namespace std;

int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> pref(n,0), dp(n,INT_MAX);

    pref[0] = arr[0];
    for(int i=1; i<n; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    int ans = INT_MAX;

    unordered_map<int,int> mp;
    mp[0] = -1;

    for(int i=0; i<n; i++) {
        mp[pref[i]] = i;
    }

    for(int i=0; i<n; i++) {
        if(mp.count(pref[i]-target)) {
            int j = mp[pref[i]-target];

            int length = i-j;

            if(j != -1 && dp[j] != INT_MAX) {
                ans = min(ans, length + dp[j]);
            }

            if(i>0 && dp[i-1] != INT_MAX) {
                dp[i] = min(dp[i-1],length);
            }
            else {
                dp[i] = length;
            }
        }
        else {
            if(i>0 && dp[i-1] != INT_MAX) {
                dp[i] = dp[i-1];
            }
        }
    }

    if(ans == INT_MAX) return -1;
    return ans;
}