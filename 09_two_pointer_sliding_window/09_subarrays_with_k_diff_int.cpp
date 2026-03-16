#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int func(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    int left = 0, right = 0;

    unordered_map<int,int> m;

    while(right < n) {
        m[nums[right]]++;

        while(m.size() > k) {
            m[nums[left]]--;
            if(m[nums[left]] == 0) m.erase(nums[left]);
            left++;
        }

        if(m.size() <= k) ans += (right-left+1);
        right++;
    }

    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return func(nums,k) - func(nums,k-1);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int k;
    cin >> k;

    cout << subarraysWithKDistinct(nums,k);
}