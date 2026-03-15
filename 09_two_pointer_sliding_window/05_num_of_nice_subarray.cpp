#include <bits/stdc++.h>
#include <map>
#define ll long long
using namespace std;

int func(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0, odd_ct = 0;
    int left = 0, right = 0;

    while(right < n) {
        if(nums[right] & 1) odd_ct++;
        
        while(odd_ct > k) {
            if(nums[left] & 1) odd_ct--;
            left++;
        }

        count += (right - left + 1);
        right++;
    }

    return count;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return func(nums,k) - func(nums,k-1);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    int k;
    cin >> k;

    cout << numberOfSubarrays(nums,k);
}