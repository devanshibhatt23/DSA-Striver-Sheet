#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// TC - O(n), SC - O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int ct_0 = 0;

        for(int i : nums) {
            if(i == 0) ct_0++;
            product *= i;
        }

        vector<int> ans;

        for(int i : nums) {
            if(i == 0) {
                if(ct_0 == 1) {
                    int prod = 1;
                    for(int j : nums) {
                        if(j) prod *= j;
                    }

                    ans.push_back(prod);
                }
                else ans.push_back(0);
            }
            else ans.push_back(product/i);
        }

        return ans;
    }
};

// TC - O(n), SC - O(n), without using division operator
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n,1), suff(n,1);

        for(int i=1; i<n; i++) {
            pref[i] = pref[i-1] * nums[i-1];
        }

        for(int i=n-2; i>=0; i--) {
            suff[i] = suff[i+1] * nums[i+1];
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            ans[i] = pref[i] * suff[i];
        }

        return ans;
    }
};