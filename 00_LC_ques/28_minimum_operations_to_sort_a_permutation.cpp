#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) {
            return 0;
        }

        int start;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                start = i;
                break;
            }
        }

        bool inc = 1, dec = 1;

        for(int i=1; i<n; i++) {
            int val = nums[(start+i)%n];

            if(val != i) {
                inc = false;
            }
            if(val != n-i) {
                dec = false;
            }

            if(!inc && !dec) {
                return -1;
            }
        }

        if(inc) {
            return min(start,n-start+2);
        }

        return min(n-start,start+2);
    }
};