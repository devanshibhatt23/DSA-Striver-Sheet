#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pref(n,0);

        pref[0] = nums[0];
        for(int i=1; i<n; i++) {
            pref[i] = pref[i-1] + nums[i];
        }

        int ans = 1e9;

        for(int size=l; size<=r; size++) {
            int left = 0, right = size-1;

            while(right < n) {
                int sum = pref[right];

                if(left == 0) {
                    if(sum > 0) {
                        ans = min(ans,sum);
                    }
                }
                else {
                    sum -= pref[left-1];
                    if(sum > 0) {
                        ans = min(ans,sum);
                    }
                }

                left++, right++;
            }
        }

        if(ans == 1e9) {
            return -1;
        }
        return ans;
    }
};