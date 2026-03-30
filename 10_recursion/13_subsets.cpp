#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

class Solution {
public:
    void generate_subsets(int idx, vector<int> &nums, vector<int> &v, vector<vector<int>> &res) {
        int n = nums.size();
        res.push_back(v);

        for(int i=idx; i<n; i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;

            v.push_back(nums[i]);
            generate_subsets(i+1,nums,v,res);

            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> empty;

        sort(nums.begin(), nums.end());

        generate_subsets(0,nums,empty,res);
        return res;
    }
};