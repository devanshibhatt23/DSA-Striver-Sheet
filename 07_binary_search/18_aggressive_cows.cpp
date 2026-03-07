#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool can_all_cows_be_placed(vector<int> &nums, int k, int gap) {
    int n = nums.size();
    k--;

    int last_idx = 0;

    for(int i=1; i<n; i++) {
        if(nums[i] - nums[last_idx] < gap) continue;
        else {
            last_idx = i;
            k--;
        }
        if(k == 0) break;
    }

    if(k > 0) return 0;
    else return 1;
}

int aggressiveCows(vector<int> &nums, int k) {
    int n = nums.size();
    int ans;
    sort(nums.begin(), nums.end());

    int low = 1, high = (nums[n-1] - nums[0]);

    while(low <= high) {
        int mid = (low + high) / 2;

        bool x = can_all_cows_be_placed(nums,k,mid);
        if(x) {
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1;
    }

    return ans;
}

int main() {
    vector<int> nums = {4, 2, 1, 3, 6};
    int cows = 2;

    cout << aggressiveCows(nums,cows);
}