#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int mini = 1e9;
        int n = nums.size();

        for(int &i : nums) {
            sum += i;
            mini = min(mini,i);
        }

        return sum - mini*1LL*n;
    }
};