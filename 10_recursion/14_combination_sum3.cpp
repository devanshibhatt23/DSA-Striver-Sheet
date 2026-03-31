#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;

class Solution {
public:
    void k_nums_with_sum_n(int idx, int k, int sum, int target, vector<int> &nums, vector<int> &v, vector<vector<int>> &res) {
        if(sum > target) return;

        if(idx >= nums.size()) {
            if(v.size() == k) {
                if(sum == target) {
                    res.push_back(v);
                }
            }
            return;
        }

        v.push_back(nums[idx]);
        sum += nums[idx];
        k_nums_with_sum_n(idx+1,k,sum,target,nums,v,res);

        sum -= nums[idx];
        v.pop_back();
        k_nums_with_sum_n(idx+1,k,sum,target,nums,v,res);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> empty;

        vector<int> nums = {1,2,3,4,5,6,7,8,9};

        k_nums_with_sum_n(0,k,0,n,nums,empty,res);
        return res;
    }
};