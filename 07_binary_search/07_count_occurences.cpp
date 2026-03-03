#include <bits/stdc++.h>
#define ll long long
using namespace std;

int first_occ(vector<int>& nums, int target) {
    int n = nums.size();
    int st = -1;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] > target) high = mid - 1;
        else if(nums[mid] < target) low = mid + 1;
        else {
            st = mid;
            high = mid - 1;
        }
    }
    return st;
}

int last_occ(vector<int>& nums, int target) {
    int n = nums.size();
    int end = -1;
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(nums[mid] > target) high = mid - 1;
        else if(nums[mid] < target) low = mid + 1;
        else {
            end = mid;
            low = mid + 1;
        }
    }
    return end;
}

int countOccurrences(vector<int>& arr, int target) {
    int st_pos = first_occ(arr,target);
    int end_pos = last_occ(arr,target);

    if(st_pos == -1 || end_pos == -1) return 0;
    else return (end_pos - st_pos + 1);
}

int main() {
    vector<int> nums = {-1,4,5,6,6,6,9,10};
    int target = 6;

    cout << countOccurrences(nums,target);
}