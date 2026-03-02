#include <bits/stdc++.h>
#define ll long long
using namespace std;

int upperBound(vector<int> &nums, int x){
    int n = nums.size();
    int ans = n;

    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] <= x) {
            low = mid + 1;
        }
        else {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {-1,4,5,6,9,10};
    int target = 7;

    cout << upperBound(nums, target);
}