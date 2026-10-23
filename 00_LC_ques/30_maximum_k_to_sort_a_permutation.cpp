#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;
        
        for(int i=0; i<n; i++) {
            if(nums[i] != i) {
                if(ans == INT_MAX) {
                    ans = nums[i];
                }
                else {
                    ans &= nums[i];
                }
            }
        }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};