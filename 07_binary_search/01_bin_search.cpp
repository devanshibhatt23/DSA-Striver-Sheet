#include <bits/stdc++.h>
#define ll long long
using namespace std;

int bin_search(vector<int>& nums, int target, int left, int right) {
    if(left <= right) {
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) return bin_search(nums,target,left,mid-1);
            else return bin_search(nums,target,mid+1,right);
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    return bin_search(nums, target, 0, nums.size()-1);
}

int main() {
    vector<int> nums = {-1,4,5,6,9,10};
    int target = 10;

    cout << search(nums, target);
}