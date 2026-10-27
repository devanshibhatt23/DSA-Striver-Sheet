#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, string s) {
        if(idx < 0) return 1;
        if(idx == 0) {
            if(s[idx] != '0') return 1;
            return 0;
        }

        int countAlone = 0;
        int countPair = 0;

        if(s[idx] != '0') countAlone = recursion(idx-1,s);

        int pair = (s[idx]-'0') + (s[idx-1]-'0') * 10;

        if(pair <= 26 && s[idx-1] != '0') {
            countPair = recursion(idx-2,s);
        }

        return countAlone + countPair;
    }

    int memoization(int idx, string &s, vector<int> &dp) {
        if(idx < 0) return 1;
        if(idx == 0) {
            if(s[idx] != '0') return dp[0] = 1;
            return dp[0] = 0;
        }

        if(dp[idx] != -1) return dp[idx];

        int countAlone = 0;
        int countPair = 0;

        if(s[idx] != '0') countAlone = memoization(idx-1,s,dp);

        int pair = (s[idx]-'0') + (s[idx-1]-'0') * 10;

        if(pair <= 26 && s[idx-1] != '0') {
            countPair = memoization(idx-2,s,dp);
        }

        return dp[idx] = countAlone + countPair;
    }

    int tabulation(string &s) {
        int n = s.size();
        vector<int> dp(n,0);

        dp[0] = 1;

        for(int i=1; i<n; i++) {
            if(s[i] != '0') {
                dp[i] += dp[i-1];
            }

            int pair = (s[i]-'0') + (s[i-1]-'0') * 10;

            if(pair <= 26 && s[i-1] != '0') {
                if(i >= 2) dp[i] += dp[i-2];
                else dp[i] += 1;
            }
        }

        return dp[n-1];
    }

    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;

        int n = s.size();

        // return recursion(n-1,s);

        // vector<int> dp(n,-1);
        // return memoization(n-1,s,dp);

        return tabulation(s);
    }
};