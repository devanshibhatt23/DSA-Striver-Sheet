#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        bool found = 0;
        int first_idx = -1;

        for(int i=0; i<n; i++) {
            if(nums[i] == target) {
                found = 1;
                first_idx = i;
                break;
            }
        }

        if(!found) return {};

        swap(nums[first_idx], nums[n-1]);
        int pivot = target;
        int i = 0;

        for(int j=0; j<n; j++) {
            if(nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[n-1]);

        int ct_target_before_pivot = 0, ct_target_after_pivot = 0;

        for(int j=0; j<i; j++) {
            if(nums[j] == target) {
                ct_target_before_pivot++;
            }
        }

        for(int j=i+1; j<n; j++) {
            if(nums[j] == target) {
                ct_target_after_pivot++;
            }
        }

        vector<int> indices;

        first_idx = i - ct_target_before_pivot;
        int total = ct_target_before_pivot + 1 + ct_target_after_pivot;

        for(int j=0; j<total; j++) {
            indices.push_back(first_idx);
            first_idx++;
        }

        return indices;
    }
};