#include <bits/stdc++.h>
using namespace std;

void moveZeroes4(vector<int>& nums) {
    for(int nonzerofoundat=0, i=0; i<nums.size(); i++) {
        if(nums[i] != 0) swap(nums[i], nums[nonzerofoundat++]);
    }
}

void moveZeroes3(vector<int>& nums) {
    int nonzerofoundat = 0;

    for(int i=0; i<nums.size(); i++) {
        if(nums[i] != 0) {
            nums[nonzerofoundat] = nums[i];
            nonzerofoundat++;
        }
    }

    for(int i=nonzerofoundat; i<nums.size(); i++) nums[i] = 0;
}

void moveZeroes2(vector<int>& nums) {
    int n = nums.size();

    int st = 0, end = n-1;

    while(st <= end) {
        if(nums[st] == 0) {
            for(int i=st+1; i<n; i++) {
                nums[i-1] = nums[i];
            }
            nums[end] = 0;
            end--;
            if(nums[st] == 0) st--;
        }
        st++;
    }
}

void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    vector<int> v;
    int zero_ct = 0;

    for(int i=0; i<n; i++) {
        if(nums[i]) v.push_back(nums[i]);
        else zero_ct++;
    }

    while(zero_ct--) {
        v.push_back(0);
    }

    for(int i=0; i<n; i++) {
        nums[i] = v[i];
    }
}

int main() {
    vector<int> v = {1,0,2,0,4,9,0,7};
    vector<int> v2 = {0,0,1,0,2,0,4,9,0,7};

    // 1. space - O(n), tc - O(n) 
    // moveZeroes(v);
    
    // 2. tc - O(n^2)
    // moveZeroes2(v2);

    // 3. tc - O(n)
    // moveZeroes3(v2);

    // 4. most optimised
    moveZeroes4(v2);

    for(int i=0; i<v2.size(); i++) {
        cout << v2[i] << " ";
    }
}