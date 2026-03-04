#include <bits/stdc++.h>
#define ll long long
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n-1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(mid != low && nums[mid] == nums[mid-1]) {
            if(mid % 2 == 0) high = mid - 2;
            else low = mid + 1;
        }
        else if(mid != high && nums[mid] == nums[mid+1]) {
            if(mid % 2 == 0) low = mid + 2;
            else high = mid - 1; 
        }
        else {
            ans = nums[mid];
            return ans;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {3,3,4,7,7,9,9,10,10};

    cout << singleNonDuplicate(nums);
}