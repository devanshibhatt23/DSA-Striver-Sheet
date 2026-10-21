#include <bits/stdc++.h>
using namespace std;

// TC - O(n log n), SC - O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        for(int i=0; i<n; i++) {
            int val = target - numbers[i];
            int l = i+1, r = n-1;

            while(l <= r) {
                int mid = (l + (r-l)/2);

                if(numbers[mid] > val) {
                    r = mid-1;
                }
                else if(numbers[mid] < val) {
                    l = mid+1;
                }
                else if(mid == i) {
                    break;
                }
                else {
                    return {i+1,mid+1};
                }
            }
        }

        return {};
    }
};

// TC - O(n), SC - O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n-1;

        while(l < r) {
            int sum = numbers[l] + numbers[r];

            if(sum > target) {
                r--;
            }
            else if(sum < target) {
                l++;
            }
            else {
                return {l+1, r+1};
            }
        } 

        return {};
    }
};