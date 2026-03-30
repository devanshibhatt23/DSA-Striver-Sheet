#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

class Solution {
public:
    void generate_subsets(int idx, vector<int> &nums, vector<int> &v, vector<vector<int>> &res) {
        int n = nums.size();

        if(idx >= n) {
            res.push_back(v);
            return;
        }

        v.push_back(nums[idx]);
        generate_subsets(idx+1,nums,v,res);

        v.pop_back();
        generate_subsets(idx+1,nums,v,res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> empty;

        generate_subsets(0,nums,empty,res);
        return res;
    }
};