#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    int left = 0, right = 0;
    int ct_zero = 0;

    while(right < n) {
        if(nums[right]) {
            ans = max(ans, right-left+1);
            right++;
        }
        else {
            ct_zero++;

            while(ct_zero > k) {
                if(nums[left] == 0) ct_zero--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;

    cout << longestOnes(nums,k);
}