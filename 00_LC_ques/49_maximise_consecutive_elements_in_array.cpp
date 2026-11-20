#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int,int> dp;
        int ans = 0;

        for(int &x : nums) {
            dp[x+1] = max(dp[x+1], dp[x]+1);
            dp[x] = max(dp[x-1]+1, dp[x]);

            ans = max(ans, max(dp[x+1], dp[x]));
        }

        return ans;
    }
};