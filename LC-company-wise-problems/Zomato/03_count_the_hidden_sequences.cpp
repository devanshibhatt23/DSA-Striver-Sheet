#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = differences.size();

        long long pref_sum = 0;
        long long max_diff = 0LL, min_diff = 0LL;

        for(int i=0; i<x; i++) {
            pref_sum += differences[i];

            max_diff = max(max_diff, pref_sum);
            min_diff = min(min_diff, pref_sum);
        }

        long long max_lower = max(lower-max_diff, lower-min_diff);
        long long min_upper = min(upper-max_diff, upper-min_diff);

        if(max_lower > min_upper) {
            return 0;
        }

        return min_upper - max_lower + 1;
    }
};