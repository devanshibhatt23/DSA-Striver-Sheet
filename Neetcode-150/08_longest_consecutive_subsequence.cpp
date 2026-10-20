#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// TC - O(n logn), SC - O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(nums.empty()) return 0;

        int len = 1, ans = 1;

        for(int i=1; i<n; i++) {
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1] + 1) len++;
            else {
                ans = max(ans,len);
                len = 1;
            }
        }

        ans = max(ans,len);
        return ans;
    }
};

// TC - O(n), SC - O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(nums.empty()) return 0;

        unordered_map<int,int> mp;
        unordered_set<int> st(nums.begin(), nums.end());

        for(int i : nums) {
            mp[i] = 1;
        }

        int ans = 1;

        for(int i : st) {
            if(mp.count(i-1)) continue;
            else {
                int curr = i;
                int len = 0;

                while(mp.count(curr)) {
                    len++;
                    curr++;
                }

                ans = max(ans,len);
            }
        }

        return ans;
    }
};